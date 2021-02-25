/********************************************************************************
** Form generated from reading UI file 'User.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QLineEdit *lineEdit;
    QPushButton *playButton;
    QVBoxLayout *verticalLayout_5;
    QListWidget *listWidget_2;
    QFormLayout *formLayout_2;
    QLabel *genreLabel;
    QLineEdit *genreLineEdit;
    QLabel *likesLabel;
    QLineEdit *likesLineEdit;
    QPushButton *filterButton;
    QPushButton *nextButton;
    QPushButton *initialButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(591, 410);
        horizontalLayout_2 = new QHBoxLayout(Form);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        listWidget = new QListWidget(Form);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_4->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveButton = new QPushButton(Form);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_4->addLayout(horizontalLayout);

        playButton = new QPushButton(Form);
        playButton->setObjectName(QStringLiteral("playButton"));

        verticalLayout_4->addWidget(playButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        listWidget_2 = new QListWidget(Form);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        verticalLayout_5->addWidget(listWidget_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        genreLabel = new QLabel(Form);
        genreLabel->setObjectName(QStringLiteral("genreLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, genreLabel);

        genreLineEdit = new QLineEdit(Form);
        genreLineEdit->setObjectName(QStringLiteral("genreLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, genreLineEdit);

        likesLabel = new QLabel(Form);
        likesLabel->setObjectName(QStringLiteral("likesLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, likesLabel);

        likesLineEdit = new QLineEdit(Form);
        likesLineEdit->setObjectName(QStringLiteral("likesLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, likesLineEdit);

        filterButton = new QPushButton(Form);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, filterButton);


        verticalLayout_5->addLayout(formLayout_2);

        nextButton = new QPushButton(Form);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        verticalLayout_5->addWidget(nextButton);

        initialButton = new QPushButton(Form);
        initialButton->setObjectName(QStringLiteral("initialButton"));

        verticalLayout_5->addWidget(initialButton);


        horizontalLayout_2->addLayout(verticalLayout_5);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label->setText(QApplication::translate("Form", "Watch List", 0));
        saveButton->setText(QApplication::translate("Form", "Save", 0));
        playButton->setText(QApplication::translate("Form", "Play", 0));
        genreLabel->setText(QApplication::translate("Form", "Genre:", 0));
        likesLabel->setText(QApplication::translate("Form", "Likes:", 0));
        filterButton->setText(QApplication::translate("Form", "Filter", 0));
        nextButton->setText(QApplication::translate("Form", "Next", 0));
        initialButton->setText(QApplication::translate("Form", "All Movies", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
