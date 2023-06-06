#ifndef CLASSES_H_
#define CLASSES_H_
#include <string>

void close(Fl_Widget*, void*);
void sistemaEqLin();
void integracionNum();

class Window{
    private:
        Fl_Window *integracionWin;
        Fl_Window *sistemaEquWin;


        static void wClose(Fl_Widget*, void*);
        static void crearMatriz(Fl_Widget*, void*);
        void crearMatriz2(Fl_Widget *);
        static void calcularMatriz(Fl_Widget*, void*);
        void setMatriz(Fl_Widget*);
        static void primeraFunc(Fl_Widget*, void*);
        void primeraFunc2(Fl_Widget *);
        static void segundaFunc(Fl_Widget*, void*);
        void segundaFunc2(Fl_Widget *);
    public:
        Window(int);
    protected:
        short inputX = 175, inputY = 225;
        short inputXAux, inputYAux;
        short mMatriz = 10;
        short i, j, k;
        float **matriz = 0;
};

class Gauss{
    private:
        short mMatriz, i, j, k, largo=0;
        float *gauss = 0, **matriz1 = 0, aux;
    public:
        Gauss(short);
        void setMatrizG(float*[]);
        std::string mDiagonal();
        std::string calcularGauss();
};

class Trapecio{
    private:
        float integral, funcionA, funcionB;
        short a, b, funcion;
    public:
        Trapecio(short, short, short);
        void calcularFunciones();
        float calcularTrapecio();
};

#endif