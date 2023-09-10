#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void cvento(void){

float ρ=get_float("densidade do ar (kg/m³): ");
float velocidadedovento = get_float("velocidadedovento (m/s): ");
float angulodovento = get_float("angulodovento (pi*input rads): ");
float u= velocidadedovento * cos(angulodovento*M_PI);

}
