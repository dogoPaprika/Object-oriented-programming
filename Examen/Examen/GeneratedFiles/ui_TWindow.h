/********************************************************************************
** Form generated from reading UI file 'TWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWINDOW_H
#define UI_TWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TWindow
{
public:

    void setupUi(QWidget *TWindow)
    {
        if (TWindow->objectName().isEmpty())
            TWindow->setObjectName(QStringLiteral("TWindow"));
        TWindow->resize(400, 300);

        retranslateUi(TWindow);

        QMetaObject::connectSlotsByName(TWindow);
    } // setupUi

    void retranslateUi(QWidget *TWindow)
    {
        TWindow->setWindowTitle(QApplication::translate("TWindow", "TWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class TWindow: public Ui_TWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWINDOW_H
