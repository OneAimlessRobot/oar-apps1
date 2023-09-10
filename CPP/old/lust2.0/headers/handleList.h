
crush findCrushWithId(long long int id)
{
    crush chosenOne=crush();
    for(int i=0;i<crushes.size();i++){

        if(crushes[i].getId()==id){

            crush::crushCopy(&crushes[i],&chosenOne);

        }

    }
    return chosenOne;
}

void fillList(int ammount)
{
    for(int i=1;i<=ammount;i++){
        crushes.push_back(crush(i));
    }
}


void setup(int *ammount, double *minEq)
{
    /*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
    /*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
    std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")
    (com micro modificações minhas para adaptar ao que eu quero)*/
    while ((std::cout << "Escreve aqui o numero de crushes perdidas :( que queres encontrar:\n") && !(std::cin >> (*ammount)) || ((*ammount) <= 0))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while ((std::cout << "Qual é a qualidade de crush que desejas?\n") && (!(std::cin >> (*minEq)) || ((*minEq) <= 0 || (*minEq) > 100)))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int afterResults(int count)
{
    int id;
    /*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
    /*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
    std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")
    (com micro modificações minhas para adaptar ao que eu quero)*/

    while ((std::cout << "Queres dar casa a alguma delas :(? Por favor? (Insere o identificador)" << std::endl) && (!(std::cin >> id) || (id<crushes[0].getId()||id>crushes.size())))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        std::cout << "Ainda não a encontraste :(" << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return id;
}

crush contestOfIQLonely()
{

    crush best=crush();
    for (crush i:crushes)
    {

        if (i.getIQ()> best.getIQ())
        {
            crush::crushCopy(&i,&best);
        }
    }
    return best;
}

crush contestOfEQLonely()
{
    crush best= crush();
    for (crush i:crushes)
    {

        if (i.getEQ()>best.getEQ())
        {
            crush::crushCopy(&i,&best);
        }
    }
    return best;
}

throwaway getSpecialCrushes(double *minEq)
{
    int crushCount = 0, specialCount = 0, currentIqSum = 0;
    crush best = crush();
    for (crush i:crushes)
    {
        currentIqSum += i.getIQ();
        crushCount++;
        if (i.getIQ() > round((double)currentIqSum / crushCount) && (i.getEQ() > (*minEq)))
        {
            crush::crushCopy(&i,&best);
            specialCount++;
        }
    }
    std::cout << specialCount << " das " << crushCount << " crushes são especiais ;)\n";
    return {best, specialCount};
}
