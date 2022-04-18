#include "RightAngled.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

bool Init(double a1, double b1, double c1)
{
    double d1 = a1;
    double d2 = b1;
    double d3 = c1;

    if(b1 > d1)
    {
        d1 = b1;
        d2 = a1;
    }
    if(c1 > d1)
    {
        d1 = c1;
        d2 = a1;
        d3 = b1;
    }

    if ((d1*d1) == (d2*d2 + d3*d3))
    {
        return true;
    }
    else
    {
        cout << "Sides don't make right angled triangle!" << endl;
        return false;
    }
}

RightAngled::RightAngled() {
    area = 0;
}

RightAngled::RightAngled(double f) {
    area = f;
}

RightAngled::RightAngled(RightAngled& f) {
    set_a(f.get_a());
    set_b(f.get_b());
    set_c(f.get_c());
    area = f.area;
}

RightAngled& RightAngled::operator = (const RightAngled& f) {
    set_a(f.get_a());
    set_b(f.get_b());
    set_c(f.get_c());
    area = f.area;
    return *this;
}

istream& operator >> (istream& in, RightAngled& f)
{
    double a, b, c;
    do
    {
        cout << "Set the sides:" << endl;
        cout << " a = "; in >> a;
        cout << " b = "; in >> b;
        cout << " c = "; in >> c;
        while((a >= b + c) ||
              (b >= a + c) ||
              (c >= b + a))
        {
            cout << "Wrong arguments to init!" << endl;
            cout << " a = "; in >> a;
            cout << " b = "; in >> b;
            cout << " c = "; in >> c;
        }
        f.set_a(a);
        f.set_b(b);
        f.set_c(c);
        f.area_calculate();
    }while(!Init(a, b, c));
    return in;
}

ostream& operator << (ostream& out, const RightAngled& a)
{
    out << string(a);
    return out;
}

RightAngled::operator string () const
{
    stringstream f;
    f << "Your triangle: "
      <<  "[" << get_a() << "] "
      <<  "[" << get_b() << "] "
      <<  "[" << get_c() << "] " << endl;
    return f.str();
}

void RightAngled::area_calculate()
{
    double p = perimeter() / 2;
    double s1 = get_a();
    double s2 = get_b();
    double s3 = get_c();
    double s = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    set_area(s);
}

double RightAngled::get_area()
{
    return area;
}

void Read(RightAngled& f)
{
    cin >> f;
}

void Display(RightAngled& f)
{
    cout << "Angles: " <<
    f.angleAlfa() << "°, " <<
    f.angleBeta() << "°, " <<
    f.angleGama() << "°" << endl;
    cout << "Perimeter: " << f.perimeter() << endl;
    cout << "Area: " << f.get_area() << endl;
}
