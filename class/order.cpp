    #include <iostream>
    #include <string>
    using namespace std;
    class CBase {
        string name;
        int age;
    public:
        CBase() {
            cout << "BASE" << endl;
        }
        ~CBase() {
            cout << "~BASE" << endl;
        }
    };
    class CDerive : public CBase {
    public:
        CDerive() {
            cout << "DERIVE" << endl;
        }
        ~CDerive() {
            cout << "~DERIVE" << endl;
        }
    };
    int main ( )
    {
        CDerive d;
        return 0;
    }