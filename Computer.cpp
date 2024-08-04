// Computer.cpp
#include "Computer.h"
#include <cstdlib>
#include <ctime>

std::shared_ptr<Move> Computer::makeMove() const {
    srand(time(0));
    int choice = rand() % 5; // Assuming 5 possible moves
    switch (choice) {
        case 0: return std::make_shared<Rock>();
        case 1: return std::make_shared<Paper>();
        // Handle other cases similarly...
    }
    return nullptr; // Default fallback
}
