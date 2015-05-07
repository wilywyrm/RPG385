//#include "display.h"
#include "data.h"
#include "colors.h"

/* function prototypes */
void VGA_text (int, int, char *);
void VGA_box (int, int, int, int, short);

volatile int * Pixel_DMA_controller = (int *) 0x10203040;	// DMA controller base address
volatile char * character_buffer = (char *) 0x10200000;		// VGA character buffer
volatile short * pixel_buffer = (short *) 0x10000000;		// VGA pixel buffer
volatile char * keycode = (char *) 0x10203030;				// Keycode PIO address
volatile char * press = (char *) 0x10203010;				// Keypress PIO address

const short BGCOLOR = DarkGray;
const short BOXCOLOR = MedGray;
const int YPADDING = 8;	// text padding
const int XPADDING = 10;
const int SCRWIDTH = 81;// screen dimensions in text columns/rows
const int SCRHIGHT = 59;
const int SCRPIXW = 319;// screen dimensions in pixel width (320x240)
const int SCRPIXH = 239;

int curTextY;	// the current Y position of the next text to be put on the screen
int choice = 0;	// current choice
int numChoices;	// choice count (if there are less than 4 valid choices), not used

// keycodes
const char UP = 0x75;
const char DOWN = 0x72;
const char LEFT = 0x6B;
const char RIGHT = 0x74;
const char ENT = 0x5A;
const char ESC = 0x76;

// selector square constants
const int SELXOFFSET = 25;
const int SELYOFFSET = 110;
const int SELWIDTH = 5;
const int SELCHOICEHEIGHT = 13;


int week = 0;

int hap = 100;	// happiness
int hyg = 100;	// hygiene
int grd = 100;	// grades
int diff = 8;	// arbitrary magic number

Event* ev[10];
Event* curE;

