#include <iostream>
#include "fecha.h"

using namespace std;


Fecha::Fecha(int dia, int mes, int ano){
    SetDate(dia, mes, ano);
}

void Fecha::SetDate(int dia, int mes, int ano){
    mes_ = mes;
    dia_ = dia;
    ano_ = ano;
}

void Fecha::Print(){
    cout << dia_ << "/" << mes_ << "/" << ano_ << endl;
}


int Fecha::AnoPosterior (int aDay, int aMonth, int aAno){
    
    if (aMonth == 12 && aDay == 31){
        aAno++;
        return aAno;
    } else{
        return aAno;
    }
}

bool Fecha::Bisiesto (int bYear){
    if (bYear % 4 == 0 && (bYear % 100 != 0 || bYear % 400 == 0)){
        return true;
    } else {
        return false;
    }
}

bool Fecha::ValidacionFecha (int day, int month, int year, bool vBisiesto){
    switch (month){ // cuando se detecta que la fecha no está entre los valores permitidos activa una "alerta" mediante el true, 
        case 1:        // dicha "alerta" se traduce en el programa principal en indicar que está mal puesta y, por tanto, finaliza el proceso
        case 3:
        case 5: 
        case 7:
        case 8:
        case 10:
        case 12: 
            if (day < 1 || day > 31){
                return true;
            } else {
                return false;
            }

        case 4:
        case 6:
        case 9:
        case 11: 
            if (day < 1 || day > 30){
                return true;
            } else {
                return false;
            }

        case 2: 
            if(vBisiesto){
                if (day < 1 || day > 29){
                    return true;
                } else {
                    return false;
                }
            } else {
                if (day < 1 || day > 28){
                    return true;
                } else {
                    return false;
                } 
            }
    }
    
    if (month < 1 || month > 12){
        return true;
    }

    if (year < 1){
        return true;
    }
}

int Fecha::DiaPosterior (int dDay, int dMonth, int dYear, bool dBisiesto){
    switch (dMonth){ // dDay es el día
        case 1:        // dMonth el mes
        case 3:         // dYear el año
        case 5:         // dBisiesto es si el año es bisiesto o no
        case 7:
        case 8:
        case 10:
        case 12: if (dDay == 31){
            dDay = 1;
            return dDay;
            } else {
                return (dDay + 1);
            }

        case 4:
        case 6:
        case 9:
        case 11: if (dDay == 30){
            dDay = 1;
            return dDay;
            } else {
                return (dDay + 1);
            }

        case 2: 
        if(dBisiesto){
            if (dDay == 29){
                dDay = 1;
                return dDay;
            } else {
                return (dDay + 1);
            }
        } else {
           if (dDay == 28){
                dDay = 1;
                return dDay;
            } else {
                return (dDay + 1);
            } 
        }
        default: return false;
    }

    if(dYear == 0){
        return false;
    }
}

int Fecha::MesPosterior (int mMonth, int mDay, bool mBisiesto){

    switch (mMonth){ // dDay es el día
        case 1:        // dMonth el mes
        case 3:         // dYear el año
        case 5:         // dBisiesto es si el año es bisiesto o no
        case 7:
        case 8:
        case 10:
        case 12: 
            if (mDay == 31){
                mMonth = 1;
                return mMonth;
            } else {
                return mMonth;
            }

        case 4:
        case 6:
        case 9:
        case 11: 
            if (mDay == 30){
                mMonth++;
                return (mMonth);
            } else {
                return mMonth;
            }

        case 2: 
            if(mBisiesto){
                if (mDay == 29){
                    mMonth++;
                    return (mMonth);
                }
            } else if (mDay == 28){
                mMonth++;
                return (mMonth);
            
            } else {
                return mMonth;
            }
    }
        
}