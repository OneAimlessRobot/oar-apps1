#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

void calculofinal(float m, float g, float α, float u, float cD, float Crr, float v, float A, float ρ);

int main(void)
{
  printf("          ===========================================================\n          =    Bem vindo! Vamos calcular a potencia de um ciclista! =\n          =                   (À superficie da terra)               = \n          ===========================================================\n");

  float ρ = get_float("Densidade do ar (kg/m³)\n: ");
  float Var = get_float("Modulo da velocidade do vento (m/s)\n: ");

  float 𝛽;
  do
  {
    𝛽 = get_float("Ângulo de ataque do vento :π * 'valor' rads (entre 0 e 2)\n: ");
  } while (𝛽 < 0 || 𝛽 >= 2);

  float v = get_float("Velocidade de movimento (m/s)\n: ");
  float A = get_float("Area frontal (m²)\n: ");
  float u = Var * cos(𝛽 * M_PI);

  int pos;
  do
  {
    pos = get_int("Em que posição viajas?\c1- Em pé na bicicleta?\c2-Ou sentado com o tronco direito?\n: ");
  } while (pos != 2 && pos != 1);

  float cD;
  if (pos == 1)
  {
    cD = 1.2;
  }
  else if (pos == 2)
  {
    cD = 1.1;
  }

  float mC = get_float("Massa do ciclista(kg)\n: ");
  float mB = get_float("Massa da bicicleta(kg)\n: ");
  float m = (mC + mB);
  float g = 9.81;

  int pneu;
  do
  {
    pneu = get_int("Que tipo de pneu usas?\c1-Pneus de estrada?\c2-Pneus Mountain Bike?\n: ");
  } while (pneu != 1 && pneu != 2);

  int piso;
  do
  {
    piso = get_int("Em que tipo de piso andas?\c1-Cimento?\c2-Asfalto?\n3-Gravilha solta?\n4-Relva?\n5-Ou areia\n: ");
  } while (piso != 1 && piso != 2 && piso != 3 && piso != 4 && piso != 5);

  float Crr;
  if (pneu == 1 && piso == 1)
  {
    Crr = 0.002;
  }
  else if (pneu == 1 && piso == 2)
  {
    Crr = 0.005;
  }
  else if (pneu == 1 && piso == 3)
  {
    Crr = 0.006;
  }
  else if (pneu == 1 && piso == 4)
  {
    Crr = 0.007;
  }
  else if (pneu == 1 && piso == 5)
  {
    Crr = 0.03;
  }
  else if (pneu == 2 && piso == 1)
  {
    Crr = 0.0025;
  }
  else if (pneu == 2 && piso == 2)
  {
    Crr = 0.0063;
  }
  else if (pneu == 2 && piso == 3)
  {
    Crr = 0.0076;
  }
  else if (pneu == 2 && piso == 4)
  {
    Crr = 0.0089;
  }
  else if (pneu == 2 && piso == 5)
  {
    Crr = 0.038;
  }
  float α;
  do
  {
    α = get_float("Inclinação da estrada : π * 'input' radianos (entre 0 e 0.5)\n: ");
  } while (α < 0 || α > 0.5);

  calculofinal(m, g, α, u, cD, Crr, v, A, ρ);
}

void calculofinal(float m, float g, float α, float u, float cD, float Crr, float v, float A, float ρ)
{

  float f_rr = m * g * cos(α * M_PI) * Crr;
  float Fg = m * g * sin(α * M_PI);
  float fD = 0.5* ρ * (pow((u - v), 2)) * cD * A;
  float powerf_rr = m * g * cos(α * M_PI) * Crr * v;
  float powerFg = m * g * sin(α * M_PI) * v;
  float powerfD = 0.5* ρ * (pow((u - v), 2)) * cD * A * v;
  printf("          ==========================================================\n          =                        Resultados                      =\n          ==========================================================\n");

  printf("Força de gravidade = %f N\nForça de resistencia do ar = %f N\nForça de resistencia de rolamento = %f N\n", Fg, fD, f_rr);
  printf("Potencia contra a força de gravidade = %f W\nPotencia contra a força de resistencia de rolamento = %f W\nPotencia contra a força de resistencia do ar = %f W\n", powerFg, powerf_rr, powerfD);

  float P = ((m * g * sin(α * M_PI)) + (m * g * cos(α * M_PI) * Crr) + (0.5* ρ * (pow((u - v), 2)) * cD * A)) * v;

  printf("Potencia = %f W\n", P);
}