int main(void)
{
	START: // dirty GOTO
	// init things
	initEvents();
	curE = ev[0];
	choice = 0;
	week = 0;

	// basically constants, for the position of the text background boxes
	// can't put them with the global constants because they depend on each other
	int TXTBOXX1 = 20;	// text box x positions (for both events and choices)
	int TXTBOXX2 = SCRPIXW - TXTBOXX1;
	int EVBOXY1 = 20;			// event box Y-positions
	int EVBOXY2 = 70 + EVBOXY1;
	int CHBOXY1 = EVBOXY2 + 10;	// character box Y-position
	int CHBOXY2 = 100 + CHBOXY1;

	hap = 100;
	hyg = 100;
	grd = 100;
	diff = 8;	// arbitrary magic number
	/* Declare volatile pointer to pixel DMA controller (volatile means that IO load
	   and store instructions will be used to access these pointer locations,
	   instead of regular memory loads and stores) */
	//int delay = 0;	// synchronize with the screen drawing

	/* these variables are used for a blue box and a "bouncing" ALTERA on the VGA screen */
	int box_x1; int box_y1; int box_x2; int box_y2;
	//short color;

	/* create messages to be displayed on the VGA display */
	/*char text_top_VGA[20] = "Altera DE2\0";
	char text_bottom_VGA[20] = "Video Buffers\0";
	char text_ALTERA[10] = "ALTERA\0";
	char text_erase[10] = "      \0";*/

	/* the following variables give the size of the pixel buffer */
	//screen_x = 319; screen_y = 239;
	//color = 0x1863;		// a dark grey color
	//VGA_box (0, 0, SCRPIXW, SCRPIXH, Black);	// fill the screen with grey
	// draw a medium-blue box around the above text, based on the character buffer coordinates
	box_x1 = 28; box_x2 = 52; box_y1 = 23; box_y2 = 31;
	// character coords * 4 since characters are 4 x 4 pixel buffer coords (8 x 8 VGA coords)
	//color = 0x187F;		// a medium blue color

	/* output text message in the middle of the VGA monitor */
	//VGA_text (box_x1 + 5, box_y1 + 3, text_top_VGA);
	//VGA_text (box_x1 + 5, box_y1 + 4, text_bottom_VGA);

	//char_buffer_x = 79; char_buffer_y = 59;
	//ALT_x1 = 0; ALT_x2 = 5/* ALTERA = 6 chars */; ALT_y = 0; ALT_inc_x = 1; ALT_inc_y = 1;
	//VGA_text (ALT_x1, ALT_y, text_ALTERA);
	//flushChar();
	//flush();

	// splash screen
	initFrame();
	//flushChar();
	//flushPixels();
	VGA_box (box_x1 * 4, box_y1 * 4, box_x2 * 4, box_y2 * 4, Orange);
	VGA_text(box_x1+9, box_y1+4, "RPG385\0");

	// flash "press any key to continue"
	int delay = 0;
	while(!((*press & 0x1))){	// while no key pressed
		delay++;
		if(delay == 50000){
			VGA_text(box_x1-1, box_y1+14, "                             \0");
		}
		else if (delay == 1){
			VGA_text(box_x1-1, box_y1+14, "Press any key to continue...\0");
		}
		else if(delay == 100000)
			delay = 0;

	}
	waitRelease();
	//waitPress();



	//curTextY = YPADDING;
	//flushPixels();
	//flushChar();
	//curTextY = YPADDING;
	initFrame();
	*(Pixel_DMA_controller) = 0;	// dummy write to start buffer swap process
	while (1)	// the game
	{
			while(week < 10){ // we only have 10 weeks
				//addToScreen(XPADDING, "lol\0");
				if ( (*(Pixel_DMA_controller+3) & 1) == 0){ // wait for Status register bit S == 0
					//initFrame();
					// make text background boxes
					VGA_box(TXTBOXX1, EVBOXY1, TXTBOXX2, EVBOXY2, BOXCOLOR);
					VGA_box(TXTBOXX1, CHBOXY1, TXTBOXX2, CHBOXY2, BOXCOLOR);
					char buf[100];
					sprintf(buf, "Week %i: \n\n\0", week+1);
					addToScreen(XPADDING, buf);	// print week
					addToScreen(XPADDING, eventTexts[curE->promptI]);	// print week event text
					printChoices(curE);	// print event choices
					// draw choice selector box
					VGA_box(SELXOFFSET, SELYOFFSET+choice*SELCHOICEHEIGHT, SELXOFFSET+SELWIDTH, SELYOFFSET+SELWIDTH+choice*SELCHOICEHEIGHT, White);
					delay = 0;
					// change choice and selector box while choice not finalized
					while(!((*press & 0x1) && (*keycode == ENT))){

						if((*press & 0x1) && (*keycode == UP)){	// handle up button
							int temp = choice;
							//change choice
							choice--;
							if(choice < 0)
								choice = 3;
							// erase old box
							VGA_box(SELXOFFSET, SELYOFFSET+temp*SELCHOICEHEIGHT, SELXOFFSET+SELWIDTH, SELYOFFSET+SELWIDTH+temp*SELCHOICEHEIGHT, BOXCOLOR);
							// draw new box
							VGA_box(SELXOFFSET, SELYOFFSET+choice*SELCHOICEHEIGHT, SELXOFFSET+SELWIDTH, SELYOFFSET+SELWIDTH+choice*SELCHOICEHEIGHT, White);
							waitRelease();
						}
						else if((*press & 0x1) && (*keycode == DOWN)){ // handle down button
							int temp = choice;
							// change choice
							choice++;
							if(choice > 3)
								choice = 0;
							// erase old box
							VGA_box(SELXOFFSET, SELYOFFSET+temp*SELCHOICEHEIGHT, SELXOFFSET+SELWIDTH, SELYOFFSET+SELWIDTH+temp*SELCHOICEHEIGHT, BOXCOLOR);
							// draw new box
							VGA_box(SELXOFFSET, SELYOFFSET+choice*SELCHOICEHEIGHT, SELXOFFSET+SELWIDTH, SELYOFFSET+SELWIDTH+choice*SELCHOICEHEIGHT, White);
							waitRelease();

						}

						delay++;
						// flash selector box
						if(delay == 40000){
							//VGA_text(box_x1-1, box_y1+14, "                             \0");
							VGA_box(SELXOFFSET, SELYOFFSET+choice*SELCHOICEHEIGHT, SELXOFFSET+SELWIDTH, SELYOFFSET+SELWIDTH+choice*SELCHOICEHEIGHT, BOXCOLOR);
						}
						else if (delay == 1){
							VGA_box(SELXOFFSET, SELYOFFSET+choice*SELCHOICEHEIGHT, SELXOFFSET+SELWIDTH, SELYOFFSET+SELWIDTH+choice*SELCHOICEHEIGHT, White);
							//VGA_text(box_x1-1, box_y1+14, "Press any key to continue...\0");
						}
						else if(delay == 80000)
							delay = 0;

					}
					waitRelease();
					// erase selector box
					VGA_box(SELXOFFSET, SELYOFFSET+choice*SELCHOICEHEIGHT, SELXOFFSET+SELWIDTH, SELYOFFSET+SELWIDTH+choice*SELCHOICEHEIGHT, BOXCOLOR);
					// print game response to player choice selection
					addToScreen(XPADDING, choiceResponses[((curE->choices)[choice]).responseI]);
					// print adjustments to stats from that choice
					char temp[100];
					sprintf(temp, "\n%+i HAP, %+i HYG, %+i GRD, %+i DIF \0", ((curE->choices)[choice]).impacts[0], ((curE->choices)[choice]).impacts[1], ((curE->choices)[choice]).impacts[2], ((curE->choices)[choice]).impacts[3]);
					addToScreen(XPADDING, temp);

					// modify and clamp values of modified stats
					hap += ((curE->choices)[choice]).impacts[0];
					hap = (hap > 100)? 100: hap;
					hyg += ((curE->choices)[choice]).impacts[1];
					hyg = (hyg > 100)? 100: hyg;
					grd += ((curE->choices)[choice]).impacts[2];
					grd = (grd > 100)? 100: grd;
					diff +=((curE->choices)[choice]).impacts[3];

					addToScreen(XPADDING, "\nPress any key to continue...\0");
					waitPress();

					// handle game over
					if(hap < 0 || hyg < 0 || grd < 0) // lose condition
						break;

					// setup next week event
					week++;
					curE = ev[((curE->choices)[choice]).nextEventI];
					//waitPress();
					initFrame();
					//flushPixels();
					//flushChar();
					//curTextY = YPADDING;
					//flush();

					/* Execute a swap buffer command. This will allow us to check if the screen has
					 * been redrawn before generating a new animation frame. */
					*(Pixel_DMA_controller) = 0;

				}

			//}

			/*if(delay == 5){
				//clear();
				initFrame();
				delay = 0;
			}*/



		}

		// game over screen
		flushChar();
		curTextY = YPADDING;
		// tally score
		int score = (hap + hyg + grd) * diff;
		// lose scenarios
		if(hap < 0)
			addToScreen(XPADDING, "Sadly you worked yourself to the bone this semester, \nand one day you just burned out from \nbeing unhappy all the time. \n\nLooks like you\'ll be taking a gap semester, buddy.\n\n\n\0");
		else if(hyg < 0)
			addToScreen(XPADDING, "You let yourself go, big time. \nAt first, people just gave you a big berth in the hallway, \nthen your friends stopped hanging out with you because of your smell, \nbut now the EPA came and sealed you off in your apartment. \n\nMaybe you can try again next semester, \nafter you\'ve been decontaminated?\n\n\n\0");
		else if(grd < 0)
			addToScreen(XPADDING, "It turns out if you flunk out of all your classes, \nyou get kicked out of them. \nWho knew? \n\nGuess you\'ll have to wait until next semester to try again.\n\n\n\0");
		// win scenario
		else
			addToScreen(XPADDING, "Congrats, you made it through 385 while somehow keeping sane!\nWant to try it again? \n\n\n\0");

		// print stats
		char temp[100];
		sprintf(temp, "Happiness: %i\0", hap);
		addToScreen(XPADDING, temp);
		sprintf(temp, "Hygiene: %i\0", hyg);
		addToScreen(XPADDING, temp);
		sprintf(temp, "Grades: %i\0", grd);
		addToScreen(XPADDING, temp);
		sprintf(temp, "Total Score: %i\0", score);
		addToScreen(XPADDING, temp);
		// wait for key press to restart
		addToScreen(XPADDING, "\nPress any key to play again...\0");
		waitPress();
		goto START;	// i am a bad programmer

	}
}


