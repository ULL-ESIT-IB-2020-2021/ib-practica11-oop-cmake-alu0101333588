#include <cstdlib>
#include <iostream>
#include <fstream>
#include "tools.h"    
#include "fecha.h"


using namespace std;


int main(int argc, char*argv[]){
    Usage(argc, argv);
    string fichero_escritura = argv[3];
    ofstream output_file(fichero_escritura);
    int dia = 0, mes = 0, ano = 0, N = 0, j =0;
    bool resultadoBool, resultadoBool2;
    string bisiesto = "Sí ";

    string line = argv[1];
    int i, posicion; 
    string dd{""}, mm{""}, aa{""};

    for(i = 0; line[i] != '/'; i++){
        dd = dd + line[i];
        posicion = i + 1;
    }

    for(i = posicion + 1; line[i] != '/'; i++){
        mm = mm + line[i];
        posicion = i + 1;
               
    }

    for(i = posicion + 1; line[i] != ' '; i++){
        aa = aa + line[i];
               
    }

    dia = stoi(dd);
    mes = stoi(mm);
    ano = stoi(aa);
    N = stoi(argv[2]);

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

        cout << "El proceso se ha finalizado con éxito, comprueba el fichero: " << fichero_escritura << endl;
    } 
    
    return 0;

}
