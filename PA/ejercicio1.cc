/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2024-2025
 *
 * @author  Pablo Romero Armas alu0101743844@ull.edu.es
 * @date dic 12 2024
 * @brief 
 *
 *
 *
 * @bug There are no known bugs
 * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
 */

#include <iostream>
#include <string>
using namespace std;

class Usuarios {
 public:
  class UsuarioBasico {
   protected:
    string nombre;
    string id;

   public:
    UsuarioBasico(const string& nombre, const string& id) : nombre(nombre), id(id) {}
    virtual void MostrarPermisos() {
      cout << "Usuario básico: " << nombre << " - Permisos limitados." << endl;
    }
  };

  class Operador : public UsuarioBasico {
   public:
    Operador(const string& nombre, const string& id) : UsuarioBasico(nombre, id) {}
    void MostrarPermisos() override {
      cout << "Operador: " << nombre << " - Permisos para gestionar vehículos y usuarios." << endl;
    }
  };

  class Administrador : public UsuarioBasico {
   public:
    Administrador(const string& nombre, const string& id) : UsuarioBasico(nombre, id) {}
    void MostrarPermisos() override {
      cout << "Administrador: " << nombre << " - Permisos completos." << endl;
    }
  };
};

class Vehiculos {
 public:
  class Vehiculo {
   protected:
    string tipo;
    double precio_base;

   public:
    Vehiculo(const string& tipo, double precio_base) : tipo(tipo), precio_base(precio_base) {}
    virtual double CalcularPrecio(int unidad) = 0;
    virtual void MostrarInfo() { cout << "Tipo: " << tipo << ", Precio base: " << precio_base << endl; }
  };

  class Caravana : public Vehiculo {
   public:
    Caravana(double precio_base) : Vehiculo("Caravana", precio_base) {}
    double CalcularPrecio(int semanas) override { return precio_base * semanas; }
  };

  class Coche : public Vehiculo {
   public:
    Coche(double precio_base) : Vehiculo("Coche", precio_base) {}
    double CalcularPrecio(int dias) override { return precio_base * dias; }
  };

  class Motocicleta : public Vehiculo {
   public:
    Motocicleta(double precio_base) : Vehiculo("Motocicleta", precio_base) {}
    double CalcularPrecio(int dias) override { return precio_base * dias; }
  };

  class Bicicleta : public Vehiculo {
   public:
    Bicicleta(double precio_base) : Vehiculo("Bicicleta", precio_base) {}
    double CalcularPrecio(int horas) override { return precio_base * horas; }
  };
};

int main() {
  Usuarios::UsuarioBasico usuario1("Juan", "U001");
  Usuarios::Operador operador1("María", "O001");
  Usuarios::Administrador admin1("Carlos", "A001");

  usuario1.MostrarPermisos();
  operador1.MostrarPermisos();
  admin1.MostrarPermisos();

  Vehiculos::Caravana caravana(500);
  Vehiculos::Coche coche(50);
  Vehiculos::Motocicleta moto(30);
  Vehiculos::Bicicleta bici(5);

  cout << "Precio de alquilar la caravana 2 semanas: " << caravana.CalcularPrecio(2) << " euros" << endl;
  cout << "Precio de alquilar el coche 3 días: " << coche.CalcularPrecio(3) << " euros" << endl;
  cout << "Precio de alquilar la moto 5 días: " << moto.CalcularPrecio(5) << " euros" << endl;
  cout << "Precio de alquilar la bicicleta 4 horas: " << bici.CalcularPrecio(4) << " euros" << endl;
  return 0;
}
