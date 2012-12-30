#include<stdlib.h>
#include<stdio.h>
#include<string.h> /* memset */

/* terminal width */
static const int width=80;
/* amplitude of oszilation. (0, +2*amp) will be scaled to (0, width) */
static const double amp=0.5;
/*
 * Numerical oszillator for stimulation purposes. Not very impressive, but I
 * liked the simplicity of generating a waveform that resembles sin/cos other
 * than calling sinus on a liner function.
 */
int
main(int argc, char *argv[])
{
	char line[width+2];
	double s=0.1;
	double x=amp;
	double y=0.0;
	memset(line, ' ', sizeof line-2);
	line[sizeof line-2] = '*';
	line[sizeof line-1] = '\0';
	for(;;) {
		int i= .5+(amp+x)*width;
		/* I forgot both, the source and the math behind using the new x
		 * in the calculation of the new y, but it is actually correct
		 * and reduces the error of the oszillation */
		x += s*y;
		y -= s*x;
		puts(line+i);
	}
	return EXIT_SUCCESS;
}
