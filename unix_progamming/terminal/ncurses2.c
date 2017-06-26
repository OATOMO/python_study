#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define PW_LEN 		256
#define NAME_LEN 	256

int main(int argc,char ** argv){
	char name[NAME_LEN];
	char password[PW_LEN];
	const char * real_password = "t2153558";
	int i = 0;

	initscr();
	move(5,10);
	printw("please login:");

	move(7,10);
	printw("name : ");
	getstr(name );

	move(9,10);
	printw("passwd : ");
	refresh();
	
	cbreak();
	noecho();
	memset(password,'\0',sizeof(password));
	while(i < PW_LEN){
		password[i] = getch();
		if(password[i] == '\n') break;
		move(9,20+i);
		addch('*');
		refresh();
		i++;
	}
	echo();
	nocbreak();

	move(11,20);
	if(strncmp(real_password,password,strlen(real_password)) == 0)
			printw("Correct");
	else printw("wrong!");
	refresh();
	sleep(2);


	endwin();
exit(EXIT_SUCCESS);
}
