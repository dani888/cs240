/*
 *  stub driver for functions to study integer-hex conversions
 *
 */
/*
Daniel Werminghausen 3/2/17
cs240
Hw3
*/
// char hexstring[ENOUGH_SPACE] = {'0'};
// main function prints out result from standard input first coverting decimal
// to hex and then from hex to int. will allow user to to do as many tests as
// they want.

#include <stdio.h>
#include <string.h>
#include "xbits.h"

#define ENOUGH_SPACE sizeof(int) * 2 + 1

int main() {
	char hexstring[ENOUGH_SPACE] = {'0'};
	int m = 0, n;
	while (scanf("%d", &n) == 1) {
		char hexstring[ENOUGH_SPACE] = {'0'};
		itox( hexstring, n);


		/* for stub testing: create a fake input string */
		// strcpy( hexstring, "6BCD7890");
		m = xtoi(hexstring);

		printf("\t%12d %s %12d\n", n, hexstring, m);
	}
	return 0;  /* everything is just fine */
}



// #include <stdio.h>
// #include <string.h>
// #include "xbits.h"

// #define ENOUGH_SPACE 2 *(sizeof(int))+1 /* not really enough space */

// int main() {
// 	// char hexstring[ENOUGH_SPACE];
// 	int m = 0, n = 170;
// 	// itox( hexstring, n);
// 	char hexstring[ENOUGH_SPACE];

// 	 for stub testing: create a fake input string
// 	while (scanf("%d", &n) == 1) {
// 		itox( hexstring, n);
// 		m = xtoi( hexstring);
// 		printf("%12d  %s  %12d\n", n, hexstring, m);
// 	}

//   strcpy( hexstring, "6BCD7890");
//   m= xtoi(hexstring);

//   printf("\t%12d %s %12d\n", n,hexstring, m);

//   return 0;  /* everything is just fine */
// }