// event constructor workaround because this is C
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
		for(a = 0; a < 4; a++)
			c[i].impacts[a] = choiceImpacts[i*4 + a];
	}

	//printf("%i\n", c[0].textI);

	return e;
}

// initialize Events of the game to point to the strings in data.h for events/choices/responses
void initEvents(){
	int* cTI;	// choice text indices
	int* cRI;	// choice response indices
	int* cNI;	// choice next event indices
	int* cI	;	// choice impacts (on happiness, hygiene, grades, difficulty)

	cTI = (int[4]) {0, 1, 2, 3};
	cRI = (int[4]) {0, 0, 3, 5};
	cNI = (int[4]) {1, 1, 1, 1};
	cI  = (int[16]) { 	0, 0, 0, 0,
						0, 0, 0, 0,
						-10, 0, 10, 0,
						15, -5, -20, 2};
	ev[0] = Event_new(0, cTI, cRI, cNI, cI);
	cTI = (int[4]) {4, 5, 6, 3};
	cRI = (int[4]) {8, 7, 9, 1};
	cNI = (int[4]) {2, 2, 2, 2};
	cI  = (int[16]) { 	0, 0, 10, 0,
						10, 0, -10, 0,
						0, -5, -20, 1,
						15, -5, -20, 2};
	ev[1] = Event_new(1, cTI, cRI, cNI, cI);

	cTI = (int[4]) {7, 8, 9, 3};
	cRI = (int[4]) {12, 3, 11, 2};
	cNI = (int[4]) {3, 3, 3, 3};
	cI  = (int[16]) { 	10, 0, -10, 0,
						-10, 0, 5, 0,
						10, 0, -5, 0,
						15, -5, -20, 2};
	ev[2] = Event_new(2, cTI, cRI, cNI, cI);

	cTI = (int[4]) {20, 15, 7, 3};
	cRI = (int[4]) {10, 1, 1, 1};
	cNI = (int[4]) {4, 4, 4, 4};
	cI  = (int[16]) { 	-10, -10, 10, 0,
						10, 0, -15, 0,
						10, 0, -15, 0,
						15, -5, -20, 2};
	ev[3] = Event_new(3, cTI, cRI, cNI, cI);

	cTI = (int[4]) {11, 12, 13, 3};
	cRI = (int[4]) {13, 14, 15, 2};
	cNI = (int[4]) {5, 5, 5, 5};
	cI  = (int[16]) { 	0, -10, 10, 0,
						10, 0, -10, 0,
						15, -10, -5, 0,
						15, -5, -20, 2};
	ev[4] = Event_new(4, cTI, cRI, cNI, cI);

	cTI = (int[4]) {3, 3, 3, 3};
	cRI = (int[4]) {22, 22, 22, 22};
	cNI = (int[4]) {6, 6, 6, 6};
	cI  = (int[16]) { 	15, -5, -10, 2,
						15, -5, -10, 2,
						15, -5, -10, 2,
						15, -5, -10, 2};
	ev[5] = Event_new(5, cTI, cRI, cNI, cI);

	cTI = (int[4]) {14, 15, 16, 3};
	cRI = (int[4]) {10, 2, 20, 20};
	cNI = (int[4]) {7, 7, 7, 7};
	cI  = (int[16]) { 	0, 0, 5, 0,
						5, 0, -15, 1,
						-10, 0, 10, 0,
						15, -5, -20, 2};
	ev[6] = Event_new(6, cTI, cRI, cNI, cI);

	cTI = (int[4]) {17, 18, 19, 3};
	cRI = (int[4]) {16, 6, 17, 0};
	cNI = (int[4]) {8, 8, 8, 8};
	cI  = (int[16]) { 	0, 0, 0, 0,
						5, 5, 0, 0,
						0, -20, 0, 1,
						15, -5, -20, 2};
	ev[7] = Event_new(7, cTI, cRI, cNI, cI);

	cTI = (int[4]) {20, 21, 22, 3};
	cRI = (int[4]) {18, 18, 18, 18};
	cNI = (int[4]) {9, 9, 9, 9};
	cI  = (int[16]) { 	-15, 0, -20, 0,
						-15, 0, -20, 0,
						-15, 0, -20, 0,
						-15, 0, -20, 0};
	ev[8] = Event_new(8, cTI, cRI, cNI, cI);

	cTI = (int[4]) {23, 20, 24, 3};
	cRI = (int[4]) {21, 19, 1, 6};
	cNI = (int[4]) {0, 0, 0, 0};
	cI  = (int[16]) { 	-10, -10, 10, 1,
						-15, -10, 15, 1,
						10, 0, -20, 1,
						15, -5, -20, 2};
	ev[9] = Event_new(9, cTI, cRI, cNI, cI);

}

