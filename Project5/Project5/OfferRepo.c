#include "OfferRepo.h"

/*
Constructs in memory an OfferRepo and returns a pointer to that adress.
IN: -
OUT: pt to Repo
*/
OfferRepository* createRepository(DynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return NULL;

	OfferRepository* newRepository = (OfferRepository*)malloc(sizeof(OfferRepository));
	newRepository->dynamicArray = dynamicArray;
	return newRepository;
}

/*
Deallocates the memory used for a OfferRepo
IN: the repo to be destroyed
OUT:-
*/
void destroyRepository(OfferRepository* offerRepository)
{
	if (offerRepository == NULL)
		return;

	/*for (int i = 0; i < orepo->arr->length; i++)
	destroyOffer(orepo->arr->elems[i]);*/

	destroyDynamicArray(offerRepository->dynamicArray);
	free(offerRepository);
}

/*
Copies the repository from parameters and returns a pointer to the new created one.
IN: OfferRepo*
OUT: OfferRepo*
*/
OfferRepository* copyRepository(OfferRepository* offerRepository)
{
	if (offerRepository == NULL)
		return NULL;

	DynamicArray* newDynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* newRepository = createRepository(newDynamicArray);

	for (int i = 0; i < getLength(offerRepository); i++)
	{
		Offer* copy = copyOffer(getOfferOnPosition(offerRepository, i));
		addElement(newRepository->dynamicArray, copy);
	}

	return newRepository;
}

/*
Finds an Offer with a given id.
IN: OfferRepo, int
OUT: position if found, -1 if doesn't exist
CONDIS: id is positive
*/
int findById(OfferRepository* offerRepository, int id)
{
	if (offerRepository == NULL)
		return -1;

	//Exception handling
	if (id < 0)
		return -1;

	for (int i = 0; i < getLength(offerRepository); i++)
		if (getId(offerRepository->dynamicArray->elements[i]) == id)
			return i;

	return -1;
}

/*
READ function. Returns Offer from repository from given position.
IN: OfferRepo*, int
OUT: Offer
CONDIS: pos >= 0 and pos < length of repo
*/
Offer* getOfferOnPosition(OfferRepository* offerRepository, int position)
{
	if (offerRepository == NULL)
		return NULL;

	if (position < 0 || position >= offerRepository->dynamicArray->length)
		return NULL;

	return offerRepository->dynamicArray->elements[position];
}

/*
READ function.
Returns the length of the offer repo.
IN: OfferRepo*
OUT: int
*/
int getLength(OfferRepository* offerRepository)
{
	if (offerRepository == NULL)
		return -1;

	return offerRepository->dynamicArray->length;
}

/*
Add an offer to the repository given by a pointer.
IN: pointer to Repo, an Offer
OUT: 1 if succesful added, anything else if not
CONDIS:-
*/
int addOffer(OfferRepository* offerRepository, Offer* offer)
{
	if (offerRepository == NULL || offer == NULL)
		return 0;

	//Uniqueness
	if (findById(offerRepository, offer->id) != FAIL)
		return 0;

	Offer* copy = copyOffer(offer);
	addElement(offerRepository->dynamicArray, copy);

	return 1;
}

/*
Updates offer on given index.
IN:...
OUT: 1 if succesful, else not 1
CONDIS: -
*/
int updateOffer(OfferRepository* offerRepository, Offer* newOffer, int index)
{
	if (offerRepository == NULL || newOffer == NULL)
		return 0;

	updateElement(offerRepository->dynamicArray, newOffer, index);

	return 1;
}

/*
Removes offer with a given id.
IN: OfferRepo*, id
OUT: 1 if succesful, else not 1
CONDIS:-
*/
int deleteById(OfferRepository* offerRepository, int id)
{
	if (offerRepository == NULL || id < 0)
		return 0;

	int position = findById(offerRepository, id);
	//Entity does not exist
	if (position == -1)
		return 0;

	//Memory of deleted element is deallocated in dynamic array's function
	deleteElement(offerRepository->dynamicArray, position);

	return 1;
}

