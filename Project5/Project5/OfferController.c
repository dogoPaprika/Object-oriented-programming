#include "OfferController.h"

/*
Creates a controller with a pointer to a repository.
IN: pointer to repository
OUT: a Controller
CONDIS:-
*/
Controller* createController(OfferRepository* offerRepository, OperationsStack* undoStack, OperationsStack* redoStack)
{
	if (offerRepository == NULL)
		return NULL;

	Controller* newController = (Controller*)malloc(sizeof(Controller));
	newController->repository = offerRepository;
	newController->undoStack = undoStack;
	newController->redoStack = redoStack;

	newController->undoList = createDynamicArray(100, destroyRepository);
	//	c->currentUndo = 0;
	newController->redoList = createDynamicArray(100, destroyRepository);
	//	c->currentRedo = 0;

	return newController;
}

/*
Deallocates the memory used for the controller.
IN: Controller
OUT: -
*/
void destroyController(Controller* controller)
{
	if (controller == NULL)
		return;

	destroyRepository(controller->repository);
	destroyStack(controller->undoStack);
	destroyStack(controller->redoStack);
	destroyDynamicArray(controller->undoList);
	destroyDynamicArray(controller->redoList);

	free(controller);
}


/*
Gives the position on which the offerwith the target id is.
IN: controller, float
OUT: integer
*/
int findByIdController(Controller* controller, int targetId)
{
	return findById(controller->repository, targetId);
}

/*
READ function. Returns the repository of the controller pointed by c.
IN: Controller*
OUT: OfferRepo*
*/
OfferRepository* getRepository(Controller* controller)
{
	if (controller == NULL)
		return NULL;
	return controller->repository;
}

/*
Returns a repository with offers containing given destination.
IN:Controller*, string
OUT: repository with results
*/
OfferRepository* getOffersByDestinationController(Controller* controller, char destination[])
{
	if (controller == NULL)
		return NULL;

	DynamicArray* dynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* destinationRepository = createRepository(dynamicArray);

	for (int i = 0; i < getLength(controller->repository); i++)
	{
		if (strcmp(getDestination(getOfferOnPosition(controller->repository, i)), destination) == 0)
			addOffer(destinationRepository, getOfferOnPosition(controller->repository, i));
	}
	return destinationRepository;
}

/*
Returns a repository with offers containing given destination.
IN:Controller*, string
OUT: repository with results
*/
OfferRepository* getOffersByPriceController(Controller* controller, float maximumPrice)
{
	if (controller == NULL)
		return NULL;

	DynamicArray* dynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* maximumPriceRepository = createRepository(dynamicArray);

	for (int i = 0; i < getLength(controller->repository); i++)
	{
		if (getPrice(getOfferOnPosition(controller->repository, i)) < maximumPrice)
			addOffer(maximumPriceRepository, getOfferOnPosition(controller->repository, i));
	}

	sortByType(maximumPriceRepository);

	return maximumPriceRepository;
}

void sortByType(OfferRepository* offerRepository)
{
	for (int i = 0; i < getLength(offerRepository) - 1; i++)
		for (int j = i+1; j < getLength(offerRepository); j++)
	{
		if (strcmp(getType(getOfferOnPosition(offerRepository, i)), getType(getOfferOnPosition(offerRepository, j))) == 1)
		{
			
			
			
			(&offerRepository->dynamicArray->elements[i], &offerRepository->dynamicArray->elements[j]);
		}
	}
}



/*
Adds new offer. Creates it from parameters. Calls the function of adding from repository.
IN: Controller*, int, char[], char[], float
OUT: 1 if succesful, anything else if unsuccesful
CONDIS: handled in validateFields()
*/
int addOfferController(Controller* controller, int id, char* type, char* destination, float price)
{
	if (controller == NULL || type == NULL || destination == NULL)
		return 0;

	//Validate offer
	if (!validateFields(id, type, destination, price))
	{
		return 0;
	}

	Offer* newOffer = createOffer(id, type, destination, price);

	//Copy the state of the repository
	OfferRepository* repo2 = copyRepository(controller->repository);

	int addStatus = addOffer(controller->repository, newOffer);

	if (addStatus == 1)
	{
		//List of lists  undo
		addElement(controller->undoList, repo2);

		//Operation stack undo
		Operation* addOperation = createOperation(newOffer, "add");
		push(controller->undoStack, addOperation);
		destroyOperation(addOperation);
	}
	else
		destroyRepository(repo2);

	destroyOffer(newOffer);
	return addStatus;
}

