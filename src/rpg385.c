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
#include <stdarg.h>
#include "data.h"

int week = 0;
int health = 100;
int hygiene = 100;
int happiness = 100;
int grades = 100;
int difficulty = 0;



char* eventTexts[] = {
		"Welcome to RPG385!\n",
		"",
};

char* choiceTexts[] = {
		"",
		"",
		"",
		"TURN UP"
};

char* choiceResponses[] = {
		"Welcome to RPG385!\n",
		"",
};

Event* e[16];


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

void initEvents(){
	int* cTI;	// choice text indices
	int* cRI;	// choice response indices
	int* cNI;	// choice next event indices

	cTI = (int[4]) {1, 2, 3, 4};
	cRI = (int[4]) {1, 2, 3, 4};
	cNI = (int[4]) {1, 1, 1, 1};
	e[0] = Event_new(0, cTI, cRI, cNI);
}

void prints(const char *format, ...){
	va_list arg;
	printf(format, arg);
}

char getIn(){
	//prints("What do you choose? ");

	char buf[80] = "boo invalid value";
	//scanf("%s", buf);

	while(strlen(buf) != 1){
		drawScreen();
		prints("What do you choose? ");
		scanf("%s", buf);
	}

	//printf("%c\n", buf[0]);
	return buf[0];
}

void drawScreen(){
	int i;
	for(i = 0; i < 20; i++){
		printf("\n");
	}
}


int main(void) {
	initEvents();

	prints(eventTexts[0]);

	while(week < 15){
		char userSel[80];
		//drawScreen();
		userSel[0] = getIn();
		printf("Press enter to continue... ");
		while(getchar() == "\n"){
			userSel[0] = userSel[0];
			//userSel[0] = getchar();
		}//while(userSel[0] == "\n");
		getchar();

		week++;
	}

	return EXIT_SUCCESS;
}
