#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int result;
char **set;
int setLen;

void printSubset(unsigned int mask)
{
	int first = 1;
	int i = 0;
	while (i < setLen)
	{
		if (mask & (1U << i))
		{
			if (!first)
				printf(" ");
			printf("%s", set[i]);
			first = 0;
		}
		i++;
	}
	printf("\n");
}

void findSubsets()
{
	unsigned int totalComb = 1U << setLen;
	unsigned int mask = 1U;
	while (mask < totalComb)
	{
		int sum = 0;
		int i = 0;

		while (i < setLen)
		{
			if (mask & (1U << i))
				sum += atoi(set[i]);
			i++;
		}
		if (sum == result)
			printSubset(mask);
		mask++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return 1;
	result = atoi(argv[1]);
	set = argv + 2;
	setLen = argc - 2;
	if (setLen >= 32)
	{
		fprintf(stderr, "Error: supports up to 31 elements.\n");
		return 1;
	}
	findSubsets();
	return 0;
}
