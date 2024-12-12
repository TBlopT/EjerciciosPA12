#include "complejo.h"
#include <cmath>

Complejo::Complejo(double r, double i) : real(r), imag(i) {}

double Complejo::getReal() const {
  return real;
}

double Complejo::getImag() const {
  return imag;
}

Complejo Complejo::operator+(const Complejo& otro) const {
  return Complejo(real + otro.real, imag + otro.imag);
}

Complejo Complejo::operator-(const Complejo& otro) const {
  return Complejo(real - otro.real, imag - otro.imag);
}

std::ostream& operator<<(std::ostream& os, const Complejo& c) {
  os << c.getReal() << (c.getImag() >= 0 ? " + " : " - ")
     << std::abs(c.getImag()) << "i";
  return os;
}

std::istream& operator>>(std::istream& is, Complejo& c) {
  double r, i;
  is >> r >> i;
  c = Complejo(r, i);
  return is;
}
