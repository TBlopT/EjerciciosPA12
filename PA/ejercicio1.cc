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
#include <vector>

class Vehiculo {
 protected:
  std::string tipo_;
  bool alquilado_;

 public:
  Vehiculo(const std::string& tipo) : tipo_(tipo), alquilado_(false) {}
  virtual ~Vehiculo() = default;

  virtual double CalcularCosto() const = 0;
  virtual void MostrarInfo() const = 0;

  void Alquilar() { alquilado_ = true; }
  void Devolver() { alquilado_ = false; }
  bool EstaAlquilado() const { return alquilado_; }
  std::string ObtenerTipo() const { return tipo_; }
};

class Coche : public Vehiculo {
  double costo_diario_;
  int dias_;

 public:
  Coche(double costo_diario, int dias)
      : Vehiculo("Coche"), costo_diario_(costo_diario), dias_(dias) {}

  double CalcularCosto() const override { return costo_diario_ * dias_; }
  void MostrarInfo() const override {
    std::cout << "Coche - Costo Diario: " << costo_diario_
              << ", Dias: " << dias_ << "\n";
  }
};

class Motocicleta : public Vehiculo {
  double costo_hora_;
  int horas_;

 public:
  Motocicleta(double costo_hora, int horas)
      : Vehiculo("Motocicleta"), costo_hora_(costo_hora), horas_(horas) {}

  double CalcularCosto() const override { return costo_hora_ * horas_; }
  void MostrarInfo() const override {
    std::cout << "Motocicleta - Costo Hora: " << costo_hora_
              << ", Horas: " << horas_ << "\n";
  }
};

class Bicicleta : public Vehiculo {
  double costo_hora_;
  int horas_;

 public:
  Bicicleta(double costo_hora, int horas)
      : Vehiculo("Bicicleta"), costo_hora_(costo_hora), horas_(horas) {}

  double CalcularCosto() const override { return costo_hora_ * horas_; }
  void MostrarInfo() const override {
    std::cout << "Bicicleta - Costo Hora: " << costo_hora_
              << ", Horas: " << horas_ << "\n";
  }
};

class Caravana : public Vehiculo {
  double costo_semanal_;
  int semanas_;

 public:
  Caravana(double costo_semanal, int semanas)
      : Vehiculo("Caravana"), costo_semanal_(costo_semanal), semanas_(semanas) {}

  double CalcularCosto() const override { return costo_semanal_ * semanas_; }
  void MostrarInfo() const override {
    std::cout << "Caravana - Costo Semanal: " << costo_semanal_
              << ", Semanas: " << semanas_ << "\n";
  }
};

class Barco : public Vehiculo {
  double costo_semanal_;
  int semanas_;

 public:
  Barco(double costo_semanal, int semanas)
      : Vehiculo("Barco"), costo_semanal_(costo_semanal), semanas_(semanas) {}

  double CalcularCosto() const override { return costo_semanal_ * semanas_; }
  void MostrarInfo() const override {
    std::cout << "Barco - Costo Semanal: " << costo_semanal_
              << ", Semanas: " << semanas_ << "\n";
  }
};

class Usuario {
 protected:
  std::string nombre_;

 public:
  explicit Usuario(const std::string& nombre) : nombre_(nombre) {}
  virtual ~Usuario() = default;

  virtual void MostrarInfo() const = 0;
  std::string ObtenerNombre() const { return nombre_; }
};

class Cliente : public Usuario {
 public:
  explicit Cliente(const std::string& nombre) : Usuario(nombre) {}

  void MostrarInfo() const override {
    std::cout << "Cliente: " << nombre_ << "\n";
  }
};

class Administrador : public Usuario {
 public:
  explicit Administrador(const std::string& nombre) : Usuario(nombre) {}

  void MostrarInfo() const override {
    std::cout << "Administrador: " << nombre_ << "\n";
  }
};

class Operador : public Usuario {
 public:
  explicit Operador(const std::string& nombre) : Usuario(nombre) {}

  void MostrarInfo() const override {
    std::cout << "Operador: " << nombre_ << "\n";
  }
};

class AgenciaViaje : public Usuario {
 public:
  explicit AgenciaViaje(const std::string& nombre) : Usuario(nombre) {}

  void MostrarInfo() const override {
    std::cout << "Agencia de Viaje: " << nombre_ << "\n";
  }
};

int main() {
  std::vector<Vehiculo*> vehiculos;
  std::vector<Usuario*> usuarios;

  vehiculos.push_back(new Coche(50.0, 5));
  vehiculos.push_back(new Motocicleta(10.0, 3));
  vehiculos.push_back(new Bicicleta(5.0, 4));
  vehiculos.push_back(new Caravana(300.0, 2));
  vehiculos.push_back(new Barco(500.0, 1));

  usuarios.push_back(new Cliente("Juan Perez"));
  usuarios.push_back(new Administrador("Maria Lopez"));
  usuarios.push_back(new Operador("Carlos Ruiz"));
  usuarios.push_back(new AgenciaViaje("TravelNow"));

  double ingresos_esperados = 0.0;

  for (auto vehiculo : vehiculos) {
    if (!vehiculo->EstaAlquilado()) {
      vehiculo->Alquilar();
      ingresos_esperados += vehiculo->CalcularCosto();
    }
  }

  std::cout << "Ingresos Esperados: " << ingresos_esperados << "\n";
  std::cout << "Vehiculos Sin Alquilar:\n";

  for (auto vehiculo : vehiculos) {
    if (!vehiculo->EstaAlquilado()) {
      vehiculo->MostrarInfo();
    }
  }

  for (auto vehiculo : vehiculos) {
    delete vehiculo;
  }

  for (auto usuario : usuarios) {
    delete usuario;
  }

  return 0;
}
