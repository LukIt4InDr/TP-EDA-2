#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <string.h>
#include "classes.h"

short flag = 0;

Window::Window(int modo){
    if(flag == 0){
        flag = 1;
        switch(modo){
            case 1:
                sistemaEquWin = new Fl_Window(520, 480);
                sistemaEquWin->label("Sistema de Ecuaciones");
                sistemaEquWin->callback(wClose,sistemaEquWin);

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