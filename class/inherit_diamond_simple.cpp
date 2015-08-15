#include <iostream>
#include <string>
using namespace std;
class CBase {
public:
    string id;
};
class CDerive1 : public CBase {
public:
    void show1() {
        cout << "CDerive1: " << id << endl;
    }
};
class CDerive2 : public CBase {
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

// Different compiler gives different result.

/* Mac OS clang:
class 'CSon' to base class 'CBase':
    class CSon -> class CDerive2 -> class CBase
    class CSon -> class CDerive1 -> class CBase
    s.CBase::id = "000";
    ^

    class CSon -> class CDerive2 -> class CBase
    class CSon -> class CDerive1 -> class CBase
    cout << "BASE: " << s.CBase::id << endl;
                        ^
2 errors generated.
*/
