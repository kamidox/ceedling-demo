#include "uart.h"

#define BUF_LEN = 10

char gBuffer[BUF_LEN] = "abCdEG=12C";

int gUartInited = 0;
int gPosIn = 0;
int gPosOut = 0;

void uart_init (void) {
	gUartInited = 1;
	gPosIn = 0;
	gPosOut = 0;
}

char uart_read (void) {
	if (!gUartInited) {
		return 0;
	}
	if (gPosIn >= BUF_LEN) {
		return 0;
	}
	return gBuffer[gPosIn ++];
}

void uart_write (char c) {
	if (!gUartInited) {
		return;
	}
	if (gPosOut >= BUF_LEN) {
		return;
	}
	gBuffer[gPosOut ++] = c;
}


