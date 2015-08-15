#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    string id;
};
//因为虚继承，CBase类在此不产生副本
class CDerive1 : virtual public CBase {
public:
    void show1() {
        cout << "CDerive1: " << id << endl;
    }
};
//因为虚继承，CBase类在此不产生副本
class CDerive2 : virtual public CBase {
public:
    void show2() {
        cout << "CDerive2: " << id << endl;
    }
};
class CSon : public CDerive2, public CDerive1 { };
int main ( )
{
    CSon s;
    s.CDerive1::id = "111";
    s.CDerive2::id = "222";
    s.CBase::id = "000";
    s.show1();
    s.show2();
    cout << "BASE: " << s.CBase::id << endl;
    return 0;
}