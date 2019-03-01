/*
wordcounter.c cs240
Daniel. Werminghausen
unix name(danwaba)
4/19/17
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define MAXWORDLEN 30

static int max = 0;

char * getword(void);
struct wordcount_node * count(char *word, struct wordcount_node *list);
struct wordcount_node * create_new_node(void);

struct wordcount_node {
  char *word;
  int count;
  struct wordcount_node *next;  /* pointer to next node in list */
} ;

// int compare(struct wordcount_node * p, struct wordcount_node * q) {
//   return (p->count - q->count);
// }

int main(void)
{
  char *newword;
  struct wordcount_node *list;  /* Pointer to list of words seen so far */
  struct wordcount_node *cur;


  list = NULL;

  /* Read in words and count them */
  while ((newword = getword()) != NULL) {
    list = count(newword, list);
    free(newword);    /* `count' made a copy of `newword', so
           we can throw `newword' away. */
  }

  /* Print out accumulated information */
  // qsort(cur, sizeof(cur), sizeof(struct wordcount_node), (int(*)(const void *, const void *))compare);
  for (int i = 1; i <= max; i ++) {
    for (cur = list; cur != NULL; cur = cur->next) {
      if (cur->count == i) {
        printf("%s %d\n", cur->word, cur->count);
      }
    }
  }
  return 0;
}


struct wordcount_node *
count(char *word, struct wordcount_node *list)
{
  struct wordcount_node *cur;
  struct wordcount_node *newnode;

  for (cur = list; cur != NULL; cur = cur->next)
    if (strcmp(word, cur->word) == 0) {
      cur->count++;
      if (max <= cur->count)
        max = cur->count;
      return list;
    }

  /* If we're here, we didn't find the word. */

  if ((newnode = create_new_node()) == NULL) {
    // fprintf(stderr, "Out of memory.\n");
    exit(1);
  }
  newnode->next = list;

  newnode->word = strdup(word);

  newnode->count = 1;

  return newnode;
}


struct wordcount_node *
create_new_node(void)
{
  return (struct wordcount_node *) malloc(sizeof(struct wordcount_node));
}



char *
getword(void)
{
  char buf[MAXWORDLEN];
  int i = 0, c;

  /* Eat up white space that precedes a word, if any. */
  while ( isspace(c = getchar()) && c != EOF  )
    /* nothing */ ;

  if (c != EOF) ungetc(c, stdin);

  while ( !isspace(c = getchar()) && c != EOF  )
    buf[i++] = c;

  buf[i] = '\0';

  if (i == 0) return NULL;
  else  return strdup(buf);
}