#pragma once
#include <cmath>

class  Hello {
private:
    double m_d;
public:
    double & myDouble() { return m_d; }
    double mySqrt() { return sqrt(m_d); }
};
