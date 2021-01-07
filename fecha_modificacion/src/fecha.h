#include <iostream>

using namespace std;

class Fecha{
    private: 
    int dia_;
    int mes_;
    int ano_;

    public:
    Fecha(int dia, int mes, int ano);
    void SetDate(int dia, int mes, int ano);
    void Print(); 

    int getYear(){return ano_;}
    int getMonth(){return mes_;}
    int getDay(){return dia_;}

    bool Bisiesto (int bYear);
    bool ValidacionFecha (int day, int month, int year, bool vBisiesto);
    int DiaPosterior (int dDay, int dMonth, int dYear, bool dBisiesto);
    int MesPosterior (int mMonth, int mDay, bool mBisiesto);
    int AnoPosterior (int aDay, int aMonth, int aAno);

};



