/********************************************************************************
** Form generated from reading UI file 'TeacherWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWINDOW_H
#define UI_TEACHERWINDOW_H

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

class Ui_TeacherWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QListWidget *allStudents;
    QListWidget *studentsList;
    QLineEdit *lineEdit;
    QPushButton *Add;

    void setupUi(QWidget *TeacherWindow)
    {
        if (TeacherWindow->objectName().isEmpty())
            TeacherWindow->setObjectName(QStringLiteral("TeacherWindow"));
        TeacherWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(TeacherWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(TeacherWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(TeacherWindow);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        allStudents = new QListWidget(TeacherWindow);
        allStudents->setObjectName(QStringLiteral("allStudents"));

        horizontalLayout->addWidget(allStudents);

        studentsList = new QListWidget(TeacherWindow);
        studentsList->setObjectName(QStringLiteral("studentsList"));

        horizontalLayout->addWidget(studentsList);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit = new QLineEdit(TeacherWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        Add = new QPushButton(TeacherWindow);
        Add->setObjectName(QStringLiteral("Add"));

        verticalLayout->addWidget(Add);


        retranslateUi(TeacherWindow);

        QMetaObject::connectSlotsByName(TeacherWindow);
    } // setupUi

    void retranslateUi(QWidget *TeacherWindow)
    {
        TeacherWindow->setWindowTitle(QApplication::translate("TeacherWindow", "TeacherWindow", 0));
        label_2->setText(QApplication::translate("TeacherWindow", "Matching Students", 0));
        label->setText(QApplication::translate("TeacherWindow", "Coordinated Students", 0));
        Add->setText(QApplication::translate("TeacherWindow", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class TeacherWindow: public Ui_TeacherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
