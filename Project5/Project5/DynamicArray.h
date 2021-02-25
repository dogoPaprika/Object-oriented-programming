#pragma once
#include "Offer.h"

typedef void* TElem;
typedef void (*DestroyElementFunctionType) (void *);

typedef struct {
	TElem* elements;
	int length;
	int capacity;
	DestroyElementFunctionType DestroyElemFunction; //knows the procedure to destroy a generic object
} DynamicArray;

DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElementFunction);
void destroyDynamicArray(DynamicArray* dynamicArray);
void clearDynamicArray(DynamicArray* dynamicArray);
TElem getElement(DynamicArray* dynamicArray, int position);
int getLengthArray(DynamicArray* dynamicArray);
void addElement(DynamicArray* dynamicArray, TElem Telement);
void updateElement(DynamicArray* dynamicArray, TElem newTelement, int index);
void deleteElement(DynamicArray* dynamicArray, int index);

void testDynamicArray();