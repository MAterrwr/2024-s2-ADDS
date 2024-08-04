#include "Computer.h"
#include "Move.h"
#include <cstdlib>
#include <ctime>

Computer::Computer(const std::string& name) : name(name) {
    std::srand(std::time(0)); // Seed for random number generation
}

Move* Computer::makeMove() {
    int randomMove = std::rand() % 5;

    switch (randomMove) {
        case 0: return new Rock();
        case 1: return new Paper();
        case 2: return new Scissors();
        case 3: return new Lizard();
        case 4: return new Spock();
        default: return nullptr;
    }
}

std::string Computer::getName() const {
    return name;
}