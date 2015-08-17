#include <iostream>
#include <string>
using namespace std;
int main ( )
{
    string strA("直接调用构造函数生成实例");  //直接调用构造函数生成实例
    cout << strA << "    " << strA.length() << endl;
    string strB;  //先调用构造函数生成空字符串实例
    strB = string("再调用构造函数生成无名实例，然后复制给strB实例，无名实例立即销毁");  //再调用构造函数生成无名实例，然后复制给strB实例，无名实例立即销毁
    cout << strB << "    " << strB.length() << endl;  //这和上面①的方法的结果相同
    string *strC;  //先定义一个指针，尚未分配空间
    //动态调用构造函数生成实例后，再将实例地址赋给指针变量
    strC = new string("动态调用构造函数生成实例后，再将实例地址赋给指针变量。千万不要忘记释放。");
    cout << *strC << "    " << strC->length() << endl;
    delete strC;              //千万不要忘记释放
    return 0;
}
// Question: 为什么上面两种不需要释放？