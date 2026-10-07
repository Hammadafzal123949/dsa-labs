#include<iostream>
using namespace std;
class Employee {
public:
	virtual double calculatesalary() = 0;
};
class Fulltime : public Employee {
private:
	double fixsalary;
public:
	Fulltime(double f) {
		fixsalary = f;
	}
	double calculatesalary() override {
		return fixsalary;
	}
};
class Parttimeemployee : public Employee {
private:
	double hourswork;
	double hourlyrate;
public:
	Parttimeemployee(double w, double r) {
		hourswork = w;
		hourlyrate = r;
	}
	double calculatesalary() override {
		return hourswork * hourlyrate;
	}
};
int main() {
	Fulltime fulltime(50000);
	Parttimeemployee parttime(20, 500);
	cout << "Full time Employee salary : " << fulltime.calculatesalary() << endl;
	cout << "Half time Employee salary : " << parttime.calculatesalary() << endl;
	return 0;
}