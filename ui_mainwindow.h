/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "fieldview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    FieldView *fieldViewWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *newGameButton;
    QPushButton *exitButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *levelLabel;
    QLabel *label;
    QLCDNumber *timeRemainsLCDNumber;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1373, 1107);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fieldViewWidget = new FieldView(centralWidget);
        fieldViewWidget->setObjectName(QString::fromUtf8("fieldViewWidget"));
        fieldViewWidget->setMinimumSize(QSize(1000, 1000));
        fieldViewWidget->setMaximumSize(QSize(1000, 1000));

        horizontalLayout->addWidget(fieldViewWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        newGameButton = new QPushButton(centralWidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newGameButton->sizePolicy().hasHeightForWidth());
        newGameButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(newGameButton);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        sizePolicy.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(exitButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        levelLabel = new QLabel(centralWidget);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(levelLabel->sizePolicy().hasHeightForWidth());
        levelLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(72);
        font.setBold(true);
        levelLabel->setFont(font);
        levelLabel->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        verticalLayout->addWidget(levelLabel);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        timeRemainsLCDNumber = new QLCDNumber(centralWidget);
        timeRemainsLCDNumber->setObjectName(QString::fromUtf8("timeRemainsLCDNumber"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(timeRemainsLCDNumber->sizePolicy().hasHeightForWidth());
        timeRemainsLCDNumber->setSizePolicy(sizePolicy2);
        timeRemainsLCDNumber->setFont(font);

        verticalLayout->addWidget(timeRemainsLCDNumber);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1373, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(fieldViewWidget, SIGNAL(gameOverSignal()), MainWindow, SLOT(gameOverSlot()));
        QObject::connect(fieldViewWidget, SIGNAL(oopsSignal()), MainWindow, SLOT(oopsSlot()));
        QObject::connect(fieldViewWidget, SIGNAL(gameOnSignal(int)), MainWindow, SLOT(gameOnSlot(int)));
        QObject::connect(MainWindow, SIGNAL(updateLCD(int)), timeRemainsLCDNumber, SLOT(display(int)));
        QObject::connect(fieldViewWidget, SIGNAL(timerStopSignal()), MainWindow, SLOT(timerStopSlot()));
        QObject::connect(fieldViewWidget, SIGNAL(updateLCDSignal()), MainWindow, SLOT(updateLCDSlot()));
        QObject::connect(fieldViewWidget, SIGNAL(setLevelSignal(int)), levelLabel, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newGameButton->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        levelLabel->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Time remains", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
