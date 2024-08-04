// Human.cpp
#include "Human.h"
#include <iostream>

std::shared_ptr<Move> Human::makeMove() const {
    std::string move;
    std::cout << "Enter Move: ";
    std::cin >> move;
    if (move == "Rock") return std::make_shared<Rock>();
    if (move == "Paper") return std::make_shared<Paper>();
    // Add other moves similarly...
    return nullptr; // Handle invalid move
}
