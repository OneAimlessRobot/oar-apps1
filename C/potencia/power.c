#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void){
  float f_rr = get_float("força de resistencia de rolamento (N): ");
  float Fg = get_float("força graviítica (N): ");
  float Fatritodoar = get_float("força de atrito do ar (N): ");
  float v = get_float("velocidade de movimento (m/s): ");
  float power = (f_rr + Fg + Fatritodoar)*v;
  printf("%0.2f W\n",power);
}
