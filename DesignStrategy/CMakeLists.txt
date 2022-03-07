cmake_minimum_required(VERSION 3.14)
project(DesignStrategy)

set(CMAKE_CXX_STANDARD 20)

add_executable(DesignStrategy
        # Strategy.cpp
        # Singleton.cpp
        # Builder.cpp AbstractFactory.cpp Adaptor.cpp Bridge.cpp Decorator.cpp Command.cpp
        # Observer.cpp
        # ObjectPool.cpp ObjectPool.h
        # JumpTable.cpp
        ThreadPool.cpp)