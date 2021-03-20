#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

typedef char t_cad[20];
struct formulario{
	t_cad nombre;
	t_cad apellido;
	t_cad calle;
	int numero;
	t_cad barrio;
	t_cad localidad;
	t_cad provincia;
};
typedef formulario vec[20];

main(){
	vec v1;
	int n,op;
	bool band1;
	char r;
	cout<<"cuantas personas dejan sus datos?"<<endl;
	cin>>n;
	
	for (int i=0;i<n;i++){
		cout<<"persona "<<i+1<<endl;
		cout<<"ingrese su nombre"<<endl;
		cin>>v1[i].nombre;
		cout<<"ingrese su apellido"<<endl;
		cin>>v1[i].apellido;
		cout<<"ingrese su calle"<<endl;
		cin>>v1[i].calle;
		cout<<"ingrese la numeracion"<<endl;
		cin>>v1[i].numero;
		cout<<"ingrese el barrio"<<endl;
		cin>>v1[i].barrio;
		cout<<"ingrese su localidad"<<endl;
		cin>>v1[i].localidad;
		cout<<"ingrese su provincia"<<endl;
		cin>>v1[i].provincia;
	}
	
	
	for(int t=0;t<n;t++){
		cout<<endl;
		cout<<"persona "<<t+1<<endl;
		cout<<endl;
		cout<<v1[t].nombre<<endl;
		cout<<v1[t].apellido<<endl;
		cout<<v1[t].calle<<endl;
		cout<<v1[t].numero<<endl;
		cout<<v1[t].barrio<<endl;
		cout<<v1[t].localidad<<endl;
		cout<<v1[t].provincia<<endl;
		cout<<endl;
	}
}
