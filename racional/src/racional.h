#include <iostream>

using namespace std;

class Racional{
    public: 
    double numerador_;
    double denominador_;

    public:
    Racional(double numerador, double denominador);
    Racional(string line);
    void Print();

    double getNumerador(){return numerador_;}
    double getDenominador(){return denominador_;}

    void SetNumeros(double numerador, double denominador);



};

bool ceroDenominador(double denom);
double juntaNumeros(double num, double den);
double Suma (double numero1, double numero2);
double Resta (double numero1, double numero2);
double Division (double numero1, double numero2);
double Multiplicacion (double numero1, double numero2);



