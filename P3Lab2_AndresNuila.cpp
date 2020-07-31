#include <iostream>
#include <cmath>
#include <iomanip>
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

int aproximacionPi(double acum, double acumDiv)
{

    if (acum < 0)
    {
        cout << 4 * acumDiv;
    }
    else
    {
        double numerador, denominador;
        numerador = pow(-1.0, acum);
        denominador = (2.0 * acum) + 1.0;
        double div = numerador / denominador;
        acumDiv += div;
        aproximacionPi(acum - 1, acumDiv);
    }
}

int main()
{
    char resp = 's';
    int opc = 0;
    while (resp == 's')
    {
        cout << "EJERCICIO 1\nEJERCICIO 2\nEJERCICIO 3\n0. SALIR\nINGRESE UNA OPCION--->";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
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
        }
        break;
        case 2:
        {
            int tam;
            cout << "Ingrese el tamaño de la matriz: ";
            cin >> tam;
            double matrizDeDatos[tam][tam];
            double matrizStandarizada[tam][tam];
            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    matrizDeDatos[i][j] = 10 + rand() % (90);
                }
            }
            cout << "Matriz Generada: " << endl;
            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    cout << setw(3) << matrizDeDatos[i][j];
                }
                cout << endl;
            }
            int suma = 0;
            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    suma += matrizDeDatos[i][j];
                }
            }
            int cantidadElementos = tam * tam;
            double media = (double)(suma) / (double)(cantidadElementos);
            double sumaAuxParaDesviacion = 0;
            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    sumaAuxParaDesviacion += pow((matrizDeDatos[i][j] - media), 2);
                }
            }
            double desviacionStandard = sumaAuxParaDesviacion / (pow(tam, 2));
            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    matrizStandarizada[i][j] = (matrizDeDatos[i][j] - media) / desviacionStandard;
                }
            }
            cout << endl;
            cout << "Matriz Estandarizada: " << endl;
            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    cout << "[" << setw(10) << matrizStandarizada[i][j] << "]"
                         << " ";
                }
                cout << endl;
            }
        }
        case 3:
        {
            int limite;
            cout << "Ingrese el limite hasta donde llegara la sumatoria para la aproximacion" << endl;
            cout << "->";
            cin >> limite;
            cout << "La aproximacion del numero pi es: " << endl;
            cout << aproximacionPi(limite, 0.0) << endl;
        }
        case 0:
            resp = 'n';
            break;
        default:
            break;
        }
    }
}
