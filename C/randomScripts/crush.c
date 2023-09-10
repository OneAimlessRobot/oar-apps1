#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    string proposta;
    int sim;
    int não;
do
{
   proposta = get_string("queres jogar, coisinha boa?(Sim/Não) ");
   sim = strcmp(proposta, "Sim");
   não = strcmp(proposta,"Não");
}
while( sim != 0 && não != 0);

    if (sim == 0)
    {
      printf("Bom menino :)\n");
    }
    else if (não == 0)
    {
      string insistencia;
      int sil2;
      int não2;
      do{
        printf("Tens a certeza ｡ﾟ･（>﹏<）･ﾟ｡ ?? (Sim/Não):\n");
        scanf("%s",&insistencia);
        sil2 = strcmp(insistencia, "Sim");
        não2 = strcmp(insistencia,"Não");
      }
      while (sil2 !=0 && não2!=0); {
      }
      if (sil2 ==0)
      {
        string desespero;
        int sim3;
        int não3;
        do{
          desespero = get_string("NÃO VÁS T-T!!!!!!! FICA POR FAVOR!!!!!!! ok?? ");
          sim3= strcmp(desespero, "Sim");
          não3= strcmp(desespero, "Não");
        }
        while (strcmp(desespero, "Sim") !=0 && strcmp(desespero, "Não")!=0);
        if (sim3 == 0) {
          printf("ÉS MAU!!!!! >PPPPPP\n ");
          return 0;
        }
        else if(não3 == 0){
          printf("Eu sabia que não me abandonarias ;) És fofo, sabes?\n");
        }
      }
      else if(não2 == 0){
      printf("Tu sabes o que é bom para ti :)\n");
    }
}

  string crush = get_string("De quem é que mais gostas ;) ? ");
  unsigned int iq;
  do{
    iq = get_int("Insere aqui o QI de quem admiras, coisa fofa (QI entre 0 e 300): ");
  }
  while(iq > 300);
  unsigned int eq;
   do{
    eq= get_int("Insere aqui o QE da(o) tua(eu) crush :) (entre 0 e 300) ");
  }
  while(eq > 300);


  
  float flexões =log2(iq*eq);
  int flexsimp = round(flexões);
  printf("A pessoa que amas é %s que tem um QI de %i e um QE de %i e consegue fazer %i flexões \n", crush, iq, eq, flexsimp);

}
