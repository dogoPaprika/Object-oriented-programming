#include "Offer.h"

/*
Validates the fields of an offer before we create it. To know if to create or not.
IN: int, char*, char*, float
OUT: 1 if valid, else not 1
CONDIS:-
*/
int validateFields(int id, char* type, char* destination, float price)
{
	if (id > 0 && price > 0)
		return 1;
	return 0;
}

/*
Creates an object/struct Offer with an id, type, destination, price.
IN: int, char*, char*, float
OUT: an Offer
CONDIS: name[49], type = (seaside, mountain, citybreak), id > 0, price >= 0
*/
Offer* createOffer(int id, char* type, char* destination, float price)
{
	if (type == NULL)
		return NULL;

	if (destination == NULL)
		return NULL;

	if (!validateFields(id, type, destination, price))
		return NULL;

	Offer* newOffer = (Offer*)malloc(sizeof(Offer));

	newOffer->id = id;
	newOffer->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(newOffer->type, type);
	newOffer->destination = (char*)malloc(sizeof(char) * (strlen(destination) + 1));
	strcpy(newOffer->destination, destination);
	newOffer->price = price;

	return newOffer;
}

/*
Destroys the memory allocated for an offer.
IN: pointer to Offer
OUT: -
*/
void destroyOffer(Offer* offer)
{
	if (offer == NULL)
		return;

	free(offer->type);
	free(offer->destination);
	free(offer);
}

/*
Returns a pointer to a copy in memory of offer p.
IN:offfer*
OUT: pt to new offer
*/
Offer* copyOffer(Offer* offer)
{
	if (offer == NULL)
		return NULL;

	Offer* newOffer = createOffer(getId(offer), getType(offer), getDestination(offer), getPrice(offer));
	return newOffer;
}

/*
Transforms into a string the offer.
*/
void toString(Offer* offer, char string[])
{
	if (offer == NULL)
		return;
	sprintf(string, "Offer '%d' of type %s, destination %s has price %.2f", offer->id, offer->type, offer->destination, offer->price);
}

/*
Gets id of offer.
*/
int getId(Offer* offer)
{
	if (offer == NULL)
		return -1;

	return offer->id;
}

/*
Gets type of offer.
*/
char* getType(Offer* offer)
{
	if (offer == NULL)
		return "";
	return offer->type;
}

/*
Gets destination of offer.
*/
char* getDestination(Offer* offer)
{
	if (offer == NULL)
		return "";
	return offer->destination;
}

/*
Gets price of offer.
*/
float getPrice(Offer* offer)
{
	if (offer == NULL)
		return -1;
	return offer->price;
}

/*
Checks if 2 offers are equal in fields.
IN: offer*, offer*
OUT:1 if are equal, else not 1
*/
int areEqual(Offer* offer1, Offer* offer2)
{
	if (getId(offer1) != getId(offer2))
		return 0;
	if (strcmp(getType(offer1), getType(offer2)) != 0)
		return 0;
	if (strcmp(getDestination(offer1), getDestination(offer2)) != 0)
		return 0;
	if (getPrice(offer1) != getPrice(offer2))
		return 0;
	return 1;
}


//TESTS
void testCreateOffer()
{
	Offer* offer1 = createOffer(123, "seaside", "Panama", 100.02);

	assert(getId(offer1) == 123);
	assert(strcmp(getType(offer1), "seaside") == 0);
	assert(strcmp(getDestination(offer1), "Panama") == 0);
	assert(getPrice(offer1) == (float)100.02);

	//validate fields
	Offer* offer2 = createOffer(123, "alpine", "Panama", -43);
	assert(offer2 == NULL);
	Offer* offer3 = createOffer(123, "seaside", "Panama", -7);
	assert(offer3 == NULL);

	Offer* offer4 = copyOffer(offer1);
	assert(areEqual(offer4, offer1));

	destroyOffer(offer1);
	destroyOffer(offer4);
}

void testOffer()
{
	testCreateOffer();
}
