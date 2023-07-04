#ifndef MENU_H
#define MENU_H
typedef std::list<std::string> optionList;
namespace Menu{
void safeInput(std::string& var,optionList ol,std::string errorMsg);

int optionInList(std::string& opt,optionList& l);


}
#endif
