#include<iostream>
#include <stdlib.h>
using namespace std;

typedef struct nodo *pnodo;
struct nodo{
    int dato;
    pnodo sig;
};
void agregar_final(pnodo &lista, pnodo nuevo);
void iniciar_lista (pnodo &lista);
void mostrar_lista (pnodo lista);
void obtener_final (pnodo lista);
void menu(int &opcion);
void crear_nodo (pnodo &nuevo);

main()
{
    pnodo lista, eliminado, nuevo;
    int opcion;
    iniciar_lista (lista);
    do
    {
        menu(opcion);
        switch (opcion)
        {
            case 1: iniciar_lista(lista);
            cout<<endl;
            break;
            case 2: crear_nodo (nuevo);
            if(nuevo!=NULL)
            {
                agregar_final(lista, nuevo);
            }
            cout<<endl;
            break;
            case 3: mostrar_lista (lista);
            cout<<endl;
            break;
            case 4: obtener_final(lista);
            cout<<endl;
            break;
            case 5:
                cout<<"Fin del programa. "<<endl;
            break;
        }
    }
    while (opcion!=6);
}
void iniciar_lista (pnodo &lista)
{
    lista=NULL;
    cout<<"Lista inicializada con exito."<<endl;
}

void crear_nodo(pnodo &nuevo)
{
  nuevo =new nodo;
  if (nuevo!=NULL)
     { cout << "Ingrese valor: "<<endl;
       cin >> nuevo->dato;
       nuevo->sig=NULL;
     }
  else
     cout << "Memoria insuficiente" << endl;
}

void agregar_final(pnodo &lista, pnodo nuevo)
{
 if(lista==NULL){
        lista=nuevo;
    }else
    {
        if(lista->sig==NULL)
            {
            lista->sig=nuevo;
            }
        else{
            agregar_final(lista->sig,nuevo);
            }
    }

}

void mostrar_lista (pnodo lista)
{
    if (lista==NULL)
    {
        cout<<"Lista vacia"<<endl;
    }
    else
    {
        if (lista->sig==NULL){
            cout<<"Dato: "<<lista->dato<<endl;}
        else
        {
            mostrar_lista (lista->sig);
            cout<<"Dato: "<<lista->dato<<endl;
        }
    }

}

void obtener_final (pnodo lista)
{
    if (lista==NULL)
    {
        cout<<"Lista vacia"<<endl;
    }
    else
    {
        if (lista->sig==NULL)
            cout<<"Valor: "<<lista->dato<<endl;
        else
            obtener_final (lista->sig);
    }
}

void menu(int &opcion)
{
    cout<<"1: inicializar lista. "<<endl;
    cout<<"2: Agregar al final de la lista. "<<endl;
    cout<<"3: Mostrar lista. "<<endl;
    cout<<"4: Mostrar ultimo valor"<<endl;
    cout<<"5: Salir."<<endl;
    cin>>opcion;
}
