// Referee.h
#ifndef REFEREE_H
#define REFEREE_H

#include "Player.h"

class Referee {
public:
    Player* refGame(Player* player1, Player* player2) {
        Move* move1 = player1->makeMove();
        Move* move2 = player2->makeMove();

        if (move1->defeats(move2)) {
            return player1;
        } else if (move2->defeats(move1)) {
            return player2;
        } else {
            return nullptr; // Tie
        }
    }
};

#endif // REFEREE_H
