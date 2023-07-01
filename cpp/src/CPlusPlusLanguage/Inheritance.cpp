#include <iostream>

class A
{
    public:
       int x;
    protected:
       int y;
    private:
       int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};


/*************************************************/
class c1 {
public:
    c1() {std::cout << "c1" << std::endl;}
    virtual ~c1() = default;
};
class c2 {
public:
    c2() {std::cout << "c2" << std::endl;}
    ~c2() {std::cout << "d2" << std::endl;}
};
class c3 : public c2,  public c1 {
public:
    c3() {std::cout << "c3" << std::endl;}
    ~c3() {std::cout << "d3" << std::endl;}
};

int test() {
    c1* o3 = new c3();
    delete o3;
}
/*************************************************
Output:
c2
c1
c3
d3
d2
*************************************************/