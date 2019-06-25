#include "Matriz.h"
Matriz::Matriz()
{
}
Matriz::Matriz(int size, int **matriz, string nombre)
{
    this->size = size;
    this->nombre = nombre;
    this->matriz = matriz;
}
int Matriz::getDeterminante()
{
    return determinante;
}
int **Matriz::suma(int **matrizB)
{
    int **sumada = NULL;
    if (size == 2)
    {
        sumada = new int *[size];
        for (int k = 0; k < size; k++)
        {
            sumada[k] = new int[size];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                sumada[i][j] = matriz[i][j] + matrizB[i][j];
            }
        }
    }
    else
    {
        sumada = new int *[size];
        for (int k = 0; k < size; k++)
        {
            sumada[k] = new int[size];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                sumada[i][j] = matriz[i][j] + matrizB[i][j];
            }
        }
    }
    return sumada;
    for (int i = 0; i < size; i++)
    {
        delete [] sumada[i];
        sumada[i] = NULL;
    }
    delete [] matriz;
    matriz = NULL;
    
}
int **Matriz::incremento(int numero)
{
    int **incrementada = NULL;
    int diferencia = std::abs(determinante - size);
    if (size == 2)
    {
        incrementada = new int *[size];
        for (int k = 0; k < size; k++)
        {
            incrementada[k] = new int[size];
        }
        incrementada[0][0] = matriz[0][0] + diferencia;
        incrementada[0][1] = matriz[0][1] + diferencia;
        incrementada[1][0] = matriz[1][0] + diferencia;
        incrementada[1][1] = matriz[1][1] + diferencia;
    }
    else if (size == 3)
    {
        incrementada = new int *[size];
        incrementada[0][0] = matriz[0][0] + diferencia;
        incrementada[0][1] = matriz[0][1] + diferencia;
        incrementada[0][2] = matriz[0][2] + diferencia;
        incrementada[1][0] = matriz[1][0] + diferencia;
        incrementada[1][1] = matriz[1][1] + diferencia;
        incrementada[1][2] = matriz[1][2] + diferencia;
        incrementada[2][0] = matriz[2][0] + diferencia;
        incrementada[2][1] = matriz[2][1] + diferencia;
        incrementada[2][2] = matriz[2][2] + diferencia;
    }
    return incrementada;
    for (int i = 0; i < size; i++)
    {
        delete[] incrementada[i];
        incrementada[i] = NULL;
    }
    delete[] incrementada;
    incrementada = NULL;
}
int **Matriz::decremento(int numero)
{
    int **decrementada = NULL;
    int diferencia = std::abs(determinante - size);
    if (size == 2)
    {
        decrementada = new int *[size];
        for (int k = 0; k < size; k++)
        {
            decrementada[k] = new int[size];
        }
        for (int i = 0; i < size; i++)
        {

            for (int j = 0; j < size; j++)
            {
                decrementada[i][j] = matriz[0][1] + diferencia;
            }
        }
    }
    else if (size == 3)
    {
        decrementada = new int *[size];
        for (int k = 0; k < size; k++)
        {
            decrementada[k] = new int[size];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                decrementada[i][j] = matriz[0][1] - diferencia;
            }
        }
    }
    return decrementada;
    for (int i = 0; i < size; i++)
    {
        delete[] decrementada[i];
        decrementada[i] = NULL;
    }
    delete[] decrementada;
    decrementada = NULL;
}
int **Matriz::Multiplicacion(int escalar)
{
    int **escalada = NULL;
    if (size == 2)
    {
        escalada = new int *[size];
        for (int i = 0; i < size; i++)
        {
            escalada[i] = new int[size];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                escalada[i][j] = escalar * matriz[i][j];
            }
        }
    }
    else if (size == 3)
    {
        escalada = new int *[size];
        for (int i = 0; i < size; i++)
        {
            escalada[i] = new int[size];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                escalada[i][j] = escalar * matriz[i][j];
            }
        }
    }
    return escalada;
}
int **Matriz::productomatrices(int **matrizB)
{
    int **producto = NULL;
    if (size == 2)
    {
        producto = new int *[size];
        for (int i = 0; i < size; i++)
        {
            producto[i] = new int[size];
        }
        producto[0][0] = matriz[0][0] * matrizB[0][0] + matriz[0][1] * matrizB[1][0];
        producto[0][1] = matriz[0][0] * matrizB[0][1] + matriz[0][1] * matrizB[1][1];
        producto[1][0] = matriz[1][0] * matrizB[0][0] + matriz[1][1] * matrizB[1][0];
        producto[1][1] = matriz[1][0] * matrizB[0][1] + matriz[1][1] * matrizB[1][1];
    }
    else if (size == 3)
    {
        producto = new int *[size];
        for (int i = 0; i < size; i++)
        {
            producto[i] = new int[size];
        }
        producto[0][0] = (matriz[0][0] * matrizB[0][0]) + (matriz[0][1] * matrizB[1][0]) + (matriz[0][2] * matrizB[2][0]);
        producto[0][1] = (matriz[0][0] * matrizB[0][1]) + (matriz[0][1] * matrizB[1][1]) + (matriz[0][2] * matrizB[2][1]);
        producto[0][2] = (matriz[0][0] * matrizB[0][2]) + (matriz[0][1] * matrizB[1][2]) + (matriz[0][2] * matrizB[2][2]);

        producto[1][1] = (matriz[1][0] * matrizB[0][1]) + (matriz[1][1] * matrizB[1][1]) + (matriz[1][2] * matrizB[2][1]);
        producto[1][2] = (matriz[1][0] * matrizB[2][0]) + (matriz[1][1] * matrizB[2][1]) + (matriz[1][2] * matrizB[2][1]);
        producto[1][0] = (matriz[1][0] * matrizB[0][0]) + (matriz[1][1] * matrizB[0][1]) + (matriz[1][2] * matrizB[0][2]);

        producto[2][0] = (matriz[2][0] * matrizB[0][0]) + (matriz[2][1] * matrizB[0][1]) + (matriz[2][2] * matrizB[0][2]);
        producto[2][1] = (matriz[2][0] * matrizB[0][1]) + (matriz[2][1] * matrizB[1][1]) + (matriz[2][2] * matrizB[2][1]);
        producto[2][2] = (matriz[2][0] * matrizB[0][2]) + (matriz[2][1] * matrizB[1][2]) + (matriz[2][2] * matrizB[2][2]);
    }
}
int **Matriz::sumaespaciovect(int **matrizB)
{
    int **sumavect;
    if (size == 2)
    {
        sumavect = NULL;
        sumavect = new int *[size];
        for (int i = 0; i < size; i++)
        {
            sumavect[i] = new int[size];
        }
        sumavect[0][0] = 2 * (matriz[0][0] - matrizB[0][0]);
        sumavect[0][1] = (matriz[0][1] + matrizB[0][1]);
        sumavect[1][0] = (matriz[1][0] + matrizB[1][0]);
        sumavect[1][1] = 2 * (matriz[1][1] - matrizB[1][1]);
    }
    else if (size == 3)
    {
        sumavect = NULL;
        sumavect = new int *[size];
        for (int i = 0; i < size; i++)
        {
            sumavect[i] = new int[size];
        }
        sumavect[0][0] = 3 * (matriz[0][0] - matriz[0][0]);
        sumavect[0][1] = (matriz[0][1] + matriz[0][1]);
        sumavect[0][2] = (matriz[0][2] + matriz[0][2]);

        sumavect[1][0] = (matriz[1][0] + matrizB[1][0]);
        sumavect[1][1] = 3 * (matriz[1][1] - matrizB[1][1]);
        sumavect[1][2] = (matriz[1][2] - matrizB[1][2]);

        sumavect[2][0] = (matriz[2][0] + matrizB[2][0]);
        sumavect[2][1] = (matriz[2][1] + matrizB[2][1]);
        sumavect[2][2] = 3 * (matriz[2][2] - matrizB[2][2]);
    }
    return sumavect;

}
string Matriz::getNombre()
{
    return nombre;
}
int Matriz::getSize()
{
    return size;
}
void Matriz::setSize(int size)
{
    this->size = size;
}
void Matriz::Determinante()
{
    if (size == 2)
    {
        determinante = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    }
    else if (size == 3)
    {
        int result1 = matriz[0][0] * matriz[1][1] * matriz[2][2];
        int result2 = matriz[0][1] * matriz[1][2] * matriz[2][0];
        int result3 = matriz[0][2] * matriz[1][0] * matriz[2][1];
        int result4 = matriz[0][1] * matriz[1][0] * matriz[2][2];
        int result5 = matriz[0][0] * matriz[1][2] * matriz[2][1];
        int result6 = matriz[0][2] * matriz[1][1] * matriz[2][0];
        determinante = result1 + result2 + result3 - result4 - result5 - result6;
    }
}
int **Matriz::espaciovectoriamult(int escalar)
{
    int newescalar = 0;
    if (size == 2)
    {
        if (escalar == 0)
        {
            cout << "La entrada ingresada no puede ser 0" << endl;
        }
        else
        {
            newescalar = determinante / escalar;
            matriz[0][0] = newescalar * matriz[0][0];
            matriz[0][1] = newescalar * matriz[1][0];
            matriz[1][0] = newescalar * matriz[0][1];
            matriz[1][1] = newescalar * matriz[1][1];
        }
    }
    else if (size == 3)
    {
        if (escalar == 0)
        {
            cout << "La entrada ingresada no puede ser 0" << endl;
        }
        else
        {
            newescalar = determinante / escalar;
            matriz[0][0] = newescalar * matriz[0][0];
            matriz[0][1] = newescalar * matriz[1][0];
            matriz[0][2] = newescalar * matriz[2][0];
            matriz[1][0] = newescalar * matriz[0][1];
            matriz[1][1] = newescalar * matriz[1][1];
            matriz[1][2] = newescalar * matriz[2][1];
            matriz[2][0] = newescalar * matriz[0][2];
            matriz[2][1] = newescalar * matriz[1][2];
            matriz[2][2] = newescalar * matriz[2][2];
        }
    }
    return matriz;
}
string Matriz::toString()
{
    return nombre + std::to_string(size);
}
int** Matriz::getMatriz(){
    return matriz;
}
