#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h"
#include <string>

class Player {
public:
    virtual Move* makeMove() = 0;
    virtual std::string getName() const = 0;
    virtual ~Player() {}
};

#endif // PLAYER_H