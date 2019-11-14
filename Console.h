/*
	Console.h: declarations for console-related functions
*/

#ifndef	__CONSOL__
#define	__CONSOL__

#ifndef _UNIX
#include <conio.h>
#include <windows.h>
#endif // _UNIX

void clrscr(void);              // clear screen
void gotoxy(int x, int y);     // move cursor to (x, y) coordinate

int getWindowWidth();       // get width of current console window
int getWindowHeight();      // get width of current console window

void DrawLine(int x1, int y1, int x2, int y2, char c);
void swap(int *pa, int *pb);

void EnableCursor(int enable);


#ifdef _UNIX


#include <unistd.h>

void resetTermios(void);
void initTermios(int echo);
int getch_(int echo);
int _getch(void);
int _getche(void);

int kbhit();
void Sleep(int msec);

#endif	// _UNIX


#endif	//	__CONSOL__

