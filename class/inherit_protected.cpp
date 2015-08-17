#include <iostream>
#include <string>
using namespace std;

class CBase {
    string name;
    int age;
public:
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
protected:
    void setName(string s) {
        name = s;
    }
    void setAge(int i) {
        age = i;
    }
};

class CDerive : protected CBase {    //用“private”指定私有继承
public:
    void setBase(string s, int i) {
        setName(s);    //调用基类的保护成员
        setAge(i);     //调用基类的保护成员
        //调用基类的私有成员
        //cout << name << "   " << age << endl;    //编译出错
    }
    string getBaseName() {
        return getName();    //调用基类的公有成员
    }
    int getBaseAge() {
        return getAge();     //调用基类的公有成员
    }
};

int main ( )
{
    CDerive d;
    d.setBase("abc", 100);
   
    //调用基类的私有成员
    //cout << d.name << "   " << d.age << endl;    //编译出错

    //调用基类的公有成员
    //cout << d.getName() << "   " << d.getAge() << endl;    //编译出错
    cout << d.getBaseName() << "   " << d.getBaseAge() << endl;
   
    //调用基类的保护成员
    //d.setName("xyz");    //编译出错
    //d.setAge(20);        //编译出错

    return 0;
}