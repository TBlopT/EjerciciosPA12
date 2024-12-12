#include <iostream>

class Complex {
 public:
  Complex(double r = 0.0, double i = 0.0);
  double getReal() const;
  double getImag() const;
  Complex operator+(const Complex& otro) const;
  Complex operator-(const Complex& otro) const;
  friend std::ostream& operator<<(std::ostream& os, const Complex& c);
  friend std::istream& operator>>(std::istream& is, Complex& c);

 private:
  double real;
  double imag;
};

