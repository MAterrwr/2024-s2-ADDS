// main.cpp
#include "Referee.h"
#include "Human.h"
#include "Computer.h"
#include <iostream>

int main() {
    Referee referee;
    Human player1;
    Computer player2;

    Player* winner = referee.refGame(&player1, &player2);
    if (winner) {
        std::cout << "Winner: " << winner->getName() << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}
