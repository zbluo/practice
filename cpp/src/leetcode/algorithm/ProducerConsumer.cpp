//
// Created by Zhong Bing on 2020-03-07.
//
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>

class condvarQueue
{
    std::queue<int> produced_nums;
    std::mutex m;
    std::condition_variable cond_var;
    std::atomic<bool> done = false;
    std::atomic<bool> notified = false;
public:
    void produce(int i)
    {
        //std::unique_lock<std::mutex> lock(m);
        std::lock_guard<std::mutex> lock(m);
        produced_nums.push(i);
        notified = true;
        cond_var.notify_one();
    }

    template<typename Consumer>
    void consume(Consumer consumer)
    {
        while (!done || !produced_nums.empty()) {
            std::unique_lock<std::mutex> lock(m);
            cond_var.wait(lock, [&](){return notified == true;});
            while (!produced_nums.empty()) {
                consumer(produced_nums.front());
                produced_nums.pop();
            }
            notified = false;
        }
    }

    void close()
    {
        done = true;
        notified = true;
        cond_var.notify_one();
    }
};

int pc_test()
{
    std::cout << "Start...\n";
    condvarQueue queue;

    std::thread producer([&]() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "producing " << i << '\n';
            queue.produce(i);
        }
        queue.close();
    });

    auto consumer_func = [](int input){
        std::cout << "consuming " << input << '\n';
    };

    std::thread consumer([&]() {
        queue.consume(consumer_func);
    });

    producer.join();
    consumer.join();
    std::cout << "End...\n";
}
