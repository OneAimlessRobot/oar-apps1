#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int Fun(int);
typedef struct BNode{

bool active;
int value;
struct BNode* next;


}BNode,*List;



void removeNode(List l,int value){
for(;l!=NULL;l=l->next){

    if(l->value== value){

        if(l->active){

            l->active=false;
            break;

        }
        else if (l->value > value){

            break;
        }


    }



}
}

List newNode(int value,List next){


    List node=malloc(sizeof(BNode));

    node->active=true;
    node->value=value;
    node->next=next;
    return node;



}
//Na stack, structs são guaradadas com os campos todos seguidos. (Arrays de strcuts ocupam sizeof(struct) * sizeofArray)
//Um inteiro e um apontador ocupam uma word. Um apontador tem o tamanho de uma word. (word e o numero de bits de um registo)
List insert(List l,int value){
    List start= l;
    if(l==NULL){

     start= newNode(value,NULL);

    }
    for(;l->next!=NULL;l=l->next){
        if(l->next->value==value&&!l->next->active){

                l->next->active= true;
                break;

        }if( l->next->value>value){
            List nNode= newNode(value,l->next);
            l->next=nNode;
            break;

        }


    }
    return start;



}

//O static link aponta para o dinamic link da ultima instancia do pai da funcao atual

List genList(int min, int max){
List start=newNode(min,NULL),l=start;
int i=min+1;
if(min==max){
    return start;

}
if(min>max){
    int tmp=min;
    min=max;
    max=tmp;

}
for(;i<=max;i++, l=l->next){

l->next=newNode(i,NULL);

}
return start;




}
/*break keyword:

evitar break/ return em ciclos;

mas nesta funçao é preciso usar


O objetivo do codigo é apagar a primeira ocorrencia do valor.
A verificaçao de maior serve para
*/
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
void printList(List l){
for(;l!=NULL;l=l->next){

    if(l->active){

        printf("%d ",l->value);

    }


}

        printf("\n");


}
int main(void){
    int res=fact(4,ret);
    List l= genList(4,9);
    removeNode(l,5);
    printList(l);
    printf("%d\n",res);

 return 0;
}
