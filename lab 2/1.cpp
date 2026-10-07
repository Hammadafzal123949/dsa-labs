#include<iostream>
using namespace std;
class shape {
public:
	virtual double area() = 0;
};
class circle : public shape {
private:
	double radius;
public:
	circle(double r) {
		radius = r;
	}
	double area()override {
		return 3.14 * radius * radius;
	}
};
class rectangle : public shape {
private:
	double length;
	double width;
public:
	rectangle(double l, double w) {
		length = l;
		width = w;
	}
	double area()override {
		return length * width;
	}
};
int main() {
	circle circle(5);
	rectangle rectangle(5, 10);
	cout << "area of circle : " << circle.area() << endl;
	cout << "area of rectangle : " << rectangle.area() << endl;
	return 0;
}