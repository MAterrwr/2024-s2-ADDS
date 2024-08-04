#include "Human.h"
#include "Move.h"
#include <iostream>

Human::Human(const std::string& name) : name(name) {}

Move* Human::makeMove() {
    std::string moveName;
    std::cout << "Enter Move: ";
    std::cin >> moveName;

    if (moveName == "Rock") return new Rock();
    if (moveName == "Paper") return new Paper();
    if (moveName == "Scissors") return new Scissors();
    if (moveName == "Lizard") return new Lizard();
    if (moveName == "Spock") return new Spock();

    return nullptr; // Handle invalid move
}

std::string Human::getName() const {
    return name;
}