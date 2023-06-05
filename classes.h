#ifndef CLASSES_H_
#define CLASSES_H_

void close(Fl_Widget*, void*);
void sistemaEqLin();
void integracionNum();

class Window{
    private:
        Fl_Window *integracionWin;
        Fl_Window *sistemaEquWin;

        static void wClose(Fl_Widget*, void*);
    public:
        Window(int);

};

class Calculadora{
    private:

    public:

};

#endif