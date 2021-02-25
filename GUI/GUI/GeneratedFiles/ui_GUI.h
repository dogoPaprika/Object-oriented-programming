/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *repoList;
    QFormLayout *formLayout;
    QLabel *descriptionLabel;
    QLineEdit *descriptionLineEdit;
    QPushButton *computeButton;
    QLabel *calculateLabel;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listPrecipitation;
    QFormLayout *formLayout_3;
    QLabel *precipitationLabel;
    QLineEdit *precipitationLineEdit;
    QPushButton *filterButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->resize(706, 584);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        repoList = new QListWidget(centralWidget);
        repoList->setObjectName(QStringLiteral("repoList"));

        verticalLayout->addWidget(repoList);


        horizontalLayout->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        descriptionLabel = new QLabel(centralWidget);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, descriptionLabel);

        descriptionLineEdit = new QLineEdit(centralWidget);
        descriptionLineEdit->setObjectName(QStringLiteral("descriptionLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, descriptionLineEdit);

        computeButton = new QPushButton(centralWidget);
        computeButton->setObjectName(QStringLiteral("computeButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, computeButton);

        calculateLabel = new QLabel(centralWidget);
        calculateLabel->setObjectName(QStringLiteral("calculateLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, calculateLabel);


        horizontalLayout->addLayout(formLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listPrecipitation = new QListWidget(centralWidget);
        listPrecipitation->setObjectName(QStringLiteral("listPrecipitation"));

        verticalLayout_2->addWidget(listPrecipitation);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        precipitationLabel = new QLabel(centralWidget);
        precipitationLabel->setObjectName(QStringLiteral("precipitationLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, precipitationLabel);

        precipitationLineEdit = new QLineEdit(centralWidget);
        precipitationLineEdit->setObjectName(QStringLiteral("precipitationLineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, precipitationLineEdit);


        verticalLayout_2->addLayout(formLayout_3);

        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        verticalLayout_2->addWidget(filterButton);


        horizontalLayout->addLayout(verticalLayout_2);

        GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 706, 26));
        GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUIClass->setStatusBar(statusBar);

        retranslateUi(GUIClass);
        QObject::connect(filterButton, SIGNAL(clicked()), GUIClass, SLOT(filterCommand()));
        QObject::connect(computeButton, SIGNAL(clicked()), GUIClass, SLOT(hoursCommand()));

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", 0));
        descriptionLabel->setText(QApplication::translate("GUIClass", "Description", 0));
        computeButton->setText(QApplication::translate("GUIClass", "Compute Total", 0));
        calculateLabel->setText(QString());
        precipitationLabel->setText(QApplication::translate("GUIClass", "Precipitation", 0));
        filterButton->setText(QApplication::translate("GUIClass", "Filter", 0));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
