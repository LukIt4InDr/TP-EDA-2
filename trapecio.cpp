#include <iostream>
#include <iomanip>
#include <cmath>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include "classes.h"

Trapecio::Trapecio(short _a, short _b, short _funcion){
    a = _a;
    b = _b;
    funcion = _funcion;
}

void Trapecio::calcularFunciones(){
    switch (funcion){
        case 1:
            funcionA = -(pow(3,2))+8*(3)-12;
            funcionB = -(pow(5,2))+8*(5)-12;
            break;
        case 2:
            funcionA = sin((3*1)+5);
            funcionB = sin((3*3)+5);
            break;
    }
}

float Trapecio::calcularTrapecio(){
    integral = (b - a)*(funcionA + funcionB)/2;

    return integral;
}