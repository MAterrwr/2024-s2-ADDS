#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
public:
    virtual std::string getName() const = 0;
    virtual ~Move() {}
};

class Rock : public Move {
public:
    std::string getName() const override { return "Rock"; }
};

class Paper : public Move {
public:
    std::string getName() const override { return "Paper"; }
};

class Scissors : public Move {
public:
    std::string getName() const override { return "Scissors"; }
};

class Lizard : public Move {
public:
    std::string getName() const override { return "Lizard"; }
};

class Spock : public Move {
public:
    std::string getName() const override { return "Spock"; }
};

#endif // MOVE_H