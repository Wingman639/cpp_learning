#include <iostream>
#include <string>
using namespace std;
class ca {
    string id;
public:
    ca(string id) {
        this->id = id;
    }
    void setId(string id) {
        this->id = id;
    }
    void print() {
        cout << "id: " << id << endl;
    }
};
int main ( )
{
    ca a("abc");
    a.print();
    a.setId("xyz");
    a.print();
    return 0;
}   