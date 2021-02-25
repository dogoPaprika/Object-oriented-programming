#pragma once

template<typename TElem>
class DynamicArray
{
private:
	int capacity;
	int size;
	TElem* elements;
public:
	DynamicArray(int capacity = 10);
	DynamicArray(const DynamicArray& array);
	~DynamicArray();

	int getSize() const;
	int getCapacity() const { return this->capacity; }
	TElem* getAllElements() const;

	DynamicArray& operator=(const DynamicArray& array);
	TElem& operator[](int index);
	DynamicArray& operator-(TElem tElement);

	/*
	Returns the position of wanted element. If its inexistent it returns -1.
	*/
	int find(const TElem& tElement);

	/*
	Adds a new generic element to the dynamic vector and increments the length.
	*/
	void add(const TElem& tElement);

	/*
	Deletes a given element from the dynamic vector.
	*/
	void remove(int position);

	static void testVector();

private:
	void resize(double factor = 2);
};

/*
Constructor function.
*/
template<typename TElem>
DynamicArray<TElem>::DynamicArray(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elements = new TElem[capacity];
}

/*
Destructor function.
*/
template<typename TElem>
DynamicArray<TElem>::~DynamicArray()
{
	delete[] this->elements;
}

/*
Copies the dynamic vector 'v'.
*/
template<typename TElem>
DynamicArray<TElem>::DynamicArray(const DynamicArray<TElem>& v)
{
	this->capacity = v.capacity;
	this->size = v.size;
	this->elements = new TElem[this->capacity]; //The copy has own memory/different elements
	for (int i = 0; i < this->size; i++)
		this->elements[i] = v.elements[i];
}

/*
Resizes the vector if the capacity is exceeded.
IN:
*/
template<typename TElem>
void DynamicArray<TElem>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElem* auxiliaryDynamicArray = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		auxiliaryDynamicArray[i] = this->elements[i];

	delete[] this->elements;
	this->elements = auxiliaryDynamicArray;
}

/*
Returns the size of the dynamic vector.
IN:-
OUT: integer
*/
template <typename TElem>
int DynamicArray<TElem>::getSize() const
{
	return this->size;
}

/*
Returns a pointer to all elements from the dynamic vector.
IN:-
OUT: TElem*
*/
template <typename TElem>
TElem* DynamicArray<TElem>::getAllElements() const
{
	return this->elements;
}

/*
Overloads + operator.
*/
template <class TElem>
DynamicArray <TElem> operator+(TElem e, DynamicArray<TElem> v)
{
	v.add(e);
	return v;
}

/*
Assignment operator. Deallocates the old elements of 'v' and creates new ones(copies from v) in memory .
IN:  dynamic vector&
OUT: dynamic vector&
*/
template<typename TElem>
DynamicArray<TElem>& DynamicArray<TElem>::operator=(const DynamicArray<TElem>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elements;
	this->elements = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = v.elements[i];

	return *this;
}

/*
Operator for element from dynamic vector.
*/
template<typename TElem>
TElem& DynamicArray<TElem>::operator[](int index)
{
	//exception for wrong index
	//if (index < 0 || index >= this->size)
	//	return NULL;//throw

	return this->elements[index];
}

/*
Finds a generic element in the array.
*/
template<typename TElem>
int DynamicArray<TElem>::find(const TElem& tElement)
{
	//Operator == must be overloaded for each class used as TElem
	for (int i = 0; i < this->getSize(); i++)
	{
		if (this->elements[i] == tElement)
			return i;
	}
	return -1;
}

/*
Add another TElement in the dynamic vector.
*/
template<typename TElem>
void DynamicArray<TElem>::add(const TElem& tElement)
{
	if (this->size == this->capacity)
		this->resize(2);

	this->elements[this->size] = tElement;
	this->size++;
}

template<typename TElem>
void DynamicArray<TElem>::remove(int position)
{
	if (position < 0 || position >= this->size)
		return;

	this->elements[position] = this->elements[this->size - 1];
	this->size--;
	//for (int i = pos; i < this->getSize() - 1; i++)
	//{
	//	this->elems[i] = this->elems[i + 1];
	//}
}

template<typename TElem>
void DynamicArray<TElem>::testVector()
{
	DynamicArray<int> dynamicArray{ 2 };
	int tElement1 = 55;
	int tElement2 = 66;
	int tElement3 = 77;

	int length = dynamicArray.getSize();

	dynamicArray.add(tElement1);
	dynamicArray.add(tElement2);
	dynamicArray.add(tElement3); //capacity must double
	assert(dynamicArray.getSize() == length + 3);
	assert(dynamicArray.find(tElement2) == 1);
	assert(dynamicArray.getCapacity() == 4);

	dynamicArray.remove(-1);
	dynamicArray.remove(1);
	assert(dynamicArray.find(tElement2) == -1);
	assert(dynamicArray.getSize() == length + 2);

	DynamicArray<int> dynamicArray1{ 10 };
	dynamicArray1.add(5);
	dynamicArray1.add(4);
	dynamicArray1.add(3);
	dynamicArray1.add(2);

	DynamicArray<int> dynamicArray2 = dynamicArray1;
	assert(dynamicArray2.getSize() == dynamicArray1.getSize());
	
	DynamicArray<int> dynamicArray3{ 2 };
	dynamicArray3 = dynamicArray1;
	assert(dynamicArray3.getSize() == dynamicArray1.getSize());

}