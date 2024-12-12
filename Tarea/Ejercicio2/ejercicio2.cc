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
#include <cmath>
using namespace std;
    enum Color {
        ROJO,
        AMARILLO,
        NARANJA,
        VERDE,
        AZUL,
    };
    Color Colores (const string& color){
      if (color == "ROJO") return ROJO;
      else if (color == "AMARILLO") return AMARILLO;
      else if (color == "NARANJA") return NARANJA;
      else if (color == "VERDE") return VERDE;
      else if (color == "AZUL") return AZUL;;
      return static_cast<Color>(-1);
    }
    string ColorAString(Color color) {
    switch (color) {
        case ROJO: return "Rojo";
        case AMARILLO: return "Amarillo";
        case NARANJA: return "Naranja";
        case VERDE: return "Verde";
        case AZUL: return "Azul";
        default: return "Desconocido";
    }
}
class Circulo {
    private:
    double circulo_centro_x;
    double circulo_centro_y;
    double circulo_radio;
    Color circulo_color;
    public:
      Circulo(double centro_x, double centro_y, double radio, Color c){
      circulo_centro_x = centro_x;
      circulo_centro_y = centro_y;
      circulo_radio = radio;
      circulo_color = c;
    }
    double Area (){
        double Area = (M_PI * pow(circulo_radio,2));
        return Area;
    }
    double Perimetro (){
        double Perimetro = (2*M_PI*circulo_radio);
        return Perimetro;
    }
    void Print() {
        cout << "Círculo: " << endl;
        cout << "  Centro: (" << circulo_centro_x << ", " << circulo_centro_y << ")" << endl;
        cout << "  Radio: " << circulo_radio << endl;
        cout << "  Color: " << ColorAString(circulo_color) << endl;
        cout << "  Área: " << Area() << endl;
        cout << "  Perímetro: " << Perimetro() << endl;
    }
    bool EsInterior(double x, double y){
        double distancia = sqrt(pow(x - circulo_centro_x, 2) + pow(y - circulo_centro_y, 2));
    return distancia <= circulo_radio;
    }
};
    int main (){
        cout << "Introduzca centro en x: ";
        double centrox_usuario, centroy_usuario, radio;
        cin >> centrox_usuario;
        cout << "Introduzca centro en y: ";
        cin >> centroy_usuario;
        cout << "Introduzca radio: ";
        cin >> radio;
        cout << "Introduzca color en mayúsculas: ";
        string color;
        cin >> color;
        Color color_enumerado;
        color_enumerado = Colores(color);
        if (color_enumerado==static_cast<Color>(-1)){
         cout << "Color no válido, prueba otro" << endl;
         return 1;
        }
        Circulo c(centrox_usuario,centroy_usuario,radio,color_enumerado);
        c.Print();
        cout << "Comprobaremos un punto en el eje, y le diré si se ubica dentro del círculo" << endl;
        cout << "Dime un punto en x ";
        int puntoen_x, puntoen_y;
        cin >> puntoen_x;
        cout << "Dime un punto en y";
        cin >> puntoen_y;
        if (c.EsInterior(puntoen_x,puntoen_y)){
            cout << "El punto que menciona SI se encuentra dentro del círculo" << endl;
        }
        else cout << "El punto que menciona NO se encuentra dentro del círculo" << endl;
        return 0;
    }
