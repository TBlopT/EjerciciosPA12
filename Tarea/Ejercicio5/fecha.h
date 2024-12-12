
#include <iostream>
#include <stdexcept>

class Fecha {
 public:
  Fecha(int d, int m, int a);
  int getDia() const;
  int getMes() const;
  int getAnio() const;
  bool esBisiesto() const;
  bool esValida() const;

  friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha);
  friend std::istream& operator>>(std::istream& is, Fecha& fecha);

 private:
  int dia;
  int mes;
  int anio;

  bool esFechaValida() const;
  int diasEnMes(int mes, int anio) const;
};

