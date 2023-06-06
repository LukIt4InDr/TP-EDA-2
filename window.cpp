#include <iostream>
#include <iomanip>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include "classes.h"

short flag = 0;

Fl_Box *titulo;
Fl_Box *resultado;

Fl_Int_Input *cantM;
Fl_Button *cantM_b;
Fl_Float_Input *floatInput[10][11];
Fl_Button *calcular;
Fl_Box *diagonal;

Window::Window(int modo){
    if(flag == 0){
        flag = 1;
        switch(modo){
            case 1:
                sistemaEquWin = new Fl_Window(520, 480);
                sistemaEquWin->label("Sistema de Ecuaciones");
                sistemaEquWin->callback(wClose,sistemaEquWin);

                titulo = new Fl_Box(60, 10, 400, 100);
                titulo->label("La Solucion del Sistema de Ecuaciones es\n por medio del Metodo de Gauss-Jordan.\n El sistema en esta calculadora solo puede\n tener hasta 10 ecuaciones.");
                titulo->box(FL_UP_BOX);
                titulo->labelfont(FL_BOLD);

                cantM = new Fl_Int_Input(175, 225, 30, 20);
                cantM->box(FL_GTK_UP_BOX);
                cantM->value("3");

                cantM_b = new Fl_Button(220, 225, 30, 20, "Crear");
                cantM_b->callback(crearMatriz, (void*)this);

                for(j = 0, inputYAux = inputY; j < mMatriz; j++){
                    for (i = 0, inputXAux = inputX; i < mMatriz+1; i++){
                        if(i < mMatriz){
                            floatInput[j][i] = new Fl_Float_Input(inputXAux, inputYAux, 30, 20);
                            floatInput[j][i]->box(FL_GTK_UP_BOX);
                        }else{
                            floatInput[j][i] = new Fl_Float_Input(inputXAux+20, inputYAux, 30, 20);
                            floatInput[j][i]->box(FL_GTK_UP_BOX);
                        }
                        floatInput[j][i]->hide();
                        inputXAux += 40;
                    }
                    inputYAux += 30;
                }

                calcular = new Fl_Button(60, 425, 400, 25, "Calcular Sistema de Ecuaciones");
                calcular->box(FL_UP_BOX);
                calcular->labelfont(FL_BOLD);
                calcular->callback(calcularMatriz, (void*)this);
                calcular->hide();

                diagonal = new Fl_Box(60, 10, 400, 350);
                diagonal->box(FL_UP_BOX);
                diagonal->labelfont(FL_BOLD);
                diagonal->hide();

                resultado = new Fl_Box(60, 380, 400, 95);
                resultado->box(FL_UP_BOX);
                resultado->labelfont(FL_BOLD);
                resultado->hide();

                sistemaEquWin->show();
                sistemaEquWin->end();
                break;
            case 2:
                integracionWin = new Fl_Window(520, 480);
                integracionWin->label("Integracion Numerica");
	            integracionWin->callback(wClose,integracionWin);

                integracionWin->show();
                integracionWin->end();
                break;
        }
    }
}

void Window::wClose(Fl_Widget* widget, void* data){
    Fl_Window *win = (Fl_Window *)data;
    win->hide();
    Fl::delete_widget(win);
    flag = 0;
}

void Window::crearMatriz(Fl_Widget *w, void *data){
    Window *o = (Window*)data;
    o->crearMatriz2(w);
}

void Window::crearMatriz2(Fl_Widget *w){  
    cantM->hide();
    cantM_b->hide();

    mMatriz = atoi(cantM->value());

    switch(mMatriz){
        case 2:
            inputX = 195;
            inputY = 240;
            break;
        case 3:
            inputX = 175;
            inputY = 225;
            break;
        case 4:
            inputX = 155;
            inputY = 210;
            break;
        case 5:
            inputX = 135;
            inputY = 195;
            break;
        case 6:
            inputX = 115;
            inputY = 180;
            break;
        case 7:
            inputX = 95;
            inputY = 175;
            break;
        case 8:
            inputX = 75;
            inputY = 150;
            break;
        case 9:
            inputX = 55;
            inputY = 135;
            break;
        case 10:
            inputX = 35;
            inputY = 120;
            break;
    }

    for(j = 0, inputYAux = inputY; j < mMatriz; j++){
        for (i = 0, inputXAux = inputX; i < mMatriz+1; i++){
            if(i < mMatriz){
                floatInput[j][i]->show();
                floatInput[j][i]->resize(inputXAux, inputYAux, 30, 20);
            }else{
                floatInput[j][i]->show();
                floatInput[j][i]->resize(inputXAux+20, inputYAux, 30, 20);
            }
            inputXAux += 40;
        }
        inputYAux += 30;
    }

    calcular->show();
}

void Window::calcularMatriz(Fl_Widget *w, void *data){
    Window *o = (Window*)data;

    calcular->hide();
    titulo->hide();
    o->setMatriz(w);

    

   
    resultado->label("Resultados:");
    resultado->show();

    // for(o->i=0; o->i<o->mMatriz; o->i++){
    //     delete[] o->matriz[o->i];
    // }
    // delete[] o->matriz;
    // **(o->matriz) = 0;
    // delete[] o->resultadoC;
    // *o->resultadoC = 0;
}

void Window::setMatriz(Fl_Widget *w){
    mMatriz = atoi(cantM->value());
    Gauss calc = Gauss(mMatriz);
    std::string diagonalS;

    matriz = new float *[mMatriz];
	for(i=0; i<mMatriz; i++){
        matriz[i] = new float [mMatriz+1];
    }

    for(j=0; j<mMatriz; j++){
		for(i=0; i<mMatriz+1; i++){
            floatInput[j][i]->hide();
            matriz[j][i] = atof(floatInput[j][i]->value());
        }
	}

    calc.setMatrizG(matriz);
    diagonalS = calc.mDiagonal(w);

    diagonal->label(diagonalS.c_str());
    diagonal->show();
}