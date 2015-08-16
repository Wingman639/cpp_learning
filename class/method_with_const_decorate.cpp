#include <iostream>
using namespace std;
class classA {
    int x;
    string y;
public:
    mutable string z;
    void get(int& i, string& s) const {
        int k;
        k = 10;       //非成员变量可以修改
        //x = k;      //成员变量不能修改
        //y = "小雅"; //成员变量不能修改
        i = x, s = y;
        z = "可以修改";
    }
    void set(int i, string s) { x = i; y = s; }
};
int main ( )
{
    classA ca;
    ca.set(100, "AAA");
    int i;
    string s;
    ca.get(i, s);
    cout << s << ", " << i << ", " << ca.z << endl;
    return 0;
}