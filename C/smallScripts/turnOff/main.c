#include <X11/Xlib.h>
#include <ncurses.h>
#include <X11/extensions/dpms.h>
#include <err.h>
int main(void){
        Display *dpy;
	char c;
        if(!(dpy = XOpenDisplay(0)))
                errx(1, "cannot open display '%s'", XDisplayName(0));
        DPMSEnable(dpy);
        DPMSForceLevel(dpy, DPMSModeOff);
	scanf("%c",&c);
	//DPMSForceLevel(dpy,DPMSModeOn);
        XSync(dpy, False);
}
