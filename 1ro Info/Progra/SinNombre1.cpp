#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

typedef char pal[20];

struct fecha{
	int dia;
	int mes;
	int anio;
};

struct juegos{
	pal categoria;
	pal nombre;
	fecha dia;
	fecha mes;
	fecha anio;
};

typedef juegos vector[2];

using namespace std;

int main(){

	int n,o;
	char r;
	cin>>n;
	vector v;
	for (int i=0;i<n;i++){
		cin>>v1[i].nombre;
		cin>>v1[i].categoria;
		cin>>v1[i].dia>>v1[i].mes>>v1[i].anio;
	}
	cout<<"como desea ordenarlos?"<<endl<<"1.dia "<<endl<<"2.mes "<<endl<<"3.fecha"<<enld
	cin>>o;
	switch (o){
		case 1: 
				sort(v1.nombre.begin(),v1.nombre.end());
		break;
		case 2:
				sort(v1.categoria.begin(),v1.categoria.end());
		break;
		case 3:
				sort(v1.fecha.anio.begin();v1.fecha.anio.end())
		break;
		deafault:
				cout<<"error"<<endl
	}
}
