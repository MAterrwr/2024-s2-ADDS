// Player.h
#pragma once
#include "Move.h"
#include <string>
#include <memory>

class Player {
public:
    virtual std::shared_ptr<Move> makeMove() const = 0;
    virtual std::string getName() const = 0;
    virtual ~Player() = default;
};

class Human : public Player {
    std::string name;
public:
    Human(const std::string& name) : name(name) {}
    std::shared_ptr<Move> makeMove() const override;
    std::string getName() const override { return name; }
};

class Computer : public Player {
    std::string name;
public:
    Computer(const std::string& name) : name(name) {}
    std::shared_ptr<Move> makeMove() const override;
    std::string getName() const override { return name; }
};
