// Move.h
#pragma once
#include <string>
#include <memory>

class Move {
public:
    virtual std::string getName() const = 0;
    virtual bool beats(const std::shared_ptr<Move>& other) const = 0;
    virtual ~Move() = default;
};

// Specific move classes inheriting from Move
class Rock : public Move {
public:
    std::string getName() const override { return "Rock"; }
    bool beats(const std::shared_ptr<Move>& other) const override {
        return other->getName() == "Scissors" || other->getName() == "Zombie";
    }
};

class Paper : public Move {
public:
    std::string getName() const override { return "Paper"; }
    bool beats(const std::shared_ptr<Move>& other) const override {
        return other->getName() == "Rock" || other->getName() == "Robot";
    }
};

// Implement other moves similarly...
