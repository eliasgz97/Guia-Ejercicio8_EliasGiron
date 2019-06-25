#ifndef Matriz_H
#define Matriz_h
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Matriz{
    private:
        int size;
        int determinante;
        string nombre;
        int** matriz;
    public:
        int getSize();
        void setSize(int);

        int** getMatriz();
        void setMatriz(int** matrizA);

        int getDeterminante();
        void Determinante();
        
        string getNombre();
        void setNombre(string);

        int** suma(int**);
        int** incremento(int);
        int** decremento(int);
        int** Multiplicacion(int);
        int** productomatrices(int**);
        int** espaciovectoriamult(int);
        int** sumaespaciovect(int**);
        Matriz();
        Matriz(int, int**, string);
        string toString();
        void destructor();
};
#endif
