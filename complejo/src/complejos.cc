#include <iostream>
#include "complejo.h"


using namespace std;


int main(){

    Complejo complejo1{4, 5};
    Complejo complejo2{7, 8};
    Complejo resultado;
    complejo1.Print();
    complejo2.Print();

    resultado.Add(complejo1.pReal_, complejo1.pImaginaria_, complejo2.pReal_, complejo2.pImaginaria_);
    resultado.Sub(complejo1.pReal_, complejo1.pImaginaria_, complejo2.pReal_, complejo2.pImaginaria_);

    return 0;

}
