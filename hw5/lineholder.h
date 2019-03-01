/* lineholder.h */
/* Daniel Werminghausen 4/1/17 */


/* 
just has prototypes for the three calls with appropriate comments explaining what they do for the caller.  
*/
#define MAXLINE 1000
#define MAXLEN 2000


void init_lineholder(int);
void insert_line(char *);
void print_lines(void);