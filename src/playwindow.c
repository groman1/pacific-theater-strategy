#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "playwindow.h"

struct playFieldCell
{
	unsigned char fleetPresent; 
	unsigned char mines; // percent of mines
	unsigned char terrainType; 
};

struct playFieldCell *map;
int rightScroll, leftScroll, winH, winW, width, height, max_rightScroll, max_upScroll;
WINDOW *playWindow;

int updatePlayWindow() // update play window, return 0 on success
{
	for (int i = rightScroll+leftScroll*width; i<width*height; ++i)
	{
		if (i%width>=rightScroll&&i%width<winW)
		{
			mvwchgat(playWindow, i/width-rightScroll-leftScroll*width, (i-rightScroll)%width, 1, A_COLOR, 3+map[i].terrainType, NULL);
		}
	}
	wrefresh(playWindow);
	return 0;
}

int initPlayWindow(WINDOW *win) // load map from file and draw islands, returns 0 on success
{
	playWindow = win;
	getyx(playWindow, winW, winH);
	FILE *f = fopen(".ptmap", "r");
	if (f==NULL) return 1;
	rightScroll = leftScroll = 0;
	fscanf(f, "%d;%d;", &width, &height);
	map = malloc(sizeof(struct playFieldCell)*(width*height));
	init_pair(4, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	for (int i = 0; i<width*height; ++i)
	{
		map[i].fleetPresent = 0;
		map[i].mines = 0;

		fscanf(f, "%c;", &map[i].terrainType);
	}
	max_rightScroll = width-winW;
	max_upScroll = height - winH;
	return updatePlayWindow();
}

int deInitPlayWindow()
{
	free(map);
	return 0;
}
