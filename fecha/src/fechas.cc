#include <cstdlib>
#include <iostream>
#include <fstream>
#include "tools.h"    
#include "fecha.h"


using namespace std;


int main(int argc, char*argv[]){
    /*Usage(argc, argv);*/
    ofstream output_file(argv[5]);
    int dia = 0, mes = 0, ano = 0, N = 1, j =0;
    bool resultadoBool, resultadoBool2;
    string bisiesto = "Sí ";
    dia = stoi(argv[1]);
    mes = stoi(argv[2]);
    ano = stoi(argv[3]);
    N = stoi(argv[4]);
    Fecha fecha{dia, mes, ano};
    string nombreFichero = argv[5];

    resultadoBool2 = fecha.Bisiesto(ano);
    resultadoBool = fecha.ValidacionFecha(dia, mes, ano, resultadoBool2);

    if (resultadoBool){
        cout << "***ERROR*** No has introduccido la fecha correctamente" << endl;

    } else {

        while(j != N){
            output_file << "///////////////" << endl;
            fecha.Print();
            output_file << dia << "/" << mes << "/" << ano << endl;
            resultadoBool2 = fecha.Bisiesto(ano);
            if (!resultadoBool2){
                bisiesto = "No ";
            }
            output_file << "¿Bisiesto?: " << bisiesto << endl;
            ano = fecha.AnoPosterior(dia, mes, ano);
            mes = fecha.MesPosterior(mes, dia, resultadoBool2);
            dia = fecha.DiaPosterior(dia, mes, ano, resultadoBool2)+1;

            fecha.SetDate(dia, mes, ano);
            j++;
        }
    } 

    return 0;

}
