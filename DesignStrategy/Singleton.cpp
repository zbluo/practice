//
// Created by Zhong Bing on 2020-01-21.
//
#include <iostream>

class StringSingleton
{
public:
    // Some accessor functions for the class, itself
    std::string GetString() const
    {return mString;}
    void SetString(const std::string &newStr)
    {mString = newStr;}
    void SetInt()
    {mInt++;}

    // The magic function, which allows access to the class from anywhere
    // To get the value of the instance of the class, call:
    //     StringSingleton::Instance().GetString();
    static StringSingleton& Instance()
    {
        // This line only runs once, thus creating the only instance in existence
        static StringSingleton instance;
        // De-referencing the variable here, saves the caller from having to use
        // the arrow operator, and removes temptation to try and delete the
        // returned instance.
        return instance; // always returns the same instance
    }
    static int mInt;

private:

    // We need to make some given functions private to finish the definition of the singleton
    StringSingleton(){} // default constructor available only to members or friends of this class
    // Note that although this should be allowed,
    // some compilers may not implement private destructors
    // This prevents others from deleting our one single instance, which was otherwise created on the heap
    ~StringSingleton(){}
    // Note that the next two functions are not given bodies, thus any attempt
    // to call them implicitly will return as compiler errors. This prevents
    // accidental copying of the only instance of the class.
    StringSingleton(const StringSingleton &old) = delete; // disallow copy constructor
    StringSingleton& operator=(const StringSingleton &old) = delete; //disallow assignment operator

private: // private data for an instance of this class
    std::string mString;
};

int StringSingleton::mInt = 0;

int main(int argc, char *argv[]) {
    StringSingleton::Instance().SetString("Test\n");
    std::cout << StringSingleton::Instance().GetString();
    StringSingleton::Instance().SetInt();
}