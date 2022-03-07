//
// Created by Zhong Bing on 2020-02-26.
//
#include <string>
#include <iostream>
#include <memory>
#include "ObjectPool.h"

using namespace std;

int main() {

    SharedPool<int> sp;
    sp.add(std::unique_ptr<int>(new int(4)));
    auto tmp = sp.acquire();
    throw std::overflow_error("Overflow error");
    //cout << *tmp << endl;
}

/*
 * https://stackoverflow.com/questions/27827923/c-object-pool-that-provides-items-as-smart-pointers-that-are-returned-to-pool
 * */
