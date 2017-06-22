#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>




int main(int argc,char ** argv){
	const char witch_one[] = " First Witch";
	const char witch_two[] = " Two Witch";

	initscr();
//-------
	move(5,15);
	attron(A_BOLD);
	printw("%s",witch_one);
	attroff(A_BOLD);
	

	attron(A_STANDOUT);
	move(20,15);
	printw("%s",witch_two);
	attroff(A_STANDOUT);

	move(LINES-1,COLS-1);
	refresh();

	sleep(2);

//-------
	endwin();
exit(EXIT_SUCCESS);
}
