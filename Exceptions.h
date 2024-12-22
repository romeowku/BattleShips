#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class FieldSizeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Incorrect field's size.";
    }
};

class AbilityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: There are no abilities to use.";
    }
};

class AttackOutException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Incorrect cell for attack.";
    }
};

class ShipPlacementException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Incorrect placment for ship.";
    }
};

class BotFileException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Save/load must be in player turn.";
    }
};

class BotAbilityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Only player can use abilities.";
    }
};

class ChooseDifficultyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Difficulty must be either easy or hard.";
    }
};

class ModifySaveFileException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: File for save/load was modified.";
    }
};

class FileException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: File not found.";
    }
};

#endif