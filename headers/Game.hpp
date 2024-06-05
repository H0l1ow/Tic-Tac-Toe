#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "../headers/Player.hpp"

class Game {
public:
    Game();

    void run();

private:
    void grid();
    void menu();
    void playerSettings();
    bool checkWin(char player);
    bool checkDraw();
    void makeMove();
    void switchPlayer();
    void clearScreen();

    int m_gridSize;
    std::vector<std::vector<char>> board;
    Player player1;
    Player player2;
    Player* currentPlayer;
};

#endif
