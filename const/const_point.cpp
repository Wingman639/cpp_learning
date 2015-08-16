#include <iostream>
using namespace std;
int main ( )
{
    int x = 12;
    int y = 25;
    char c = 'D';
    const int * p1;
    //新分配一块int型空间，再将p1指向新空间作为常量，OK！
    p1 = new int(100);
    cout << "p1: " << *p1 << endl;
    delete p1;
    //将p1指向非int型变量作为常量，NG！
    //p1 = &c;    //类型不匹配
    //将p1指向int型变量作为常量，OK！
    p1 = &x;
    cout << "p1: " << *p1 << endl;
    //修改p1的地址，OK！
    p1 = &y;        //地址可以被修改
    cout << "p1: " << *p1 << endl;
    //修改p1指针的值，NG！
    //*p1 = 156;    //指针值不能被修改
    //通过其它变量，间接地修改p1指针的值，OK！
    y = 158;
    cout << "p1: " << *p1 << endl;


    //int * const p3;    //编译出错，初始化必须赋值
    int * const p3 = &x;    //其地址作为常量并指针限制为int类型。变量的地址不可以改变，但内容可以改变。
    //新分配一块int型空间，再将p3指向新空间作为常量，NG！
    //p3 = new int(100);
    //修改p3的地址，NG！
    //p3 = &y;      //地址不能被修改
    //修改p3指针的值，OK！
    *p3 = 156;      //指针值可以被修改
    cout << "p3: " << *p3 << endl;


    //const int * const p4;    //编译出错，初始化必须赋值
    const int * const p4 = &x;  //既不允许修改地址，也不允许修改内容。
    //修改p4的地址，NG！
    //p4 = &y;      //地址不能被修改
    //修改p4指针的值，NG！
    //*p4 = 156;    //指针值不能被修改
    cout << "p4: " << *p4 << endl;
    //通过其它变量，间接地修改p4指针的值，OK！
    x = 123;
    cout << "p4: " << *p4 << endl;

    return 0;
}