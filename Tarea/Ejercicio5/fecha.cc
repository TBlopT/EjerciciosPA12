#include "fecha.h"

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
  if (!esFechaValida()) {
    throw std::invalid_argument("Fecha no válida");
  }
}

int Fecha::getDia() const {
  return dia;
}

int Fecha::getMes() const {
  return mes;
}

int Fecha::getAnio() const {
  return anio;
}

bool Fecha::esBisiesto() const {
  return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

bool Fecha::esValida() const {
  return esFechaValida();
}

bool Fecha::esFechaValida() const {
  if (mes < 1 || mes > 12) return false;
  return dia >= 1 && dia <= diasEnMes(mes, anio);
}

int Fecha::diasEnMes(int mes, int anio) const {
  switch (mes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      return 31;
    case 4: case 6: case 9: case 11:
      return 30;
    case 2:
      return esBisiesto() ? 29 : 28;
    default:
      return 0;
  }
}

std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
  os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio();
  return os;
}

std::istream& operator>>(std::istream& is, Fecha& fecha) {
  int d, m, a;
  char slash1, slash2;
  is >> d >> slash1 >> m >> slash2 >> a;
  if (slash1 == '/' && slash2 == '/' && is) {
    fecha = Fecha(d, m, a);
  }
  return is;
}
