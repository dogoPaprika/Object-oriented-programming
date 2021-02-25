#pragma once

#include "Offer.h"
#include "DynamicArray.h"
#include <string.h>
#include <assert.h>

typedef struct
{
	DynamicArray* dynamicArray;

} OfferRepository;

//CREATE
OfferRepository* createRepository(DynamicArray* dynamicArray);
void destroyRepository(OfferRepository* offerRepository);
OfferRepository* copyRepository(OfferRepository* offerRepository);

//READ
int getLength(OfferRepository* offerRepository);
Offer* getOfferOnPosition(OfferRepository* offerRepository, int position);
int findById(OfferRepository* offerRepository, int id);

int addOffer(OfferRepository* offerRepository, Offer* offer);
///Adds offer to offer repository.

//UPDATE - by id
int updateOffer(OfferRepository* offerRepository, Offer* newOffer, int id);

//DELETE
int deleteById(OfferRepository* offerRepository, int id);

//TESTS
void initiateOffersRepositoryForTests(OfferRepository* offerRepository);
void testOfferRepository();