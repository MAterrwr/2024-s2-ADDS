// Referee.cpp
#include "Referee.h"

std::shared_ptr<Player> Referee::refGame(const std::shared_ptr<Player>& player1, const std::shared_ptr<Player>& player2) {
    auto move1 = player1->makeMove();
    auto move2 = player2->makeMove();
    if (move1->beats(move2)) {
        return player1;
    } else if (move2->beats(move1)) {
        return player2;
    } else {
        return nullptr; // It's a tie
    }
}
