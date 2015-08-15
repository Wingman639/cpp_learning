#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    virtual void show() = 0;    //这是“纯虚函数”
    virtual void print() {      //这是普通的“虚函数”
        cout << "BASE PRINT" << endl;
    }
};
class CDerive : public CBase {
public:
    void show() {      //在派生类中，对“纯虚函数”必须实装
        cout << "DERIVE SHOW" << endl;
    }
};
int main ( )
{
    CDerive d;
    CBase& x = d;
    d.show(),  x.show();
    d.print(), x.print();
    //CBase b;     //抽象类不能实例化
    //b.show(),  b.show();
    return 0;
}