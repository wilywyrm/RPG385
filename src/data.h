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
		"You wake up and look out to see a blanket of snow about a foot thick. \nThe chancellor sent out an email letting you know that class was NOT canceled today. \nWelcome back to campus.\0",
		"You forget about your 385 Lab this week and miss it entirely, so you reschedule to go to the Thursday 3PM section. \nYou need to pick a TA. \0",
		"Career fair! Sadly, it cuts into all your classes for Tuesday.\0",
		"Surprise, midterms already!\0",
		"IEEE and ACM have had a falling out after a friendly coding competition. \nBeing a member of both, you are stuck in the middle.\n You need to pick a side in this nerdy gang war.\0",
		"\0",
		"It is pitch black. You are likely to be eaten by a grue.\0",
		"\0",
		"\0",
		"SURPRISE! 385 final is next Monday!\0",
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
		"I mean, it's not like you're paying to go here or anything.\0",
		"This couldn't possibly go wrong.\0",
		"Obviously the only real choice.\0",
		"You must be fun at parties, huh?\0",
		"Big mistake...\0",
		"Nice, it's what Jesus would do\0",
		"How original.\0",
		"1v1 me, 4-stock final dest\0",
		"EZ mode unlocked\0",
		"Feeling alpha, are we?\0",
		"Why would you ever do that?\0",
		"I hear Walmart is hiring\0",
		"You make great progress on your quest to become a vegetable\0",
		"You throw your lot in with president-for-eternity Brady Salz\0",
		"Whatever, man. We didn\'t want you here anyway.\0",
		"In fact, forget the RSO!\0",
		"I forget what happens next. Oh well.\0",
		"Become one with the building\0",
		"You can have a social life when you\'re dead, right?\0",
		"A paragon of virtue you are.\0",
		"You board the struggle bus with the rest of the class.\0"

};

#endif
