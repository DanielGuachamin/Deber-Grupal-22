#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//prototipos y ejercicio 1
void ejer1();
#define LONG_MAX 6
using namespace std;
void obtenerValores (float [], int);
void intercambiaValores (float [], float[], int );
void imprimirValores (float [], int);

//prototipos y ejercicio 2 
void ejer2();
void algoritmoseleccion(int a[], int n) ;
void ingresar(int a[],int n);
void imprimir(int a[],int n);

//prototipos y ejercicio 3
void ejer3();
double ingresoP(int n,int m, string c);
string meses(int a);
int menu();

int main() {
  int opcion;
  cout << "\t\t\tTRABAJO EN GRUPO" << endl << endl;
  cout << "\tALGORITMOS Y ESTRUCTURAS DE DATOS" << endl << endl;
  do
  {  
    opcion = menu(); 
    switch (opcion)
    {
      case 1:
      {
        ejer1();
      break;
      }
      case 2:
      {
        ejer2();
      break;
      }
      case 3:
      {
        ejer3();
      break;
      }
    }
  }while (opcion != 4);
  cout << "\nGRACIAS POR USAR NUESTRO SERVICIO" << endl;
  
  return 0;
}
//Funcion menu
int menu()
{
  int op;
  do
  {
    cout << "\n\tSELECCIONE UNA OPCIÓN DEL MENÚ" << endl << endl;
    cout << "1. INTERCAMBIAR POSICIONES DE UN VECTOR" << endl;
    cout << "2. ORDENAMIENTO DE UN VECTOR" << endl;
    cout << "3. CUENTA DE AHORROS VIRTUAL DEL BANCO PICHINCHA" << endl;
    cout << "4. SALIR" << endl;
    cout << "OPCION: ";
    cin >> op;
    if ((op < 1) || (op > 4))
    {
      cout << "\nEliga una opción correcta" << endl;
    }
  }while ((op < 1) || (op > 4));
  return op;
}
//Ejercicio 1 y sus funciones
void ejer1()
{
  ofstream Intercambiar;
  int n=6, x;
  float vo[LONG_MAX], vi[LONG_MAX];
  Intercambiar.open("intercambiar", ios::out);
  if(Intercambiar.is_open())
  {
    cout << "Ingreso de valores: " <<endl;
    obtenerValores (vo, n);
    for (x = 0; x < n; x++)
    {
      Intercambiar << "Valor ingresado[" << x + 1 << "]: " << vo[x] << '\n';
    }
    Intercambiar << "Vector Original: ";
    cout << "Vector Original: " <<endl;
    imprimirValores (vo, n);
    for (x = 0; x < n; x++)
    {
      Intercambiar << vo[x] << " ";
    }
    cout <<endl;
    cout << "Vector Intercambiado: " << endl;
    intercambiaValores(vo, vi, n);
    Intercambiar << "\nVector Intercambiado: ";
    imprimirValores(vi, n);
    for (x = 0; x < n; x++)
    {
      Intercambiar << vi[x] << " ";
    }
    Intercambiar.close();
  }
  else
  {
    cout << "El archivo no abrio exitosamente" << endl;
  }
}
void obtenerValores (float valores [], int n)
{
  int i, j=0;
  for (i=0; i<n; i ++)
  {
    cout << "Valor " <<j+1 <<":";
    cin >> valores [i];
    j++;
  }
}
void intercambiaValores (float valores [], float valoresIntercabiados[], int n)
{
  int i;
  for (i=0; i<n; i++)
  {
    valoresIntercabiados[i] = valores [n-1-i];
  }
}
void imprimirValores (float valores [], int n){
  int i;
  for(i=0; i<n; i++)
  {
    cout << valores [i] << " ";
  }
}
// Ejercicio 2 y sus funciones
void ejer2()
{
  ofstream Ordenamiento;
  int arreglo[100];
  int n=0, x;
  Ordenamiento.open("ordenamiento", ios::out);
  if (Ordenamiento.is_open())
  {
    cout << "INGRESE EL TAMANIO:";
    cin >> n;
    Ordenamiento << "El tamaño del arreglo es: " << n <<'\n';
    ingresar(arreglo,n);
     for (x = 0; x < n; x++)
    {
      Ordenamiento << "Valor ingresado[" << x + 1 << "]: " << arreglo[x] << '\n';
    }
    cout << endl;
    cout << "Los numeros ingresados son: ";
    imprimir(arreglo,n);
    Ordenamiento << "Los numeros ingresados son: ";
    for (x = 0; x < n; x++)
    {
      Ordenamiento << arreglo[x] << " ";
    }
    cout << endl;
    algoritmoseleccion(arreglo,n);
    cout << endl;
    cout << "Los numeros ordenados son :";
    imprimir(arreglo,n);
    Ordenamiento << "\nLos numeros ordenados son: ";
    for (x = 0; x < n; x++)
    {
      Ordenamiento << arreglo[x] << " ";
    }
    Ordenamiento.close();
  }
  else
  {
    cout << "El archivo no abrio exitosamente" << endl;
  }
}
void ingresar(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    cout<<"Ingrese el elemento al arreglo[" << i+1 << "]: ";
    cin>>a[i];
  }
}
void imprimir(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    cout<<a[i]<<" , ";
  }
}

