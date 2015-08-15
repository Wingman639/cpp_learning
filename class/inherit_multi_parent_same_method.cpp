#include <iostream>
#include <string>
using namespace std;
class CBase1 {
public:
    string name;
protected:
    string id;
public:
    CBase1(string s1, string s2) : name(s1), id("base1-"+s2) { }
    void show() {
        cout << "A.name: " << name << endl;
        cout << "A.id: " << id << endl;
    }
};
class CBase2 {
public:
    int salary;
protected:
    string id;
public:
    CBase2(int y, string s2) : salary(y), id("base2-"+s2) { }
    void show() {
        cout << "B.salary: " << salary << endl;
        cout << "B.id: " << id << endl;
    }
};
class CDerive : public CBase1, public CBase2 {
    string id;
    int age;
public:
    CDerive(string s1, int a, string s2, int y)
        : age(a), id("DERIVE-"+s2), CBase1(s1, s2), CBase2(y, s2) { }
    void show() {
        cout << "Child.id: " << id << endl;
        cout << "Child.age: " << age << endl;
        cout << "Child.name: " << name << endl;
        cout << "Child.salary: " << salary << endl;
        CBase1::show();
        CBase2::show();
        cout << "bas1: " << CBase1::id << endl;  //调用CBase1的成员变量
        cout << "bas2: " << CBase2::id << endl;  //调用CBase2的成员变量
    }
};
int main ( )
{
    CDerive d("子类实例", 3, "111", 5000);
    d.show();
    return 0;
}