#pragma once

#include "Offer.h"

typedef Offer* OpElem; //Operation's element

/*
Operation is composed of element on which the operation acted and the operation type.
*/
typedef struct
{
	OpElem OperationElement;
	char* operationType;
} Operation;

Operation* createOperation(OpElem operationElement, char* operationType);
void destroyOperation(Operation* operation);
Operation* copyOperation(Operation* operation);
char* getOperationType(Operation* operation);
OpElem getOperationElement(Operation* operation);

// ---------------------------------------------------------------
typedef struct
{
	Operation* operations[100];
	int length;
} OperationsStack;

OperationsStack* createStack();
void destroyStack(OperationsStack* operationsStack);
void push(OperationsStack* operationsStack, Operation* operation);
Operation* pop(OperationsStack* operationsStack);
Operation* onTop(OperationsStack* operationsStack);
int isEmpty(OperationsStack* operationsStack);
int isFull(OperationsStack* operationsStack);
void clear(OperationsStack* operationsStack);

void testOperationsStack();
