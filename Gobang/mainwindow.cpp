#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionStartNewGame, &QAction::triggered,
            this, &MainWindow::startNewGame);
    connect(ui->gameBoard, &Gobang::gameOver,
            this, &MainWindow::handleGameOver);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame(){
    ui->player1Name->setText("Yang");
    ui->player2Name->setText("Wang");
    ui->gameBoard->initNewGame();
}

void MainWindow::handleGameOver(Gobang::Player winner)
{
    QString message;
    if(winner == Gobang::Player::Draw){
        message = tr("Game ended with a draw.");
    }else{
        QString winnerName = winner == Gobang::Player::Player1 ?
                    ui->player1Name->text() : ui->player2Name->text();
        message = tr("%1 wins").arg(winnerName);
    }
    QMessageBox::information(this, tr("Info"), message);
}
