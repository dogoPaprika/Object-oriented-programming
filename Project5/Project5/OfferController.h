#pragma once

#include "OfferRepo.h"
#include "Offer.h"
#include "OperationsStack.h"

typedef struct
{
	OfferRepository* repository;
	OperationsStack* undoStack;
	OperationsStack* redoStack;
	DynamicArray* undoList;
	DynamicArray* redoList;

} Controller;

Controller* createController(OfferRepository* offerRepository, OperationsStack* undoStack, OperationsStack* redoStack);
void destroyController(Controller* controller);

//CRUD
int findByIdController(Controller* controller, int targetId);
OfferRepository* getRepository(Controller* controller);
int addOfferController(Controller* controller, int id, char* type, char* destination, float price);

int updateOfferController(Controller* controller, int id, char* newType, char* newDestination, float newPrice);

int deleteByIndexController(Controller* controller, int index);
int deleteByIdController(Controller* controller, int id);



OfferRepository* listOffersController(Controller* controller);
OfferRepository* getOffersByDestinationController(Controller* controller, char destination[]);
OfferRepository* getOffersByPriceController(Controller* controller, float maximumPrice);
void sortByType(OfferRepository* repository);
void swap(void** element1, void** element2);

//Undo, Redo
void clearRedo(Controller* controller);
int undoOperationStack(Controller* controller);
int redoOperationStack(Controller* controller);

//List of lists functionalities
int undoListOfList(Controller* controller);
int redoListOfList(Controller* controller);

void testController();