#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>


void power(void){
  printf("Finalmente, vamos calcular a potência\n");
  float f_rr = get_float("Força de resistencia de rolamento (N): ");
  float Fg = get_float("Força graviítica (N): ");
  float Fatritodoar = get_float("Força de atrito do ar (N): ");
  float v = get_float("Módulo da velocidade do movimento (m/s): ");
  float power = (f_rr + Fg + Fatritodoar)*v;
  printf("%0.2f W\n",power);
}

void crrolamento(void) {

printf("Vamos calcular a intensidade da força de resistencia de rolamento na direção do movimento\n");
int pneu;
do {
  pneu = get_int("Que tipo de pneu usas?\c1- Pneus de estrada\c2- Ou pneus de montanha\n: ");
} while(pneu != 1 && pneu != 2);

float g=9.81;

int piso;
do {
  piso=get_int("Em que tipo de piso andas?\c1- Cimento?\c2- Asfalto\n3- Gravilha solta?\n4- Relva\n5- Ou areia?\n:");
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
  float mciclista = get_float("Quanto pesa o ciclista?(kg) ");
  float mbicicleta= get_float("Quanto pesa a bicicleta?(kg) ");
  float m = (mbicicleta + mciclista);
  float α;
  do {
  α = get_float("Inclinação da estrada (pi * input radianos) (entre 0 e 0.5) ");
} while(α<0 || α>0.5);

float f_rr = g * m * cos(α*M_PI)* Crr;
printf("%0.2fN\n",f_rr);
}

void catritodoar(void){
printf("Vamos calcular a intensidade da força de atrito aerodinâmico na direção do movimento\n");
float ρ=get_float("Densidade do ar (kg/m³): ");
float velocidadedovento = get_float("Módulo da velocidade do vento (m/s): ");
float angulodovento = get_float("Ângulo do vetor força de atrito aerodinâmico em relação ao movimento do ciclista (pi*input em radianos): ");
float u= velocidadedovento * cos(angulodovento*M_PI);
float v= get_float("Velocidade de movimento (m/s): ");
float area= get_float("Àrea frontal (m²): ");
float cD;
int posicao;
do {
  posicao = get_int("Em que posição viaja?\c1- De pé na bicicleta?\c2- Ou entado com o tronco direito?\n: ");
}
while(posicao != 2 && posicao !=1);
if (posicao==1) {
  cD=1.2;
}
else if(posicao ==2){
  cD=1.1;
}
float Fatritodoar= 0.5*ρ*(pow((u-v),2))*cD*area;
printf("%0.2f N\n",Fatritodoar);

}

void cgravidade(void)
{
  printf("Vamos calcular a intensidade da força gravítica na direção do movimento\n");
  float mciclista = get_float("Quanto pesa o ciclista?(kg) ");
  float mbicicleta= get_float("Qual a massa da bicicleta?(kg) ");
  float α = get_float("Inclinação da estrada (pi * input radianos) (de 0 a 0.5)\n (Mete valores negativos se a inclinação for a favor do ciclista)\n: ");
  float m = (mbicicleta + mciclista);
  float g=9.81;
  float Fg= m*g*sin(α*M_PI);
  printf("%0.2f N\n", Fg);


}

void reynolds(void){
printf("Vamos calcular o numero de reynold. Vai ser importante para determinar a equação usada para calcular a força de atrito aerodinâmico\n");
float ρ=get_float("Densidade do ar (kg/m³): ");
float velocidadedovento = get_float("Velocidade do vento (m/s): ");
float angulodovento = get_float("Ângulo do vetor força de atrito aerodinâmico em relação ao movimento do ciclista (pi*input em radianos):  ");
float u= velocidadedovento * cos(angulodovento*M_PI);
float v= get_float("velocidade de movimento (m/s): ");
float cL= get_float("Dimensão caracteristica (comprimento da bicicleta) (m): ");
float μ= get_float("Viscosidade dinâmica do ar (kg/m*s): ");

float re= ((abs(u-v))*ρ*cL)/μ;
printf("%0.2f\n", re);

if (re>1){
  printf("Equação a usar\n: 0.5*ρ*V²*cD*A\n");
}
else if(re<1){

    printf("Equação a usar\n: 6*pi*μ*V\n");
}
}

int main(void)
{
printf("Vamos calcular a potência de um ciclista\n");
reynolds();
cgravidade();
catritodoar();
crrolamento();
power();
}
