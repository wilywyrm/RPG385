#ifndef DATA_H
#define DATA_H

typedef struct Choice {
	//char* text;
	//char* response;
	int textI;
	int responseI;
	int nextEventI;
} Choice;

typedef struct Event {
	//char* prompt;
	int promptI;
	Choice* choices;
} Event;


const char* eventTexts[] = {
		"Welcome to RPG385!",
		"",
};

const char* choiceTexts[] = {
		"as",
		"sd",
		"df",
		"TURN UP"
};

const char* choiceResponses[] = {
		"\n",
		"How original.",
};

#endif
