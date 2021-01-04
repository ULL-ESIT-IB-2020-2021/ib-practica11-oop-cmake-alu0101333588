#include <iostream>
#include "complejo.h"

using namespace std;

void Complejo::Print(){
    cout << pReal_ << " + " << pImaginaria_ << "i" << endl;
}

void Complejo::Add(int x1, int y1, int x2, int y2){
    cout << "Suma: " << x1+x2 << " + " << y1+y2 << "i" << endl;
}
void Complejo::Sub(int x1, int y1, int x2, int y2){
    cout << "Resta: " << x1-x2 << " + " << y1-y2 << "i" << endl;
}