/*

OUT:1 if succesful, else not 1
*/
int updateOfferController(Controller* controller, int id, char* type, char* destination, float price)
{
	if (controller == NULL || id < 0)
		return 0;

	if (!validateFields(id, type, destination, price))
		return 0;

	//If the one we want to update does not exist
	//or the new concentration exists in repo (will not be unique)
	int position = findByIdController(controller, id);

	if (position == -1)
		return 0;

	//Store in operations stack 2 operations first is 'remove' next on top is 'update'
	Offer* offer = getOfferOnPosition(controller->repository, position);
	Offer* newOffer = createOffer(id, type, destination, price);
	Operation* operation1 = createOperation(offer, "remove");//know the old one as "update"
	Operation* operation2 = createOperation(newOffer, "update");//updated offer is add so undo will delete it

	OfferRepository* repo2 = copyRepository(controller->repository);

	int updateStatus = updateOffer(controller->repository, newOffer, position);

	if (updateStatus == 1)
	{
		push(controller->undoStack, operation1);
		push(controller->undoStack, operation2);

		//List of Lists
		addElement(controller->undoList, repo2);
	}
	else
		destroyRepository(repo2);

	destroyOffer(offer);
	destroyOperation(operation1);
	destroyOperation(operation2);
	return updateStatus;
}


/*
Removes offer with a given id.
IN: Controller*, char []
OUT: 1 if succesful, else not 1
CONDIS:-
*/
int deleteByIdController(Controller* controller, int id)
{
	if (controller == NULL)
		return 0;

	int position = findByIdController(controller, id);
	if (position == -1)
		return 0;

	Offer* offer = getOfferOnPosition(controller->repository, position);
	Operation* operation = createOperation(offer, "remove");

	OfferRepository* repo2 = copyRepository(controller->repository);

	int deleteStatus = deleteById(controller->repository, id);
	if (deleteStatus != 0)
	{
		push(controller->undoStack, operation);

		//List of Lists
		addElement(controller->undoList, repo2);
	}
	else
		destroyRepository(repo2);

	destroyOperation(operation);

	return deleteStatus;
}



/*
Swaps 2 pointers. They will point to other's element.
IN: void pointer, void pointer
OUT:-
*/
void swap(void** element1, void** element2)
{
	if (element1 == NULL || element2 == NULL)
		return;

	void* temporary = *element1;
	*element1 = *element2;
	*element2 = temporary;
}

/*
Sorts any list comparing 2 elements with the function relation.
IN: pointer to pointer (to a list), length of list, a function to compare
OUT:-

void mySort(void** list, int length, relation rel)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (rel(list[i], list[j]))
			{
				swap(&list[i], &list[j]);
			}
		}
	}
}
*/


/*
The original repository becomes the last one added in undo list of repositories.
IN: Controller*
OUT: 1 if succesful, else not 1
*/
int undoListOfList(Controller* controller)
{
	if (getLengthArray(controller->undoList) == 0)
		return 0;

	int length = getLengthArray(controller->undoList);

	addElement(controller->redoList, controller->repository); //add current repository (undo operation) in redo list
							   //destroyRepo(c->repo);

	controller->repository = controller->undoList->elements[length - 1];
	controller->undoList->elements[length - 1] = NULL;
	controller->undoList->length--;

	return 1;
}

/*
Redos the operation that was undo-ed until add/update/delete is used, then the repo becomes empty.
IN:Controller*
OUT: 1 if succesful, else not 1
*/
int redoListOfList(Controller* controller)
{
	if (getLengthArray(controller->redoList) == 0)
		return 0;

	int length = getLengthArray(controller->redoList);

	addElement(controller->undoList, controller->repository); //add redo-ed operation in undo list

	controller->repository = controller->redoList->elements[length - 1];
	controller->redoList->elements[length - 1] = NULL;
	controller->redoList->length--;

	return 1;
}

