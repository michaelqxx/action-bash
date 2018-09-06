/*
 ============================================================================
 Name        : action-bash.c
 Author      : Nathan Smith
 Version     : tbd
 Copyright   : tbd
 Description : action-bash in C, Ansi-style
 ============================================================================
 */

/* some defines might be needed for unicode support but it works in os x right now
#define _XOPEN_SOURCE_EXTENDED
#define _BSD_SOURCE
#define _DEFAULT_SOURCE
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>		//for animating the terminal
#include <locale.h> 		//for unicode support

#define DELAY 199999

//NOTE: Defined game area as 20x5 - the smallest terminal size OS X allows
int main()
{
	setlocale(LC_ALL, ""); //unicode on
	//y is up down x is left right
	int x = 0, y = 3;
	int max_y = 4, max_x = 21; //legacy - loop is hardcoded right now
	int next_x = 0;
	int direction = 1;
	int ch; //beginning input

	//ncurses calls to start game and hide the cursor
	initscr();
	noecho();
	curs_set(FALSE);

	// Global var `stdscr` is created by the call to `initscr()`
	// not needed - get terminal size // getmaxyx(stdscr, max_y, max_x);

	//Game Loop
	while (1)
	{
		//getmaxyx(stdscr, max_y, max_x);
		//max_x = max_x - 1; //keep one space from right for better behavior

		
		clear();
		timeout(1);
		ch = getch();
		if (ch != ERR)
		{
			printw("%c\n", ch);
			y=2;
		} else if (ch == ERR)
		{
			mvprintw(0, 0, "input");
			y=3;
		}
		mvprintw(1,0,"    🌥         ☁️");
		mvprintw(y, x, "💩");
		mvprintw(4, 0, "🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫🌫");

		/*fix bug of going to far right when resized
 if(x > max_x){
	x = max_x -1; 
 }*/
		refresh();
		usleep(DELAY);
		//update
		next_x = x + direction;

		if (next_x >= 19 || next_x < 0)
		{
			direction *= -1;
		}
		else
		{
			x += direction;
		}
	}

	endwin();
}