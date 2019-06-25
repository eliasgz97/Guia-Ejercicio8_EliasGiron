#include <iostream>
#include <string>
#include "Matriz.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
void imprimirmatriz(int **matriz, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "[" << matriz[i][j] << "]";
        }
        cout << endl;
    }
}
int main()
{
    char resp = 's';
    int opcion = 0, size = 0;
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, opcion2, pos = 0, incrementar = 0;
    num1 = num1, num2 = num3 = num4 = num5 = num6 = num7 = num8 = num9 = 0;
    string nombre, entrada, operacion;
    int **matriz;
    int pos_eliminar = 0, pos_sumada = 0;
    vector<Matriz *> matrices;
    while (resp == 's' || resp == 'S')
    {
        cout << "1. Agregar Matrices" << endl
             << "2. Listar Matrices: " << endl
             << "3. Eliminar Matrices: " << endl
             << "4. Operar con matrices: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese el tamano de la matriz: ";
            cin >> size;
            while (size > 3 || size < 2)
            {
                cout << "Ingrese un tamano no mayor a 3: " << endl;
                cin >> size;
            }
            cout << "Ingrese nombre de la matriz: ";
            cin >> nombre;
            if (size == 2)
            {
                matriz = new int *[size];
                for (int i = 0; i < size; i++)
                {
                    matriz[i] = new int[size];
                }
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num1;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num2;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num3;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num4;
                matriz[0][0] = num1;
                matriz[0][1] = num2;
                matriz[1][0] = num3;
                matriz[1][1] = num4;
                matrices.push_back(new Matriz(size, matriz, nombre));
            }
            else
            {
                matriz = new int *[size];
                for (int i = 0; i < size; i++)
                {
                    matriz[i] = new int[size];
                }

                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num1;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num2;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num3;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num4;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num5;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num6;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num7;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num8;
                cout << "Ingrese numero que contendrá la matriz: ";
                cin >> num9;
                matriz[0][0] = num1;
                matriz[0][1] = num2;
                matriz[0][2] = num3;
                matriz[1][0] = num4;
                matriz[1][1] = num5;
                matriz[1][2] = num6;
                matriz[2][0] = num7;
                matriz[2][1] = num8;
                matriz[2][2] = num9;
                matrices.push_back(new Matriz(size, matriz, nombre));
            }

            break;
        case 2:
            for (int i = 0; i < matrices.size(); i++)
            {
                cout << i << ". "
                     << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
            }
            break;
        case 3:
            for (int i = 0; i < matrices.size(); i++)
            {
                cout << i << ". "
                     << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
            }
            cout << "Ingrese posicion de la matriz que desea eliminar: ";
            cin >> pos_eliminar;
            matrices.erase(matrices.begin() + pos_eliminar);
            break;
        case 4:
            cout << "1. Suma" << endl
                 << "2. Incremento" << endl
                 << "3. Decremento" << endl
                 << "4. Multiplicacion por un escalar: " << endl
                 << "5. Producto entre matrices: " << endl
                 << "6. Suma dentro del espacio vectorial: " << endl
                 << "7. Multiplicacion dentro del espacio vectorial: " << endl;
            cin >> opcion2;
            switch (opcion2)
            {
            case 1:
            {
                cout << "Elija una matriz: " << endl;
                for (int i = 0; i < matrices.size(); i++)
                {
                    cout << i << ". "
                         << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
                }
                cout << "Ingrese posicion de la matriz a sumar: ";
                cin >> pos;
                cout << "Ingrese posicion de la matriz sumada: ";
                cin >> pos_sumada;
                cout << "Ingrese operacion de suma: ";
                cin >> operacion;
                int **matrizB = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizB[i] = new int[size];
                }
                matrizB = matrices[pos]->getMatriz();
                int **matrizC = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizC[i] = new int[matrices[pos]->getSize()];
                }
                matrizC = matrices[pos_sumada]->suma(matrizB);
                imprimirmatriz(matrizC, matrices[pos]->getSize());
                break;
            }
            case 2:
            {
                for (int i = 0; i < matrices.size(); i++)
                {
                    cout << i << ". "
                         << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
                }
                cout << "Ingrese posicion de la matriz a incrementar: ";
                cin >> pos;
                cout << "Ingrese el numero con que incrementará: ";
                cin >> incrementar;
                int **matrizresult = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizresult[i] = new int[matrices[pos]->getSize()];
                }
                matrizresult = matrices[pos]->incremento(incrementar);
                imprimirmatriz(matrizresult, matrices[pos]->getSize());
                break;
            }
            case 3:
            {
                int decrementar = 0;
                for (int i = 0; i < matrices.size(); i++)
                {
                    cout << i << ". "
                         << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
                }
                cout << "Ingrese posicion de la matriz a decrementar: ";
                cin >> pos;
                cout << "Ingrese el numero con que decrementará: ";
                cin >> decrementar;
                int **matrizresult = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizresult[i] = new int[matrices[pos]->getSize()];
                }
                matrizresult = matrices[pos]->decremento(incrementar);
                imprimirmatriz(matrizresult, matrices[pos]->getSize());
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    delete[] matrizresult[i];
                    matrizresult[i] = NULL;
                }
                delete[] matrizresult;
                break;
            }
            case 4:
            {
                int escalar = 0;
                for (int i = 0; i < matrices.size(); i++)
                {
                    cout << i << ". "
                         << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
                }
                cout << "Ingrese posicion de la matriz a decrementar: ";
                cin >> pos;
                cout << "Ingrese escalar: ";
                cin >> escalar;
                int **matrizresult = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizresult[i] = new int[matrices[pos]->getSize()];
                }
                matrizresult = matrices[pos]->Multiplicacion(escalar);
                imprimirmatriz(matrizresult, matrices[pos]->getSize());
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    delete[] matrizresult[i];
                    matrizresult[i] = NULL;
                }
                delete[] matrizresult;
                break;
            }
            case 5:
            {
                int pos_multiplicar = 0;
                cout << "Elija una matriz: " << endl;
                for (int i = 0; i < matrices.size(); i++)
                {
                    cout << i << ". "
                         << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
                }
                cout << "Ingrese posicion de la matriz a multiplicar: ";
                cin >> pos;
                cout << "Ingrese posicion de la matriz multiplicante: ";
                cin >> pos_multiplicar;
                cout << "Ingrese operacion de suma: ";
                cin >> operacion;
                int **matrizB = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizB[i] = new int[size];
                }
                matrizB = matrices[pos]->getMatriz();
                int **matrizC = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizC[i] = new int[matrices[pos]->getSize()];
                }
                matrizC = matrices[pos_multiplicar]->productomatrices(matrizB);
                imprimirmatriz(matrizC, matrices[pos]->getSize());
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    delete[] matrizC[i];
                }
                delete[] matrizC;
                break;
            }
            case 6:
            {
                int pos_espaciovect = 0;
                cout << "Elija una matriz: " << endl;
                for (int i = 0; i < matrices.size(); i++)
                {
                    cout << i << ". "
                         << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
                }
                cout << "Ingrese posicion de la matriz 1: ";
                cin >> pos;
                cout << "Ingrese posicion de la matriz 2: ";
                cin >> pos_espaciovect;
                int **matrizB = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizB[i] = new int[size];
                }
                matrizB = matrices[pos]->getMatriz();
                int **matrizC = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizC[i] = new int[matrices[pos]->getSize()];
                }
                matrizC = matrices[pos_espaciovect]->sumaespaciovect(matrizB);
                imprimirmatriz(matrizC, matrices[pos]->getSize());
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    delete[] matrizC[i];
                }
                delete[] matrizC;
                break;
            }
            case 7:
            {
                int escalar;
                int pos_espaciovect = 0;
                cout << "Elija una matriz: " << endl;
                for (int i = 0; i < matrices.size(); i++)
                {
                    cout << i << ". "
                         << "Matriz: " << matrices[i]->getNombre() << ", de orden: " << matrices[i]->getSize() << endl;
                }
                cout << "Ingrese posicion de la matriz 1: ";
                cin >> pos;
                cout << "Ingrese un escalar: ";
                cin >> escalar;
                int **matrizB = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizB[i] = new int[size];
                }
                matrizB = matrices[pos]->getMatriz();
                int **matrizC = new int *[matrices[pos]->getSize()];
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    matrizC[i] = new int[matrices[pos]->getSize()];
                }
                matrizC = matrices[pos_espaciovect]->espaciovectoriamult(escalar);
                imprimirmatriz(matrizC, matrices[pos]->getSize());
                for (int i = 0; i < matrices[pos]->getSize(); i++)
                {
                    delete[] matrizC[i];
                }
                delete[] matrizC;
                break;
            }
            break;
        }
        cout << "Desea regresar[s/n]: ";
        cin >> resp;
    }

    return 0;
}