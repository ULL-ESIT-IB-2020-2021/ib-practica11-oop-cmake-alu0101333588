#include <iostream>
#include <fstream>
#include "racional.h"
#include <string>

using namespace std;


Racional::Racional(double numerador, double denominador){
    SetNumeros(numerador, denominador);
}

void Racional::SetNumeros(double numerador, double denominador){
    numerador_ = numerador;
    denominador_ = denominador;
}

Racional::Racional(string line){ //ftexto es por el fichero de texto

        double numerador = 0, denominador = 0;
        int i, posicion; 
        string num{""}, dem{""};
       
            
            for(i = 0; line[i] != '/'; i++){
                num = num + line[i];
                posicion = i + 1;
            }

            for(i = posicion + 1; line[i] != ' '; i++){
                dem = dem + line[i];
               
            }

            numerador = stoi(num);
            denominador = stoi(dem);
            SetNumeros(numerador, denominador);

            
}

void Racional::Print(){
    cout << numerador_ << "/" << denominador_;
}


double juntaNumeros(double num, double den){

    return (num/den);
} 

bool ceroDenominador(double denom){
    if (denom == 0){
        return true;
    } else{
        return false;
    }
}

double Suma (double numero1, double numero2){
    return numero1+numero2;
}

double Resta (double numero1, double numero2){
    return numero1-numero2;
}

double Division (double numero1, double numero2){
    return numero1/numero2;
}

double Multiplicacion (double numero1, double numero2){
    return numero1*numero2;
}
