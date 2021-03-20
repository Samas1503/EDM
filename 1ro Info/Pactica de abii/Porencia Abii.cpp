#include <iostream>
#include <string>
void ingreso(int &a, int &b);
int potencia (int a, int b);
using namespace std;
main(){
	int a,b;
	ingreso(a,b);
	cout<<potencia(a,b)<<endl;
	}
	void ingreso(int &a, int &b){
		cin>>a>>b;
	}
	int potencia(int a, int b){
		bool band=true;
		int cont=1,aux=a;
		do{
			cont++;
			a*=aux;
			if (cont==b) band=false;
		}
		while (band==true);
		return a;
	}
