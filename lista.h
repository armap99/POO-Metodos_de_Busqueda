//Lista.h
#ifndef LISTA_H
#define LISTA_H
#include <iomanip>

#include "cancion.h"
#include "error.h"

class Lista
{
private:
    Cancion playlist[4000];
    int last;
    bool isValidPos(const int&);

public:
    Lista();
    void Inicializa();
    bool Vacia();
    bool Llena();
    void Inserta(const Cancion&, const int&);
    void Borrar(const int&);
    Cancion Recupera(const int&);
    int getPrimero();
    int getUltimo();
    int getSeguiente(const int&);
    int getAnterior(const int&);
    void Anula();
    void Mostrar();
    int busquedaLineal(const Cancion&);
    int busquedaBinaria(const Cancion&);
    void swapData(Cancion&, Cancion&);
    void ordenaBurbujaA();
    void ordenaShellA();
    void ordenaBurbujaC();
    void ordenaShellC();
    void ordenaInsertC();
    void ordenaSelectC();
    void ordenaInsertA();
    void ordenaSelectA();

};

#endif // LISTA_H
