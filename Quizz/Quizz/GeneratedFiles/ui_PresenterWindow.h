/********************************************************************************
** Form generated from reading UI file 'PresenterWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTERWINDOW_H
#define UI_PRESENTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PresenterWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *questionsList;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *questionLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *answerLine;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *scoreLine;
    QPushButton *addQuestion;

    void setupUi(QWidget *PresenterWindow)
    {
        if (PresenterWindow->objectName().isEmpty())
            PresenterWindow->setObjectName(QStringLiteral("PresenterWindow"));
        PresenterWindow->resize(397, 296);
        verticalLayout_3 = new QVBoxLayout(PresenterWindow);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        questionsList = new QListWidget(PresenterWindow);
        questionsList->setObjectName(QStringLiteral("questionsList"));

        verticalLayout_2->addWidget(questionsList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(PresenterWindow);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        idLine = new QLineEdit(PresenterWindow);
        idLine->setObjectName(QStringLiteral("idLine"));

        horizontalLayout->addWidget(idLine);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(PresenterWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        questionLine = new QLineEdit(PresenterWindow);
        questionLine->setObjectName(QStringLiteral("questionLine"));

        horizontalLayout_2->addWidget(questionLine);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(PresenterWindow);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        answerLine = new QLineEdit(PresenterWindow);
        answerLine->setObjectName(QStringLiteral("answerLine"));

        horizontalLayout_3->addWidget(answerLine);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(PresenterWindow);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        scoreLine = new QLineEdit(PresenterWindow);
        scoreLine->setObjectName(QStringLiteral("scoreLine"));

        horizontalLayout_5->addWidget(scoreLine);


        verticalLayout_2->addLayout(horizontalLayout_5);

        addQuestion = new QPushButton(PresenterWindow);
        addQuestion->setObjectName(QStringLiteral("addQuestion"));

        verticalLayout_2->addWidget(addQuestion);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(PresenterWindow);
        QObject::connect(addQuestion, SIGNAL(clicked()), PresenterWindow, SLOT(addQuestion()));

        QMetaObject::connectSlotsByName(PresenterWindow);
    } // setupUi

    void retranslateUi(QWidget *PresenterWindow)
    {
        PresenterWindow->setWindowTitle(QApplication::translate("PresenterWindow", "PresenterWindow", 0));
        label->setText(QApplication::translate("PresenterWindow", "Id:", 0));
        idLine->setText(QString());
        label_2->setText(QApplication::translate("PresenterWindow", "Question:", 0));
        questionLine->setInputMask(QString());
        questionLine->setText(QString());
        label_3->setText(QApplication::translate("PresenterWindow", "Asnwer:", 0));
        answerLine->setText(QString());
        label_4->setText(QApplication::translate("PresenterWindow", "Score:", 0));
        scoreLine->setText(QString());
        addQuestion->setText(QApplication::translate("PresenterWindow", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class PresenterWindow: public Ui_PresenterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTERWINDOW_H
