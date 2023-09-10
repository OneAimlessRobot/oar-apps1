#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void) {
//tipos de pneus
int pneu;
do {
  pneu = get_int("que tipo de pneu usas?\c1-pneus de estrada\c2-pneus de montanha\n: ");
} while(pneu != 1 && pneu != 2);

float g=9.81;

int piso;
do {
  piso=get_int("em que tipo de piso andas?\c1-cimento\c2-asfalto\n3-gravilha solta\n4-relva\n5-areia\n:");
}
while(piso != 1 && piso != 2 && piso != 3 && piso != 4 && piso !=5);

float Crr;

if(pneu==1&&piso==1){
  Crr=0.002;
}
else if(pneu==1&&piso==2){
  Crr=0.005;
}
else if(pneu==1&&piso==3){
  Crr=0.006;
}
else if(pneu==1&&piso==4){
  Crr=0.007;
}
else if(pneu==1&&piso==5){
  Crr=0.03;
}
else if(pneu==2&&piso==1){
  Crr=0.0025;
}
else if(pneu==2&&piso==2){
  Crr=0.0063;
}
else if(pneu==2&&piso==3){
  Crr=0.0076;
}
else if(pneu==2&&piso==4){
  Crr=0.0089;
}
else if(pneu==2&&piso==5){
  Crr=0.038;
}
printf("%0.2f\n",Crr);
  float mciclista = get_float("quanto pesa o ciclista?(kg) ");
  float mbicicleta= get_float("qual a massa da bicicleta?(kg) ");
  float m = (mbicicleta + mciclista);
  float α;
  do {
  α = get_float("inclinação da estrada (pi * input radianos) (entre 0 e 0.5) ");
} while(α<0 || α>0.5);

float f_rr = g * m * cos(α*M_PI)* Crr;
printf("%0.2fN\n",f_rr);
}
