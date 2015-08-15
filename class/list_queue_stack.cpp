// This is a bad example in both design and name.

#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;
class list {
public:
    list *head;    //头指针
    list *tail;    //尾指针
    list *next;    //下一个指针
    int num;       //当前节点的值
    list() { head = tail = next = NULL; }    //构造函数
    virtual void store(int i) = 0;           //增加节点
    virtual int retrive() = 0;               //删除节点
};
//队列
class queue : public list {
public:
    //增加节点
    virtual void store(int i) {
        list *item = new queue;
        if (!item) {
            cout << "内存分配失败！" << endl;
            exit(1);
        }
        item->num = i;
        //链表末尾插入
        if (tail) tail->next = item;
        tail = item;
        item->next = NULL;
        if (!head) head = tail;
    }
    //取值并删除节点
    int retrive() {
        int i;
        list *p;
        if (!head) {
            cout << "链表已经为空" << endl;
            return 0;
        }
        //从链表头部删除
        i = head->num;
        p = head;
        head = head->next;
        delete p;
        return i;
    }
};
//堆栈
class stack : public list {
public:
    //增加节点
    virtual void store(int i) {
        list *item = new stack;
        if (!item) {
            cout << "内存分配失败！" << endl;
            exit(1);
        }
        item->num = i;
        //链表头部插入
        if (head) item->next = head;
        head = item;
        if (!tail) tail = head;
    }
    //取值并删除节点
    int retrive() {
        int i;
        list *p;
        if (!head) {
            cout << "链表已经为空" << endl;
            return 0;
        }
        //从链表头部删除
        i = head->num;
        p = head;
        head = head->next;
        delete p;
        return i;
    }
};
int main ( )
{
    list *p;
    //队列的演示
    queue q;
    p = &q;
    p->store(111), p->store(222), p->store(333);
    cout << "队列：  ";
    cout << p->retrive() << "  ";
    cout << p->retrive() << "  ";
    cout << p->retrive() << endl;
    //堆栈的演示
    stack s;
    p = &s;
    p->store(111), p->store(222), p->store(333);
    cout << "堆栈：  ";
    cout << p->retrive() << "  ";
    cout << p->retrive() << "  ";
    cout << p->retrive() << endl;
    return 0;
}