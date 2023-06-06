#include<stdio.h>

typedef int Fun(int);

int ret(int n){return n;}

int fact(int n,Fun k){
    int cont(int a){
    int l=n;
    int m=a;
    return k(m*l);
    }
    int cont2(int a){
    int l=n;
    int m=a;
    return k(m+l);
    }

     if(n==0){
     return k(1);
     }
     else if(n%2==0){
     return fact(n-1,cont);
     }
     else{


     return fact(n-1,cont2);

     }


}
int fact(){

    return 0;
}
int main(void){
    int res=fact(4,ret);

    printf("%d\n",res);

 return 0;
}
