/* pseudo code for reverse function

	read in file line by line
		loop over each char from the back
			print char

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

	fp = fopen("reverse.in", "r");

	while ((read = getline(&line, &len, fp)) != -1) {
		for (int i = read-1; i >= 0; --i)
		{
			printf("%c", line[i]);
		}
	}

	fclose(fp); 
}

