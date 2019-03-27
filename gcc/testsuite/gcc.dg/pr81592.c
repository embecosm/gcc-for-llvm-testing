/* { dg-do compile } */
/* { dg-options "-O2 -Wall -fno-strict-overflow  -Wstrict-overflow=2 -fsanitize=signed-integer-overflow" } */
/* { dg-require-effective-target gcc_frontend } */

#include <stdio.h>

int proc_keys_show(long expiry, long now)
{
	unsigned long timo;
	char xbuf[4];

	if (now < expiry) {
		timo = expiry - now;
		if (timo < 60)
			sprintf(xbuf, "%lus", timo);
	}

	return 0;
}