// print choices of the event
void printChoices(Event* e){
	curTextY = 26;
	//numChoices = 0;

	addToScreen(XPADDING, "What do you do?\n\0");

	int i;
	Choice* a = e->choices;
	for(i = 0; i < 4; i++){
		if(a[i].nextEventI != -1){ // we don't print a choice with nextEvent index of -1
			//numChoices++;
			char buf[100];
			sprintf(buf, "%c. %s\n\n", (char)(i+97), choiceTexts[(a[i]).textI]);
			addToScreen(XPADDING, buf);
			//prints("%c. %s\n", (char)(i+97), choiceTexts[(a[i]).textI]);
		}
	}
	curTextY += 2;
	if(curTextY >= (SCRHIGHT - YPADDING) ){
		curTextY = YPADDING;
	}
	//prints("\n\n");
}

// this function assumes only one line of text, which is sanely selected
void blinkText(int x, int y, char* text){
	// implementation would work better with interrupts
}

// wait for a press of the "any" key
void waitPress(){
	int i = 0;
	while(!((*press & 0x1))){	// while no key pressed
		i++;	// wait
	}
	waitRelease();	// then wait for a release of the key
}

// wait for a release of all keys of the keyboard
void waitRelease(){
	int i = 0;
	while(*press & 0x1){
		i++;
	}
}

