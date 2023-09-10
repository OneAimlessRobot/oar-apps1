#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
  float mciclista = get_float("quanto pesa o ciclista?(kg) ");
  float mbicicleta= get_float("qual a massa da bicicleta?(kg) ");
  float α = get_float("inclinação da estrada (pi * input radianos) (de 0 a 1) ");
  float m = (mbicicleta + mciclista);
  float g=9.81;
  float Fg= m*g*sin(α*M_PI);
  printf("%0.2f N\n", Fg);


}
