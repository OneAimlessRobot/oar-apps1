/**
Incluir:
-string
-Structs.h
**/
#ifndef GLOBALS_H
#define GLOBALS_H

extern
int
g_Accepted,
g_MusicOn,
g_SoundOn,
g_Option,
g_Attempts,
g_Debug;

#define EXIT (10)
extern
phraseVector mediaOptions, mainMenuOptions;
extern
runningMediaVector runningImages,runningSounds,runningMusic;
extern
FileStreamVector images,music;

extern char* passwordToMatch;

#endif
