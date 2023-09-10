
#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void){

float ρ=get_float("densidade do ar (kg/m³): ");
float velocidadedovento = get_float("velocidadedovento (m/s): ");
float angulodovento = get_float("angulodovento (pi*input rads): ");
float u= velocidadedovento * cos(angulodovento*M_PI);
float v= get_float("velocidade de movimento (m/s): ");
float μ= get_float("viscosidade dinâmica do ar (kg/m*s): ");
float cL= get_float("dimensão caracteristica (m): ");

float re= ((abs(u-v))*ρ*cL)/μ;
printf("%0.2f\n", re);

if (re>1){
  printf("equação a usar\n: 0.5*ρ*V²*cD*A");
}
else if(re<1){

    printf("equação a usar\n: 6*pi*μ*V");
}
}
