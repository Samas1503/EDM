#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
typedef struct nodo *pnodo;
struct nodo{
    string dato;
    pnodo sig;
};
string meses(int m){
    if(m==0) return "Diciembre";
    if(m==1) return "Noviembre";
    if(m==2) return "Octubre";
    if(m==3) return "Septiembre";
    if(m==4) return "Agosto";
    if(m==5) return "Julio";
    if(m==6) return "Junio";
    if(m==7) return "Mayo";
    if(m==8) return "Abril";
    if(m==9) return "Marzo";
    if(m==10) return "Febrero";
    if(m==11) return "Enero";
}
void mostrar(pnodo lista){
    if(lista == NULL)
        cout<<"Lista vacia"<<endl;
    else{
        pnodo p=lista;
        while(p!=NULL){
            cout<<p->dato<<' '<<endl;
            p=p->sig;
        }
        cout<<endl;
    }
}
void modificar (pnodo &lista,string mod){
    int cont=0;
    pnodo p=lista,nlis;
    while(p!=NULL&&p->dato!=mod&&cont<12){
        lista=lista->sig;
        p->sig=NULL;
        nlis=p;
        p=lista;
        while(p->sig!=NULL)
        {p=p->sig;}
        p->sig=nlis;
        cont++;
        p=lista;
    }
}
int main(){
    pnodo lista=NULL,aux;
    for(int i=0;i<12;i++){
        aux=new nodo;
        aux->dato=meses(i);
        aux->sig=NULL;
        aux->sig=lista;
        lista=aux;

    }
    mostrar(lista);
    string mod;
    cout<<"elija el mes con el cual modificar la lista: "<<endl;
    cin>>mod;
    if(mod[0]>=97 && mod[0]<=122)
    	mod[0]-=32;
    for(int i=1;i<mod.size();i++){
    	if(mod[i]>=65 && mod[i]<=90)
    		mod[i]+=32;
	}
    cout<<endl;
    cout<<"La lista quedo de la siguiente forma: "<<endl;
    modificar(lista,mod);
    mostrar(lista);
}
