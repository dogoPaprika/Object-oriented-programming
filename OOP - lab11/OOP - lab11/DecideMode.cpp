#include "DecideMode.h"


DecideMode::DecideMode(Controller* controller, int argc, char* argv[], QWidget *parent)
	:controller{ controller }, argc{ argc }, argv{ argv }, QWidget(parent)
{
	ui.setupUi(this);
}

DecideMode::~DecideMode()
{
}

void DecideMode::goToAdmin()
{
	Administrator* administrator = new Administrator{ controller };
	administrator->show();
}

void DecideMode::goToUser()
{
	UserMode* userMode = new UserMode{ controller };
	userMode->show();
}
