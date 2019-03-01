/* pseudo code for the trim program

read in file line by line
	trim charcters at beginning of line until first char is found
	print line

end of pseudo code
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("trim.in", "r");

	while ((read = getline(&line, &len, fp)) != -1) {
		while(isspace((unsigned char)*line)) line++;
		printf("%s", line);
	}

	fclose(fp);
}


               