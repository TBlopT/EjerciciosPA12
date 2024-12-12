/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2024-2025
 *
 * @author
 *  alu0101743844@ull.edu.es
 * @date 2024-12-06
 * @brief Descripción breve
 *
 * @bug There are no known bugs
 * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
 */

#include <iostream>

class Complejo {
 public:
  Complejo(double r = 0.0, double i = 0.0);
  double getReal() const;
  double getImag() const;
  Complejo operator+(const Complejo& otro) const;
  Complejo operator-(const Complejo& otro) const;
  friend std::ostream& operator<<(std::ostream& os, const Complejo& c);
  friend std::istream& operator>>(std::istream& is, Complejo& c);

 private:
  double real;
  double imag;
};


