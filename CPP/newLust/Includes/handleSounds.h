/**
Include:
-string
-future
-Struts.h

**/

#ifndef SOUNDS_H
#define SOUNDS_H
void kissPlusMoan(int dt2, std::string sentence);
void kissesAndMoans(int dt2, int repeats, std::string sentence);
void acceleratingMoans(int dt, int repeats, int dtSubtract, std::string sentence);
 void loadNplaySound(Uint32 freq,const char*filename,int time,std::future<void> future,int *g_Var);
#endif