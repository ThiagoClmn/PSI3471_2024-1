//exercicio sobel.cpp - 2024
#include "procimagem.h"
#include <cekeikon.h>


int main(){

    Mat_<GRY> a, b, c;
    le(a, "fever-2.pgm");

    medianBlur(a, b, 9);
    medianBlur(b, c, 9);

    imp(a, "mapa1.png");
    imp(b, "mapa2.png");
    imp(c, "mapa3.png");

    
}
