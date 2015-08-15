#include <iostream>
using namespace std;
class area {
    double dim1, dim2;
public:
    //设置数据
    void setData(double d1, double d2) {
        dim1 = d1, dim2 = d2;
    }
    //取数据
    void getData(double& d1, double& d2) {
        d1 = dim1, d2 = dim2;
    }
    //求面积
    virtual double getArea() = 0;    //纯虚函数
};
//长方形
class rectangle : public area {
public:
    double getArea() {
        double d1, d2;
        getData(d1, d2);
        return d1 * d2 ;
    }
};
//三角形
class triangle : public area {
public:
    double getArea() {
        double d1, d2;
        getData(d1, d2);
        return d1 * d2 / 2 ;
    }
};
int main ( )
{
    area *p;
    rectangle r;    //长方形类的实例
    triangle t;     //三角形类的实例
    r.setData(2, 3);
    t.setData(3, 2);
    p = &r;
    cout << "长方形的面积为： " << p->getArea() << endl;
    p = &t;
    cout << "三角形的面积为： " << p->getArea() << endl;
    return 0;
}