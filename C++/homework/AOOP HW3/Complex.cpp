#include "Complex.h"
using namespace std ;
Complex::Complex(const double re , const double im ):real(re),imag(im)
{
}

Complex::Complex(const Complex &c):real(c.real),imag(c.imag)
{
}
Complex &Complex::operator=(const Complex &c)
{

}
Complex Complex::Polar(const double leng, const double arg)
{
}

double Complex::Real()
{
    return real ;
}
double Complex::Imag()
{
    return imag ;
}
double Complex::Norm()
{
    return pow(real , 2) + pow(imag , 2);
}
double Complex::Abs()
{
    return sqrt ( pow(real , 2) + pow(imag , 2) );
}
double Complex::Arg()
{
}

Complex &Complex::operator++()
{
}
Complex Complex::operator++(int)
{
}
Complex &Complex::operator--()
{
}
Complex Complex::operator--(int)
{
}

Complex::~Complex()
{
}

Complex Polar(const double leng, const double arg)
{
}
double Norm(const Complex &x)
{
    return pow(x.real , 2) + pow(x.imag , 2);
}
double Abs(const Complex &x)
{
    return sqrt ( pow(x.real , 2) + pow(x.imag , 2) );
}
double Arg(const Complex &x)
{
}
Complex operator+(const Complex &x, const Complex &y)
{
}
Complex operator-(const Complex &x, const Complex &y)
{
}
Complex operator*(const Complex &x, const Complex &y)
{
}
Complex operator/(const Complex &x, const Complex &y)
{
}
Complex operator+=(Complex &x, const Complex &y)
{
}
Complex operator-=(Complex &x, const Complex &y)
{
}
Complex operator*=(Complex &x, const Complex &y)
{
}
Complex operator/=(Complex &x, const Complex &y)
{
}
bool operator==(const Complex &x, const Complex &y)
{
}
bool operator!=(const Complex &x, const Complex &y)
{
}
ostream &operator<<(ostream &o, const Complex &x)
{
    o << "(" << x.real << ',' << x.imag << ')' ;
    return o ;
}
