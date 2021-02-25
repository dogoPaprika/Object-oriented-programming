/********************************************************************************
** Form generated from reading UI file 'DecideMode.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECIDEMODE_H
#define UI_DECIDEMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DecideMode
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *adminButton;
    QPushButton *userMode;

    void setupUi(QWidget *DecideMode)
    {
        if (DecideMode->objectName().isEmpty())
            DecideMode->setObjectName(QStringLiteral("DecideMode"));
        DecideMode->resize(170, 108);
        verticalLayout = new QVBoxLayout(DecideMode);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DecideMode);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        adminButton = new QPushButton(DecideMode);
        adminButton->setObjectName(QStringLiteral("adminButton"));

        verticalLayout->addWidget(adminButton);

        userMode = new QPushButton(DecideMode);
        userMode->setObjectName(QStringLiteral("userMode"));

        verticalLayout->addWidget(userMode);


        retranslateUi(DecideMode);
        QObject::connect(adminButton, SIGNAL(clicked()), DecideMode, SLOT(goToAdmin()));
        QObject::connect(userMode, SIGNAL(clicked()), DecideMode, SLOT(goToUser()));

        QMetaObject::connectSlotsByName(DecideMode);
    } // setupUi

    void retranslateUi(QWidget *DecideMode)
    {
        DecideMode->setWindowTitle(QApplication::translate("DecideMode", "DecideMode", 0));
        label->setText(QApplication::translate("DecideMode", "Please, choose the mode:", 0));
        adminButton->setText(QApplication::translate("DecideMode", "Administrator", 0));
        userMode->setText(QApplication::translate("DecideMode", "User", 0));
    } // retranslateUi

};

namespace Ui {
    class DecideMode: public Ui_DecideMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECIDEMODE_H
