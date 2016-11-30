#include "unity.h"
#include "main.h"
#include "mock_uart.h"
#include "board.h"

void setUp (void) {}
void tearDown (void) {}

void test_main_should_call_board_init (void) {
	extern int gBoardInited;
	uart_init_Expect();
	uart_read_ExpectAndReturn(0);

	AppMain();

	TEST_ASSERT_EQUAL(gBoardInited, 0);
}

void test_main_should_work_properly (void) {
	int ret;

	uart_init_Expect();
	uart_read_ExpectAndReturn('A');
	uart_write_Expect('a');

	uart_read_ExpectAndReturn('b');
	uart_write_Expect('b');

	uart_read_ExpectAndReturn('1');
	uart_write_Expect('1');

	uart_read_ExpectAndReturn('!');
	uart_write_Expect('!');

	uart_read_ExpectAndReturn(0);

	ret = AppMain();
	TEST_ASSERT_EQUAL(ret, 4);
}

