#include "Referee.h"

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    if (move1->getName() == move2->getName()) {
        return nullptr; // It's a tie
    }

    if ((move1->getName() == "Rock" && (move2->getName() == "Scissors" || move2->getName() == "Lizard")) ||
        (move1->getName() == "Paper" && (move2->getName() == "Rock" || move2->getName() == "Spock")) ||
        (move1->getName() == "Scissors" && (move2->getName() == "Paper" || move2->getName() == "Lizard")) ||
        (move1->getName() == "Lizard" && (move2->getName() == "Spock" || move2->getName() == "Paper")) ||
        (move1->getName() == "Spock" && (move2->getName() == "Scissors" || move2->getName() == "Rock"))) {
        return player1;
    } else {
        return player2;
    }
}