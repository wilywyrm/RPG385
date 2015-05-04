#ifndef DATA_H
#define DATA_H

typedef struct Choice {
	//char* text;
	//char* response;
	int textI;
	int responseI;
	int nextEventI;
	int impacts[3];
} Choice;

typedef struct Event {
	//char* prompt;
	int promptI;
	Choice* choices;
} Event;


const char* eventTexts[] = {
		"You wake up and look out to see a blanket of snow about a foot thick. \nThe chancellor sent out an email letting you know that class was NOT canceled today. \nWelcome back to campus.",
		"You forget about your 385 Lab this week and miss it entirely, so you reschedule to go to the Thursday 3PM section. \nYou need to pick a TA. ",
		"Career fair! Sadly, it cuts into all your classes for Tuesday. ",
		"Surprise, midterms already! ",
		"IEEE and ACM have had a falling out after a friendly coding competition. \nBeing a member of both, you are stuck in the middle.\n You need to pick a side in this nerdy gang war.",
		"",
		"It is pitch black. You are likely to be eaten by a grue.",
		"",
		"",
		"SURPRISE! 385 final is next Monday!",
};

const char* choiceTexts[] = {
		"Stay in bed. It's chillabus week, right?",
		"Contemplate the wisdom of your decision to go to this school",
		"Trudge out into the frozen wasteland and go to class",
		"TURN UP", // Turning up is always an option
		"Stay in bed",
		"Go anyway",
		"Go ice skating with your buds",
		"Go to Cravings",
		"Pick IEEE",
		"Pick ACM",
		"Screw this, start your own RSO with blackjack and hookers",
		"Grab some red bull from County and study your ass off",
		"Watch Netflix in bed."
};

const char* choiceResponses[] = {
		"\n",
		"I mean, it's not like you're paying to go here or anything.",
		"This couldn't possibly go wrong.",
		"Obviously the only real choice.",
		"You must be fun at parties, huh?",
		"Big mistake...",
		"Nice, it's what Jesus would do.",
		"How original.",
};

#endif
