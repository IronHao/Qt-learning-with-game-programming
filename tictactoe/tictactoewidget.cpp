#include "tictactoewidget.h"

#include <QGridLayout>
#include <QSignalMapper>
#include <QDebug>

TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    QSignalMapper *mapper = new QSignalMapper(this);
    m_currentPlayer = Player::Invalid;
    for(int row = 0; row < 3; ++row){
        for(int column = 0; column < 3; ++column){
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

void TicTacToeWidget::initNewGame()
{
    for(QPushButton *button: m_board){
        button->setText(" ");
    }
    setCurrentPlayer(Player::Player1);
}


TicTacToeWidget::Player TicTacToeWidget::checkWinCondition()
{
    Player winner = Player::Draw;
    for(QPushButton *button: m_board){
        if(button->text() == " "){
            winner = Player::Invalid;
            break;
        }
    }
    if((m_board[0]->text() == "X" && m_board[4]->text() == "X" && m_board[8]->text() == "X") ||
            (m_board[2]->text() == "X" && m_board[4]->text() == "X" && m_board[6]->text() == "X") ||
            (m_board[0]->text() == "X" && m_board[1]->text() == "X" && m_board[2]->text() == "X") ||
            (m_board[3]->text() == "X" && m_board[4]->text() == "X" && m_board[5]->text() == "X") ||
            (m_board[6]->text() == "X" && m_board[7]->text() == "X" && m_board[8]->text() == "X") ||
            (m_board[0]->text() == "X" && m_board[3]->text() == "X" && m_board[6]->text() == "X") ||
            (m_board[1]->text() == "X" && m_board[4]->text() == "X" && m_board[7]->text() == "X") ||
            (m_board[2]->text() == "X" && m_board[5]->text() == "X" && m_board[8]->text() == "X") ){
        winner = Player::Player1;
    }
    else if((m_board[0]->text() == "O" && m_board[4]->text() == "O" && m_board[8]->text() == "O") ||
            (m_board[2]->text() == "O" && m_board[4]->text() == "O" && m_board[6]->text() == "O") ||
            (m_board[0]->text() == "O" && m_board[3]->text() == "O" && m_board[6]->text() == "O") ||
            (m_board[1]->text() == "O" && m_board[4]->text() == "O" && m_board[7]->text() == "O") ||
            (m_board[2]->text() == "O" && m_board[5]->text() == "O" && m_board[8]->text() == "O") ||
            (m_board[0]->text() == "O" && m_board[1]->text() == "O" && m_board[2]->text() == "O") ||
            (m_board[3]->text() == "O" && m_board[4]->text() == "O" && m_board[5]->text() == "O") ||
            (m_board[6]->text() == "O" && m_board[7]->text() == "O" && m_board[8]->text() == "O") ){
        winner = Player::Player2;
    }
    return winner;
}


void TicTacToeWidget::handleButtonClick(int index)
{
    if(m_currentPlayer == Player::Invalid){
        return; // game is not started
    }
    if(index < 0 || index >= m_board.size()){
        return; // bounding check
    }
    QPushButton *button = m_board[index];
    if(button->text() != " "){
        return; // invalid move
    }
    button->setText(currentPlayer() == Player::Player1 ? "X" : "O");
    Player winner = checkWinCondition();
    if(winner == Player::Invalid){
        setCurrentPlayer(currentPlayer() == Player::Player1 ?
                         Player::Player2 : Player::Player1);
        return;
    } else{
        qDebug() << "GameOver";
        emit gameOver(winner);
    }
}
