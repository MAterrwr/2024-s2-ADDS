#include "Referee.h"
#include "Human.h"
#include "Computer.h"
#include <iostream>

int main() {
    Referee referee;
    Human human("Alice");
    Computer computer("Bot");

    Player* winner = referee.refGame(&human, &computer);
    if (winner) {
        std::cout << "Winner: " << winner->getName() << std::endl;
    } else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}