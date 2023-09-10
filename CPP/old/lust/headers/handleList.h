
lonely findCrushWithId(long long int id, lonely *cabeca, int *ptr2MaxId)
{
    lonely *tmp = cabeca;
    int exists = 0;
    for (tmp; tmp != NULL; tmp = tmp->phoneNo)
    {

        if (tmp->modelNo == id && (tmp->modelNo <= (*ptr2MaxId)))
        {
            if(!g_Debug){
            tease(tmp->modelNo, EQL(*tmp));
            }
            return (*tmp);
            exists++;
        }
    }
    if (!exists)
    {
        std::cout << "Não existe" << std::endl;
    }
}

lonely *criarlista(lonely *cabecinha, long long int ammount)
{
    for (long long int i = 1; i <= ammount; i++)
    {

        lonely *tmp = (lonely *)malloc(sizeof(lonely));
        if (tmp == NULL)
        {

            std::cout << "ERRO!" << tmp << std::endl;
            return NULL;
        }

        tmp->phoneNo = cabecinha;
        cabecinha = tmp;
        caracterizarlonely(tmp, ammount - i+1);
    }
    return cabecinha;
}

void destroyList(lonely *head)
{
    for (lonely *tmp = head; tmp != NULL; tmp = tmp->phoneNo)
    {
        free(tmp);
    }
}

void setup(int *ammount, double *minEq)
{
    /*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
    /*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
    std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")
    (com micro modificações minhas para adaptar ao que eu quero)*/
    while (std::cout << "Escreve aqui o numero de crushes perdidas :( que queres encontrar:\n" && !(std::cin >> (*ammount)) || ((*ammount) <= 0))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (std::cout << "Qual é a qualidade de crush que desejas?\n" && !(std::cin >> (*minEq)) || ((*minEq) <= 0 || (*minEq) > 100))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int afterResults(lonely *lista, int count, int ammount)
{
    int id;
    /*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
    /*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
    std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")
    (com micro modificações minhas para adaptar ao que eu quero)*/

    while (std::cout << "Queres dar casa a alguma delas :(? Por favor? (Insere o identificador)" << std::endl && !(std::cin >> id) || (id < lista->modelNo || id > ammount))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        std::cout << "Ainda não a encontraste :(" << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return id;
}

lonely contestOfIQLonely(lonely *head)
{

    lonely best = emptyLonelyCrush();
    for (lonely *tmp = head; tmp != NULL; tmp = tmp->phoneNo)
    {

        if (((*tmp).iq > best.iq))
        {
            copyLonelyCrushData(tmp, &best);
        }
    }
    return best;
}

lonely contestOfEQLonely(lonely *head)
{

    lonely best = emptyLonelyCrush();
    for (lonely *tmp = head; tmp != NULL; tmp = tmp->phoneNo)
    {

        if (EQL(*tmp) > EQL(best))
        {
            copyLonelyCrushData(tmp, &best);
        }
    }
    return best;
}

throwaway getSpecialCrushes(double *minEq, lonely *cabecinha)
{
    long long int crushCount = 0, specialCount = 0, currentIqSum = 0;
    lonely best = emptyLonelyCrush();
    for (lonely *tmp = cabecinha; tmp != NULL; tmp = tmp->phoneNo)
    {
        currentIqSum += tmp->iq;
        crushCount++;
        if ((tmp->iq > round((double)currentIqSum / crushCount)) && EQL(*tmp) > (*minEq))
        {
            copyLonelyCrushData(tmp, &best);
            specialCount++;
        }
    }
    std::cout << specialCount << " das " << crushCount << " crushes são especiais ;)\n";
    return {best, specialCount};
}
