#include "board.h"

int gBoardInited = 0;

void board_init () {
	gBoardInited = 1;
}

void board_deinit () {
	gBoardInited = 0;
}

