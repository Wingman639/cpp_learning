#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    void show() {
        cout << "BASE" << endl;
    }
};
class CDerive : public CBase {
public:
    void show() {
        cout << "DERIVE" << endl;
    }
};
int main ( )
{
    CDerive d;
    CBase& x = d;  //这里发生了一个类型转换， x 不再是 d 的类型了，而是 CBase
    d.show();
    x.show();
    return 0;
}