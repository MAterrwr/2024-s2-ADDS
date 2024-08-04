// Referee.h
#pragma once
#include "Player.h"

class Referee {
public:
    std::shared_ptr<Player> refGame(const std::shared_ptr<Player>& player1, const std::shared_ptr<Player>& player2);
};
