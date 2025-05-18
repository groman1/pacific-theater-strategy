#include <ncurses.h>
#include <stdlib.h>

int main()
{
	int game;
	initscr();
	keypad(stdscr, 1);
	noecho();
	curs_set(0);
	game = 1;
	char ch;
	int maxx, maxy;
	getmaxyx(stdscr, maxy, maxx);
	printw("%d %d", maxy, maxx);
	while (game)
	{
		ch = getch();
		switch (ch)
		{
			case 113: game = 0; break;
			default: break;
		}
	}
	endwin();
}
