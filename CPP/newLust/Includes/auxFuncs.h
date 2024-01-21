/**
Include:
-string
-Structs.h


**/


#ifndef AUX_H
#define AUX_H
phraseVector getLinesFromFile(std::string filepath);

int randNumBetZeroAnd(int lim);

void loading();

void displayMenu(phraseVector menu);

void displayRandomPhrase(phraseVector phraseVec);

int inquerito(std::string demand, std::string insist, std::string otherwise);

int safeMenuInput(std::string demand, phraseVector vec);

void desabafo(int nLines, std::string filepath);


std::string removeNLastCharactersFromString(std::string src, int n);
#endif