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
        static void crearMatriz(Fl_Widget*, void*);
        void crearMatriz2(Fl_Widget *);
        static void calcularMatriz(Fl_Widget*, void*);
        void setMatriz(Fl_Widget *);
    public:
        Window(int);
    protected:
        short inputX = 175, inputY = 225;
        short inputXAux, inputYAux;
        short mMatriz = 3;
        short i, j, k;
        float **matriz = 0;
};

class Calculadora{
    private:
        short i, j, k;
        float aux;
    public:
        char *resultado(short);
};

class Gauss: Calculadora{
    private:
        short mMatriz;
        float *gauss = 0, **matriz = 0;
    public:
        Gauss();
        void setMatrizG(short, float*[]);
        float **mDiagonal();
        float **calcularGauss();
};

#endif