#include "TWindow.h"

TWindow::TWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

TWindow::~TWindow()
{
}
