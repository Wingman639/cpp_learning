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

class CDerive : public CBase {    //用“public”指定公有继承
public:
    void setBase(string s, int i) {
        setName(s);    //调用基类的保护成员
        setAge(i);     //调用基类的保护成员
        //调用基类的私有成员
        //cout << name << "   " << age << endl;    //编译出错
    }
};

int main ( )
{
    CDerive d;
    d.setBase("abc", 100);
   
    //调用基类的私有成员
    //cout << d.name << "   " << d.age << endl;    //编译出错

    //调用基类的公有成员
    cout << d.getName() << "   " << d.getAge() << endl;
   
    //调用基类的保护成员
    //d.setName("xyz");    //编译出错
    //d.setAge(20);        //编译出错

    return 0;
}