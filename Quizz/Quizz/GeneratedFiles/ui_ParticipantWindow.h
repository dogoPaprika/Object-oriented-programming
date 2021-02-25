/********************************************************************************
** Form generated from reading UI file 'ParticipantWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTICIPANTWINDOW_H
#define UI_PARTICIPANTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParticipantWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *questions;
    QLineEdit *answerLineEdit;
    QVBoxLayout *verticalLayout_2;
    QListWidget *score;
    QPushButton *answer;

    void setupUi(QWidget *ParticipantWindow)
    {
        if (ParticipantWindow->objectName().isEmpty())
            ParticipantWindow->setObjectName(QStringLiteral("ParticipantWindow"));
        ParticipantWindow->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ParticipantWindow);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        questions = new QListWidget(ParticipantWindow);
        questions->setObjectName(QStringLiteral("questions"));

        verticalLayout->addWidget(questions);

        answerLineEdit = new QLineEdit(ParticipantWindow);
        answerLineEdit->setObjectName(QStringLiteral("answerLineEdit"));

        verticalLayout->addWidget(answerLineEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        score = new QListWidget(ParticipantWindow);
        score->setObjectName(QStringLiteral("score"));
        score->setEnabled(true);

        verticalLayout_2->addWidget(score);

        answer = new QPushButton(ParticipantWindow);
        answer->setObjectName(QStringLiteral("answer"));

        verticalLayout_2->addWidget(answer);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(ParticipantWindow);

        QMetaObject::connectSlotsByName(ParticipantWindow);
    } // setupUi

    void retranslateUi(QWidget *ParticipantWindow)
    {
        ParticipantWindow->setWindowTitle(QApplication::translate("ParticipantWindow", "ParticipantWindow", 0));
        answer->setText(QApplication::translate("ParticipantWindow", "Answer", 0));
    } // retranslateUi

};

namespace Ui {
    class ParticipantWindow: public Ui_ParticipantWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTICIPANTWINDOW_H
