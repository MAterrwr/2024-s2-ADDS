#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include "Move.h"
#include <string>

class Computer : public Player {
    std::string name;
public:
    Computer(const std::string& name);
    Move* makeMove() override;
    std::string getName() const override;
};

#endif // COMPUTER_H