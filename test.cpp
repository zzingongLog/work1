#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    Circle();
    Circle(int r);
    double getArea();
};
Circle::Circle() : Circle(1) {}
Circle::Circle(int r)
{
    radius = r;
    cout << "반지름 " << radius << "원 생성" << '\n';
}
double Circle::getArea()
{
    return 3.14 * radius * radius;
}
int main() 
{
    Circle donut;
    double area = donut.getArea();
    cout << "donut의 면적은 " << area << '\n';

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza의 면적은 " << area << '\n';
    return 0;
}