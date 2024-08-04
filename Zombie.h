#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Move.h"

class Zombie : public Move {
public:
    Zombie();
    std::string getName() const  {
        return "Zombie";
    }
};

#endif // ZOMBIE_H