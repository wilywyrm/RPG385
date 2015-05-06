#ifndef DATA_H
#define DATA_H

typedef struct Choice {
	//char* text;
	//char* response;
	int textI;
	int responseI;
	int nextEventI;
	int impacts[4];
} Choice;

typedef struct Event {
	//char* prompt;
	int promptI;
	Choice* choices;
} Event;

const char* openingText = "A long time ago, in a ";

const char* eventTexts[] = {
		"You wake up and look out to see a blanket of snow about\n a foot thick.\nThe chancellor sent out an email letting you know\nthat class was NOT canceled today. \n\nWelcome back to campus.\0",
		"You forget about your 385 Lab this week \nand miss it entirely, so you reschedule to go to the Thursday 3PM section. \nYou need to pick a TA. \0",
		"Career fair! Sadly, it cuts into all your classes for \nTuesday.\0",
		"Surprise, midterms already!\0",
		"IEEE and ACM have had a falling out after a \nfriendly coding competition. \nBeing a member of both, you are stuck in the middle.\n\nYou need to pick a side in this nerdy gang war.\0",
		"Unofficial.\0",	// 5
		"After you stopped attending 385 lecture in the second week,\nyour life has improved dramatically. \nYou lose 15 pounds, your IQ doubles, \nand you have so much time that you learn three new languages. \nSadly, you accidentally step into 1002 at 4:08PM, \nand you become a total slob again. \n\nYou also learn that 385 final project has kicked off.\0",
		"It is the day before lab demos, \nand you decide to just now start on implementing AES \ndecryption. \nAfter banging your head on the desk for 8 STRAIGHT hours, \nyou give up and walk out of the building. \n\nIt is pitch black. You are likely to be eaten by a grue.\0",
		"SURPRISE! 385 final is next Monday!\0",
		"Final project is due this week, \nbut you have your most important finals Friday. \n\nBecause your time-management skills are non-existent, \nyou only have a limited number of ways to poorly allot \nyour time. \0"
};

const char* choiceTexts[] = {
		"Stay in bed. It's chillabus week, right?\0",
		"Contemplate the wisdom of your decision to go to \n   this school\0",
		"Trudge out into the frozen wasteland and go to class\0",
		"TURN UP\0", // Turning up is always an option
		"Pick Den Belay\0",
		"Pick Kohn Jim\0",	// 5
		"Start a fight in lab to avoid making a real decision\0",
		"Stay in bed\0",
		"Go to class anyway\0",
		"Go to the fair and awkwardly stumble around \n   in hopes of scoring that Google internship",
		"Go to Cravings\0",	// 10
		"Pick IEEE\0",
		"Pick ACM\0",
		"Screw this, start your own RSO with blackjack and hookers\0",
		"Find your lab partner who you haven\'t seen for 2 weeks\0",
		"Don\'t sweat it.\0",	// 15
		"Set your mind to following the timeline on the 385 course\n   website\0",
		"Further investigate to reveal more about their nature\0",
		"Head back home and get some shuteye\0",
		"Decide you might as well stay in ECEB for the night\0",
		"Grab some red bull from County and study until your eyes \n   fall out\0",	// 20
		"Watch Netflix in bed\0",
		"Focus on final project instead\0",
		"Sweat it out in 3022 for the next week with your smelly \n   classmates.\0",
		"Never crawl out of bed this week. \0"
};

const char* choiceResponses[] = {
		"I mean, it's not like you're paying to go here or anything.\0",
		"This couldn't possibly go wrong.\0",
		"Obviously the only real choice.\0",
		"You must be fun at parties, huh?\0",
		"Big mistake...\0",
		"Nice, it's what Jesus would do\0",		// 5
		"How original.\0",
		"1v1 me, 4-stock final dest\0",
		"EZ mode unlocked\0",
		"Feeling alpha, are we?\0",
		"Why would you ever do that?\0",		// 10
		"I hear Walmart is hiring\0",
		"You make great progress on your quest to become a vegetable\0",
		"You throw your lot in with president-for-eternity Brady Salz\0",
		"Whatever, man. We didn\'t want you here anyway.\0",
		"In fact, forget the RSO!\0",			// 15
		"Well, I\'m all out of Zork references.\0",
		"Become one with the building\0",
		"YOU GET AN F, YOU GET AN F, EVERYONE GETS AN F!\0",
		"You can have a social life when you\'re dead, right?\0",
		"A paragon of virtue you are.\0",		// 20
		"The struggle bus has room for all.\0",
		"You ever get the feeling you really have no choice \nin the matter?\0"

};

#endif
