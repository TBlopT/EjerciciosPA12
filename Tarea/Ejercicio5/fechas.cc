#include <iostream>
#include "fecha.h"

int main() {
  try {
    Fecha fecha1(29, 2, 2024);  // Fecha válida: 29 de febrero de 2024 (bisiesto)
    std::cout << "Fecha 1: " << fecha1 << std::endl;

    Fecha fecha2(31, 4, 2023);  // Fecha inválida: 31 de abril no es válida
    std::cout << "Fecha 2: " << fecha2 << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  Fecha fecha3(0, 0, 0);  // Fecha inválida
  std::cout << "Introduce una fecha (dd/mm/yyyy): ";
  std::cin >> fecha3;
  if (fecha3.esValida()) {
    std::cout << "Fecha introducida: " << fecha3 << std::endl;
  } else {
    std::cerr << "Fecha no válida." << std::endl;
  }

  return 0;
}
