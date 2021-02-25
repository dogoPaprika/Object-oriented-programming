#pragma once
#include <QWidget>
#include <QtGUI>
#include <QtCore>

class ProgramaticallyDesignedWidget : public QWidget
{
public:
	ProgramaticallyDesignedWidget(QWidget * parent = Q_NULLPTR);
	~ProgramaticallyDesignedWidget();

private:
	void initGUI();
protected:
	void paintEvent(QPaintEvent *e);
};