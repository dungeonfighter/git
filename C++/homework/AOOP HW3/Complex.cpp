#include "Complex.h"
using namespace std;
Complex::Complex(const double re, const double im) : real(re), imag(im)
{
}

Complex::Complex(const Complex &c) : real(c.real), imag(c.imag)
{
}
Complex &Complex::operator=(const Complex &c)
{
    real = c.real;
    imag = c.imag;
    return *this ; 
}
Complex Complex::Polar(const double leng, const double arg)
{
    real = leng * cos(arg);
    imag = leng * sin(arg);
    return *this;
}

double Complex::Real()
{
    return real;
}
double Complex::Imag()
{
    return imag;
}
double Complex::Norm()
{
    return pow(real, 2) + pow(imag, 2);
}
double Complex::Abs()
{
    return sqrt(pow(real, 2) + pow(imag, 2));
}
double Complex::Arg()
{
    return acos(real / Abs());
}

Complex &Complex::operator++()
{
    real += 1;
    imag += 1;
    return *this;
}
Complex Complex::operator++(int)
{
    Complex temp(*this);
    ++(*this);
    return temp;
}
Complex &Complex::operator--()
{
    real -= 1;
    imag -= 1;
    return *this;
}
Complex Complex::operator--(int)
{
    Complex temp(*this);
    --(*this);
    return temp;
}

Complex::~Complex()
{
}

Complex Polar(const double leng, const double arg)
{
    return Complex(leng * cos(arg), leng * sin(arg));
}
double Norm(const Complex &x)
{
    return pow(x.real, 2) + pow(x.imag, 2);
}
double Abs(const Complex &x)
{
    return sqrt(pow(x.real, 2) + pow(x.imag, 2));
}
double Arg(const Complex &x)
{
    return acos(x.real / Abs(x));
}
Complex operator+(const Complex &x, const Complex &y)
{
    return Complex(x.real + y.real, x.imag + y.imag);
}
Complex operator+(int x, const Complex &y)
{
    return Complex(x + y.real, y.imag);
}
Complex operator-(const Complex &x, const Complex &y)
{
    return Complex(x.real - y.real, x.imag - y.imag);
}
Complex operator*(const Complex &x, const Complex &y)
{
    double r = x.real * y.real - x.imag * y.imag;
    double i = x.real * y.imag + x.imag * y.real;
    return Complex(r, i);
}
Complex operator/(const Complex &x, const Complex &y)
{
    double p = pow(y.real, 2) + pow(y.imag, 2); //分母
    double r = (x.real * y.real + x.imag * y.imag) / p;
    double i = (x.imag * y.real - x.real * y.imag) / p;
    return Complex(r, i);
}
Complex operator+=(Complex &x, const Complex &y)
{
    x = x + y;
    return x;
}
Complex operator-=(Complex &x, const Complex &y)
{
    x = x - y;
    return x;
}
Complex operator*=(Complex &x, const Complex &y)
{
    x = x * y;
    return x;
}
Complex operator/=(Complex &x, const Complex &y)
{
    x = x / y;
    return x;
}
bool operator==(const Complex &x, const Complex &y)
{
    return (x.real == y.real && x.imag == y.imag);
}
bool operator!=(const Complex &x, const Complex &y)
{
    return !(x.real == y.real && x.imag == y.imag);
}
ostream &operator<<(ostream &o, const Complex &x)
{
    o << "(" << x.real << ',' << x.imag << ')';
    return o;
}
