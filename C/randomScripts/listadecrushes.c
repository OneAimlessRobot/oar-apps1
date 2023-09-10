#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "/home/oneaimlessrobot/scripts/crush.h"
#include <math.h>

float EQ(crushinmass sample);

void ranking(int n, crushinmass array[n]);

void procura(int k, int n, crushinmass array[n]);

int gerabd(unsigned int n, crushinmass array[n], float s);

bool pergunta1(void);

int main(void)
{

   /* Aquela miuda do refeitório era tão gira.... quem me dera que ela e as amigas que a acompanhavam me levassem para um lugar em que
só tivessemos nós os 4, me fizessem fazer flexões, que me insultassem e que me humilhassem pela minha lógica formal incompetente. Elas estão num curso que
nem sequer precisa assim tanto de matemática e elas são melhores que eu, mais inteligentes do que eu, mais giras, mais calmas, mais bem educadas, mais claras nas palavras,
mais populares....*/

   srand(time(NULL));
   unsigned int n;

   do
   {
      printf("Quantas crushes queres?\n");
      scanf("%i", &n);
   } while (n <= 0 || n >= 261250);

   float eqmin;
   do
   {
      printf("Qual é a qualidade de crush que desejas?\n");
      scanf("%f",&eqmin);
   } while (eqmin <= 0 || eqmin > 100);

   crushinmass lista[n];

   printf("A gerar crushes. Preparate;)\n");
   int k = gerabd(n, lista, eqmin);
   printf("%.4f %% das crushes são dignas ;)\n\n", ((k / (float)n) * 100));
   printf("Vamos ver a quantas isso corresponde:\n");
   printf("\nSão %i\n", k);
   ranking(n, lista);
   printf("Gostarias de falar com alguma delas em especial?\nInsere aqui o identificador: ");
   int identidade;
   scanf("%i", &identidade);
   for (identidade; identidade < lista[0].modelno || identidade > n;)
   {
      printf("Essa crush não existe...ainda :)\n");
      scanf("%i", &identidade);
   }
   procura(identidade, n, lista);

   printf("Vamos ver se a %i gosta de ti:\n", identidade);
   bool resposta = pergunta1();

   if (resposta == true)
   {
      printf("FOFO! Vai arranjar a fechadura que estragaste. Ela vai querer privacidade contigo 🤫 \n");
   }
   else
   {
      printf("Desculpa seu falhado, ela prefere alguém melhor, mesmo sendo um ser artificialmente criado por uma base de dados tua.\n");
   }
}

int gerabd(unsigned int n, crushinmass array[n], float s)
{
   int j = 0;
   for (int i = 0; i < n; i++)
   {
      array[i].modelno = i + 1;
      array[i].iq = round(((random() / ((double)RAND_MAX + 1)) * 300) + 100);
      for (int k = 0; k < 4;)
      {
         array[i].eq[k] = round(((random() / ((double)RAND_MAX + 1)) * 100));
         k++;
      }
      int eq = EQ(array[i]);
      printf("O identificador desta crush é %i, tem %i de QI e tem %i de QE\n", array[i].modelno, array[i].iq, eq);

      if (eq > s && array[i].iq > ((array[0].iq + array[i - 1].iq) / 2))
      {
         j++;
         printf("%i....Hummmm....Que boa...🥵...\n\n", i + 1);
      }
   }
   return j;
}

float EQ(crushinmass sample)
{

   return (sample.eq[0] + sample.eq[1] + sample.eq[2] + sample.eq[3]) / (float)4;
}

bool pergunta1(void)
{
   float n = (rand() / (float)RAND_MAX);
   if (n < 0.5)
   {
      return false;
   }
   else
   {
      return true;
   }
}

void ranking(int n, crushinmass array[n])
{

   int slot;
   crushinmass melhor = array[0];
   for (slot = 0; slot < n; slot++)
   {
      if (melhor.iq < array[slot].iq)
      {
         melhor = array[slot];
      }
   }
   crushinmass fofa = array[0];
   for (slot = 0; slot < n; slot++)
   {
      if (EQ(fofa) < EQ(array[slot]))
      {
         fofa = array[slot];
      }
   }
   printf("\nA crush mais inteligente 🤓 é %i com %i de QI\n\nE a mais simpática é %i com %.4f de QE\n\n", melhor.modelno, melhor.iq, fofa.modelno, EQ(fofa));
}

void procura(int k, int n, crushinmass array[n])
{

   for (int slot = 0; slot < n; slot++)
   {
      if (array[slot].modelno == array[k - 1].modelno)
      {
         array[slot] = array[k - 1];
         printf("Hummmmm.....🥰....ela tem %i de QI e %.4f de QE 😏 tens a certeza que estás pronto? \n\n", array[k - 1].iq, EQ(array[k - 1]));
      }
   }
}