// wrapper to handle adding text to the screen, with minimal protections
// handles text wrapping
// handles newlines on '\n' and end of string ('\0')
// does NOT handle text Y going beyond screen bounds except by printing from the top

void addToScreen(int x, char* text_ptr)
{
	//char cur = text_ptr[0];
	char buf[100];	// buffer to parse multi-line strings
	buf[0] = '\0'; // init first one, in case we are passed a string of just '\0'
	int pos = 0;

	while ( *(text_ptr) ){	// while char array not terminated
		if(*(text_ptr) == '\n'){	// if current char is a newline
			buf[pos] = '\0';		// terminate the buffer
			VGA_text(x, curTextY, buf);	// push to screen
			pos = 0;				// reset buffer position

			curTextY++;				// increment Y, with bounds
			if(curTextY >= SCRHIGHT - YPADDING){
				curTextY = YPADDING;
			}
		}
		else{	// if current char isn't a newline
			if(pos + x >= (SCRWIDTH - x) ){ // we hit the edge of our writable screen space
				buf[pos] = '\0';		// terminate the buffer
				VGA_text(x, curTextY, buf);	// push to screen
				pos = 0;				// reset buffer position

				curTextY++;				// increment Y, with bounds
				if(curTextY >= SCRHIGHT - YPADDING){
					curTextY = YPADDING;
				}
			}

			buf[pos] = *(text_ptr);	// add it to the buffer
			pos++;
		}

		text_ptr++;	// move on
	}
	buf[pos] = '\0';
	VGA_text(x, curTextY, buf);	// push out whatever's left in the buffer (last sentence)
	//VGA_text(x, curTextY, text_ptr);
	curTextY++;
	if(curTextY >= (SCRHIGHT - YPADDING) ){
		curTextY = YPADDING;
	}
}

void initFrame()
{
	flush();
	curTextY = YPADDING;
}

void flush(){
	flushPixels();
	flushChar();
}

void flushPixels(){
	VGA_box (0, 0, SCRPIXW, SCRPIXH, BGCOLOR);
}

void flushChar()
{
	char temp[100];
	//int screenWidth = 81;
	//int screenHeight = 59;
	int i = 0;
	for(i = 0; i < SCRWIDTH-1; i++){
		temp[i] = ' ';
	}
	temp[SCRWIDTH] = '\0';

	for(i = 0; i <= SCRHIGHT; i++)
		VGA_text(0, i, temp);
}

/****************************************************************************************
 * Subroutine to send a string of text to the VGA monitor
****************************************************************************************/
void VGA_text(int x, int y, char * text_ptr)
{
	int offset;

	/* assume that the text string fits on one line */
	offset = (y << 7) + x;
	while ( *(text_ptr) )
	{
		*(character_buffer + offset) = *(text_ptr);	// write to the character buffer
		++text_ptr;
		++offset;
	}
}

/****************************************************************************************
 * Draw a filled rectangle on the VGA monitor
****************************************************************************************/
void VGA_box(int x1, int y1, int x2, int y2, short pixel_color)
{
	int offset, row, col;

	/* assume that the box coordinates are valid */
	for (row = y1; row <= y2; row++)
	{
		col = x1;
		while (col <= x2)
		{
			offset = (row << 9) + col;
			*(pixel_buffer + offset) = pixel_color;	// compute halfword address, set pixel
			++col;
		}
	}
}
