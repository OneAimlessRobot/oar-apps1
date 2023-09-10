

typedef std::vector<std::string> phraseVector;

phraseVector getValidLinesFromFile(std::string filepath)
{

    phraseVector vec = {};

    std::ifstream ficheiro(filepath);
    std::string placeholder;
    while (std::getline(ficheiro, placeholder))
    {
	if(!(placeholder[0]=='#')&&!(trim(placeholder).size()==0)){
        	vec.push_back(placeholder);
        }
    }
    return vec;
}

int randNumBetZeroAnd(int lim)
{
    int num = round(((random() / ((double)RAND_MAX + 1)) * lim));

    return num;
}

