#include <iostream>
#include <string>
void ingreso_datos(int &x, int &y);
int division(int x, int y);

using namespace std;
int main(){ 
	int a,b;
	ingreso_datos(a,b);
	cout<<division(a,b)<<endl;
}
	void ingreso_datos (int &x, int &y){
		cin>>x>>y;
	}
	int division (int x, int y){
		int r=0;
		do{
			if (x>=y)r++
			x-=y
			}
		while (x>=y);
		return r;
	}
