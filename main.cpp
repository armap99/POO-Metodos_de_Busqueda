//Main.cpp
#include <iostream>

#include "cancion.h"
#include "lista.h"
using namespace std;

int main()
{
    string aux,op;
    int selct, pos;
    Cancion cancion;
    Lista nueva;
    nueva.Inicializa();
    cout << "Bienvenido a tu playlist" << endl;
        while(true){
            cout << "1)Agregar Nueva Cancion " << endl
            << "2)Eliminar Cancion de la lista " << endl
            << "3)Busqueda lineal" << endl
            << "4)Busqueda binaria " << endl
            << "5)BubbleSort " << endl
            << "6)ShellSort " << endl
            << "7)InsertSort " << endl
            << "8)SelectSort " << endl
            << "0)Salir " << endl;
            getline(cin,op);
            if(op == "1"){
                cin >> cancion;
                cout << "Posicion donde desea agregarla: " << endl;
                cin >> pos;
                cin.ignore();
                nueva.Inserta(cancion,pos);
                system ("cls");
                nueva.Mostrar();
            }
            else if(op == "2"){
                system ("cls");
                nueva.Mostrar();
                cout << "Posicion de la cancion que desea eleiminar: " << endl;
                cin >> pos;
                cin.ignore();
                nueva.Borrar(pos);
                system ("cls");
                nueva.Mostrar();
            }
            else if(op == "3"){
                cout << "Metodos de busqueda lineal" << endl
                << "1)Por nombre de Cancion" << endl
                << "2)Por nombre de Autor" << endl;
                cin >> selct;
                cin.ignore();
                if(selct == 1){
                    Cancion buscada;
                    int fpos;
                    cout << "Ingrese nombre de la cancion: " << endl;
                    getline(cin,aux);
                    buscada.setNombre(aux);
                    fpos=nueva.busquedaLineal(buscada);
                    if(fpos == -1){
                        cout << "La cancion no esta en la playlist" << endl;
                    }
                    cout << "Posicion de la cancion: " << fpos << endl
                    <<"Archivo Mp3:" << nueva.Recupera(fpos).toString() << endl;
                }
                else if(selct == 2){
                    Cancion buscada;
                    int fpos;
                    cout << "Ingresa nombre del autor: " << endl;
                    getline(cin,aux);
                    buscada.setAutor(aux);
                    fpos = nueva.busquedaLineal(buscada);
                    if(fpos == -1){
                        cout << "La cancion no esta en la playlist" << endl;
                    }
                    cout << "Posicion de la cancion: " << fpos << endl
                    <<"Archivo Mp3:" << nueva.Recupera(fpos).toString() << endl;

                }
            }
            else if(op == "4"){
                int rpos;
                cout << "Metodos de busqueda binaria" << endl
                << "1)Por nombre de Cancion" << endl
                << "2)Por nombre de Autor" << endl;
                cin >> selct;
                cin.ignore();
                if(selct == 1){
                    Cancion buscada2;
                    cout << "Ingrese nombre de la cancion: " << endl;
                    getline(cin,aux);
                    buscada2.setNombre(aux);
                    rpos= nueva.busquedaBinaria(buscada2);
                    if(rpos == -1){
                        cout << "La cancion no esta en la playlist" << endl;
                    }
                    else{
                        cout << "Posicion de la cancion: " << rpos << endl
                        <<"Archivo Mp3:" << nueva.Recupera(rpos).toString() << endl;
                    }

                }
                else if(selct == 2){
                    Cancion buscada2;
                    cout << "Ingresa nombre del autor: " << endl;
                    getline(cin,aux);
                    buscada2.setAutor(aux);
                    rpos= nueva.busquedaBinaria(buscada2);
                    if(rpos == -1){
                        cout << "La cancion no esta en la playlist" << endl;
                    }
                    else{
                        cout << "Posicion de la cancion: " << rpos << endl
                        <<"Archivo Mp3:" << nueva.Recupera(rpos).toString() << endl;
                    }
                }
            }
            else if(op == "5"){
                cout << "BubbleSort" << endl
                << "1)Ordenar por autor" << endl
                << "2)Ordenar por nombre de cancion" << endl;
                cin >> selct;
                if(selct == 1){
                    nueva.ordenaBurbujaA();
                }
                else if(selct == 2){
                    nueva.ordenaBurbujaC();
                }
                cin.ignore();
                system ("cls");
                nueva.Mostrar();
            }
            else if(op == "6"){
                cout << "ShellSort " << endl
                << "1)Ordenar por autor" << endl
                << "2)Ordenar por nombre de cancion" << endl;
                cin >> selct;
                if(selct == 1){
                    nueva.ordenaShellA();
                }
                else if(selct == 2){
                    nueva.ordenaShellC();
                }
                cin.ignore();
                system ("cls");
                nueva.Mostrar();
            }
            else if(op == "7"){
                cout << "InsertSort " << endl
                << "1)Ordenar por autor" << endl
                << "2)Ordenar por nombre de cancion" << endl;
                cin >> selct;
                if(selct == 1){
                    nueva.ordenaInsertA();
                }
                else if(selct == 2){
                    nueva.ordenaInsertC();
                }
                cin.ignore();
                system ("cls");
                nueva.Mostrar();
            }
            else if(op == "8"){
                cout << "SelectSort " << endl
                << "1)Ordenar por autor" << endl
                << "2)Ordenar por nombre de cancion" << endl;
                cin >> selct;
                if(selct == 1){
                    nueva.ordenaSelectA();
                }
                else if(selct == 2){
                    nueva.ordenaSelectC();
                }
                cin.ignore();
                system ("cls");
                nueva.Mostrar();
            }
            else if(op == "0"){
                cout << "Adios" <<  endl << endl;
                break;
            }
        }
}
