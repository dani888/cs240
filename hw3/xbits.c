/*
 *  stubs for functions to study
 *  integer-hex conversions
 *
 */
/*
Daniel Werminghausen 3/2/17
cs240
Hw3
*/
/* function returns in hexstring the char sequence of hex digits
 * '0' ... 'F' used to represent int n. It is the caller's responsibility
 * to have allocated at least 1+2*sizeof(int) positions in bitstring.
 * itox must provide the concluding \0 in bitstring.
 */

#include <stdio.h>
#include <math.h>
#include "xbits.h"


/* function represents the int n as a hexstring which it places in the
hexstring array */

void itox( char hexstring[], int n) {
	// printf("in itox, processing %d\n", n);
	// Add the next hex char to the char array
	int remainder = n % 16;
	char result;
	switch (remainder) {
	case 0 :
		result = '0';
		break;
	case 1 :
		result = '1';
		break;
	case 2 :
		result = '2';
		break;
	case 3 :
		result = '3';
		break;
	case 4 :
		result = '4';
		break;
	case 5 :
		result = '5';
		break;
	case 6 :
		result = '6';
		break;
	case 7 :
		result = '7';
		break;
	case 8 :
		result = '8';
		break;
	case 9 :
		result = '9';
		break;
	case 10 :
		result = 'A';
		break;
	case 11 :
		result = 'B';
		break;
	case 12 :
		result = 'C';
		break;
	case 13 :
		result = 'D';
		break;
	case 14 :
		result = 'E';
		break;
	case 15 :
		result = 'F';
		break;
	default :
		break;
	}
	// printf("%c\n", result);
	for (int i = (sizeof(int) * 2) - 1; i >= 0; --i)
	{
		if (hexstring[i] == 0)
		{
			hexstring[i] = result;
			break;
		}
	}
	// printf("%s\n", hexstring);
	if (n / 16 > 0) {
		itox(hexstring, n / 16);
	}
	else {
		for (int i = 0; i < (sizeof(int) * 2) - 1; ++i)
		{
			if (hexstring[i] == 0) {
				hexstring[i] = '0';
			}
		}
		hexstring[(sizeof(int) * 2)] = '\0';
	}
}

/* function converts hexstring array to equivalent integer value  */

/* function returns in integer the decimal representation of
 * the hex characters in hexstring. The function needs to check if hexstring
 * contains only the characters '0' ... 'F'.
 */

int xtoi( char hexstring[]) {
	int res = 0;
	int result = -1;
	for (int i = (sizeof(char) * 9) - 2; i >= 0; i--) {
		// printf("%c\n", hexstring[i]);
		switch (hexstring[i]) {
		case '0' :
			result = 0;
			break;
		case '1' :
			result = 1;
			break;
		case '2' :
			result = 2;
			break;
		case '3' :
			result = 3;
			break;
		case '4' :
			result = 4;
			break;
		case '5' :
			result = 5;
			break;
		case '6' :
			result = 6;
			break;
		case '7' :
			result = 7;
			break;
		case '8' :
			result = 8;
			break;
		case '9' :
			result = 9;
			break;
		case 'A' :
			result = 10;
			break;
		case 'B' :
			result = 11;
			break;
		case 'C' :
			result = 12;
			break;
		case 'D' :
			result = 13;
			break;
		case 'E' :
			result = 14;
			break;
		case 'F' :
			result = 15;
			break;
		default :
			result = - 1;
			break;
		}
		// printf("%f\n", result * pow(16, fabs(i - 7)));
		res += result * pow(16, fabs(i - 7));
	}
	return res;
}

// int main(int argc, char const **argv[]) {
// 	char hex[2 * sizeof(int) + 1] = "";

// 	itox(hex, 170);

// 	printf("%s\n", hex);

// 	printf("%i\n", xtoi(hex));

// 	return 0;
// }

