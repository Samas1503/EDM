#include <iostream>
#include <string>

using namespace std;

const int MAX = 25;
const int MAX2 = 2;
const int MAX3 = 24;
const int MAX4 = 1000;
const int MAX5 = 60;

typedef char pal[MAX];

typedef int vec[MAX3];

struct fecha {
  int dia;
  int mes;
  int anio;
};
struct dom {
  pal calle;
  int num;
  pal localidad;
  pal provincia;
};
struct mozo {
  int leg;
  pal nom;
  pal ape;
  int DNI;
  fecha fecn;
  dom domicilio;
  pal e_mail;
  int tel_ref;
  int ocup;
  vec cant_mesas;
};
typedef mozo personal[MAX2];

typedef int ocupaciones[MAX3];

struct mesa {
  int num;
  int ocup;
  ocupaciones mozo_asig;
};

typedef mesa mesas[MAX3];

typedef bool num_mesa[MAX3];

struct ingr {
  pal nom;
  pal desc;
  int cant;
};
typedef ingr stock[MAX4];

typedef ingr ingr_p[MAX];

struct info {
  pal nom;
  int num_p;
  pal des;
  ingr_p lista_ingr;
  bool disp;
};

typedef info menu[MAX5];

void cambio (mozo &mozo1, mozo &mozo2);
void burbuja (personal &mozos);
void mostrar_ingredientes(stock ingr);
void mostrar_mozos(personal mozos);
void mostrar_numeros(num_mesa num);
void mostrar_mesas(mesas mesa);
void mostrar_menu(menu plats, int cant);
void mostrar_faltantes(stock faltantes);
void designar_ganador(personal &mozos);

void controlar_stock(menu &plat, stock &ingr, int n, int i, int e, stock &faltantes);

void agregar_datos_mozos(personal &mozos);
void agregar_datos_mesas(mesas &mesa, personal &mozos, num_mesa &numeros);
void agregar_datos_ingredientes(stock &ingr);
void agregar_datos_platos(menu &plat, stock &ingr, stock &faltantes, int &cant);

int main() {
  personal mozos;
  mesas mesa;
  stock ingr;
  stock faltantes;
  menu plat;
  num_mesa numeros;
  int op, cant;
  bool band1 = false, band2 = false, band3 = false, band4 = false;
  do{
    cout << "*********** Menu Principal*************" << endl;
    cout << "1. Mozos" << endl;
    cout << "2. Mesas" << endl;
    cout << "3. Stock" << endl;
    cout << "4. Carta" << endl;
    cout << "*********** ************** ************" << endl;
    cout << "Seleccione una las opciones segun el orden." << endl << "Opcion: ";
    cin >> op;
    switch (op) {
    case 1:
      agregar_datos_mozos(mozos);
      band1 = true;
      break;
    case 2:
      if (band1) {
        for (int i = 0; i < MAX3; i++)
          numeros[i] = false;
        agregar_datos_mesas(mesa, mozos, numeros);
        band2 = true;
      }else{
        cout<<"Debe seleccionar la opcion 1"<<endl;
      }
      break;
    case 3:
      if (band2) {
        agregar_datos_ingredientes(ingr);
        band3 = true;
      }else{
        cout<<"Debe seleccionar la opcion 2"<<endl;
      }
      break;
    case 4:
      if (band3) {
        for(int i=0;i<MAX4;i++){
            faltantes[i].cant=0;
        }
        agregar_datos_platos(plat, ingr, faltantes, cant);
        band4 = true;
      }else{
        cout<<"Debe seleccionar la opcion 3"<<endl;
      }
      break;
    default:
      cout << "Opcion Incorrecta";
    }
  }while(op!=4);
  op = 0;
  if (band4) {
    do {
      cout << "******************* Consultas *********************" << endl;
      cout << "1. Listar Mesas" << endl;
      cout << "2. Listar Carta disponible" << endl;
      cout << "3. Listar ingredientes faltantes" << endl;
      cout << "4. Premio" << endl;
      cout << "5. Salir" << endl;
      cout << "*********** ************** ************ ************" << endl;
      switch (op) {
      case 1:
        mostrar_mesas(mesa);
        break;
      case 2:
        mostrar_menu(plat,cant);
        break;
      case 3:
        mostrar_faltantes(faltantes);
        break;
      case 4:
        designar_ganador(mozos);
        break;
      case 5:
        cout << "Saliendo. Gracias por usar el Sistema InfoRestorant Abigail "
                "Cazon"
             << endl;
        break;
      default:
        cout << "Option Incorrecta" << endl;
      }
    } while (op != 5);
  }
}

