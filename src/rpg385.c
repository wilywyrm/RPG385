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


Event* ev[16];
Event* curE;

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

	//printf("%i\n", c[0].textI);

	return e;
}

void initEvents(){
	int* cTI;	// choice text indices
	int* cRI;	// choice response indices
	int* cNI;	// choice next event indices

	cTI = (int[4]) {0, 1, 2, 3};
	cRI = (int[4]) {0, 1, 2, 3};
	cNI = (int[4]) {1, 1, 1, 1};
	ev[0] = Event_new(0, cTI, cRI, cNI);
	//int i = 0;
	//Choice* a = ev[0]->choices;
	//for(i = 0; i < 4; i++){
	//	prints("%i %c. %s\n", i, (char)(i+97), choiceTexts[(a[i]).textI]);
	//}
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
		prints("%c. %s\n", (char)(i+97), choiceTexts[(a[i]).textI]);
	}
	prints("\n\n");
}

char getIn(){
	char buf[80] = "boo invalid value";
	//scanf("%s", buf);

	while(strlen(buf) != 1){
		drawScreen();
		prints("What do you choose? ");
		scanf("%s", buf);
	}

	return buf[0];
}

void drawScreen(){
	int i;
	for(i = 0; i < 20; i++){
		printf("\n");
	}

	printf("Week %i: \n\n", week);
	printf("%s\n\n", eventTexts[curE->promptI]);
	printChoices(curE);
}

void waitEnter(){
	printf("Press enter to continue... ");
	int i = 0;
	while(getchar() == "\n"){
		i++;
	}
	getchar();
}


int main(void) {
	initEvents();
	curE = ev[0];

	prints(eventTexts[0]);

	while(week < 15){
		char userSel;
		//drawScreen();
		userSel = getIn();
		waitEnter();
		week++;
	}

	return EXIT_SUCCESS;
}
