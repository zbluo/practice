//
// Created by Zhongbing Luo on 2/3/22.
//

#ifndef CPPTEST_TEST1_H
#define CPPTEST_TEST1_H
#include <iostream>
#include <vector>
#include <iomanip>
//#include <openssl/obj_mac.h>
//#include <openssl/ec.h>
//#include <openssl/ecdsa.h>
//#include <openssl/bn.h>
//#include <openssl/evp.h>
//#include <openssl/crypto.h>
//#include <openssl/err.h>
//#include <openssl/x509.h>
//#include <openssl/ossl_typ.h>
//#include <openssl/pem.h>
//#include <openssl/pkcs7.h>
//#include <openssl/asn1.h>
//#include <fstream>
// #include <boost/filesystem.hpp>
#include <stdlib.h>
#include <queue>
#include <future>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <unistd.h>
#include <pthread.h>
#include "openssl_test.h"

using namespace std;
void divInt() __attribute__((optnone));

void adInt(int a, int b) {
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
void sched() {
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
} __attribute__ ((optimize(0)))

int init() {
    return 10;
}

int fun() {
    static int count = init();
    count++;
    return count;
}

struct st{
    int i;
    string s;
};

union un {
    st  s;
    char c[128];
    ~un() {}

    un() {

    }
};

typedef struct struct_1_t STRUCT_1;
typedef struct struct_2_t STRUCT_2;

struct struct_1_t {
    unsigned char ch[2];
    int (*init) (STRUCT_2 *st_2);
};

struct struct_2_t {
    int i[2];
    int (*init) (STRUCT_1 *st_1);
};

int do_sth(STRUCT_2 *st2) {
    printf("\n%d\n", st2->i[0]);
}

STRUCT_1 st1 = {{'a', 'b'}, do_sth};

typedef int MyDisp (unsigned char ch[2]);
int hello(unsigned char ch[2]) {
    cout << endl << ch[1] << endl << ch[0] << endl;
}

int main1() {

    MyDisp *md;
    md = hello;
    unsigned char ch[2] = {'a', 'b'};
    md(ch);
    STRUCT_2 myst2 = {{11, 22}, NULL};
    myst2.i[0] = 33;
    st1.init(&myst2);

    sched();
    cout << endl;
    int i = 5, j = -2;
    int x = i - j;
    int y = i + (~j + 1);

    cout << (~j + 1) << endl << bitset<8>(j) << endl;

    cout << x << endl << y << endl;

    vector<int> test = {1, 2, 3};
    for(auto it = test.crbegin(); it < test.crend(); it++)
        cout << *it << endl;

    cout << ('F' - '0') << endl;

    unordered_map<char, int> hm = {{'A', 10}, {'B', 11}};

    cout << hm['A'] << endl;

    mutex mtx;
    unique_lock<mutex> lk(mtx, defer_lock);
    lk.try_lock();

    cout << endl << endl << endl;
    int t1[2] = {0x41, 0x42};
    int t2[2] = {0x43, 0x44};
    int *p1 = t1;
    for(int i = 0; i < 20; i++) {
        cout << *(p1+i) << endl << *(p1-i) << endl;
    }

    cout << "t2: " << t2[0] << endl << t2[1];

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(2);
    cout << endl << pq.top() << endl;

    int m = 73, n = 1;
    cout << &m << endl << &n << endl;
    // int *pInt = (int*)0x7ffeed1387bc;
    // cout << *pInt << endl;
    cout << fun() << endl;
    cout << fun() << endl;
    sleep(1);
    cout << fun() << endl;
    cout << fun() << endl;

    un u;
    u.s.i = 145534;
    cout << u.s.i << endl << sizeof(un) << endl << sizeof(u) << endl;

    void *p = nullptr;
    cout << sizeof(void *) << endl << sizeof(p) << endl;
    printf("hello\n");

    const volatile int vi = 10;
    cout << vi << endl;
    int *pi = (int *)(&vi);
    *pi = 100;
    cout << vi << endl;
    printf("%d",90);
    printf("%d", 0b101010);

    hash<string> h;
    cout << endl << endl << endl << h("2") << endl << hash<string>()("2") << endl;
    cout << atoi("73") << endl;
    map<char, int> mp = {{'a', 1}};
    auto it = mp.begin();
    cout << (*it).first << endl << (*it).second << endl;

    cout << "end" << endl;

    string ssss = "abcde";
    cout << ssss.substr(0, 0) << endl << ssss.substr(1) << endl;

    char a[10] = "geek";
    char *pa = "geek";
    cout << endl << sizeof(a) << endl << sizeof(pa) << endl;

    istringstream is("   +     567239      ");
    char op;
    int op1;
    is >> op >> op1;
    cout << endl << op << endl << op1 << endl;

    cout << hex << sbrk(0) << endl;
    pthread_mutex_t pmtx;
    pthread_mutex_lock(&pmtx);
    cout << "bye!" << endl;
    pthread_mutex_unlock(&pmtx);

    future<int> f1 = async([](){sleep(2); cout << "hi    1" << endl; return 0;});
    future<int> f2 = async([](){sleep(1); cout << "hi      2" << endl; return 0;});

    struct teststru {
        string s;
    } ttu;

    ttu.s = "ni hao";
    cout << ttu.s << endl;

    cout << sizeof(struct teststru) << endl << sizeof(ttu) << endl << "abcdef"[5] << endl;

    cout << atoi("a99") << endl << atoi("88kghi") << endl;
    uint8_t iiiiii = 0;

    printf("%d", 2);
    openssl_test();

    cout << (1UL << 2) << endl;

    return 0;
}
class c1 {
public:
    c1() {cout << "c1" << endl;}
    virtual ~c1() = default;
};
class c2 {
public:
    c2() {cout << "c2" << endl;}
    ~c2() {cout << "d2" << endl;}
};
class c3 : public c2,  public c1 {
public:
    c3() {cout << "c3" << endl;}
    ~c3() {cout << "d3" << endl;}
};

#endif //CPPTEST_TEST1_H
