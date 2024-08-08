// Computer.h
#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <cstdlib>
#include <ctime>

class Computer : public Player {
public:
    Computer() {
        std::srand(std::time(0));
    }

    std::string getName() const override {
        return "Computer";
    }

    Move* makeMove() override {
        int randomMove = std::rand() % 8;
        // Return a random move
        switch (randomMove) {
            case 0: return new Rock();
            // Add other cases here
            default: return nullptr; // Should never reach here
        }
    }
};

#endif // COMPUTER_H