void cambio (mozo &mozo1, mozo &mozo2){
    mozo aux;
    aux=mozo1;
    mozo1=mozo2;
    mozo2=aux;
}
void burbuja (personal &mozos){
    bool band=false;
    while(!band){
        band=true;
        for(int i=0;i<MAX2-1;i++){
            if(mozos[i].ocup > mozos[i+1].ocup){
                cambio(mozos[i],mozos[i+1]);
                band=false;
            }
        }
    }
}
void mostrar_ingredientes(stock ingr, int max) {
  int i = 0;
  while(i!=max){
    cout << i + 1 << ". " << ingr[i].nom << "  ";
    if (i + 1 % 10 == 0)
      cout << endl;
    i++;
  }
    cout << "Estos son todos los ingredientes Disponibles" << endl;
}
void mostrar_mozos(personal mozos) {
  int i = 0;
  while (i != MAX2) {
    cout << "mozo " << i + 1 << ": " << endl;
    cout << "Nombre: " << mozos[i].nom << " Legajo: " << mozos[i].leg << endl;
    i++;
  }
}
void mostrar_numeros(num_mesa num) {
  int i = 0;
  while (i != MAX3) {
    if (num[i] == true)
      cout << i + 1 << " ";
    i++;
  }
}
void mostrar_mesas(mesas mesa) {
  int i = 0;
  while (i != MAX3) {
    cout << "Numero: " << mesa[i].num << endl;
    cout << "Se ocupo " << mesa[i].ocup << " veces la mesa" << endl;
    for (int e = 0; e < mesa[i].ocup; i++) {
      cout << "En la ocacion " << e + 1 << " el mozo con legajo";
      cout << mesa[i].mozo_asig[e] << " atendio la mesa" << endl;
    }
    i++;
  }
}
void mostrar_menu(menu plats, int cant) {
  int i = 0, e = 0;
  while (i < MAX5) {
    if (plats[i].disp) {
      cout << "Platillo " << plats[i].num_p << ": " << endl;
      cout << "Nombre: " << plats[i].nom << endl;
      cout << "Descripcion: " << plats[i].des << endl;
      cout << "Contiene " << cant << " ingredientes: " << endl;
      while (e != cant - 1) {
        cout << plats[i].lista_ingr[e].cant << " de ";
        cout << plats[i].lista_ingr[e].nom << " ";
        cout << plats[i].lista_ingr[e].desc << endl;
        e++;
      }
      i++;
    }
  }
}
void mostrar_faltantes(stock faltantes){
    int i=0,e=1;
    while(i!=MAX4){
        cout<<"Los ingredientes que faltan son: "<<endl;
        if(faltantes[i].cant>0){
            cout<<e<<". "<<faltantes[i].cant<<" "<<faltantes[i].nom<<": "<<faltantes[i].desc<<endl;
            e++;
        }
        i++;
    }
}
void designar_ganador(personal &mozos){
    burbuja(mozos);
    cout<<"El mozo ganador es: "<<endl;
    cout<<"Nombre: "<<mozos[MAX-1].nom<<endl;
    cout<<"Apellido: "<<mozos[MAX-1].ape<<endl;
    cout<<"Provincia: "<<mozos[MAX-1].domicilio.provincia<<endl;
    cout<<"Obtuvo "<<mozos[MAX-1].ocup<<" ocupaciones."<<endl;
}

void controlar_stock(menu &plat, stock &ingr, int n, int i, int e, stock &faltantes) {
  int acum;
  if (ingr[n].cant - plat[i].lista_ingr[e].cant > 0) {
    ingr[n].cant -= plat[i].lista_ingr[e].cant;
    plat[i].disp = true;
  } else {
    acum = (ingr[n].cant - plat[i].lista_ingr[e].cant) * (-1);
    faltantes[n] = plat[i].lista_ingr[e];
    faltantes[n].cant = acum;
    plat[i].disp = false;
  }
}

