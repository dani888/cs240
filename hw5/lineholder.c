/* lineholder.c */
/* Daniel Werminghausen 4/1/17 */

// static char * lines[MAXLEN];

// void init_lineholder(int nlines) {
		//initializes nlines first and last and n 


// void insert_line(char * line) {
	//initial call, for edge case first
	// inserts line into the array
	// mantaining a moving "first"

// void print_lines() {
	//prints out the last two in memonry

/*
contains a static array of pointers for lines.
  		Implements init_lineholder, insert_line, and print_lines.
  		Init_lineholder initializes the "first" slot and related variables.
  		Insert_line adds a line to the array.
It must allocate memory for the new line.
It must free the memory for a line no longer needed, if any.
  		Print_lines prints the lines in the array and frees the memory used for them.
*/
#include <stdio.h>
#include <string.h>
#include "lineholder.h"

void *malloc(int);
void free(void*);
int abs(int);

static char *lines[MAXLEN];
static int first, last, n, max = MAXLEN;

void init_lineholder(int nlines)
{
	if (nlines > MAXLINE)
		nlines = MAXLINE;

	first = last = 0;
	n = nlines;
}

void insert_line(char *line)
{
	//initial call, edge case
	if (lines[last] == NULL && first == last) {
	} else {
		last++;
		if (last >= max) {
			last = 0;
		}
	}
	if (lines[last] != NULL && first == last)
		free((void *) lines[last]);
	first++;
	if (first >= max) {
		first = 0;
	}
	// printf("%d\n", strlen(line));
	if ((lines[last] =  (char * ) malloc(strlen(line) + 1)) != NULL)
		strcpy(lines[last], line);
}

void print_lines(void)
{
	int i;
	if (last - n + 1 >= 0) {
		for (i = last - n + 1; i <= last; i++) {
			if (lines[i] != NULL) {
				printf("%s\n", lines[i]);
			}
		}
	} else {
		for (i = MAXLEN - abs(last - n + 1); i < MAXLEN; i++) {
			if (lines[i] != NULL) {
				printf("%s\n", lines[i]);
			}
		}
		for (i = 0; i <= last; i++) {
			if (lines[i] != NULL) {
				printf("%s\n", lines[i]);
			}
		}
	}
}