/* Tail.c */
/* Daniel Werminghausen 4/1/17 */

#include <stdio.h>
#include "lineholder.h"
#include <stdlib.h>


/* pseudo code,
find the command line input using the pointer argv,
call the init_lineholder using command line number,
while there is a next line
	stroe the line by calling insert_line call to
	print the desired numberof lines */

int getline1(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}

int main(int argc, char * argv[]) {
	//interperts the command line arguments
	int nline;
	char line[MAXLINE];
	if (argc <= 1) {
		nline = 10;
		printf("wrong != 10\n");
	}
	else if (argc > 1) {
		nline = atoi(argv[1]);
	}
	// printf("%d\n", nline);
	init_lineholder(nline);
	// need a way to convert a string to a digit input_line

	// if (insert_line < MAXLEN) {
	// 	nline = insert_line;
	// }

	//loop calling getline
	while (getline1(line, MAXLINE) > 0) {
		insert_line(line);
	}

	//print Lines
	print_lines();
	return 1;
}

