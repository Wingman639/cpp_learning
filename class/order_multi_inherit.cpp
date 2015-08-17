    #include <iostream>
    #include <string>
    using namespace std;
    class CBase1 {
        string name;
    public:
        CBase1(string s) : name(s) {
            cout << "BASE1: " << name << endl;
        }
        ~CBase1() {
            cout << "~BASE1" << endl;
        }
    };
    class CBase2 {
        int age;
    public:
        CBase2(int a) : age(a) {
            cout << "BASE2: " << age << endl;
        }
        ~CBase2() {
            cout << "~BASE2" << endl;
        }
    };
    class CDerive : public CBase1, public CBase2 {
        string id;
    public:
        CDerive(string s1, int a, string s2) : CBase1(s1), CBase2(a), id(s2) {
            cout << "DERIVE: " << id << endl;
        }
        ~CDerive() {
            cout << "~DERIVE" << endl;
        }
    };
    int main ( )
    {
        CDerive d("小雅", 27, "8503026");
        return 0;
    }