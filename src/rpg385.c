/*
 ============================================================================
 Name        : rpg385.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int week = 0;
int health = 100;
int hygiene = 100;
int grades = 100;
int difficulty = 0;


char* eventTexts[] = {
		"Welcome to RPG385!\n",
		"",
};

int main(void) {
	//puts("ayy lmao"); // prints !!!Hello World!!!
	//printf("ayy lmao\n");
	prints(eventTexts[0]);

	while(week < 15){
		int userSel;
		drawScreen();
		prints("What do you choose? ");
		userSel = getIn();
		week++;
	}

	return EXIT_SUCCESS;
}

Event* Event_new(int eventTextI, int choiceTextI[], int choiceResponsesI[], int choiceNextEventI[]){
	Event* e = malloc(sizeof(Event));
	e->promptI = eventTextI;
	e->choices = malloc(4 * sizeof(Choice));

	int i;
	Choice* c = e->choices;
	for(i = 0; i < 4; i++){
		c[i].textI = choiceTextI[i];
		c[i].responseI = choiceResponsesI[i];
		c[i].nextEventI = choiceNextEventI[i];
	}

	return e;
}

void prints(const char *format, ...){
	va_list arg;
	printf(format, arg);
}

int getIn(){
	char buf[80] = "boo false value";

	scanf("%s", buf);

	while(strlen(buf) != 1){
		drawScreen();
		scanf("%s", buf);
	}

	//printf("%c\n", buf[0]);
	return buf[0];
}

void drawScreen(){

}
