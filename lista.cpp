//Lista.cpp
#include "lista.h"

Lista::Lista()
{

}

bool Lista::isValidPos(const int &p)
{
    return p > -2 && p <= last;
}


void Lista::Inicializa()
{
    last = -1;
}

bool Lista::Vacia()
{
    return last == -1;
}

bool Lista::Llena()
{
    return last == 3999;
}

void Lista::Inserta(const Cancion &e, const int &pos)
{
    if(!isValidPos(pos) or pos< -1 or Llena()){
        throw Error("Desbordamineto de datos,Inserta nueva1");
    }
    int i(last);
    while(i>pos){
        playlist[i+1] = playlist[i];
        i--;
    }
    playlist[pos+1] = e;
    last++;
}

void Lista::Borrar(const int &pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion a eleminar no valida,borrar");
    }
    if(Vacia()){
        throw Error("Lista vacia,borrar");
    }
    int i(pos);
    while (i < last) {
        playlist[i]=playlist[i+1];
        i++;
    }
    last--;
}

Cancion Lista::Recupera(const int &pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion Invalida,Recupera");
    }
    return playlist[pos];
}

int Lista::getPrimero()
{
    if(Vacia()){
        throw Error("La playlist esta vacia,getprimero");
    }
    return 0;
}

int Lista::getUltimo()
{
    if(Vacia()){
        throw Error("La playlist esta vacia,getultimo");
    }
 return last;
}

int Lista::getSeguiente(const int &pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion invalida,getSiguiente");
    }
    if(Vacia()){
        throw Error("La lista esta vacia,getsiguiente");
    }
    return pos+1;
}

int Lista::getAnterior(const int &pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion invalida,getanterior");
    }
    if(Vacia()){
        throw Error("La lista esta vacia,getanterior");
    }
    return pos+1;
}

void Lista::Anula()
{
    last = -1;
}

void Lista::Mostrar()
{
    if(Vacia()){
        throw Error("Datos insuficientes,mostrar");
    }
    cout << left;
    cout << setw(7) << "Numero" << " | "
         << setw(25) << "Cancion" << " | "
         << setw(15) << "Autor" << " | "
         << setw(17) << "Interprete" << " | "
         << setw(4) << "Duracion"
         << endl;
    for (int i=0;i <= last;i++) {
        cout << setw(7)<< i << " | "
             << setw(25)<< playlist[i].getNombre() << " | "
             << setw(15) << playlist[i].getAutor() << " | "
             << setw(17) << playlist[i].getInterprete() << " | "
             << setw(4) << playlist[i].getDuracion()
             << endl;
    }
}

int Lista::busquedaLineal(const Cancion&c)
{
    for(int j(0); j <= last; j++){
        if(playlist[j] == c){
            return j;
        }
    }
    return -1;

}

int Lista::busquedaBinaria(const Cancion &c)
{
    int i(0), j(last),m;
    while(i<=j){
        m = (1+j)/2;
        if(playlist[m] == c){
            return m;
        }
        if(c < playlist[m]){
            j = m-1;
        }
        i = m+1;
    }
    return -1;
}

void Lista::swapData(Cancion &a, Cancion &b)
{
    Cancion Aux(a);
    a=b;
    b=Aux;
}

void Lista::ordenaBurbujaA()
{
    int i(last),j;
    bool flag;
    do{
        flag = false;
        j = 0;
        while(j < i){
            if(playlist[j].getAutor() > playlist[j+1].getAutor()){
                swapData(playlist[j], playlist[j+1]);
                flag = true;
            }
            j++;
        }
        i--;
    }while(flag);
}

void Lista::ordenaShellA()
{
    float fact(3.0/4.0);
    int dif((last+1)*fact),lim,i;
    while(dif > 0){
        lim = last -dif;
        i = 0;
        while(i <= lim){
            if(playlist[i].getAutor() > playlist[i+dif].getAutor()){
                swapData(playlist[i], playlist[i+dif]);
            }
            i++;
        }
        dif*=fact;
    }
}

void Lista::ordenaBurbujaC()
{
    int i(last),j;
    bool flag;
    do{
        flag = false;
        j = 0;
        while(j < i){
            if(playlist[j] > playlist[j+1]){
                swapData(playlist[j], playlist[j+1]);
                flag = true;
            }
            j++;
        }
        i--;
    }while(flag);
}

void Lista::ordenaShellC()
{
    float fact(3.0/4.0);
    int dif((last+1)*fact),lim,i;
    while(dif > 0){
        lim = last -dif;
        i = 0;
        while(i <= lim){
            if(playlist[i] > playlist[i+dif]){
                swapData(playlist[i], playlist[i+dif]);
            }
            i++;
        }
        dif*=fact;
    }
}

void Lista::ordenaInsertC()
{
    int i(1),j;
    Cancion aux;
    while(i <= last){
        aux = playlist[i];
        j = i;
        while(j > 0 and aux < playlist[j-1]){
            playlist[j] = playlist[j-1];
            j--;
        }
        if(i != j){
            playlist[j] = aux;
        }
        i++;
    }
}

void Lista::ordenaSelectC()
{
    int i(0),j,m;
    while(i < last){
        m = i;
        j = i+1;
        while(j <= last){
            if(playlist[j] < playlist[m]){
                m = j;
            }
            j++;
        }
        if(i != m){
            swapData(playlist[i],playlist[m]);
        }
        i++;
    }
}

void Lista::ordenaInsertA()
{
    int i(1),j;
    Cancion aux;
    while(i <= last){
        aux = playlist[i];
        j = i;
        while(j > 0 and aux.getAutor() < playlist[j-1].getAutor()){
            playlist[j] = playlist[j-1];
            j--;
        }
        if(i != j){
            playlist[j] = aux;
        }
        i++;
    }
}

void Lista::ordenaSelectA()
{
    int i(0),j,m;
    while(i < last){
        m = i;
        j = i+1;
        while(j <= last){
            if(playlist[j].getAutor() < playlist[m].getAutor()){
                m = j;
            }
            j++;
        }
        if(i != m){
            swapData(playlist[i],playlist[m]);
        }
        i++;
    }
}
