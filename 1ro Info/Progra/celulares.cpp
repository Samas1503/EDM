#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef char pal[50];
const int c=0;
void cantidad (int c){
	cout<<"cuantos  celulares desea registrar?"<<endl;
	cin>>c;
}
const int d=c;
struct celular{
	pal marca;
	pal modelo;	
};
struct caracteristicas{
	pal procesador;
	int ram;
	int memoria;
	int camara;
	pal resolucion1;
};
main(){
	cantidad(c);
	celular <vector> v1(c);
	caracteristicas <vector> v2(c);
	for (int i=0;i<c;i++){
		cout<<"ingrese marca"<<endl;
		cin>>a[i].marca;
		cout<<"ingrese modelo"<<endl;
		cin>>a[i].modelo;
		cout<<"ingrese procesador"<<endl;
		cin>>b[i].procesador;
		cout<<"ingrese cantidad de ram"<<endl;
		cin>>b[i].ram;
		cout<<"ingrese capacidad de memoria"<<endl;
		cin>>b[i].memoria;
		cout<<"ingrese calidad de camara"<<endl;
		cin>>b[i].camara;
		cout<<"ingrese la resolucion de pantalla"<<endl;
		cin>>b[i].resolucion1;
	}
	for (int i=0;i<c;i++){
		cout<<a[i].marca<<endl;
		cout<<a[i].modelo<<endl;
		cout<<b[i].procesador<<endl;
		cout<<b[i].ram<<endl;
		cout<<b[i].memoria<<endl;
		cout<<b[i].camara<<endl;
		cout<<b[i].resolucion1<<endl;
	}
}
