#include <ncurses.h>

#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

struct playFieldCell;

int initPlayWindow(WINDOW*);
int deInitPlayWindow();

#endif
