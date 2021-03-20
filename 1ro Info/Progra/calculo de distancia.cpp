#include <iostream>
#include <string>

using namespace std;

float calculo (float v, float t){
	float r;
	return r=v*t;
}

main(){
	float v,t;
	cout<<"ingrese la velocidad en km/h"<<endl;
	cin>>v;
	cout<<"ingrese el tiempo en h"<<endl;
	cin>>t;
	cout<<"la distancia es "<<calculo(v,t)<<" kilometros"<<endl;
}
