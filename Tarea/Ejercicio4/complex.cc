#include "complex.h"
#include <cmath>

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::getReal() const {
  return real;
}

double Complex::getImag() const {
  return imag;
}

Complex Complex::operator+(const Complex& otro) const {
  return Complex(real + otro.real, imag + otro.imag);
}

Complex Complex::operator-(const Complex& otro) const {
  return Complex(real - otro.real, imag - otro.imag);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << c.getReal() << (c.getImag() >= 0 ? " + " : " - ")
     << std::abs(c.getImag()) << "i";
  return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
  double r, i;
  is >> r >> i;
  c = Complex(r, i);
  return is;
}
