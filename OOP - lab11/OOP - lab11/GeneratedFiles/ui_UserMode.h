/********************************************************************************
** Form generated from reading UI file 'UserMode.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMODE_H
#define UI_USERMODE_H

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

class Ui_UserMode
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QListWidget *watchList;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QLineEdit *saveLineEdit;
    QPushButton *playButton;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QListWidget *filterList;
    QFormLayout *formLayout_2;
    QLabel *genreLabel;
    QLineEdit *genreLineEdit;
    QLabel *likesLabel;
    QLineEdit *likesLineEdit;
    QPushButton *filterButton;
    QPushButton *nextButton;
    QPushButton *initialButton;

    void setupUi(QWidget *UserMode)
    {
        if (UserMode->objectName().isEmpty())
            UserMode->setObjectName(QStringLiteral("UserMode"));
        UserMode->resize(407, 301);
        horizontalLayout_2 = new QHBoxLayout(UserMode);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(UserMode);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        watchList = new QListWidget(UserMode);
        watchList->setObjectName(QStringLiteral("watchList"));

        verticalLayout_4->addWidget(watchList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveButton = new QPushButton(UserMode);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);

        saveLineEdit = new QLineEdit(UserMode);
        saveLineEdit->setObjectName(QStringLiteral("saveLineEdit"));

        horizontalLayout->addWidget(saveLineEdit);


        verticalLayout_4->addLayout(horizontalLayout);

        playButton = new QPushButton(UserMode);
        playButton->setObjectName(QStringLiteral("playButton"));

        verticalLayout_4->addWidget(playButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_2 = new QLabel(UserMode);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);

        filterList = new QListWidget(UserMode);
        filterList->setObjectName(QStringLiteral("filterList"));

        verticalLayout_5->addWidget(filterList);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        genreLabel = new QLabel(UserMode);
        genreLabel->setObjectName(QStringLiteral("genreLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, genreLabel);

        genreLineEdit = new QLineEdit(UserMode);
        genreLineEdit->setObjectName(QStringLiteral("genreLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, genreLineEdit);

        likesLabel = new QLabel(UserMode);
        likesLabel->setObjectName(QStringLiteral("likesLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, likesLabel);

        likesLineEdit = new QLineEdit(UserMode);
        likesLineEdit->setObjectName(QStringLiteral("likesLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, likesLineEdit);

        filterButton = new QPushButton(UserMode);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, filterButton);


        verticalLayout_5->addLayout(formLayout_2);

        nextButton = new QPushButton(UserMode);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        verticalLayout_5->addWidget(nextButton);

        initialButton = new QPushButton(UserMode);
        initialButton->setObjectName(QStringLiteral("initialButton"));

        verticalLayout_5->addWidget(initialButton);


        horizontalLayout_2->addLayout(verticalLayout_5);


        retranslateUi(UserMode);
        QObject::connect(saveButton, SIGNAL(clicked()), UserMode, SLOT(saveMovie()));
        QObject::connect(playButton, SIGNAL(clicked()), UserMode, SLOT(playTrailer()));
        QObject::connect(initialButton, SIGNAL(clicked()), UserMode, SLOT(initiate()));
        QObject::connect(filterButton, SIGNAL(clicked()), UserMode, SLOT(filterRepository()));
        QObject::connect(nextButton, SIGNAL(clicked()), UserMode, SLOT(nextMovie()));

        QMetaObject::connectSlotsByName(UserMode);
    } // setupUi

    void retranslateUi(QWidget *UserMode)
    {
        UserMode->setWindowTitle(QApplication::translate("UserMode", "UserMode", 0));
        label->setText(QApplication::translate("UserMode", "Watch List", 0));
        saveButton->setText(QApplication::translate("UserMode", "Save", 0));
        playButton->setText(QApplication::translate("UserMode", "Play", 0));
        label_2->setText(QApplication::translate("UserMode", "Filter Results", 0));
        genreLabel->setText(QApplication::translate("UserMode", "Genre:", 0));
        likesLabel->setText(QApplication::translate("UserMode", "Likes:", 0));
        filterButton->setText(QApplication::translate("UserMode", "Filter", 0));
        nextButton->setText(QApplication::translate("UserMode", "Next", 0));
        initialButton->setText(QApplication::translate("UserMode", "All Movies", 0));
    } // retranslateUi

};

namespace Ui {
    class UserMode: public Ui_UserMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMODE_H