//TESTS
void initiateOffersRepositoryForTests(OfferRepository* offerRepository)
{
	if (offerRepository == NULL)
		assert(0);

	Offer* offer1 = createOffer(123, "seaside", "Panama", 100.02);
	Offer* offer2 = createOffer(124, "seaside", "Costa", 133.02);
	Offer* offer3 = createOffer(125, "mountain", "Everest", 270.02);
	Offer* offer4 = createOffer(126, "mountain", "Caucazi", 70.02);
	Offer* offer5 = createOffer(127, "mountain", "YeelowCreek", 110.02);
	Offer* offer6 = createOffer(128, "citybreak", "Moscov", 60.02);
	Offer* offer7 = createOffer(129, "citybreak", "Lisabona", 200.02);
	addOffer(offerRepository, offer1);
	addOffer(offerRepository, offer2);
	addOffer(offerRepository, offer3);
	addOffer(offerRepository, offer4);
	addOffer(offerRepository, offer5);
	addOffer(offerRepository, offer6);
	addOffer(offerRepository, offer7);
	//Copies are added.
	destroyOffer(offer1);
	destroyOffer(offer2);
	destroyOffer(offer3);
	destroyOffer(offer4);
	destroyOffer(offer5);
	destroyOffer(offer6);
	destroyOffer(offer7);
}

void testCopy()
{
	DynamicArray* dynamicArray = createDynamicArray(30, destroyOffer);
	OfferRepository* offerRepository = createRepository(dynamicArray);
	if (offerRepository == NULL || dynamicArray == NULL)
		assert(0);
	initiateOffersRepositoryForTests(offerRepository);

	OfferRepository* copyOfferRepository = copyRepository(offerRepository);
	assert(copyOfferRepository != offerRepository);
	for (int i = 0; i < getLength(copyOfferRepository); i++)
		assert(copyOfferRepository->dynamicArray->elements[i] != offerRepository->dynamicArray->elements[i]); //Point to same object?

	destroyRepository(copyOfferRepository);
	destroyRepository(offerRepository);
}

void testAdd()
{
	DynamicArray* dynamicArray = createDynamicArray(30, destroyOffer);
	OfferRepository* offerRepository = createRepository(dynamicArray);
		assert (offerRepository != NULL);
		assert(dynamicArray != NULL);
	initiateOffersRepositoryForTests(offerRepository);

	//add new unique element
	Offer* offer = createOffer(500, "seaside","Belize", 123);
	int size = getLength(offerRepository);
	assert(size == 7);
	assert(addOffer(offerRepository, offer) == 1);
	assert(getLength(offerRepository) == size + 1);

	// now try to add the same planet again -> add must return 0
	assert(!addOffer(offerRepository, offer));
	assert(areEqual(offer, getOfferOnPosition(offerRepository, 7)));

	//We added a copy in repo so the original medication remains to be deallocated.
	destroyOffer(offer);
	destroyRepository(offerRepository);
}

void testFind()
{
	DynamicArray* dynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* offerRepository = createRepository(dynamicArray);
	initiateOffersRepositoryForTests(offerRepository);

	assert(findById(offerRepository, 127) == 4);

	destroyRepository(offerRepository);
}

void testUpdate()
{
	DynamicArray* dynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* offerRepository = createRepository(dynamicArray);
	initiateOffersRepositoryForTests(offerRepository);

	Offer* offer1 = createOffer(800, "citybreak", "Bucharest", 25.88);
	destroyOffer(getOfferOnPosition(offerRepository, 1)); //pointer goes to new updated offer, old one must be deallocated
	updateOffer(offerRepository, offer1, 1); //update at given index

	Offer* offer2 = getOfferOnPosition(offerRepository, 1);
	assert(strcmp(getType(offer2), "citybreak") == 0);
	assert(getId(offer2) == 800);
	assert(strcmp(getDestination(offer2), "Bucharest") == 0);
	assert(getPrice(offer2) == (float)25.88);

	destroyRepository(offerRepository);
}

void testDelete()
{
	DynamicArray* dynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* offerRepository = createRepository(dynamicArray);
	initiateOffersRepositoryForTests(offerRepository);
	int size = getLength(offerRepository);

	//Delete, even from memory
	deleteById(offerRepository, 127);
	assert(getLength(offerRepository) == size - 1);

	//Inexisting element
	assert(deleteById(offerRepository, 127) == 0);

	destroyRepository(offerRepository);
}

/*
Calls all test fcts.
*/
void testOfferRepository()
{
	testAdd();
	testFind();
	testUpdate();
	testDelete();
	testCopy();
}