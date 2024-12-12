#include <iostream>
#include "complejo.h"

int main() {
  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado;

  resultado = complejo1 + complejo2;
  std::cout << resultado << std::endl;

  resultado = complejo1 - complejo2;
  std::cout << resultado << std::endl;

  return 0;
}
