#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <string.h>
#include "classes.h"

int main(){
    Fl_Window *window = new Fl_Window(520, 480);
    window->label("Calculadora TP EDA 2");
    window->callback(close, window);

    Fl_Box *titulo = new Fl_Box(60, 40, 400, 100);
    titulo->label("Calculadora TP EDA 2\n2023");
    titulo->box(FL_UP_BOX);
    titulo->labelfont(FL_BOLD+FL_ITALIC);
    titulo->labelsize(36);
    titulo->labeltype(FL_SHADOW_LABEL);

    Fl_Button *sisEqu = new Fl_Button(20, 220, 220, 30, "Sistema de Ecuaciones Lineales");
    sisEqu->callback((Fl_Callback*)sistemaEqLin);

    Fl_Box *text1 = new Fl_Box(240, 220, 220, 30);
    text1->label("Solucion utilizando Gauss-Jordan.");

    Fl_Button *inteNum = new Fl_Button(20, 300, 220, 30, "Integracion Numerica");
    inteNum->callback((Fl_Callback*)integracionNum);

    Fl_Box *text2 = new Fl_Box(255, 300, 220, 30);
    text2->label("Solucion utilizando Regla del Trapecio.");

   
    Fl_Box *titulo2 = new Fl_Box(60, 40, 400, 100);
    titulo2->label("Calculadora TP EDA 2\n2023");
    titulo2->hide();

    window->end();
    window->show();
    return Fl::run();
}

void close(Fl_Widget* widget, void* data){
    Fl_Window *win = (Fl_Window *)data;
    win->hide();
    Fl::delete_widget(win);
    exit(0);
}

void sistemaEqLin(){
    Window wind = Window();
}

void integracionNum(){
    Window wind = Window();
}