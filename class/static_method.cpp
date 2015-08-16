#include <iostream>
using namespace std;
class Integer {
public:
    static int atoi(const char *s) {
        return ::atoi(s);
    }
    static float atof(const char *s) {
        return ::atof(s);
    }
};
int main ( )
{
    int x = Integer::atoi("322");
    float y = Integer::atof("3.14");
    cout << "x = " << x << "  y = " << y << endl;
    return 0;
}