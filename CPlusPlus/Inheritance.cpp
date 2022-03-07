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

int main() {
    c1* o3 = new c3();
    delete o3;
}
/*************************************************/
Output:
c2
c1
c3
d3
d2
