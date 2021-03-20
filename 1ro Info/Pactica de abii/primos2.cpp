#include <iostream> //Colocar.h en TC++
#include <conio.h>
#define max 100
   
     using namespace std; //Eliminar esta linea en TC++
    main (){
    int a[max],b[max],i,j=0,n,div,t=0;
 cout<<"Ingrese las dimensiones del arreglo: ";
 cin>>n;
  system("cls");
 for (i=0; i<n;i++)
 {
  cout<<"Ingrese el  elemento nro "<<i+1<<" del arreglo: ";
  cin >>a[i];
 
 }
  for(i=0; i<n;i++)
 {div=2;
  while(div<a[i] && a[i]%div>0) // Determinando si es primo
   div++;
  if(div==a[i]){          
       b[j++]=a[i];
       t++; //Contador para saber si encontró al menos un numero primo
       }
 }
 if(t>0){
    cout<<"\nLos numeros primos de su arreglo son:"<<endl;
    for(i=0;i<j;i++)
    cout<<b[i]<<" ";
    }else cout<<"\nNo hay numeros primos en su arreglo";

 getch();
 }
