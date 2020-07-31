#include <iostream>
#include <cmath>
using namespace std;
double NewtonRaphson(int a, double b);

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
            int a, b, c;
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
            cout << "x=" << coorXVertice << "y=" << coorYVertice;
            xParaPrimeraRaiz = coorXVertice - 200;
            xParaSegundaRaiz = coorXVertice + 200;

            break;
        
        default:
            break;
        }
    }
}
double NewtonRaphson(int a, double b){
    if (a==100)
    {
        
    }
    
}