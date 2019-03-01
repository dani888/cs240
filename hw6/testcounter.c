/* wordcounter.c */
/* Daniel Werminghausen 4/13/17 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // check if character is a number
#include <malloc.h>

#define NKEYS 5000
#define BUFSIZE 100
#define MAXWORD 30

// int getword(char*, int);
// int getch(void);
// void ungetch();

void insert(char *);
struct Node getWordNode(char *);
void read_words (FILE *);
void print();

struct Node {
	char *word;
	int count;
	struct Node * next_node;
} root_node;

// struct Node temp;
// temp.word...
// temp count ...

//Nodetab_root.next_node = (struct Node *)malloc(sizeof(struct Node));

int main() {

	// printf("in main\n");
	FILE * fp;
	fp = fopen("gettysburg.txt", "r");
	read_words(fp);
	fclose(fp);

	print();

	return 1;
}

void read_words (FILE *f) {
	char word[MAXWORD];
	/* assumes no word exceeds length of 1023 */
	while (fscanf(f, "%1023s", word) == 1) {
		puts(word);
		// if (isalpha(word[0])) {
		// 	insert(word);
	}
}

void insert (char * newword) {
	int count = 0;
	struct Node wordNode = getWordNode(newword);
	if (wordNode.word == NULL) {
		// printf("increment count of word: %c\n", *wordNode.word);
		wordNode.count++;
	} else {
		// printf("insert new word\n");
		struct Node newNode;
		newNode.word = newword;
		newNode.count = count ;
		newNode.next_node = &root_node;
		root_node = newNode;
	}
}

struct Node getWordNode(char * word) {
	struct Node tempNode;
	tempNode = root_node;
	while (tempNode.word != NULL) {
		if (tempNode.word == word) {
			// printf("in get word node found node\n");
			return tempNode;
		}
		if (tempNode.next_node == NULL) {break;}
		tempNode = *tempNode.next_node;
	}
	struct Node fail;
	return fail;
}

void print() {
	struct Node tempNode;
	tempNode = root_node;
	// printf("in print\n");
	while (tempNode.word != NULL) {
		// printf("printing\n");
		printf("%d\n", tempNode.count);
		if (tempNode.next_node == NULL) {break;}
		tempNode = *tempNode.next_node;
	}
}



// int getword(char * word, int lim) {
// 	return 1;
// }

// int getch() {
// 	return 1;
// }

// void ungetch() {

// }


// keytab[i].word = (char*)malloc(strlen(newword) + 1);
// strcpy(keytab[i].word, newword);