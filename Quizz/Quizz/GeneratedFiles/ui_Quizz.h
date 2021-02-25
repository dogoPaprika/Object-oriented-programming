/********************************************************************************
** Form generated from reading UI file 'Quizz.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZZ_H
#define UI_QUIZZ_H

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

class Ui_QuizzClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuizzClass)
    {
        if (QuizzClass->objectName().isEmpty())
            QuizzClass->setObjectName(QStringLiteral("QuizzClass"));
        QuizzClass->resize(600, 400);
        menuBar = new QMenuBar(QuizzClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QuizzClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QuizzClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QuizzClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QuizzClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QuizzClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QuizzClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QuizzClass->setStatusBar(statusBar);

        retranslateUi(QuizzClass);

        QMetaObject::connectSlotsByName(QuizzClass);
    } // setupUi

    void retranslateUi(QMainWindow *QuizzClass)
    {
        QuizzClass->setWindowTitle(QApplication::translate("QuizzClass", "Quizz", 0));
    } // retranslateUi

};

namespace Ui {
    class QuizzClass: public Ui_QuizzClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZZ_H
