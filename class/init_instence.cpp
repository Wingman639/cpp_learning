#include <iostream>
#include <string>
using namespace std;
class stuff {
    string name;
    int age;
public:
    stuff() {        //这是写法一
        cout << name << "---" << age << endl;  //赋值前可能会为未初始化值
        name = "赋值前可能会为空";
        age = 0;
        cout << name << "---" << age << endl;
    }
    stuff(string n, int a):name(n),age(a)     //这是写法二, 在成员变量分配空间的同时将参数的值赋给成员变量。
    {
        cout << name << "---" << age << endl;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
};
int main ( )
{
    stuff st2;
    stuff st1("构造的同时初始化，避免半初始化状态", 3);
    return 0;
}