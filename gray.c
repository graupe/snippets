#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

static void
putbinary(uint32_t binary, uint8_t width)
{
	while(width--) {
		putchar('0' + !!(binary&1<<width));
		putchar(' ');
	}
}

int
main(int argc, char *argv[])
{
	uint32_t x;
	uint8_t width = 4;
	if (argc>1)
		width = atoi(argv[1]);
	x = 1<<width;
	while (x--) {
		putbinary(x^(x>>1), width);
		putchar('\n');
	}
	return EXIT_SUCCESS;
}
