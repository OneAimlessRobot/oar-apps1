
typedef struct crush
{

   std::string name;
   int iq;
   int eq[4];
} crush;

typedef struct crushinmass
{
   long long int modelNo;
   int iq;
   int eq[4];

} crushinmass;

typedef struct lonely
{
   long long int modelNo;
   int iq, eq[4];
   struct lonely *phoneNo;
} lonely;


typedef struct throwaway
{

    lonely needy;
    long long int ammountOspecial;
} throwaway;

typedef struct convenient
{

    SDL_Rect *rect;
    SDL_Texture *txtr;
    int w;
    int h;
} convenient;

typedef struct embededFileStream{

    const char* start;
    const char* end;
    const char *size;

}embededFileStream;

typedef struct promiseThreadPair{
    std::promise<void>* promisePtr;
    std::thread* threadPtr;
}promiseThreadPair;


typedef std::vector<std::string> phraseVector;


typedef std::vector<promiseThreadPair> runningMediaVector;

typedef std::vector<embededFileStream> FileStreamVector;


std::string removeNLastCharactersFromString(std::string src,int n){

std::string::iterator it;
int i;
    for(it=src.end()-1,i=0;it!=src.begin()&&i<n+1;it--,i++){
        
        std::cout<<"Posição "<<it-src.begin()<<" Da string"<<std::endl;
                src.erase(it);
        

    }

    return src;

}
template <typename T>

T getFilteredInput(T value,std::string query)
{
    while (std::cout << query << std::endl &&!(std::cin >> (value)))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}