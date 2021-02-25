/********************************************************************************
** Form generated from reading UI file 'Examen.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMEN_H
#define UI_EXAMEN_H

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

class Ui_ExamenClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamenClass)
    {
        if (ExamenClass->objectName().isEmpty())
            ExamenClass->setObjectName(QStringLiteral("ExamenClass"));
        ExamenClass->resize(600, 400);
        menuBar = new QMenuBar(ExamenClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ExamenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamenClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ExamenClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ExamenClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ExamenClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ExamenClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ExamenClass->setStatusBar(statusBar);

        retranslateUi(ExamenClass);

        QMetaObject::connectSlotsByName(ExamenClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamenClass)
    {
        ExamenClass->setWindowTitle(QApplication::translate("ExamenClass", "Examen", 0));
    } // retranslateUi

};

namespace Ui {
    class ExamenClass: public Ui_ExamenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMEN_H