void algoritmoseleccion(int a[], int n)  
{
  int i ,j, aux,min ;
  for(i=0;i<n;i++) //recorrer arreglo
  {
    min=i;
    for(j=i+1;j<n;j++ )
    {
      if(a[j]<a[min])
      {
        min=j;
      }
    }
    aux=a[i];
    a[i]=a[min];
    a[min]=aux;
  }
}
//Ejercicio 3 y sus funciones
void ejer3()
{
  int op=0;
  ofstream Cuenta;
  string Mes;
  Cuenta.open("cuenta", ios::out);
  if (Cuenta.is_open())
  {
    double mes[12],val;
    for (int i=0; i<12; i++)
    {
      cout << "Mes " << meses(i) << endl;
      Mes = meses(i);
      Cuenta << "Mes " << Mes << '\n';
      mes[i]=ingresoP(-1, 1410065408, "Ingrese el valor a depositar en dólares: ");
      Cuenta << "Valor ingresado en el mes " << Mes << ": " << mes[i]<< '\n';
    }
    val=ingresoP(-1, 1410065408, "Ingrese el valor en dólares que desea buscar: ");
    Cuenta << "El valor en dólares que se desea buscar: " << val;
    for(int i=0; i<12; i++)
    {
    if(mes[i]==val)
      {
        cout << "\nSe encontró el dinero en el mes de " << meses(i) << endl;
        op=1;
        Cuenta << "\nSe encontró el dinero en el mes de " << meses(i);
      }
    } 
    if(op==0)
    {
      cout<<"\nEl valor de dinero ingresado no existe en la cuenta"<<endl;
      Cuenta << "\nEl valor de dinero ingresado no existe en la cuenta"; 
    }
  }
  else
  {
    cout << "El archivo no abrio exitosamente" << endl;
  }
  Cuenta.close();
}
string meses(int a)
{
  string b;
  switch (a) 
  {
    case 0:
      b= "Enero";
      break;
    case 1:
      b= "Febrero";
      break;
    case 2:
      b= "Marzo";
      break;
    case 3:
      b= "Abril";
      break;
    case 4:
      b= "Mayo";
      break;
    case 5:
      b= "Junio";
      break;
    case 6:
      b= "Julio";
      break;
    case 7:
      b= "Agosto";
      break;
    case 8:
      b= "Septiembre";
      break;
    case 9:
      b= "Octubre";
      break;
    case 10:
      b= "Noviembre";
      break;
    case 11:
      b= "Diciembre";
      break;
    }
  return b;
}
double ingresoP(int n,int m, string c)
{
  int op = 0;
  double a;
  while(op == 0)
  {
    cout << c;
    cin >> a;
    if(a>n && a<=m)
    {
      op=1;
    }
    else
    {
      cout<<"El valor ingresado no es correcto"<<endl;
    }
  }
  return a;
}