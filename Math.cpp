#include <iostream>
#include <stdio.h>

class ComplexNumber
{
private:
    /* data */
public:
    double re, im;
    ComplexNumber(/* args */);

    void Set(double _re, double _im) 
    {
        re = _re;
        im = _im;
    }

    void operator+=(const ComplexNumber& cn)
    {
        re += cn.re;
        im += cn.im;
    }

    void operator-=(const ComplexNumber& cn)
    {
        re -= cn.re;
        im -= cn.re;
    }

    void operator*=(const double d)
    {
        re *= d;
        im *= d;
    }

    bool operator==(const ComplexNumber other)
    {
        if (re == other.re && im == other.im)
        {
            return true;
        }
        return false;
    }

    ComplexNumber& operator=(ComplexNumber& other)
    {
        std::swap(re, other.re);
        std::swap(im, other.im);
        return *this;
    }

    ~ComplexNumber();
};

ComplexNumber::ComplexNumber(/* args */)
{
    re = 0.0f;
    im = 0.0f;
}

ComplexNumber::~ComplexNumber()
{
}

inline ComplexNumber operator+(ComplexNumber& a, ComplexNumber& b)
{
    ComplexNumber c;
    c.im = a.im + b.im;
    c.re = a.re + b.re;

    return c;
}

inline ComplexNumber operator-(ComplexNumber& a, ComplexNumber& b)
{
    ComplexNumber c;
    c.im = a.im - b.im;
    c.re = a.re - b.re;

    return c;
}

inline ComplexNumber operator*(ComplexNumber& a, ComplexNumber& b)
{
    ComplexNumber c;
    c.re = a.re * b.re - a.im * b.im;
    c.im = a.re * b.im + a.im * b.re;

    return c;
}

inline ComplexNumber operator/(ComplexNumber& a, ComplexNumber& b)
{
    double base = a.im * a.im + b.im * b.im;
    ComplexNumber c;
    c.re = (a.re * b.re + a.im * b.im) / base;
    c.im = (- a.re * b.im + a.im * b.re) / base;

    return c;
}