/*
Looks into stack. Sees last operation and does the requierement in order to nullify it.
IN: controller
OUT: 1 if succesful, else not 1
*/
int undoOperationStack(Controller* controller)
{
	if (isEmpty(controller->undoStack))
		return 0;

	Operation* operation = pop(controller->undoStack);
	push(controller->redoStack, operation); //Push in redo stack so we can cancel the undo.
								   //printf("%s\n", getOperationType(operation));
								   //printf("redo: %s\n", getOperationType(c->redoStack->operations[c->redoStack->length-1]));

	if (strcmp(getOperationType(operation), "add") == 0 || strcmp(getOperationType(operation), "update") == 0)
	{
		Offer* offer = getOperationElement(operation); //This offer surely exists
		deleteById(controller->repository, getId(offer));
		if (strcmp(getOperationType(operation), "update") == 0)
		{
			undoOperationStack(controller);
		}
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		Offer* offer = getOperationElement(operation); //Offer that was removed
		addOffer(controller->repository, offer);
	}

	destroyOperation(operation);
	return 1;
}

/*
When user performs any task, the redo stack is cleared. This function is called from UI infinite loop.
IN: Controller*
OUT:-
*/
void clearRedo(Controller* controller)
{
	clear(controller->redoStack);
}

/*
Re-does the operation that we undo-ed last time.
IN:Controller*
OUT:1 if succesful, else not 1
*/
int redoOperationStack(Controller* controller)
{
	if (isEmpty(controller->redoStack))
		return 0;

	Operation* operation = pop(controller->redoStack);

	if (strcmp(getOperationType(operation), "add") == 0 )
	{
		Offer* offer = getOperationElement(operation); //Re-add the element
		addOfferController(controller, getId(offer), getType(offer), getDestination(offer), getPrice(offer));
	}
	else if (strcmp(getOperationType(operation), "update") == 0)
	{
		Offer* offer = getOperationElement(operation);
		updateOfferController(controller, getId(offer), getType(offer), getDestination(offer), getPrice(offer));
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		Offer* offer = getOperationElement(operation);

		Operation* operation = onTop(controller->redoStack); //Check if next operation is update
		int isEmptyList = 1;//1 if list is not empty
		int nextOperationUpdate = 1;//1 if list is not empty and next operation is update

		if (operation == NULL)
			isEmptyList = 0;
		else
			if (strcmp(getOperationType(operation), "update") != 0)
				nextOperationUpdate = 0;
			else
			{
				addOffer(controller->repository, offer);
				redoOperationStack(controller);
			}

		if (!isEmptyList || !nextOperationUpdate)
			deleteByIdController(controller, getId(offer));
	}

	destroyOperation(operation);
	return 1;
}

//TESTS


void testUndoRedo()
{
	OperationsStack* undoSack = createStack();
	OperationsStack* redoStack = createStack();
	DynamicArray* dynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* offerRepository = createRepository(dynamicArray);
	initiateOffersRepositoryForTests(offerRepository);

	Controller* controller = createController(offerRepository, undoSack, redoStack);

	//Undo/redo for add new.
	int length = getLength(getRepository(controller));
	addOfferController(controller, 100, "mountain", "Nevada", 55.7);
	assert(getLength(getRepository(controller)) == length + 1);
	addOfferController(controller, 101, "seaside", "Palmize", 140.07);
	undoOperationStack(controller);
	undoOperationStack(controller);
	assert(undoOperationStack(controller) == 0);
	assert(getLength(getRepository(controller)) == length);
	redoOperationStack(controller);
	assert(getLength(getRepository(controller)) == length + 1);
	redoOperationStack(controller);
	assert(redoOperationStack(controller) == 0);

	//remove
	deleteByIdController(controller, 101);
	int findStatus = findByIdController(controller, 101);
	assert(findStatus == -1);
	undoOperationStack(controller);
	findStatus = findByIdController(controller, 101);
	assert(findStatus != -1);
	redoOperationStack(controller);
	findStatus = findByIdController(controller, 101);
	assert(findStatus == -1);

	//update


	destroyController(controller);
}

void testCreateController()
{
	OperationsStack* undoStack = createStack();
	OperationsStack* redoStack = createStack();
	DynamicArray* dynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* offerRepository = createRepository(dynamicArray);
	initiateOffersRepositoryForTests(offerRepository);

	//DynamicArray* undoList = createDynamicArray(100, destroyRepo);
	Controller* controller = createController(offerRepository, undoStack, redoStack);

	if (controller == NULL)
		assert(0);

	destroyController(controller);
}

//Tests the functions from the Controller.
void testController()
{
	testCreateController();
	testUndoRedo();
}