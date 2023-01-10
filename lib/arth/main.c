#include <stdio.h>
#include <time.h>

#include "arth.h"

void print_usage(char *file)
{
	printf("%s -[d,e] [input file] [output file]\n", file);
}

int main(int argc, char** argv)
{
	clock_t start, finish;
	FILE *os, *is;
	double duration;
	int symbol;

	if(argc!=4)
	{
		print_usage(argv[0]);
		return 1;
	}

	if((is = fopen(argv[2], "rb")))
	{
		if(argv[1][0] ==  '-' )
		{
			os = fopen(argv[3], "wb");

			switch(argv[1][1])
			{
			case 'e':

				printf("Arithmetic encoding...\n");

				init_arth(os);

				start = clock();

				while((symbol=fgetc(is))!=EOF)
				{
					encode(symbol);
				}
				encode(-1);
				close_encode();
				finish = clock();

				break;
			case 'd':

				printf("Arithmetic decoding...\n");

				init_arth(is);

				start = clock();

				while((symbol=decode())>=0)
				{
					putc(symbol, os);
				}

				finish = clock();

				break;
			}

			fclose(os);
		}
		fclose(is);
	}

	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	printf("Time Consumption: %.5f\n", duration);

	return 0;
}
