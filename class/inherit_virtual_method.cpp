#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    virtual void show() {
        cout << "BASE SHOW" << endl;
    }
    virtual void print() {
        cout << "BASE PRINT" << endl;
    }
};
class CDerive : public CBase {
public:
    void show() {
        cout << "DERIVE SHOW" << endl;
    }
};
int main ( )
{
    CDerive d;
    CBase& x = d;
    d.show(),  x.show();    //虚函数只影响派生类的实装
    d.print(), x.print();
    CBase b;
    b.show(),  b.print();   //虚函数不影响基类自身的实例
    return 0;
}