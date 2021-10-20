/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionA_propos;
    QAction *actionQuitter;
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nomLabel;
    QLineEdit *nomLineEdit;
    QLabel *prNomLabel;
    QLineEdit *prNomLineEdit;
    QLabel *dateDeNaissanceLabel;
    QLineEdit *dateDeNaissanceLineEdit;
    QLabel *villeLabel;
    QLineEdit *villeLineEdit;
    QPushButton *pushButton;
    QTextEdit *resultText;
    QLabel *timerLabel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFichier;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(586, 684);
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 601, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nomLabel = new QLabel(formLayoutWidget);
        nomLabel->setObjectName(QStringLiteral("nomLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nomLabel);

        nomLineEdit = new QLineEdit(formLayoutWidget);
        nomLineEdit->setObjectName(QStringLiteral("nomLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nomLineEdit);

        prNomLabel = new QLabel(formLayoutWidget);
        prNomLabel->setObjectName(QStringLiteral("prNomLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, prNomLabel);

        prNomLineEdit = new QLineEdit(formLayoutWidget);
        prNomLineEdit->setObjectName(QStringLiteral("prNomLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, prNomLineEdit);

        dateDeNaissanceLabel = new QLabel(formLayoutWidget);
        dateDeNaissanceLabel->setObjectName(QStringLiteral("dateDeNaissanceLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, dateDeNaissanceLabel);

        dateDeNaissanceLineEdit = new QLineEdit(formLayoutWidget);
        dateDeNaissanceLineEdit->setObjectName(QStringLiteral("dateDeNaissanceLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dateDeNaissanceLineEdit);

        villeLabel = new QLabel(formLayoutWidget);
        villeLabel->setObjectName(QStringLiteral("villeLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, villeLabel);

        villeLineEdit = new QLineEdit(formLayoutWidget);
        villeLineEdit->setObjectName(QStringLiteral("villeLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, villeLineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 150, 88, 27));
        resultText = new QTextEdit(centralWidget);
        resultText->setObjectName(QStringLiteral("resultText"));
        resultText->setGeometry(QRect(13, 229, 551, 431));
        timerLabel = new QLabel(centralWidget);
        timerLabel->setObjectName(QStringLiteral("timerLabel"));
        timerLabel->setGeometry(QRect(160, 190, 67, 19));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 586, 24));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ma premi\303\250re UI", nullptr));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", nullptr));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", nullptr));
        nomLabel->setText(QApplication::translate("MainWindow", "nom", nullptr));
        prNomLabel->setText(QApplication::translate("MainWindow", "pr\303\251nom", nullptr));
        dateDeNaissanceLabel->setText(QApplication::translate("MainWindow", "date de naissance", nullptr));
        villeLabel->setText(QApplication::translate("MainWindow", "ville", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "VALIDE BRO", nullptr));
        timerLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fic&hier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
