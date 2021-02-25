#include "OperationsStack.h"

/*
Creates the operation to be added in the stack.
IN: element, op type
OUT: pt to operation
*/
Operation* createOperation(OpElem operationElement, char* operationType)
{
	Operation* newOperation = (Operation*)malloc(sizeof(Operation));
	newOperation->OperationElement = copyOffer(operationElement);

	if (operationType != NULL)
	{
		newOperation->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
		strcpy(newOperation->operationType, operationType);
	}
	else
		newOperation->operationType = NULL;

	return newOperation;
}

/*
Deallocates the memory used for an operation.
IN: pt to operation
OUT:-
*/
void destroyOperation(Operation* operation)
{
	if (operation == NULL)
		return;

	// first destroy the offer
	destroyOffer(operation->OperationElement);
									 // then the operationType
	free(operation->operationType);
	// then free the operation
	free(operation);
}

/*
Creates another Operation in memory and returns pt to it.
IN:Oper*
OUT:Oper*
*/
Operation* copyOperation(Operation * operation)
{
	if (operation == NULL)
		return NULL;

	Operation* newOperation = createOperation(operation->OperationElement, operation->operationType);
	return newOperation;
}

/*
Getter for type of operation.
IN:Operation*
OUT: char*
*/
char* getOperationType(Operation* operation)
{
	if (operation == NULL)
		return NULL;
	return operation->operationType;
}

/*
Gets a pointer to a type of object from operation.
IN:Oper*
OUT:OpElem-TElem*
*/
OpElem getOperationElement(Operation* operation)
{
	if (operation == NULL)
		return NULL;
	return operation->OperationElement;
}

// ---------------------------------------------------------------

/*
Creates a stack composed of length and operations.
IN:-
OUT: pt to stack
*/
OperationsStack* createStack()
{
	OperationsStack* stack = (OperationsStack*)malloc(sizeof(OperationsStack));
	stack->length = 0;

	return stack;
}

/*
Deallocates the memory used for a operation stack.
IN: OperationsStack*
OUT:-
*/
void destroyStack(OperationsStack* stack)
{
	if (stack == NULL)
		return;

	// first deallocate memory of operations (this is allocated when a new operation is pushed onto the stack)
	for (int i = 0; i < stack->length; i++)
		destroyOperation(stack->operations[i]);

	// then free the stack
	free(stack);
}

/*
Add new element in the stack on top of others in order.
IN: the stack, the element
OUT:-
*/
void push(OperationsStack* stack, Operation* operation)
{
	if (isFull(stack))
		return;

	stack->operations[stack->length++] = copyOperation(operation);	// copies of operations are added, such that the stack manages its own operations
}

/*
Takes out the last element in order from the stack.
IN:the stack
OUT:Operation*
*/
Operation* pop(OperationsStack* stack)
{
	if (isEmpty(stack))
		return NULL;
	stack->length--;
	return stack->operations[stack->length];
}

/*
Checks if the stack is empty.
IN: the stack
OUT: 1 if empty, 0 else
*/
int isEmpty(OperationsStack* stack)
{
	return (stack->length == 0);
}

/*
Checks if the stack is full for its capacity.
IN: the stack
OUT: 1 if full, 0 else
*/
int isFull(OperationsStack* stack)
{
	return stack->length == 100;
}

/*
Returns a pointer to the operation on top of the stack.
IN:the stack
OUT: Op*
*/
Operation* onTop(OperationsStack* stack)
{
	if (isEmpty(stack))
		return NULL;
	return stack->operations[stack->length - 1];
}

/*
Pops all elements leaving the stack empty.
IN: the stack*
OUT:-
*/
void clear(OperationsStack* stack)
{
	while (!isEmpty(stack))
	{
		Operation* operation = pop(stack);
		destroyOperation(operation);
	}
}


// Tests
//void initUndoStack(OperationsStack* undoS);

void testOperationsStack()
{
	//copyOperation, getOperationElement()
	OperationsStack* operationStackTest = createStack();

	OpElem operationElement1 = createOffer(50, "seaside", "Panama", 152);
	OpElem operationElement2 = createOffer(51, "seaside", "Chile", 45);
	OpElem operationElement3 = createOffer(52, "mountain", "Everest", 51);
	OpElem operationElement4 = createOffer(53, "mountain", "K2", 425);

	Operation* operation1 = createOperation(operationElement1, "add");
	Operation* operation2 = createOperation(operationElement2, "add");
	Operation* operation3 = createOperation(operationElement1, "remove");

	// the operation elements may be destroyed, as the operations contain copies of these objects
	destroyOffer(operationElement1);
	destroyOffer(operationElement2);
	destroyOffer(operationElement3);
	destroyOffer(operationElement4);

	push(operationStackTest, operation1);
	push(operationStackTest, operation2);
	push(operationStackTest, operation3);

	// the operations may be destroyed, as the stack contains copies of these operations
	destroyOperation(operation1);
	destroyOperation(operation2);
	destroyOperation(operation3);

	assert(isFull(operationStackTest) == 0);
	assert(isEmpty(operationStackTest) == 0);
	Operation* operation4 = pop(operationStackTest);
	assert(strcmp(operation4->operationType, "remove") == 0);
	// after each pop, the operations must be destroyed
	destroyOperation(operation4);

	operation4 = pop(operationStackTest);
	assert(strcmp(operation4->operationType, "add") == 0);
	destroyOperation(operation4);

	operation4 = pop(operationStackTest);
	assert(strcmp(operation4->operationType, "add") == 0);
	destroyOperation(operation4);

	assert(isEmpty(operationStackTest) == 1);

	Operation* operation5 = createOperation(operationElement1, "add");
	Operation* operation6 = createOperation(operationElement2, "add");
	push(operationStackTest, operation5);
	push(operationStackTest, operation6);
	clear(operationStackTest);
	destroyOperation(operation5);
	destroyOperation(operation6);

	assert(isEmpty(operationStackTest) == 1);

	// destroy the stack
	destroyStack(operationStackTest);
}