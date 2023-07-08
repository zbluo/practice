#include <iostream>
#include <thread>
#include <queue>
#include <atomic>
#include <stdio.h>
#include <vector>
#include <future>

using namespace std;

void adInt(int a, int b)
{
    cout << "+: " << a + b << "\n";
}
void mulInt(int a) {
    cout << "*: " << a * 10 << "\n";
}
void divInt() {
    cout << "/: " << 100 / 5 << "\n";
}

typedef void(*myFunc)();

class mySch{
private:
    queue<myFunc> jobs;
    condition_variable con_var;
    atomic<bool> notified;
    atomic<bool> done;
    mutex mu;
public:
    mySch(){
        notified = false;
        done = false;
    }
    void produce(myFunc func) {
        unique_lock<mutex> lock1(mu);
        jobs.push(func);
        notified = true;
        con_var.notify_one();
    }
    void consume() {
        while(!done || !jobs.empty()) {
            unique_lock<mutex> lock1(mu);
            con_var.wait(lock1, [&](){return notified == true;});
            while(!jobs.empty()) {
                myFunc job = jobs.front();
                jobs.pop();
                async(job);
            }
            notified = false;
        }
    }
    void close() {
        notified = true;
        done = true;
    }
};

static int x = 2, y = 3, z = 5;
int sc_test() {
    mySch sch;
    vector<myFunc> funcs;
    myFunc fun[10];
    fun[0] = divInt;
    fun[0]();
    char* pt = (char *)malloc(10);
    *(pt+1) = 'A';
    cout << *(pt + 1) << endl;
    funcs.push_back([](){adInt(x, y); });
    funcs.push_back([](){mulInt(z);});
    funcs.push_back([](){divInt();});
    auto f1 = [&](){
        for(auto f : funcs) {
            sch.produce(f);
        }
        sch.close();
    };
    thread t1([&](){sch.consume();});
    thread t2(f1);
    t1.join();
    t2.join();
}
