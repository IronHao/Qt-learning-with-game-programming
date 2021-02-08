/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <gobang.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStartNewGame;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *player1Name;
    Gobang *gameBoard;
    QLabel *player2Name;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(643, 690);
        actionStartNewGame = new QAction(MainWindow);
        actionStartNewGame->setObjectName(QString::fromUtf8("actionStartNewGame"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 611, 611));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        player1Name = new QLabel(verticalLayoutWidget);
        player1Name->setObjectName(QString::fromUtf8("player1Name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(player1Name->sizePolicy().hasHeightForWidth());
        player1Name->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(player1Name);

        gameBoard = new Gobang(verticalLayoutWidget);
        gameBoard->setObjectName(QString::fromUtf8("gameBoard"));

        verticalLayout->addWidget(gameBoard);

        player2Name = new QLabel(verticalLayoutWidget);
        player2Name->setObjectName(QString::fromUtf8("player2Name"));
        sizePolicy.setHeightForWidth(player2Name->sizePolicy().hasHeightForWidth());
        player2Name->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(player2Name);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 643, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(actionStartNewGame);
        toolBar->addAction(actionStartNewGame);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionStartNewGame->setText(QCoreApplication::translate("MainWindow", "StartNewGame", nullptr));
#if QT_CONFIG(tooltip)
        actionStartNewGame->setToolTip(QCoreApplication::translate("MainWindow", "start a new game", nullptr));
#endif // QT_CONFIG(tooltip)
        player1Name->setText(QCoreApplication::translate("MainWindow", "Player 1", nullptr));
        player2Name->setText(QCoreApplication::translate("MainWindow", "Player 2", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
