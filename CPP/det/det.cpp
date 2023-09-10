#include <stdio.h>
#include <iostream>

using namespace std;
void mallocMatrix(int n,double** array);
int main(){


    int n;
    cout<<"insere a ordem da matriz"<<endl;
    cin>>n;
    double** array;
    mallocMatrix(n,array);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            cout<<array<<" ";
        }
        cout<<endl;
    }
}


void mallocMatrix(int n,double** array){

array=(double**)malloc(sizeof(double*)*n);

for(int i=0;i<n;i++){

    (*(array+i))=(double *)malloc(sizeof(double)*n);

    for(int j=0;j<n;j++){

        (*((*(array+i))+j))=j;
    }
}

}