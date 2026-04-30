#include "Fraction.h"
#include <iostream>
#include <cmath>

Fraction::Fraction(int numerator, int denominator)
    : m_numerator(numerator), m_denominator(denominator){
        reduce();
}

Fraction::Fraction(double val){
    m_denominator = 1;
    while(fabs(val - static_cast<int>(val)) > 1e-12)
    {
        m_denominator *= 10;
    }
    m_numerator = static_cast<int>(val);

    reduce();
}

int gcd(int m, int n)
{
    return (n==0 ? abs(m) : gcd(n, m%n));
}
void Fraction::reduce()
{
    int common = gcd(m_numerator, m_denominator);
    
    if (common)
    {
        m_numerator /= common;
        m_denominator /= common;
    }
}

Fraction Fraction::operator+(Fraction f2)
{
    return Fraction(m_numerator*f2.m_denominator+m_denominator*f2.m_numerator,
    m_denominator*f2.m_denominator);
}
/*
Fraction operator+(Fraction f1, Fraction f2)
{
    return Fraction(f1.m_numerator*f2.m_denominator+f1.m_denominator*f2.m_numerator,
    f1.m_denominator*f2.m_denominator);
}
*/

std::ostream& operator<<(std::ostream& os, Fraction f)
{
    os << f.m_numerator << "/" << f.m_denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f)
{
    is >> f.m_numerator >> f.m_denominator;
    f.reduce();
    
    return is;
}

int main()
{
    Fraction    f1(1,2);
    Fraction    f2(1, 3);
    Fraction    f3 = f1 + f2;//operator+(f1, f2)
    Fraction    f5 = f1.operator+(f2);
    Fraction    f6 = f1 + 1;    //f6 = f1 + Fraction(1)
    Fraction    f7 = f1 + 0.5;  //f7 = f1 + Fraction(0.5)
    std::cin >> f1 >> f2;   //operator>>(std::cin, f1) >> f2
    // operator>>(std::cin, f1) ---> std::cin
    // operator>>( operator>>(std::cin, f1), f2)
    std::cout << f1+f2 << std::endl;

    return 0;
}


using namespace std;
class Complex{
public:
    Complex(double r=0.0, double i=0.0) : real(r),imag (i){}
    Complex operator+(const Complex &c2)const;
    void display() const;
private:
    double real, imag;
};
Complex Complex::operator+(const Complex &c2)const{
    return Complex(real+c2.real, imag+c2.imag);
}
void Complex::display() const {cout<< "("<< real<< "," << imag << ")"<<endl;}
int main(){
    Complex c1(5, 4), c2(2, 10), c3;
    c3 = c1 + c2;
    c3.display();
    return 0;
}
