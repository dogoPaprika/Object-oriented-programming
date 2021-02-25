/********************************************************************************
** Form generated from reading UI file 'GraphicalUserInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICALUSERINTERFACE_H
#define UI_GRAPHICALUSERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicalUserInterfaceClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphicalUserInterfaceClass)
    {
        if (GraphicalUserInterfaceClass->objectName().isEmpty())
            GraphicalUserInterfaceClass->setObjectName(QStringLiteral("GraphicalUserInterfaceClass"));
        GraphicalUserInterfaceClass->resize(600, 400);
        menuBar = new QMenuBar(GraphicalUserInterfaceClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GraphicalUserInterfaceClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GraphicalUserInterfaceClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GraphicalUserInterfaceClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GraphicalUserInterfaceClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GraphicalUserInterfaceClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GraphicalUserInterfaceClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GraphicalUserInterfaceClass->setStatusBar(statusBar);

        retranslateUi(GraphicalUserInterfaceClass);

        QMetaObject::connectSlotsByName(GraphicalUserInterfaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphicalUserInterfaceClass)
    {
        GraphicalUserInterfaceClass->setWindowTitle(QApplication::translate("GraphicalUserInterfaceClass", "GraphicalUserInterface", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicalUserInterfaceClass: public Ui_GraphicalUserInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICALUSERINTERFACE_H
