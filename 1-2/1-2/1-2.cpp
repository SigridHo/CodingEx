#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class complex
{
private:
	double real;
	double ima;
public:
	complex(double a, double b)
	{
		real = a;
		ima = b;
	}
	complex(double a)
	{
		real = a;
		ima = 0;
	}
	complex()
	{
		real = 0;
		ima = 0;
	}
	double get_real();
	double get_ima();
	complex change_real(double a);
	complex change_ima(double a);
	complex operator + (complex a);
	complex operator - (complex a);
	complex operator * (complex a);
	complex operator / (complex a);
	complex operator = (complex a);
	
};
double complex::get_real()
{
	return real;
}
double complex::get_ima()
{
	return ima;
}
complex complex::change_ima(double a)
{
	(*this).ima = a;
	return (*this);
}
complex complex::change_real(double a)
{
	(*this).real = a;
	return (*this);
}
complex complex::operator + (complex a)
{
	complex temp;
	temp.real = (*this).real + a.real;
	temp.ima = (*this).ima + a.ima;
	return temp;
}
complex complex::operator - (complex a)
{
	complex temp;
	temp.real = (*this).real - a.real;
	temp.ima = (*this).ima - a.ima;
	return temp;
}
complex complex::operator * (complex a)
{
	complex temp;
	temp.real = (*this).real * a.real - (*this).ima * a.ima;
	temp.ima = (*this).real * a.ima + (*this).ima * a.real;
	return temp;
}
complex complex::operator/ (complex a)
{
	complex temp;
	temp.real = ((*this).real * a.real + (*this).ima * a.ima) / (a.real * a.real + a.ima * a.ima);
	temp.ima = ((*this).ima * a.real - (*this).real * a.ima ) / (a.real * a.real + a.ima * a.ima);
	return temp;
}
complex complex::operator = (complex a)
{
	(*this).real = a.real;
	(*this).ima = a.ima;
	return *this;
}
ostream& operator<< (ostream& o, complex& a)
{
	o << a.get_real() << " + " << a.get_ima() << "i";
	return o;
}
int main()
{
	complex a;
	cout << a << endl;
	complex b(2.5);
	cout << b << endl;
	complex c(1.3, 3.0);
	cout << c << endl;
	cout <<c.get_ima() << ' ' << c.get_real() << endl;
	c.change_ima(1.3);
	c.change_real(3.2);
	cout << c << endl;
	b.change_ima(2);
	cout << b + c << endl;
	cout << b - c << endl;
	cout << b * c << endl;
	cout << b / c << endl;
	system("pause");
	return 0;
}