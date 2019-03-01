/* pseudo code for reverse function

	initialize an int array of same size S ASCIINAMES set all element s to 0
	read in file line by line
		for each char
			increment the counter array for that char

	loop over all asciinames
		print if more than 0


end of pseudo code
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char asciiname[] =
	    "NUL\0"  "SOH\0"  "STX\0"  "ETX\0"  "EOT\0"  "ENQ\0"  "ACK\0"  "BEL\0"
	    " BS\0"  " HT\0"  " NL\0"  " VT\0"  " NP\0"  " CR\0"  " SO\0"  " SI\0"
	    "DLE\0"  "DC1\0"  "DC2\0"  "DC3\0"  "DC4\0"  "NAK\0"  "SYN\0"  "ETB\0"
	    "CAN\0"  " EM\0"  "SUB\0"  "ESC\0"  " FS\0"  " GS\0"  " RS\0"  " VS\0"
	    " SP\0"  "  !\0"  "  \"\0" "  #\0"  "  $\0"  "  %\0"  "  &\0"  "  '\0"
	    "  (\0"  "  )\0"  "  *\0"  "  +\0"  "  ,\0"  "  -\0"  "  .\0"  "  /\0"
	    "  0\0"  "  1\0"  "  2\0"  "  3\0"  "  4\0"  "  5\0"  "  6\0"  "  7\0"
	    "  8\0"  "  9\0"  "  :\0"  "  ;\0"  "  <\0"  "  =\0"  "  >\0"  "  ?\0"
	    "  @\0"  "  A\0"  "  B\0"  "  C\0"  "  D\0"  "  E\0"  "  F\0"  "  G\0"
	    "  H\0"  "  I\0"  "  J\0"  "  K\0"  "  L\0"  "  M\0"  "  N\0"  "  O\0"
	    "  P\0"  "  Q\0"  "  R\0"  "  S\0"  "  T\0"  "  U\0"  "  V\0"  "  W\0"
	    "  X\0"  "  Y\0"  "  Z\0"  "  [\0"  "  \\\0" "  ]\0"  "  ^\0"  "  _\0"
	    "  `\0"  "  a\0"  "  b\0"  "  c\0"  "  d\0"  "  e\0"  "  f\0"  "  g\0"
	    "  h\0"  "  i\0"  "  j\0"  "  k\0"  "  l\0"  "  m\0"  "  n\0"  "  o\0"
	    "  p\0"  "  q\0"  "  r\0"  "  s\0"  "  t\0"  "  u\0"  "  v\0"  "  w\0"
	    "  x\0"  "  y\0"  "  z\0"  "  {\0"  "  |\0"  "  }\0"  "  ~\0"  "DEL\0"
	    ;
	int counter[128];
	for (int i = 0; i < 128; ++i)
	{
		counter[i] = 0;
	}

	fp = fopen("vt.in", "r");

	while ((read = getline(&line, &len, fp)) != -1) {
		for (int i = 0; i < read; ++i)
		{
			counter[line[i]]++;
		}
	}

	printf("DEC	HEX	ASCII NAME	COUNT \n");
	for (int i = 0; i < 128; ++i)
	{
		if(counter[i] != 0){
			printf("%d	%3x	%s 		%i\n", i, i, &asciiname[4 * i], counter[i]);
		}
	}

	fclose(fp);
}