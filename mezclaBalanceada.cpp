#include <iostream>
#include <cstdlib>

using namespace std;

void leerArreglo (int a[], int n);
void mostrarArreglo (int a[], int n);
void mBalanceada(int *A,int n);
void mezcla(int *izq,int nIzq,int *der,int nDer,int *A);

int main(){

    int n;
    cout<<"Ingrese el numero de elementos del arreglo: ";
    cin>>n;
    int arreglo[n];
    leerArreglo(arreglo,n);
    mBalanceada(arreglo,n);
    cout<<"Arreglo Ordenado"<<endl;
    mostrarArreglo(arreglo,n);
}

void leerArreglo (int a[], int n){
    int i;
    for(i=0;i<n;i++){
        cout<<"Ingrese el elemento "<<i+1<<" del arreglo: ";
        cin>>a[i];
    }
}

void mostrarArreglo (int a[], int n){
    for(int i=0;i<n;i++)
        cout<<" "<<a[i];
}

void mBalanceada(int *A,int n){
    if(n==1){return;}
    int mitad = n / 2;
    int *izq = new int[mitad];
    int *der = new int[n-mitad];
    for(int i=0;i<mitad;i++)
        izq[i] = A[i];
        for(int i=mitad;i<n;i++)
            der[i-mitad] = A[i];
    mBalanceada(izq, mitad);
    mBalanceada(der, n-mitad);
    mezcla(izq, mitad, der, n-mitad, A);

}

void mezcla(int *izq,int nIzq,int *der,int nDer,int *A){
    int i=0,j=0,k=0;
    while( ( i < nIzq ) && ( j < nDer ) ){
            if( izq[i] <= der[j]){
                A[k] = izq[i];
    i++;
    }
    else{
            A[k] = der[j];
    j++;
    }
    k++;
    }
    while(i < nIzq){
            A[k] = izq[i];
    i++;
    k++;
    }
    while(j < nDer){
        A[k] = der[j];
    j++;
    k++;
    }

}
