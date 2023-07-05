#ifndef MENU_H
#define MENU_H
typedef std::set<std::string> optionSet;
namespace Menu{
void safeInput(std::string& var,optionSet ol,std::string errorMsg);

int optionInList(std::string& opt,optionSet& l);

std::string toString(optionSet& l);
}
#endif
