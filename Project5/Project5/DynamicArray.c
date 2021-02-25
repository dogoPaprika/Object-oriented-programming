#include "DynamicArray.h"

/*
Creates a dynamic array in memory and returns a pointer to it.
IN: int
OUT: DynamicArray*
*/
DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFunction)
{
	DynamicArray* dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));

	if (dynamicArray == NULL)
		return NULL;

	dynamicArray->length = 0;
	dynamicArray->capacity = capacity;

	//allocate space for the elements
	dynamicArray->elements = (TElem*)malloc(capacity * sizeof(TElem));
	if (dynamicArray->elements == NULL)
		return NULL;

	dynamicArray->DestroyElemFunction = destroyElemFunction;

	return dynamicArray;
}

/*
Destroys the d array from the memory.
IN: pt to DA
OUT:-
*/
void destroyDynamicArray(DynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	//free space allocated for offers pointed by pointers from elems* (confused?)
	for (int i = 0; i < dynamicArray->length; i++)
		dynamicArray->DestroyElemFunction(dynamicArray->elements[i]);

	//free space allocated for pointer to list of pointers
	free(dynamicArray->elements);
	dynamicArray->elements = NULL;

	//free space for array
	free(dynamicArray);
	dynamicArray = NULL;
}

/*
Reallocates memory for the d.array making it larger in case of new elements.
IN:DA*
OUT:-
*/
void resize(DynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	dynamicArray->capacity *= 2;
	TElem* auxiliaryArray = (TElem*)realloc(dynamicArray->elements, dynamicArray->capacity * sizeof(TElem));
	if (auxiliaryArray == NULL)
		return; // array cannot be resized

	dynamicArray->elements = auxiliaryArray;
}

/*
Makes all elems pointers point to NULL so its similar to being empty.
IN: DA*
OUT:-
*/
void clearDynamicArray(DynamicArray* dynamicArray)
{
	for (int i = 0; i < dynamicArray->length; i++)
	{
		dynamicArray->DestroyElemFunction(dynamicArray->elements[i]);
		dynamicArray->elements[i] = NULL;
	}
	dynamicArray->length = 0;
}

/*
Returns an element from the array from given position.
IN: pt to array, position
OUT:
*/
TElem getElement(DynamicArray* dynamicArray, int index)
{
	if (dynamicArray == NULL || dynamicArray->elements == NULL)
		return NULL;

	if (index < 0 || index >= dynamicArray->length)
		return NULL;

	return dynamicArray->elements[index];
}

/*
Returns the length of the array.
IN: pt to array
OUT:integer
*/
int getLengthArray(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	return arr->length;
}

/*
Adds new element in the dynamic array. If exceeds the capacity it resizes.
IN: pt to the array, new element
OUT:-
*/
void addElement(DynamicArray* dynamicArray, TElem element)
{
	if (dynamicArray == NULL)
		return;
	if (dynamicArray->elements == NULL)
		return;

	// resize the array, if necessary
	if (dynamicArray->length == dynamicArray->capacity)
		resize(dynamicArray);

	//Points to the element pointed by t
	dynamicArray->elements[dynamicArray->length] = element;

	dynamicArray->length++;
}

/*
Updates an element from the dynamic array at a given index.
IN:DA*, TElem, int
OUT:-
CONDIS: index is not out of range
*/
void updateElement(DynamicArray* dynamicArray, TElem newElement, int index)
{
	if (dynamicArray == NULL || dynamicArray->elements == NULL)
		return;

	if (index < 0 || index >= dynamicArray->length)
		return;

	dynamicArray->elements[index] = newElement;
}

/*
Deletes element at given index.
IN: DA*, int
OUT:-
*/
void deleteElement(DynamicArray* dynamicArray, int index)
{
	if (dynamicArray == NULL || dynamicArray->elements == NULL)
		return;

	if (index < 0 || index >= dynamicArray->length)
		return;

	//Deallocate memory used for removed object
	dynamicArray->DestroyElemFunction(dynamicArray->elements[index]);

	for (int i = index; i < dynamicArray->length - 1; i++)
		dynamicArray->elements[i] = dynamicArray->elements[i + 1];
	dynamicArray->length--;
}

//TESTS
void testDynamicArray()
{
	DynamicArray* dynamicArrayTest = createDynamicArray(2, destroyOffer);
	if (dynamicArrayTest == NULL || dynamicArrayTest->elements == NULL)
		assert(0);

	assert(dynamicArrayTest->capacity == 2);
	assert(dynamicArrayTest->length == 0);

	//Can be TElem t1 = createOffer(...)
	//TElem t2 = createPlanet(...) for more repos
	Offer* offer1 = createOffer(123, "seaside", "Panama", 100.02);
	Offer* offer2 = createOffer(321, "mountain", "Everest", 120.33);

	addElement(dynamicArrayTest, offer1);
	assert(dynamicArrayTest->length == 1);
	addElement(dynamicArrayTest, offer2);
	assert(dynamicArrayTest->length == 2);

	// capacity must double
	Offer* offer3 = createOffer(700, "citybreak", "Paris", 170.00);
	addElement(dynamicArrayTest, offer3);
	assert(getLengthArray(dynamicArrayTest) == 3);
	assert(dynamicArrayTest->capacity == 4);

	// delete planet on position 0
	// first get the pointer to the planet, to still be able to access the pointed memory
	Offer* offer5 = getElement(dynamicArrayTest, 1);
	deleteElement(dynamicArrayTest, 0);
	assert(dynamicArrayTest->length == 2);
	assert(areEqual(offer5, getElement(dynamicArrayTest, 0)));

	// destroy the dynamic array - this will also destroy the offers
	destroyDynamicArray(dynamicArrayTest);
}

