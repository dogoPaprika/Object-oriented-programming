#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

void main()
{
	printf("Hello World!\n");
	printf("Give some input \n");
	char userInput[100];
	scanf("%[^'\n']s", userInput);
	printf("%s", userInput);
	//_getch(); 
}