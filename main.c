#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
    int *pos;
	int *neg;

	pos = (int *) malloc(100);
	neg = (int *) malloc(100);

	int numz, nump, numn;
	int temp;

	numz = nump = numn = 0;

	FILE *file;
	file = fopen(argv[1], "r");
    if (file == NULL) printf ("file not opened\n");
    else printf ("file opened\n");

	while (fscanf(file, "%d", &temp) ==1)
	{
		if (temp > 0)
		{
			pos[nump] = temp;
			++nump;
			if(sizeof(pos) / sizeof(pos[nump]) == nump)
				pos = (int *) realloc (pos, nump + 100);
		}
		else
			if(temp < 0)
			{
				neg[numn] = temp;
				++numn;
				if(sizeof(neg) / sizeof(neg[numn]) == numn)
					neg = (int *) realloc (neg, numn + 100);
			}
			else ++numz;
	}
	fclose(file);

    int i;
	file = fopen(argv[1], "w");
	if (file == NULL) printf ("file not opened\n");
    else printf ("done\n");

	for(i = 0; i < numz; ++i)
	{
        fprintf(file, "%d", 0);
        fprintf(file, " ");
	}
	for(i = 0; i < numn; ++i)
	{
        fprintf(file, "%d", neg[i]);
        fprintf(file, " ");
    }
	for(i = 0; i < nump; ++i)
	{
		fprintf(file, "%d", pos[i]);
        fprintf(file, " ");
    }
	fclose(file);

	return 0;
}
