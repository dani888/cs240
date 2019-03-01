/* pseudo code for the trim program

assigns int to i, count, space
while there is still a line to process
	for each character starting at the end of the line
		find the first non blank character or the beginning of the line
		if a non-blank character is found
			add an eol and terminating zero
			and print it out

end of pseudo code
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("trim.in", "r");

	while ((read = getline(&line, &len, fp)) != -1) {
		while (line == " " || line == "\t" || line == "\v" || line == "\f" || line == "\r") line++;
		if (line == "\n") continue;
		printf("%s", line);
	}

	fclose(fp);


}