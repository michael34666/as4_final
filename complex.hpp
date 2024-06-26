//Michael_dadush12@gmail.com
#include <iostream>
#include <cmath>
#pragma once
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) 
    {}

    // Getters
    double getReal() const 
    {
      return real; 
    }
    double getImag() const 
    { 
      return imag; 
    }

    // Setters
    void setReal(double r) 
    { 
        real = r; 
    }
    void setImag(double i) 
    {
         imag = i; 
    }


    // Overload the << operator to print complex numbers
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) 
    {   if(c.real!=0)
        {

         os << c.real;
        }

       
        if (c.imag > 0) {
            os << "+" << c.imag << "i";
        } 
        
        else {
            os << "-" << -c.imag << "i";
        }
        return os;
    }
   //for heap
    friend bool operator<(const Complex& lhs, const Complex& rhs) 
    {
        double mag1 = std::sqrt(lhs.real * lhs.real + lhs.imag * lhs.imag);
        double mag2 = std::sqrt(rhs.real * rhs.real + rhs.imag * rhs.imag);
        return mag1 < mag2;
    }
};