#pragma once
#include <string>
#include <iostream>
#include "Triangle.hpp"
using namespace std;

class RightAngled : public Triangle
{
private:
    double area;
public:
    RightAngled();
    RightAngled(double);
    RightAngled(RightAngled&);
    RightAngled& operator = (const RightAngled&);
    
    operator string() const;
    friend ostream& operator << (ostream&, const RightAngled&);
    friend istream& operator >> (istream&, RightAngled&);
    
    friend void Read(RightAngled&);
    friend void Display(RightAngled&);
    bool Init(double, double, double);

    void set_area(double value) { area = value; };
    double get_area();
    void area_calculate();
};
