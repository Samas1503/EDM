#include <iostream>
#include <string>

const int vec=5,fila=4,columna=4;

using namespace std;

typedef int vectorn [vec],matrizn[fila][columna];

typedef char vectorc [vec],matrizc[fila][columna];

void agregar (vectorn v1,int &ocup);
void insertar (vectorn v1, int n, int &ocup);
void mostrar (vectorn v1);
void mostrar_pares (vectorn v1);
void mostrar_impares (vectorn v1);
void borrar(vectorn v1,int goma,int ocup);
void copiar (vectorn v1, vectorn v2);
void contar (vectorn v1,int &c1, int &c2, int &c3);
int determinar (vectorn v1);
float promedio (vectorn v1);
int suma (vectorn v1);
int resta (vectorn v1);
int multiplicacion (vectorn v1);

void agregar (matrizn m1,int &ocup);
void mostrar (matrizn m1);
void mostrar_pares (matrizn m1);
void mostrar_impares (matrizn m1);
void borrar(matrizn m1,int goma,int ocup);
void copiar (matrizn m1, vectorn v2);
void contar (matrizn m1,int &c1, int &c2, int &c3);
int determinarm (matrizn m1);
float promedio (matrizn m1);
int suma (matrizn m1);
int resta (matrizn m1);
int multiplicacion (matrizn m1);


main(){
	
	char a,r;
	int o,c1=0,c2=0,c3=0,n,ocup=0,goma,m=0;
	bool band=true,band2=false;
	vectorn v1,v2;
	matrizn m1,m2;
	cout<<"Vectores, Matrices o MultiDimencionales? :v/ v/m/d \v:"<<endl;
	cin>>a;
	for (int i=0;i<vec;i++)
		v1[i]=0;
	switch (a){
		case 'v':
				do{
					cout<<"Que desea hacer?"<<endl<<cout<<"1.Agregar"<<endl;
					cout<<"2.Insertar"<<endl<<cout<<"3.Mostrar"<<endl;
					cout<<"4.Borrar"<<endl<<cout<<"5.Copiar"<<endl;
					cout<<"6.Promedio"<<endl<<cout<<"7.Suma"<<endl;
					cout<<"8.Resta"<<endl<<cout<<"9.multiplicacion"<<endl;
					cout<<"10.Contar"<<endl<<cout<<"11.Determinar mayor"<<endl;
					
					cout<<"0.Salir"<<endl;
					cin>>o;
					switch (o){
						case 1:
								agregar (v1,ocup);
							break;
						case 2:
								cout<<"ingrese un numero: "<<endl;
								cin>>n;
								insertar (v1,n,ocup);
							break;
						case 3:
								cout<<"Todos: ";mostrar(v1);cout<<" ";cout<<endl;
								cout<<"Pares: ";mostrar_pares(v1);cout<<" ";cout<<endl;
								cout<<"Impares: ";mostrar_impares(v1);cout<<" ";cout<<endl;
									band=false;
							break;
						case 4:
									cin>>goma;
									borrar(v1,goma,ocup);
									band=false;
							break;
						case 5:
									copiar(v1,v2);
									band=false;
							break;
						case 6:
								cout<<promedio(v1)<<" ";
								cout<<endl;
									band=false;
							break;
						case 7:
								cout<<suma(v1)<<" ";
								cout<<endl;
									band=false;
							break;
						case 8:
								cout<<resta(v1)<<" ";
								cout<<endl;
									band=false;
							break;
						case 9:
								cout<<multiplicacion(v1)<<" ";
								cout<<endl;
									band=false;
							break;
						case 10:
									contar(v1,c1,c2,c3);
									cout<<"Total"<<c1<<" "<<endl;
									cout<<"Pares"<<c2<<" "<<endl;
									cout<<"Impares"<<c3<<" "<<endl;
									band=false;
							break;
						case 11:
								cout<<"El mayor es "<<determinar (v1);
							break;
						case 0:
									cout<<"Gracias por cooperar"<<endl;
									band=false;
							break;
						default:
								cout<<"error"<<endl;
					}
					cout<<"Deseas hacer algo mas?? s/n"<<endl;
					cin>>r;
					if (band==false)
						if (r=='n' || r=='N')
							band2=true;
				}
				while (band2==false);		
				break;
		case 'm':
				do{
					cout<<"Que desea hacer?"<<endl<<cout<<"1.Agregar"<<endl;
					cout<<"2.Mostrar"<<endl<<cout<<"3.Copiar"<<endl;
					cout<<"4.Promedio"<<endl<<cout<<"5.Suma"<<endl;
					cout<<"6.Resta"<<endl<<cout<<"7.multiplicacion"<<endl;
					cout<<"8.Contar"<<endl<<cout<<"9.Determinar mayor"<<endl;
					
					cout<<"0.Salir"<<endl;
					cin>>o;
					switch (o){
						case 1:
								agregar (m1,ocup);
							break;
						case 2:
								cout<<"Todos: ";mostrar(v1);cout<<" ";cout<<endl;
								cout<<"Pares: ";mostrar_pares(v1);cout<<" ";cout<<endl;
								cout<<"Impares: ";mostrar_impares(v1);cout<<" ";cout<<endl;
									band=false;
							break;
						case 3:
									copiar(m1,v2);
									band=false;
							break;
						case 4:
								cout<<promedio(m1)<<" ";
								cout<<endl;
									band=false;
							break;
						case 5:
								cout<<suma(m1)<<" ";
								cout<<endl;
									band=false;
							break;
						case 6:
								cout<<resta(m1)<<" ";
								cout<<endl;
									band=false;
							break;
						case 7:
								cout<<multiplicacion(m1)<<" ";
								cout<<endl;
									band=false;
							break;
						case 8:
									contar(m1,c1,c2,c3);
									cout<<"Total"<<c1<<" "<<endl;
									cout<<"Pares"<<c2<<" "<<endl;
									cout<<"Impares"<<c3<<" "<<endl;
									band=false;
							break;
						case 9:								
								cout<<"El mayor es "<<determinarm (m1);
							break;
						case 0:
									cout<<"Gracias por cooperar"<<endl;
									band=false;
							break;
						default:
								cout<<"error"<<endl;
					}
					cout<<"Deseas hacer algo mas?? s/n"<<endl;
					cin>>r;
					if (band==false)
						if (r=='n' || r=='N')
							band2=true;
				}
				while (band2==false);
				
				break;
		default:
				cout<<"error"<<endl;
	}
}

