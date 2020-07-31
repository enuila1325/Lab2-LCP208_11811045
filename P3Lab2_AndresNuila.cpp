#include <iostream>
#include <cmath>
using namespace std;

double NewtonRaphson(double x, double a, double b, double c, int contador)
{
    if (contador > 100)
        return x;
    double funcion = (a * pow(x, 2)) + (b * x) + c;
    double derivada = 2 * (a * x) + b;
    double division = funcion / derivada;
    double raiz = x - division;
    return NewtonRaphson(raiz, a, b, c, ++contador);
}

int aproximacionPi(int a);

int main()
{
    char resp = 's';
    int opc = 0;
    while (resp == 's')
    {
        cout << "EJERCICIO 1\nEJERCICIO 2\nEJERCICIO 3\nINGRESE UNA OPCION--->";
        cin >> opc;
        switch (opc)
        {
        case 1:
            double a, b, c;
            cout << "Ingrese el valor de a-->";
            cin >> a;
            while (a == 0)
            {
                cout << "a debe ser distinto de 0. Ingrese de nuevo los datos" << endl;
                cout << "Ingrese el valor de a-->";
                cin >> a;
            }
            cout << "Ingrese el valor de b-->";
            cin >> b;
            cout << "Ingrese el valor de c-->";
            cin >> c;
            double coorXVertice, coorYVertice, xParaPrimeraRaiz, xParaSegundaRaiz;
            coorXVertice = ((double)(-b) / (double)(2 * a));
            coorYVertice = (a * coorXVertice) + (b * coorXVertice) + c;
            xParaPrimeraRaiz = coorXVertice - 200;
            xParaSegundaRaiz = coorXVertice + 200;
            cout << "Raiz 1--->" << NewtonRaphson(xParaPrimeraRaiz, a, b, c, 0) << endl;
            cout << "Raiz 2--->" << NewtonRaphson(xParaSegundaRaiz, a, b, c, 0) << endl;
            break;
        case 2:
            
            break;
        default:
            break;
        }
    }
}
