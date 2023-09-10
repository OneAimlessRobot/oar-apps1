static int g_Debug=0;
class crush
{
private:
    int modelNo,iq, eq[4];
    constexpr static double g_ChanceOfFailure=0.8;
    std::string name;

public:
    crush(int id)
    {
        this->modelNo = id;

        this->iq = round(((random() / ((double)RAND_MAX + 1)) * 300) + 100);
        for (int k = 0; k < 4;)
        {
            this->eq[k] = round(((random() / ((double)RAND_MAX + 1)) * 100));
            k++;
        }
    }
    crush(std::string name)
    {

        this->name.assign(name);

        this->iq = round(((random() / ((double)RAND_MAX + 1)) * 300) + 100);
        for (int k = 0; k < 4;)
        {
            this->eq[k] = round(((random() / ((double)RAND_MAX + 1)) * 100));
            k++;
        }
    }
    crush()
    {
        this->modelNo = 0;
        this->iq = 0;

        for (int k = 0; k < 4;)
        {
            this->eq[k] = 0;
            k++;
        }
        this->name = "";
    }

    void flirt()
    {

        sleep(3);
        std::cout << "\nHmmmmm.....olha para mim. Este vai ser o dia da tua vida, fofo ;) quer te conhecer melhor 😳....mas não fiques com medo. Ela certamente que não morde...\n";
        usleep(3000000);
        std::cout << "\nE Ela sabe o que é importante... esses " << this->getEQ() << " de QE não enganam 😌 \n";
        usleep(1000000);
        std::cout << "(A não ser que tu queiras, é claro 😘)\n\n";
        sleep(3);
    }

    double getEQ()
    {

        return (this->eq[0] + this->eq[1] + this->eq[2] + this->eq[3]) / (double)4;
    }
    void printCrushFileLine(std::ofstream &file)
    {
        file << this->modelNo << "," << this->iq << "," << this->getEQ() << std::endl;
    }

    void printCrushLine()
    {

        std::cout << "O identificador desta crush é " << this->modelNo << ", tem " << this->iq << " de QI e tem " << this->getEQ() << " de QE\n";
    }

    void setIQ(int value)
    {
        this->iq = value;
    }
    static void EQcopy(crush *src, crush *dest)
    {

        for (int k = 0; k < 4;)
        {
            dest->eq[k] = src->eq[k];
            k++;
        }
    }
    std::string getName()
    {
        return this->name;
    }
    void rename(std::string newname)
    {
        this->name.assign(newname);
    }
    int getIQ()
    {
        return this->iq;
    }
    int getId()
    {
        return this->modelNo;
    }
    void setId(int value)
    {

        this->modelNo = value;
    }
    static void crushCopy(crush *src, crush *dest)
    {

        dest->setId(src->getId());
        dest->setIQ(src->getIQ());

        EQcopy(src, dest);

        dest->name.assign(src->getName());
    }

    int pergunta()
    {

        double n = ((random() / ((double)RAND_MAX)));

        std::cout << "\nVamos ver se a " << this->getName() << " gosta de ti:\n";
        sleep(3);

        int accepted = 0;

        if (n < crush::g_ChanceOfFailure)
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
};

typedef struct
{

    SDL_Rect *rect;
    SDL_Texture *txtr;
    int w;
    int h;
} convenient;


typedef struct
{
    crush result;
    int value;
} throwaway;

typedef struct embededFileStream
{

    const char *start;
    const char *end;
    //caso seja uma música
    int freq;

} embededFileStream;

typedef struct promiseThreadPair
{
    std::promise<void> *promisePtr;
    std::thread *threadPtr;
} promiseThreadPair;

typedef std::vector<std::string> phraseVector;

typedef std::vector<promiseThreadPair> runningMediaVector;

typedef std::vector<embededFileStream> FileStreamVector;

std::string removeNLastCharactersFromString(std::string src, int n)
{

    std::string::iterator it;
    int i;
    for (it = src.end() - 1, i = 0; it != src.begin() && i < n + 1; it--, i++)
    {

        if(g_Debug){
        std::cout << "Posição " << it - src.begin() << " Da string" << std::endl;
        }
        src.erase(it);
    }

    return src;
}
template <typename T>

T getFilteredInput(T value, std::string query)
{
    while ((std::cout << query << std::endl) && !(std::cin >> (value)))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

typedef std::vector<crush> crushVector;
