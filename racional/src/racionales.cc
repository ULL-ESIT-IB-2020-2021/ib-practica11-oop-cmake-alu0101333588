#include <cstdlib>
#include <iostream>
#include <fstream>
#include "racional.h"
#include "tools.h"
#include <string>


using namespace std;


int main(int argc, char*argv[]){
    Usage(argc, argv);
    string linea;
    string fLectura = "prueba.txt"; // Nombre del fichero a leer
    fLectura = argv[1];
    const string fEscritura = "racionales.txt"; // Nombre del fichero a escribir
    ifstream lectura_fichero(fLectura);
    ofstream escritura_fichero(fEscritura);
    string tanda1, tanda2;

    /*while(getline(input_fichero, linea)){
        
    }*/

    if (!lectura_fichero){
        cerr << "***ERROR*** El archivo de lectura no se ha podido abrir correctamente" << endl;
        exit(EXIT_SUCCESS);
    }

    if (!escritura_fichero){
        cerr << "***ERROR*** El archivo de escritura no se ha podido abrir correctamente" << endl;
        exit(EXIT_SUCCESS);
    }
    
    while(lectura_fichero >> tanda1 >> tanda2){
        Racional racional1(tanda1);
        Racional racional2(tanda2);
        
        if (ceroDenominador(racional1.getDenominador()) || ceroDenominador(racional2.getDenominador())){
            escritura_fichero << "***ERROR*** el denominador no puede ser cero" << endl;
            escritura_fichero << "La operación se ha cancelado";
            exit(EXIT_SUCCESS);
        }
        
        double num1, num2;
        num1 = juntaNumeros(racional1.getNumerador(), racional1.getDenominador());
        num2 = juntaNumeros(racional2.getNumerador(), racional2.getDenominador());

        escritura_fichero << racional1.getNumerador() << "/" << racional1.getDenominador(); // SUMA
        escritura_fichero << " + ";
        escritura_fichero << racional2.getNumerador() << "/" << racional2.getDenominador();
        escritura_fichero << " = " << Suma(num1, num2) << endl;

        escritura_fichero << racional1.getNumerador() << "/" << racional1.getDenominador(); // RESTA
        escritura_fichero << " - ";
        escritura_fichero << racional2.getNumerador() << "/" << racional2.getDenominador();
        escritura_fichero << " = " << Resta(num1, num2) << endl;

        escritura_fichero << racional1.getNumerador() << "/" << racional1.getDenominador(); // MULTIPLICACIÓN
        escritura_fichero << " * ";
        escritura_fichero << racional2.getNumerador() << "/" << racional2.getDenominador();
        escritura_fichero << " = " << Multiplicacion(num1, num2) << endl;

        escritura_fichero << racional1.getNumerador() << "/" << racional1.getDenominador(); // DIVISIÓN
        escritura_fichero << " / ";
        escritura_fichero << racional2.getNumerador() << "/" << racional2.getDenominador();
        escritura_fichero << " = " << Division(num1, num2) << endl;

        if(num1 > num2){ // COMPARACIÓN
            escritura_fichero << racional1.getNumerador() << "/" << racional1.getDenominador();
            escritura_fichero << " es mayor que ";
            escritura_fichero << racional2.getNumerador() << "/" << racional2.getDenominador() << endl;

        } else if(num1 == num2){
            escritura_fichero << racional1.getNumerador() << "/" << racional1.getDenominador();
            escritura_fichero << " es igual que ";
            escritura_fichero << racional2.getNumerador() << "/" << racional2.getDenominador() << endl;

        } else{
            escritura_fichero << racional1.getNumerador() << "/" << racional1.getDenominador();
            escritura_fichero << " es menor que ";
            escritura_fichero << racional2.getNumerador() << "/" << racional2.getDenominador() << endl;
        }

        escritura_fichero << "/////////////////////////" << endl;
        
        
    }

    cout << "MISIÓN COMPLIDA. Revisa tu .txt " << endl;

    return 0;

}
