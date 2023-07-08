// constructing atomics
#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>         // std::thread, std::this_thread::yield
#include <vector>         // std::vector
#include <string>
#include <functional>
#include <numeric>
#include <future>
#include <mutex>
#include <condition_variable>
#include <map>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <list>
#include <set>
#include <stack>
#include <iomanip>
#include <signal.h>
#include <unistd.h>
#include <semaphore.h>
#include <shared_mutex>

using namespace std;

class ThreadSafeCounter {
public:
    ThreadSafeCounter() = default;

    // Multiple threads/readers can read the counter's value at the same time.
    unsigned int get() const {
        std::shared_lock lock(mutex_);
        return value_;
    }

    // Only one thread/writer can increment/write the counter's value.
    void increment() {
        std::unique_lock lock(mutex_);
        value_++;
    }

    // Only one thread/writer can reset/write the counter's value.
    void reset() {
        std::unique_lock lock(mutex_);
        value_ = 0;
    }

private:
    mutable std::shared_mutex mutex_;
    unsigned int value_ = 0;
};

int rw_test() {
    ThreadSafeCounter counter;

    auto increment_and_print = [&](string str) mutable -> void {
        int i;
        for (i = 0; i < 3; i++) {
            counter.increment();
            std::cout << std::this_thread::get_id() << ' ' << counter.get() << '\n';
            // Note: Writing to std::cout actually needs to be synchronized as well
            // by another std::mutex. This has been omitted to keep the example small.
        }
        if (i == 3)
            std::cout << str << '\n';
    };

    std::thread thread1(increment_and_print, "thread1");
    std::thread thread2(increment_and_print, "thread2");

    thread1.join();
    thread2.join();
}