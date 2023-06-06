#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include "classes.h"

Gauss::Gauss(short _mMatriz){
    mMatriz = _mMatriz;

    matriz1 = new float *[mMatriz];
    gauss = new float [mMatriz];
	for(i=0; i<mMatriz; i++){
        matriz1[i] = new float [mMatriz+1];
    }
}

void Gauss::setMatrizG(float *_matriz[]){
    for(j=0; j<mMatriz; j++){
		for(i=0; i<mMatriz+1; i++){
            matriz1[j][i] = _matriz[j][i];
        }
	}
}

std::string Gauss::mDiagonal(){
    std::stringstream ss;
    std::string diagonalS;

    for(j=0; j<mMatriz; j++){
		for(i=0; i<mMatriz; i++){
		    if(i!=j){
			    aux=matriz1[i][j]/matriz1[j][j];

			    for(k=0; k<mMatriz+1; k++){
				    matriz1[i][k]-=matriz1[j][k]*aux;
                }
		    }
        }
    }

    for(i=0; i<mMatriz; i++){
		for(j=0; j<mMatriz+1; j++){
		    ss << matriz1[i][j] << "\t";
        }
        ss << "\n";
	}
    diagonalS = ss.str();
    
    return diagonalS;
}

std::string Gauss::calcularGauss(){
    std::stringstream ss;
    std::string gaussS;

    for(i=0; i<mMatriz; i++){
        gauss[i] = matriz1[i][mMatriz]/matriz1[i][i];
        ss << gauss[i];
    }
    gaussS = ss.str();

    return gaussS;
}