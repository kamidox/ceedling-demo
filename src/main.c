#include "main.h"
#include "board.h"
#include "uart.h"

#ifndef __TEST__
int main (void) {
	AppMain();
}
#endif

int AppMain (void) {
	int ret = 0;
	board_init();

	uart_init();

	while (1) {
		unsigned char c = uart_read();
		if (c == 0) {
			break;
		} else if (c >= 0x41 && c <= 0x5A) {
			c += 0x20;
		}
		ret ++;
		uart_write(c);
	}
	board_deinit();
	return ret;
}

