#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

int main(void){

float ρ=get_float("densidade do ar (kg/m³): ");
float velocidadedovento = get_float("modulo da velocidade do vento (m/s): ");
float angulodovento = get_float("angulodovento (pi*input rads): ");
float u= velocidadedovento * cos(angulodovento*M_PI);
float v= get_float("velocidade de movimento (m/s): ");
float area= get_float("area frontal (m²): ");
float cD;
int posicao;
do {
  posicao = get_int("em que posição viajas?\c1- em pé na bicicleta\c2-sentado com o tronco direito\n: ");
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
