// Human.h
#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <iostream>

class Human : public Player {
public:
    std::string getName() const override {
        return name;
    }

    Move* makeMove() override {
        std::string moveName;
        std::cout << "Enter Move: ";
        std::cin >> moveName;
        // Instantiate the appropriate Move object based on user input
        // This should be improved with a factory pattern or similar
        if (moveName == "Rock") {
            return new Rock();
        }
        // Add other moves here
        return nullptr; // Invalid move
    }

private:
    std::string name;
};

#endif // HUMAN_H
