#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
void caracterizarlonely(lonely *sample, long long int i)
{
   sample->modelNo = i + 1;
   sample->iq = round(((random() / ((double)RAND_MAX + 1)) * 300) + 100);
   for (int k = 0; k < 4;)
   {
      sample->eq[k] = round(((random() / ((double)RAND_MAX + 1)) * 100));
      k++;
   }
}

float EQ(crushinmass sample)
{

   return (sample.eq[0] + sample.eq[1] + sample.eq[2] + sample.eq[3]) / (float)4;
}

float EQN(crush sample)
{

   return (sample.eq[0] + sample.eq[1] + sample.eq[2] + sample.eq[3]) / (float)4;
}

float EQL(lonely sample)
{

   return (sample.eq[0] + sample.eq[1] + sample.eq[2] + sample.eq[3]) / (float)4;
}
void printCrushFileLine(crushinmass sample, std::ofstream &file)
{
   file << sample.modelNo << "," << sample.iq << "," << EQ(sample) << std::endl;
}

void printLonelyCrushFileLine(lonely needy, std::ofstream &file)
{
   file << needy.modelNo << "," << needy.iq << "," << EQL(needy) << std::endl;
}

void printLonelyCrushLine(lonely needy)
{

   std::cout << "O identificador desta crush é " << needy.modelNo << ", tem " << needy.iq << " de QI e tem " << EQL(needy) << " de QE\n";
}
void printCrushLine(crushinmass sample)
{

   std::cout << "O identificador desta crush é " << sample.modelNo << ", tem " << sample.iq << " de QI e tem " << EQ(sample) << " de QE\n";
}

crushinmass *gerarcrushes(unsigned int n, crushinmass *array)
{
   for (int i = 0; i < n; i++)
   {
      (array + i)->modelNo = i + 1;
      (array + i)->iq = round(((random() / ((double)RAND_MAX + 1)) * 300) + 100);
      for (int k = 0; k < 4;)
      {
         (array + i)->eq[k] = round(((random() / ((double)RAND_MAX + 1)) * 100));
         k++;
      }
   }
   return array;
}

void ranking(int n, crushinmass *array)
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
   std::cout << "\nA crush mais inteligente 🤓 é " << melhor.modelNo << " com " << melhor.iq << " de QI\n\nE a mais simpática é " << fofa.modelNo << " com " << EQ(fofa) << " de QE\n\n";
}

void printcsv(int n, crushinmass *lista, std::ofstream &targetcsv)
{
   int j = 0;
   for (int i = 0; i < n; i++)
   {

      std::cout << "id,iq,eq";

      printCrushFileLine(lista[i], targetcsv);
   }

   std::cout << (float)(j / (float)n) * 100 << "%%Das crushes são dignas. Vamos ver a quantas isso corresponde. São " << j;
   targetcsv.close();
}

int pergunta(std::string nome)
{
   
   double n = ((random() / ((double)RAND_MAX)));

   std::cout << "\nVamos ver se a " << nome << " gosta de ti:\n";
   sleep(3);

   int accepted = 0;

   if (n <g_ChanceOfFailure)
   {
      sleep(3);
      std::cout << "Desculpa seu falhado, ela prefere alguém melhor, mesmo sendo um ser artificialmente criado por uma base de dados tua.\n";
   }
   else
   {
      accepted++;
      sleep(3);
      std::cout << "FOFO! Vai arranjar a fechadura que estragaste. Ela vai querer privacidade contigo 🤫 \n";
   }
   return accepted;
}

crush convertAndRename(lonely escolhida, int nameLength)
{
   std::string newname;
   /*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
   /*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
   std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")*/


   newname=getFilteredInput(newname,"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)");

   crush placeholder;

   placeholder.iq = escolhida.iq;
   for (int i = 0; i < 4; i++)
   {
      placeholder.eq[i] = escolhida.eq[i];
   }
   placeholder.name.assign(newname);
   std::cout << "UUiiiii que fofo.... ela agora chama-se " << placeholder.name << std::endl;

   return placeholder;
}

void tease(long long int id, double EQ)
{

   sleep(3);
   std::cout << "\nHmmmmm.....olha para ela. A " << id << " quer te conhecer melhor 😳....mas não fiques com medo. Ela certamente que não morde...\n";
   usleep(3000000);
   std::cout << "\nE Ela sabe o que é importante... esses " << EQ << " de QE não enganam 😌 \n";
   usleep(1000000);
   std::cout << "(A não ser que tu queiras, é claro 😘)\n\n";
   sleep(3);
}

void copyLonelyCrushData(lonely *src, lonely *dest)
{

   dest->modelNo = src->modelNo;
   for (int i = 0; i < 4; i++)
   {
      dest->eq[i] = src->eq[i];
   }
   dest->iq = src->iq;
}

lonely emptyLonelyCrush()
{
   return {0, 0, {0, 0, 0, 0}};
}