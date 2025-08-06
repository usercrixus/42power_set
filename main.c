#include <stdio.h>
#include <stdlib.h>

int result;
char **set;
int setLen;
char *matrix;

int verifyMatrix()
{
	int sum = 0;
	int i = 0;
	while (i < setLen)
	{
		if (matrix[i])
			sum += atoi(set[i]);
		i++;
	}
	return sum == result;
}

void printMatrix()
{
	int i = 0;
	int first = 1;
	while (i < setLen)
	{
		if (matrix[i])
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

void incrementMatrix()
{
	int i = 0;
	int carry = 1;
	while (carry && i < setLen)
	{
		if (matrix[i] == 1)
		{
			matrix[i] = 0;
			carry = 1;
		}
		else
		{
			matrix[i] = 1;
			carry = 0;
		}
		i++;
	}
}

int isEnd()
{
	int i = 0;
	while (i < setLen)
	{
		if (matrix[i] == 0)
			return 0;
		i++;
	}
	return 1;
}

int magic()
{
	while (!isEnd())
	{
		if (verifyMatrix())
			printMatrix();
		incrementMatrix();
	}
	if (verifyMatrix())
		printMatrix();
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	result = atoi(argv[1]);
	set = argv + 2;
	setLen = argc - 2;
	matrix = calloc(setLen, sizeof(char));
	if (!matrix)
		return 1;
	magic();
	free(matrix);
	return 0;
}
