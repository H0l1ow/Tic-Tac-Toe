#include <iostream>
#include <cstdlib>
#include "../headers/Game.hpp"

Game::Game()
    : m_gridSize(3), board(m_gridSize, std::vector<char>(m_gridSize, ' ')), 
      player1('X', "Player X"), player2('O', "Player O"), currentPlayer(&player1) {}

void Game::playerSettings() {
    std::string name;
    char symbol;

    std::cout << "Set Player 1 name: ";
    std::cin >> name;
    player1.setName(name);
    std::cout << "Set Player 1 symbol: ";
    std::cin >> symbol;
    player1.setSymbol(symbol);

    clearScreen();

    std::cout << "Set Player 2 name: ";
    std::cin >> name;
    player2.setName(name);
    std::cout << "Set Player 2 symbol: ";
    std::cin >> symbol;
    player2.setSymbol(symbol);

    clearScreen();
}

void Game::menu() {
    std::cout << "\tWelcome to Tic-Tac-Toe Game\n";
    std::cout << "\t\tCool text\n\n\n";

    playerSettings();    
}

void Game::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Game::grid() {
    for (int i = 0; i < m_gridSize; ++i) {
        for (int j = 0; j < m_gridSize; ++j) {
            std::cout << " " << board.at(i).at(j) << " ";
            if (j < m_gridSize - 1) 
                std::cout << "|";
        }
        std::cout << std::endl;
        if (i < m_gridSize - 1) 
            std::cout << "---|---|---" << std::endl;
    }
}

bool Game::checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < m_gridSize; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool Game::checkDraw() {
    for (int i = 0; i < m_gridSize; ++i) {
        for (int j = 0; j < m_gridSize; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void Game::makeMove() {
    int move;
    bool validMove = false;
    while (!validMove) {
        std::cout << currentPlayer->getName() << " (" << currentPlayer->getSymbol() << "), enter your move (1-9): ";
        std::cin >> move;
        if (move >= 1 && move <= 9) {
            int row = (3 - (move - 1) / 3) - 1;
            int col = (move - 1) % 3;
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer->getSymbol();
                validMove = true;
            } else {
                std::cout << "\nCell already taken, try again." << std::endl;
            }
        } else {
            std::cout << "\nInvalid move, try again." << std::endl;
        }
    }
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

void Game::run() {
    menu();
    bool gameWon = false;
    bool draw = false;

    while (!gameWon && !draw) {
        clearScreen();
        grid();
        makeMove();
        gameWon = checkWin(currentPlayer->getSymbol());
        if (gameWon) {
            grid();
            std::cout << currentPlayer->getName() << " wins!" << std::endl;
        } else {
            draw = checkDraw();
            if (draw) {
                grid();
                std::cout << "It's a draw!" << std::endl;
            } else {
                switchPlayer();
            }
        }
    }
}
