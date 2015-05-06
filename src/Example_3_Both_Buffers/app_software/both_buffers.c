/* function prototypes */
void VGA_text (int, int, char *);
void VGA_box (int, int, int, int, short);

/********************************************************************************
 * This program demonstrates use of the character and pixel buffers
 *
 * It performs the following: 
 * 	1. Draws a blue box on the VGA display, and places a text string inside
 * 	   the box. Also, moves the word ALTERA around the display, "bouncing" off
 * 	   the blue box and screen edges
********************************************************************************/
int main(void)
{
	/* Declare volatile pointer to pixel DMA controller (volatile means that IO load
	   and store instructions will be used to access these pointer locations, 
	   instead of regular memory loads and stores) */
  	volatile int * Pixel_DMA_controller = (int *) 0x00008B000;	// DMA controller base address

	int delay = 0;	// synchronize with the screen drawing

	/* these variables are used for a blue box and a "bouncing" ALTERA on the VGA screen */
	int ALT_x1; int ALT_x2; int ALT_y; 
	int ALT_inc_x; int ALT_inc_y;
	int blue_x1; int blue_y1; int blue_x2; int blue_y2; 
	int screen_x; int screen_y; int char_buffer_x; int char_buffer_y;
	short color;

	/* create messages to be displayed on the VGA display */
	char text_top_VGA[20] = "Altera DE2\0";
	char text_bottom_VGA[20] = "Video Buffers\0";
	char text_ALTERA[10] = "ALTERA\0";
	char text_erase[10] = "      \0";

	/* the following variables give the size of the pixel buffer */
	screen_x = 319; screen_y = 239;
	color = 0x1863;		// a dark grey color
	VGA_box (0, 0, screen_x, screen_y, color);	// fill the screen with grey
	// draw a medium-blue box around the above text, based on the character buffer coordinates
	blue_x1 = 28; blue_x2 = 52; blue_y1 = 26; blue_y2 = 34;
	// character coords * 4 since characters are 4 x 4 pixel buffer coords (8 x 8 VGA coords)
	color = 0x187F;		// a medium blue color
	VGA_box (blue_x1 * 4, blue_y1 * 4, blue_x2 * 4, blue_y2 * 4, color);
	/* output text message in the middle of the VGA monitor */
	VGA_text (blue_x1 + 5, blue_y1 + 3, text_top_VGA);
	VGA_text (blue_x1 + 5, blue_y1 + 4, text_bottom_VGA);

	char_buffer_x = 79; char_buffer_y = 59;
	ALT_x1 = 0; ALT_x2 = 5/* ALTERA = 6 chars */; ALT_y = 0; ALT_inc_x = 1; ALT_inc_y = 1;
	VGA_text (ALT_x1, ALT_y, text_ALTERA);

	*(Pixel_DMA_controller) = 0;	// dummy write to start buffer swap process
	while (1)
	{
		if ( (*(Pixel_DMA_controller+3) & 1) == 0) // wait for Status register bit S == 0
		{
			/* If the screen has been drawn completely then we can draw a new image. This 
			 * section of the code will only be entered each time the screen is redrawn */
			delay = delay + 1;

			if (delay == 2)
			{
				delay = 0;
				/* The delay is inserted to slow down the animation */

				/* move the ALTERA text around on the VGA screen */
				VGA_text (ALT_x1, ALT_y, text_erase);		// erase
				ALT_x1 += ALT_inc_x; 
				ALT_x2 += ALT_inc_x; 
				ALT_y += ALT_inc_y;

				if ( (ALT_y == char_buffer_y) || (ALT_y == 0) )
					ALT_inc_y = -(ALT_inc_y);
				if ( (ALT_x2 == char_buffer_x) || (ALT_x1 == 0) )
					ALT_inc_x = -(ALT_inc_x);

				if ( (ALT_y >= blue_y1 - 1) && (ALT_y <= blue_y2 + 1) )
				{
					if ( ((ALT_x1 >= blue_x1 - 1) && (ALT_x1 <= blue_x2 + 1)) ||
						((ALT_x2 >= blue_x1 - 1) && (ALT_x2 <= blue_x2 + 1)) )
					{
						if ( (ALT_y == (blue_y1 - 1)) || (ALT_y == (blue_y2 + 1)) )
							ALT_inc_y = -(ALT_inc_y);
						else
							ALT_inc_x = -(ALT_inc_x);
					}
				}
				VGA_text (ALT_x1, ALT_y, text_ALTERA);
			}
			/* Execute a swap buffer command. This will allow us to check if the screen has 
			 * been redrawn before generating a new animation frame. */
			*(Pixel_DMA_controller) = 0;	
		}
	}
}

/****************************************************************************************
 * Subroutine to send a string of text to the VGA monitor 
****************************************************************************************/
void VGA_text(int x, int y, char * text_ptr)
{
	int offset;
  	volatile char * character_buffer = (char *) 0x00088000;	// VGA character buffer

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
  	volatile short * pixel_buffer = (short *) 0x00000000;	// VGA pixel buffer

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
