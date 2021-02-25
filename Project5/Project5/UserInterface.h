#pragma once

#include <stdio.h>
#include "OfferController.h"

/*
Just receives things from Controller and prints and reads.
Cascading arhitecture.
*/
typedef struct
{
	Controller* controller;
} UserInterface;

UserInterface* createUserInterface(Controller* controller);
void destroyUserInterface(UserInterface* userInterface);

void startUserInterface(UserInterface* userInterface);

void readStringWithSpaces(const char* message, int maxStringSize, char string[]);
void listAllOffers(UserInterface* userInterface);
void listOffersByDestinationUserInterface(UserInterface* userInterface, char* parameters);
void listOffersByPriceUserInterface(UserInterface* userInterface, float maximumPrice);
void printRepository(OfferRepository* offerRepository);

int deleteByIdUserInterface(UserInterface* userInterface, char parameters[][10], int length);
int updateByIdUserInterface(UserInterface* userInterface, char parameters[][10], int length);
int addOfferUserInterface(UserInterface* userInterface, char parameters[][10], int length);

int inOptions(char* opt);
void calculateFirstWord(char* userInput, char *firstWord);
void returnParameters(char* userInput, char parameters[][10], int* length);

