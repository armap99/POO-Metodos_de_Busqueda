//Canccion.cpp
#include "cancion.h"

Cancion::Cancion()
{

}

Cancion::Cancion(Cancion &c):duracion(c.getDuracion()), nombre(c.getNombre()), autor(c.getAutor()), interprete(c.getInterprete()) { }

void Cancion::setDuracion(const unsigned int &d)
{
    duracion = d;
}

void Cancion::setNombre(const string &c)
{
    nombre = c;
}

void Cancion::setAutor(const string &a)
{
    autor = a;
}

void Cancion::setInterprete(const string &i)
{
    interprete = i;
}

unsigned int Cancion::getDuracion() const
{
    return duracion;
}

string Cancion::getNombre() const
{
    return nombre;
}

string Cancion::getAutor() const
{
    return autor;
}

string Cancion::getInterprete() const
{
    return interprete;
}

string Cancion::toString() const
{
    string strings;
    strings += autor;
    strings += "_";
    strings += nombre;
    strings += "_";
    strings += to_string(duracion);
    strings += ".MP3";

    return strings;
}

Cancion Cancion::operator = (const Cancion &o)
{
    duracion = (o.getDuracion());
    nombre = (o.getNombre());
    autor = (o.getAutor());
    interprete = (o.getInterprete());

    return *this;
}

bool Cancion::operator ==(const Cancion &a) const
{
    return (nombre == a.getNombre()); //or (autor == a.getAutor());
}

bool Cancion::operator !=(const Cancion &c) const
{
    return  nombre != c.getNombre(); //or (autor != c.getAutor()); otra posivilidad
}

bool Cancion::operator <(const Cancion &c) const
{
    return nombre < c.getNombre(); //or (autor < c.getAutor());
}

bool Cancion::operator <=(const Cancion &c) const
{
    return nombre <= c.getNombre(); //or  (autor <= c.getAutor());
}

bool Cancion::operator >(const Cancion &c) const
{
    return nombre > c.getNombre(); //or (autor < c.getAutor());
}

bool Cancion::operator >=(const Cancion &c) const
{
    return nombre >= c.getNombre(); //or (autor < c.getAutor());
}

/*ostream &Cancion::operator <<(ostream &os, Cancion &n)
{
    os << n.getNombre() << endl;
    os << n.getAutor() << endl;
    os << n.getInterprete() << endl;
    os << n.getDuracion() << endl;

    return os;
}*/

//std::istream& Cancion::operator >>(std::istream &is, Cancion &n){
//    cout << "Nombre: " << endl;
//    getline(is,n.nombre);
//    cout << "Autor: " << endl;
//    getline(is,n.autor);
//    cout << "Interprete: " << endl;
//    getline(is,n.interprete);
//    cout << "Duracion: " << endl;
//    is>> n.duracion;

//    return is;
//}

