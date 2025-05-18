#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int ch, width, heigth, pos = 0, xoffset = 0, yoffset = 0;
	scanf("%d %d", &width, &heigth);
	initscr();
	noecho();
	keypad(stdscr, 1);
	unsigned char *field = malloc(sizeof(unsigned char)*(width*heigth)); 
	while ((ch = getch())!=10)
	{
		switch (ch)
		{
			case 32: { printw("%c", field[pos]==1?' ':'1'); field[pos] = !field[pos]; move(pos/width, pos%width); break; }
			case 259: if (pos>=width) { pos -= width; } break;
			case 258: if (pos<(heigth-1)*width) { pos += width; } break;
			case 260: if (pos>0) { --pos; } break;
			case 261: if (pos<heigth*width-1) { ++pos; } break;
		}
		move(pos/width, pos%width);
	}
	endwin();
	FILE *outfile;
	if (argc>1) { outfile = fopen(argv[1], "w"); }
	else { outfile = stdout; }
	for (int i = 0; i<heigth*width; ++i)
	{
		fprintf(outfile, "%d;", field[i]);
	}
	if (argc>1) {fclose(outfile);}
}
