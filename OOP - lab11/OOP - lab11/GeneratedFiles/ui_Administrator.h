/********************************************************************************
** Form generated from reading UI file 'Administrator.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

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

class Ui_Administrator
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QListWidget *listMovies;
    QFormLayout *formLayout;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *genreLabel;
    QLineEdit *genreLineEdit;
    QLabel *yearLabel;
    QLineEdit *yearLineEdit;
    QLabel *likesLabel;
    QLineEdit *likesLineEdit;
    QLabel *trailerLabel;
    QLineEdit *trailerLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;

    void setupUi(QWidget *Administrator)
    {
        if (Administrator->objectName().isEmpty())
            Administrator->setObjectName(QStringLiteral("Administrator"));
        Administrator->resize(702, 703);
        verticalLayout_3 = new QVBoxLayout(Administrator);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(Administrator);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        listMovies = new QListWidget(Administrator);
        listMovies->setObjectName(QStringLiteral("listMovies"));

        verticalLayout_3->addWidget(listMovies);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        titleLabel = new QLabel(Administrator);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, titleLabel);

        titleLineEdit = new QLineEdit(Administrator);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, titleLineEdit);

        genreLabel = new QLabel(Administrator);
        genreLabel->setObjectName(QStringLiteral("genreLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, genreLabel);

        genreLineEdit = new QLineEdit(Administrator);
        genreLineEdit->setObjectName(QStringLiteral("genreLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, genreLineEdit);

        yearLabel = new QLabel(Administrator);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, yearLabel);

        yearLineEdit = new QLineEdit(Administrator);
        yearLineEdit->setObjectName(QStringLiteral("yearLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, yearLineEdit);

        likesLabel = new QLabel(Administrator);
        likesLabel->setObjectName(QStringLiteral("likesLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, likesLabel);

        likesLineEdit = new QLineEdit(Administrator);
        likesLineEdit->setObjectName(QStringLiteral("likesLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, likesLineEdit);

        trailerLabel = new QLabel(Administrator);
        trailerLabel->setObjectName(QStringLiteral("trailerLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, trailerLabel);

        trailerLineEdit = new QLineEdit(Administrator);
        trailerLineEdit->setObjectName(QStringLiteral("trailerLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, trailerLineEdit);


        verticalLayout_3->addLayout(formLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        addButton = new QPushButton(Administrator);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_3->addWidget(addButton);

        deleteButton = new QPushButton(Administrator);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_3->addWidget(deleteButton);

        updateButton = new QPushButton(Administrator);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout_3->addWidget(updateButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(Administrator);
        QObject::connect(addButton, SIGNAL(clicked()), Administrator, SLOT(addMovie()));
        QObject::connect(deleteButton, SIGNAL(clicked()), Administrator, SLOT(deleteMovie()));
        QObject::connect(updateButton, SIGNAL(clicked()), Administrator, SLOT(updateMovie()));

        QMetaObject::connectSlotsByName(Administrator);
    } // setupUi

    void retranslateUi(QWidget *Administrator)
    {
        Administrator->setWindowTitle(QApplication::translate("Administrator", "Administrator", 0));
        label->setText(QApplication::translate("Administrator", "Movies", 0));
        titleLabel->setText(QApplication::translate("Administrator", "Title", 0));
        genreLabel->setText(QApplication::translate("Administrator", "Genre", 0));
        yearLabel->setText(QApplication::translate("Administrator", "Year", 0));
        likesLabel->setText(QApplication::translate("Administrator", "Likes", 0));
        trailerLabel->setText(QApplication::translate("Administrator", "Trailer", 0));
        addButton->setText(QApplication::translate("Administrator", "Add", 0));
        deleteButton->setText(QApplication::translate("Administrator", "Delete", 0));
        updateButton->setText(QApplication::translate("Administrator", "Update", 0));
    } // retranslateUi

};

namespace Ui {
    class Administrator: public Ui_Administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