void agregar (vectorn v1,int &ocup){	
	for(int i=0;i<vec;i++){
		cin>>v1[i];
		ocup++;}
	cout<<ocup<<endl;
}
void insertar (vectorn v1, int n, int &ocup){
	int i,j;
	if (ocup==vec)
		cout<<"Vector Completo....."<<endl;
	else{
		i=-1;
		while (i<ocup && v1[i]<n)
			i++;
		j=ocup;
		while (j>=i){
			v1[j+1]=v1[j];
			j--;
		}
		v1[i]=n;
		ocup++;
		}
}
void mostrar (vectorn v1){
	for (int i=0;i<vec;i++)
		cout<<v1[i]<<" ";
}
void mostrar_pares (vectorn v1){
	for (int i=0;i<vec;i++){
		if (v1[i]%2==0)
			cout<<v1[i]<<" ";
	}
}
void mostrar_impares (vectorn v1){
	for (int i=0;i<vec;i++){
		if (v1[i]%2!=0)
			cout<<v1[i]<<" ";
	}
}
void borrar(vectorn v1,int goma,int ocup){
	int i;
	bool encontrado;
	if (ocup==0)
		cout<<"el vector no contiene elementos"<<endl;
	else{
		encontrado=false;
		i=0;
		while (i<=ocup && encontrado==false){
			if (goma=v1[i])
				encontrado=true;
			else
			i++;
		}
		if (encontrado=true){
			while (i<ocup){
				v1[i]=v1[i+1];
				i++;
				v1[ocup]=0;
			}
			ocup--;
		}
		else 
			cout<<"el elemento no existe"<<endl;
	}
	for (int i=0;i<vec;i++){
		cout<<v1[i]<<" ";
	}
}
void copiar (vectorn v1, vectorn v2){
	for (int i=0;i<vec;i++)
		v2[i]=v1[i];
	for (int i=0;i<vec;i++)
		cout<<v2[i]<<" ";
}
void contar (vectorn v1,int &c1, int &c2, int &c3){
	for (int i=0;i<vec;i++){
			c1++;
		if (v1[i]%2==0)
			c2++;
		else
			c3++;
	}
}
int determinar (vectorn v1){
	int m=0;
	for(int i=0;i<vec;i++){
		if (v1[i]>m)
			m=v1[i];
	}
return m;
}
float promedio (vectorn v1){
	int s=0,p;
	for (int i=0;i<vec;i++)
		s+=v1[i];
	p=s/vec;
	return p;	
}
int suma (vectorn v1){	
	int s;
	for(int i=0;i<vec;i++)
		s+=v1[i];
	return s;
}
int resta (vectorn v1){
	int r=v1[0];
	for(int i=1;i<vec;i++)
		r-=v1[i];
	return r;
}
int multiplicacion (vectorn v1){
	int r=1;
	for(int i=0;i<vec;i++)
		r*=v1[i];
	return r;
}

void agregar (matrizn m1,int &ocup){
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
		cin>>m1[i][e];
		ocup++;
		}
	}
	cout<<ocup<<endl;
}
void mostrar (matrizn m1){
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++)
			cout<<m1[i][e];
	}
}
void mostrar_pares (matrizn m1){
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
			if (m1[i][e]%2==0)
				cout<<m1[i][e];
		}
	}
}
void mostrar_impares (matrizn m1){
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
			if (m1[i][e]%2!=0)
				cout<<m1[i][e];
		}
	}
}
void copiar (matrizn m1, vectorn v2){
	int c=0;
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
			v2[c]=m1[i][e];
			c++;
		}
	}
	for (int i=0;i<c;i++)
		cout<<v2[c];
}
void contar (matrizn m1,int &c1, int &c2, int &c3){
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
				c1++;
			if (m1[i][e]%2==0)
				c2++;
			if (m1[i][e]%2!=0)
				c3++;
		}
	}
}
int determinarm (matrizn m1){
	int m=0;
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
			if (m1[i][e]>m)
				m=m1[i][e];
		}
	}
	return m;
}
float promedio (matrizn m1){
	int a=0,c=0;
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
			a+=m1[i][e];
			c++;
		}
	}
	a/=c;
	return a;
}
int suma (matrizn m1){
	int a=0;
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
			a+=m1[i][e];
		}
	}
	return a;
}
int resta (matrizn m1){
	int a;
	a=m1[0][0];
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
			a-=m1[i][e];
		}
	}
}
int multiplicacion (matrizn m1){
	int a=1;
	for(int i=0;i<fila;i++){
		for (int e=0;e<columna;e++){
			a+=m1[i][e];
		}
	}
}
