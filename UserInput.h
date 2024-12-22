#ifndef USERINPUT_H
#define USERINPUT_H

#include "json.hpp"
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class UserInput
{
public:
    enum class UserCommand { 
    NewGame,
    Attack,
    UseAbility,
    Save,
    Load,
    Exit,
    None };

private:
    std::unordered_map<char, UserCommand> command;
    std::unordered_map<std::string, char> command_keys;
    void setCommands();
    bool loadCommandsFromFile(std::string& filename);
    bool isValidCommands(nlohmann::json &j);
public:

    UserInput(std::string& filename);

    UserCommand getCommand();
    void mainMenu();
    void gameMenu();

    std::pair<int, int> attackCoordinates();
    std::vector<std::pair<std::pair<int, int>, int>> setParams(int count); 

    int getPos();
    int getInt();  
    std::string saveName();
    void clearInput();
    void clear(); 
};

#endif