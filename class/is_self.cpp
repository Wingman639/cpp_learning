#include <iostream>
#include <string>
using namespace std;
class base {
public:
    void check(base *obj) {
        if (obj == this) {
            cout << "这是当前的对象"  << endl;
        } else {
            cout << "这不是同一个对象"  << endl;
        }
    }
};
class derive : public base {
public:
    base *getBase() {
        base *p = this;   //强制转换成父类的地址
        return p;          //返回父类地址
    }
};
int main ( )
{
    base ba;
    derive de;
    base *p1 = de.getBase();    //取基类地址
    base *p2 = &ba;
    ba.check(p1);
    ba.check(p2);
    return 0;
}