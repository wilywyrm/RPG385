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

int happiness = 100;
int hygiene = 100;
int grades = 100;

int difficulty = 0;


Event* ev[10];
Event* curE;

Event* Event_new(int eventTextI, int choiceTextI[], int choiceResponsesI[], int choiceNextEventI[], int choiceImpacts[]){
	Event* e = malloc(sizeof(Event));
	e->promptI = eventTextI;
	e->choices = malloc(4 * sizeof(Choice));

	int i;
	Choice* c = e->choices;
	for(i = 0; i < 4; i++){ // we use nextEventI to mark if this choice is possible (if -1, don't show the choice)
			c[i].textI = choiceTextI[i];
			c[i].responseI = choiceResponsesI[i];
			c[i].nextEventI = choiceNextEventI[i];
			int a;
			for(a = 0; a < 3; a++)
				c[i].impacts[a] = choiceImpacts[i*3 + a];
	}

	//printf("%i\n", c[0].textI);

	return e;
}

void initEvents(){
	int* cTI;	// choice text indices
	int* cRI;	// choice response indices
	int* cNI;	// choice next event indices
	int* cI	;	// choice impacts (on happiness, hygiene, grades)

	cTI = (int[4]) {0, 1, 2, 3};
	cRI = (int[4]) {0, 1, 2, 3};
	cNI = (int[4]) {1, 1, 1, 1};
	cI  = (int[12]) { 	0, 0, 0,
						0, 0, 0,
						0, 0, 0,
						0, 0, 0 };
	ev[0] = Event_new(0, cTI, cRI, cNI, cI);

}

void prints(const char *format, ...){
	va_list arg;
	va_start(arg, format);
	vprintf(format, arg); // printf doesn't work like you want it to
	va_end(arg);
}

void printChoices(Event* e){
	int i = 0;
	Choice* a = e->choices;
	for(i = 0; i < 4; i++){
		if(a[i].nextEventI != -1) // we don't print a choice with nextEvent index of -1
			prints("%c. %s\n", (char)(i+97), choiceTexts[(a[i]).textI]);
	}
	prints("\n\n");
}

char getIn(Event* e){
	char buf[80] = "boo invalid value";
	//scanf("%s", buf);

	while(strlen(buf) != 1){
		drawScreen(e);
		prints("What do you choose? ");
		scanf("%s", buf);
	}

	return buf[0];
}

void drawScreen(Event* e){
	int i;
	for(i = 0; i < 20; i++){
		prints("\n");
	}

	prints("Week %i: \n\n", week+1);
	prints("%s\n\n", eventTexts[e->promptI]);
	printChoices(e);
}

void waitEnter(){
	prints("Press enter to continue... ");	// prompt
	int i = 0;
	char buf[50];
	while(getchar() != '\n'){	// wait for any preceding scanf() to flush out stdin buffer
		i++;
	}
	fgets(buf, 10, stdin);					// actual wait for Enter (or any other key really, we don't check)
}


int main(void) {
	initEvents();
	curE = ev[0];

	prints("Welcome to RPG385!\n");

	waitEnter();

	while(week < 10){
		char userSel;
		//drawScreen();
		userSel = getIn(curE);
		userSel -= 97; // turn ascii lowercase char into index num
		curE = ev[(int) (curE->choices)[userSel].nextEventI];

		waitEnter();
		week++;
	}

	return EXIT_SUCCESS;
}
