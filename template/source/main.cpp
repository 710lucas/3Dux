// Simple citro2d untextured shape example

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "3dux/3dux.h"


#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

	u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	u32 clrGreen = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
	u32 clrRed   = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
	u32 clrBlue  = C2D_Color32(0x00, 0x00, 0xFF, 0xFF);

//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------

	Dux game;
	game.init();

	Rectangle rec(10, 10, 10, 10, clrWhite);

	printf("\nYour game!");

	while (aptMainLoop())
	{
		game.update_buttons();

		if (game.pressed(KEY_START))
			break; // break in order to return to hbmenu
		if (game.held(KEY_RIGHT))
			rec.move(5, 0);
		if (game.held(KEY_UP))
			rec.move(0, 5);
		if(game.held(KEY_DOWN))
			rec.move(0,-5);

		game.begin_render();
		rec.render();
		/*
		You can render things between begin_render() and end_render()
		*/

		game.end_render();
	}

	// Deinit libs
	game.end();
	return 0;
}
