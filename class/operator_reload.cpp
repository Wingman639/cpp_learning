#include <iostream>
#include <string>
using namespace std;
class stuff {
    string name;
    int age;
public:
    stuff(string n, int a):name(n),age(a)
    {
        cout << name << "---" << age << endl;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    void operator +(int x);       //运算符重载的定义
    void operator +(string s);    //运算符重载的定义
};
void stuff::operator +(int x)       //运算符重载的实装
{
    age = age + x;
}
void stuff::operator +(string s)    //运算符重载的实装
{
    name = name + s;
}
int main ( )
{
    stuff st2("初始化的字符串", 3);
    st2 + 2;          //+运算
    st2 + ".第二阶段字符串";    //+运算
    cout << st2.getName() << st2.getAge() << endl;
    return 0;
}