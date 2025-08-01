#include <stdio.h>
#include <stdlib.h>

int result;
char **set;
int setLen;
char *matrix;

int verifyMatrix()
{
	int sum = 0;
	int len = 0;
	int i = 0;
	while (i < setLen)
	{
		if (matrix[i])
		{
			sum += atoi(set[i]);
			len++;
		}
		i++;
	}
	return (sum == result) ? len : 0;
}

void printMatrix(int len)
{
	int i = 0;
	while (i < setLen)
	{
		if (matrix[i])
		{
			printf("%s", set[i]);
			if (len)
				printf(" ");
			len--;
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
		int len = verifyMatrix();
		if (len)
			printMatrix(len - 1);
		incrementMatrix();
	}
	int len = verifyMatrix();
	if (len)
		printMatrix(len - 1);
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
		return 1;
	result = atoi(argv[1]);
	set = (char **)(argv + 2);
	setLen = argc - 2;
	matrix = calloc(setLen, sizeof(char));
	if (!matrix)
		return 1;
	magic();
	free(matrix);
	return 0;
}
