// main.cpp
#include "Referee.h"
#include "Human.h"
#include "Computer.h"
#include <iostream>

int main() {
    auto player1 = std::make_shared<Human>("Player 1");
    auto player2 = std::make_shared<Computer>("Computer");

    Referee referee;
    auto winner = referee.refGame(player1, player2);
    if (winner) {
        std::cout << "Winner: " << winner->getName() << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }
    return 0;
}
