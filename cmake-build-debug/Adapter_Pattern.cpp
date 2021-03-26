#include <iostream>
typedef int coordenada;
typedef int Dimension;
using namespace std;
//Interfaz deseada
class rectangulo
{
public:
    virtual void dibujar() = 0;
};

// Componente heredado
class rectanguloHeredado
{
public:
    rectanguloHeredado(coordenada x1, coordenada y1, coordenada x2, coordenada y2)
    {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
        cout << "rectanguloHeredado:  crear.  (" << x1_ << "," << y1_ << ") => ("
             << x2_ << "," << y2_ << ")" << endl;
    }
    void Ant_dibujo()
    {
        cout << "rectanguloHeredado:  Ant_dibujo.  (" << x1_ << "," << y1_ <<
             ") => (" << x2_ << "," << y2_ << ")" << endl;
    }
private:
    coordenada x1_;
    coordenada y1_;
    coordenada x2_;
    coordenada y2_;
};

// Adaptador envolvente
class AdaptadorRectangulo: public rectangulo, private rectanguloHeredado
{
public:
    AdaptadorRectangulo(coordenada x, coordenada y, Dimension w, Dimension h):
            rectanguloHeredado(x, y, x + w, y + h)
    {
        cout << "AdaptadorRectangulo: crear.  (" << x << "," << y <<
             "), Ancho = " << w << ", Alto = " << h << endl;
    }
    virtual void dibujar()
    {
        cout << "AdaptadorRectangulo: dibujar." << endl;
        Ant_dibujo();
    }
};

int main()
{
    rectangulo *r = new AdaptadorRectangulo(120, 200, 60, 40);
    r->dibujar();
}