void agregar_datos_mozos(personal &mozos) {
  int i=0;
  while (i != MAX2) {
    cout << "Ingrese el legajo del mozo " << i + 1 << ": ";
    cin >> mozos[i].leg;
    cout << endl;
    cout << "Ingrese el nombre del mozo " << i + 1 << ": ";
    cin>>mozos[i].nom;
    cout << endl;
    cout << "Ingrese el apellido del mozo " << i + 1 << ": ";
    cin>>mozos[i].ape;
    cout << endl;
    cout << "Ingrese el DNI del mozo " << i + 1 << ": ";
    cin >> mozos[i].DNI;
    cout << endl;
    cout << "Ingrse la fecha de nacimiento del mozo " << i + 1 << ": ";
    cout<<endl;
    cout << "Dia: " << endl;
    cin >> mozos[i].fecn.dia;
    cout << "Mes: " << endl;
    cin >> mozos[i].fecn.mes;
    cout << "Año: " << endl;
    cin >> mozos[i].fecn.anio;
    cout << "Ingrese el domicilio del mozo " << i + 1 << ": " << endl;
    cout << "Calle: ";
    cin>>mozos[i].domicilio.calle;
    cout << endl;
    cout << "Numero: ";
    cin >> mozos[i].domicilio.num;
    cout << endl;
    cout << "Localidad: ";
    cin>>mozos[i].domicilio.localidad;
    cout << endl;
    cout << "Provincia: ";
    cin>>mozos[i].domicilio.provincia;
    cout << endl;
    cout << "Ingrese el E-Mail del mozo " << i + 1 << ": ";
    cin >> mozos[i].e_mail;
    cout << endl;
    cout << "Ingrese un Telefono de referencia del mozo " << i + 1 << ": ";
    cin >> mozos[i].tel_ref;
    for (int e = 0; e < MAX3; e++)
      mozos[i].cant_mesas[e] = 0;
    mozos[i].ocup = 0;
    i++;
  }
  cout << "Datos agregados correctamente" << endl;
}
void agregar_datos_mesas(mesas &mesa, personal &mozos, num_mesa &numeros) {
  int i = 0, e = 0, p, num;
  bool band = false;
    cout << "Datos agregados correctamente" << endl;
  do{
    do {
      cout << "Ingrese el numero que desea agregar a las mesas." << endl;
      cout << "Mesa: ";
      cin >> num;
      if (!numeros[num - 1]) {
        mesa[num - 1].num = num;
        band = true;
      } else {
        cout << "Debe ingresar otro numero entre 1 y 24" << endl;
        cout << "Disponibles: " << endl;
        mostrar_numeros(numeros);
      }
    } while (!band);
    cout << endl;
    cout << "Cuantas veces se ocupo la mesa " << mesa[num - 1].num << ": ";
    cin >> mesa[num - 1].ocup;
    cout << endl;
    if (e != mesa[num - 1].ocup) {
      cout << "A que mozos se le asigno esta mesa en la ocacion " << e + 1
           << "?" << endl;
      mostrar_mozos(mozos);
      cin >> p;
      if (mozos[p - 1].ocup != MAX3) {
        mesa[num - 1].mozo_asig[e] = mozos[p - 1].leg;
        mozos[p - 1].cant_mesas[mozos[p - 1].ocup] = mesa[num - 1].num;
        mozos[p - 1].ocup++;
      }
      e++;
    }
    i++;
  }while(i!=MAX3);
  cout << "Datos agregados correctamente" << endl;
}
void agregar_datos_ingredientes(stock &ingr) {
  int i = 0;
  while (i != MAX4) {
    cout << "Ingrdiente " << i + 1 << ": " << endl;
    cout << "Ingrese el nombre del inngrediente: ";
    cin >> ingr[i].nom;
    cout << "Ingrese la descricpcion del ingrediente: " << endl;
    cin >> ingr[i].desc;
    cout << endl;
    cout << "Ingrese la cantidad disponible del ingrediente: ";
    cin >> ingr[i].cant;
    cout << endl;
    i++;
  }
  cout << "Datos agregados correctamente" << endl;
}
void agregar_datos_platos(menu &plat, stock &ingr, stock &faltantes, int &cant) {
  int i = 0, e = 0, cant2, num;
  char r;
  bool band;
  while (i != MAX5) {
    cout << "Ingrese el nombre del platillo: " << endl;
    cin >> plat[i].nom;
    plat[i].num_p = i + 1;
    cout << "Ingrese una descripcion del platillo " << i + 1 << ": " << endl;
    cin >> plat[i].des;
    mostrar_ingredientes(ingr, MAX4);
    cout << "Cuantos ingredientes lleva el platillo?" << endl;
    cin >> cant;
    if (e == cant - 1) {
      e = 0;
      cout << "Ingredientes cargados correctamente" << endl;
      cout << "Los ingredientes que lleva son:" << endl;
      if (e == cant - 1) {
        cout << "Listado completo" << endl;
      } else {
        cout << e + 1 << ". " << plat[e].nom << endl;
        e++;
      }
    } else {
      cout << "Seleccione los ingredientes necesarios que estan en la lista "
              "anterior"
           << endl;
      cout << "Ingrediente " << e + 1 << ": ";
      cin >> num;
      plat[i].lista_ingr[e] = ingr[num - 1];
      cout << "Que cantidad necesita para el platillo?" << endl;
      cin >> cant2;
      plat[i].lista_ingr->cant = cant2;
      controlar_stock(plat, ingr, num, i, e, faltantes);
      e++;
    }
    i++;
  }
  cout << "Datos agregados correctamente" << endl;
}
