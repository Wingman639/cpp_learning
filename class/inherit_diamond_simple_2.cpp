#include <iostream>
#include <string>
using namespace std;
class CBase {
    string id;
public:
    void show() {
        cout <<  id << endl;
    }
};
class CDerive1 : public CBase { };
class CDerive2 : public CBase { };
class CSon : public CDerive2, public CDerive1 { };
int main ( )
{
    CSon s;
    cout <<  &s << endl;
    cout <<  "---------" << endl;
    CDerive1 *pd1 = &s;
    cout <<  pd1 << endl;
    CDerive2 *pd2 = &s;
    cout <<  pd2 << endl;
    cout <<  "---------" << endl;
    CBase *pb1 = pd1;
    cout <<  pb1 << endl;
    CBase *pb2 = pd2;
    cout <<  pb2 << endl;
    //CBase *pb = &s;    //编译有错
    return 0;
}