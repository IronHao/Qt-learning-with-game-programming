#ifndef GOBANG_H
#define GOBANG_H

#include <QWidget>
#include <QPushButton>

class Gobang : public QWidget
{
    Q_OBJECT
public:
    explicit Gobang(QWidget *parent = nullptr);
    enum class Player{
        Invalid, Player1, Player2, Draw
    };
    Player currentPlayer();
    void setCurrentPlayer(Player currentPlayer);
    void initNewGame();

    Player checkWinCondition(int index);
    Player checkHorizontalCondition(int index);
    Player checkVerticalCondition(int index);
    Player checkDiagonalCondition(int index);

private:
    QVector<QPushButton*> m_board;
    Player m_currentPlayer;

private slots:
    void handleButtonClick(int index);

signals:
    void gameOver(Player);
};

#endif // GOBANG_H
