/*
For a list of numbers, find the longest contiguous subsequence such that the difference
of any two consecutive elements is a prime number.
(Eg. 1 1 6 8 9 => 1 6 8)
*/

#define _CRT_SECURE_NO_WARNINGS

// header files
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

// prototype declaration section of functions
void readArray(int*, int[]);
void printSeq(int, int, int[]);
void determineMaximumLength(int*, int*, int[], int);
int prime(int);
void Test();

//main
void main(void)
{
	Test();
	int arrayLen = 0, array[101];
	char sequence[256] = "";
	scanf("%[^'\n']s", sequence);

	int position = 0;
	array[position] = 0;
	for (int i = 0; i < strlen(sequence); i++)
	{
		if (sequence[i] != ' ')
			array[position] = array[position] * 10 + (sequence[i] - '0');
		else 
			array[++position] = 0;
	}

	arrayLen = position + 1;

	int length = 0, pos = -1;
	determineMaximumLength(&length, &pos, array, arrayLen);
	printSeq(pos, length, array);
	//_getch();
}
/*
void readArray(int *arrayLen, int array[])
{
	printf("Give the dimension of the vector\n");
	scanf("%d", &(*arrayLen));
	int index;
	for (index = 0; index < *arrayLen; index++)
	{
		printf("element [%d]: \n", index);
		scanf("%d", &array[index]);
	}
}
*/
/*
This function verifies whether an integer is a prime number or not.
IN: x = integer number
OUT: 0 - is not a prime number
1 - otherwise
*/
int prime(int number)
{
	if (number < 2)
		return 0;
	if (number == 2)
		return 1;
	if (number % 2 == 0)
		return 0;
	for (int index = 3; index*index <= number; index = index + 2)
		if (number % index == 0)
			return 0;
	return 1;
}

/*
This function determines the maximum length of elements of an array, which have the property that every 2 consecutive
elements have the difference a prime number.
IN: n - dimension of the array, a - the array
OUT: pos - position from where the sequence starts, length - the length of the sequence
*/
void determineMaximumLength(int *length, int *pos, int array[], int arrayLen)
{
	int i = 0, p = i;
	while (i < arrayLen)
	{
		p = i;
		while ((prime(array[i + 1] - array[i])) && (i < arrayLen))
			i++;
		if (i - p + 1 > *length)
		{
			*pos = p;
			*length = i - p + 1;
		}
		i++;
	}

}

/*
This function prints a sequence from a certain position and of a certain length from an array
IN: pos - start position, length - the length of the sequence to be printed, a - the array
OUT: -------
*/
void printSeq(int pos, int length, int array[])
{
	for (int i = pos; i < pos + length; i++)
		printf("%d ", array[i]);
}

// this is the test function
void Test()
{
	assert(prime(1) == 0);
	assert(prime(2) == 1);
	assert(prime(5) == 1);
	assert(prime(9) == 0);

	int a[5] = { 1, 1, 6, 8, 9 };
	int pos = -1, len = 0;
	determineMaximumLength(&len, &pos, a, 5);
	assert((len == 3) && (pos == 1));

	int b[5] = { 1, 2, 3, 5, 6 };
	pos = -1, len = 0;
	determineMaximumLength(&len, &pos, b, 5);
	assert((len == 2) && (pos == 2));

	int c[10] = { 1, 3, 5, 6, 8, 13, 20, 22, 23, 24 };
	pos = -1, len = 0;
	determineMaximumLength(&len, &pos, c, 10);
	assert((len == 5) && (pos == 3));

	//printf("---Every test went ok---\n\n");
}