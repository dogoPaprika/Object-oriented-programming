#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define FAIL -1

/*
An offer is composed of 2 vectors of characters(type and destination), 1 integer(id) and 1 float(price).
*/
typedef struct
{
	int id;
	char* type;
	char* destination;
	float price;
} Offer;

int validateFields(int id, char* type, char* destination, float price);
Offer* createOffer(int id, char* type, char* destination, float price);
void destroyOffer(Offer* offer);
Offer* copyOffer(Offer* offer);

//Getters, setters
int getId(Offer* offer);
char* getType(Offer* offer);
char* getDestination(Offer* offer);
float getPrice(Offer* offer);

int areEqual(Offer* offer1, Offer* offer2);
void toString(Offer* offer, char string[]);

//TESTS
void testOferr();

