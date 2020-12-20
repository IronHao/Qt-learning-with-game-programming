#include "gobang.h"
#include <QGridLayout>
#include <QSignalMapper>
#include <QDebug>

Gobang::Gobang(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    QSignalMapper *mapper = new QSignalMapper(this);
    m_currentPlayer = Player::Invalid;
    for(int row = 0; row < 15; ++row){
        for(int column = 0; column < 15; ++column){
            QPushButton *button = new QPushButton(" ");
            button->setSizePolicy(QSizePolicy::Preferred,
                                  QSizePolicy::Preferred);
            gridLayout->addWidget(button, row, column);
            m_board.append(button);
            mapper->setMapping(button, m_board.count() - 1);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
        }
    }
    connect(mapper, SIGNAL(mappedInt(int)),
            this,   SLOT(handleButtonClick(int)));
}

Gobang::Player Gobang::currentPlayer()
{
    return m_currentPlayer;
}

void Gobang::setCurrentPlayer(Gobang::Player currentPlayer)
{
    m_currentPlayer = currentPlayer;
}

void Gobang::initNewGame()
{
    for(QPushButton *button: m_board){
        button->setText(" ");
    }
    //qDebug() << "new";
    setCurrentPlayer(Player::Player1);
}

Gobang::Player Gobang::checkWinCondition(int index){
    Player tempH = checkHorizontalCondition(index);
    Player tempV = checkVerticalCondition(index);
    Player tempD = checkDiagonalCondition(index);
    if(tempH != Player::Invalid){
        return tempH;
    }
    if(tempV != Player::Invalid){
        return tempV;
    }
    if(tempD != Player::Invalid){
        return tempD;
    }
    return Player::Invalid;

}

Gobang::Player Gobang::checkHorizontalCondition(int index)
{
    Player winner = Player::Invalid;
    int tempX = 0;
    int tempY = 0;
    int deflectionSmallH = (index % 15) < 5 ? (index % 15 - 4) : 0;
    int deflectionBigH = (index % 15) > 10 ? (index % 15 - 10) : 0;
    for(int i = index - 4 - deflectionSmallH; i <= index + 4 - deflectionBigH; i++){
        if(m_board[i]->text() == "X"){
            tempX += 1;
            tempY = 0;
        }
        else if (m_board[i]->text() == "O"){
            tempY += 1;
            tempX = 0;
        }
        else{
            tempX = 0;
            tempY = 0;
        }
        if(tempX >= 5){
            qDebug() << tempX;
            winner = Player::Player1;
        }
        else if(tempY >= 5){
            winner = Player::Player2;
        }
    }
    return winner;
}

Gobang::Player Gobang::checkVerticalCondition(int index)
{
    Player winner = Player::Invalid;
    int tempX = 0;
    int tempY = 0;
    int deflectionSmallV = (index / 15) < 5 ? (index / 15 - 4) : 0;
    int deflectionBigV = (index / 15) > 10 ? (index / 15 - 10) : 0;
    for(int i = index - (4+deflectionSmallV) * 15; i <= index + (4-deflectionBigV) * 15; i = i + 15){
        if(m_board[i]->text() == "X"){
            tempX += 1;
            tempY = 0;
        }
        else if (m_board[i]->text() == "O"){
            tempY += 1;
            tempX = 0;
        }
        else{
            tempX = 0;
            tempY = 0;
        }
        if(tempX >= 5){
            qDebug() << tempX;
            winner = Player::Player1;
        }
        else if(tempY >= 5){
            winner = Player::Player2;
        }
    }
    return winner;
}

Gobang::Player Gobang::checkDiagonalCondition(int index)
{
    Player winner = Player::Invalid;
    int tempX = 0;
    int tempY = 0;
    int deflectionSmallH = (index % 15) < 5 ? (index % 15 - 4) : 0;
    int deflectionBigH = (index % 15) > 10 ? (index % 15 - 10) : 0;
    int deflectionSmallV = (index / 15) < 5 ? (index / 15 - 4) : 0;
    int deflectionBigV = (index / 15) > 10 ? (index / 15 - 10) : 0;
    for(int i = index - (4+deflectionSmallV) * 15 - 4 - deflectionSmallH; i <= index + (4-deflectionBigV) * 15 + 4 - deflectionBigH; i = i + 16){
        if(m_board[i]->text() == "X"){
            tempX += 1;
            tempY = 0;
        }
        else if (m_board[i]->text() == "O"){
            tempY += 1;
            tempX = 0;
        }
        else{
            tempX = 0;
            tempY = 0;
        }
        if(tempX >= 5){
            qDebug() << tempX;
            winner = Player::Player1;
        }
        else if(tempY >= 5){
            winner = Player::Player2;
        }
    }
    return winner;
}

void Gobang::handleButtonClick(int index)
{
    //qDebug() << "Clicked";
    if (m_currentPlayer == Player::Invalid) {
        return;
    }
    if (index < 0 || index >= m_board.size()) {
        return;
    }
    QPushButton *button = m_board[index];
    if(button->text() != " "){
        return;
    }
    button->setText(currentPlayer() == Player::Player1 ? "X" : "O");
    Player winner = checkWinCondition(index);
    if(winner == Player::Invalid){
        setCurrentPlayer(currentPlayer() == Player::Player1 ?
                             Player::Player2 : Player::Player1);
        return;
    }else{
     emit gameOver(winner);
    }
}

