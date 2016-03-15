#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[])
{
        int *pos = (int *) malloc(2 * sizeof(int));
        pos[0] = 0;
        pos[1] = 0;
    	int *neg = (int *) malloc(2 * sizeof(int));
    	neg[0] = 0;
        neg[1] = 0;
        int lenp = 2, lenn = 2;


    	int numz = 0, nump = 0, numn = 0;
    	int temp = 0;

    	FILE *file;
        file = fopen(argv[1], "r");
        if (file == NULL)
            printf ("file not opened\n");
    	else
    	{
    		printf ("file opened\n");

            	while (fscanf(file, "%d", &temp) ==1)
            	{
                	if (temp > 0)
                	{
                    		pos[nump] = temp;
                    		++nump;
                		if(lenp == nump)
                    		{
                        		pos = (int *) realloc (pos, sizeof(int) * (lenp *= 2));
                        		int i = nump;
                        		for( ; i < lenp; ++i)
                            			pos[i] = 0;
		                }
                	}
			else if(temp < 0)
			{
				neg[numn] = temp;
                    		++numn;
                    		if(lenn == numn)
                    		{
                        		neg = (int *) realloc (neg, sizeof(int) * (lenn *= 2));
                        		int i = numn;
                        		for( ; i < lenn; ++i)
                            		neg[i] = 0;
                    		}
			}
			else ++numz;
		}//while (fscanf(file, "%d", &temp) ==1)
		fclose(file);


        int i=0;
        file = fopen(argv[1], "w");

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
        free(pos);
        free(neg);
    }

	return 0;
}
