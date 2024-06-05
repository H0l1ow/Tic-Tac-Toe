#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
public:
    Player();
    Player(char symbol, const std::string& name);

    char getSymbol() const;
    std::string getName() const;
    void setSymbol(char symbol);
    void setName(const std::string& name);

private:
    char symbol;
    std::string name;
};

#endif
