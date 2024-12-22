#include "UserInput.h"
#include <unordered_set>
#include <termios.h>
#include <unistd.h>
#include <limits>

UserInput::UserInput(std::string& filename)
{
    if(!loadCommandsFromFile(filename)) { setCommands(); }
}

std::pair<int, int> UserInput::attackCoordinates() 
{
    std::cout << "Enter coordinates for attack cell (x y):\n";
    int x = getInt();
    int y = getInt();
    return {x, y};
}

std::vector<std::pair<std::pair<int, int>, int>> UserInput::setParams(int count) 
{
    int x, y;
    bool pos;
    std::vector<std::pair<std::pair<int, int>, int>> coords;
    coords.resize(count);

    for (int i = 0; i < count; i++) 
    {
        std::cout << "Enter coordinates for set ship (x y): ";
        x = getInt();
        y = getInt();
        
        std::cout << "Enter orientation (0 horizontal or 1 vertical): ";
        pos = getPos();
        coords[i] = {{x, y}, pos};
    }

    return coords;
}

std::string UserInput::saveName()
{
    std::cout << "Enter file name for saving: ";
    std::string name;
    std::cin >> name;
    return name;
}

UserInput::UserCommand UserInput::getCommand() 
{
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    read(STDIN_FILENO, &ch, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    if (!command.empty() && std::islower(command.begin()->first)) 
    {
        ch = std::tolower(ch);
    } else if (!command.empty() && std::isupper(command.begin()->first)) {
        ch = std::toupper(ch);
    }
    
    if (command.find(ch) == command.end()) { return UserCommand::None; }
    
    return command[ch];
}

void UserInput::setCommands()
{
    command_keys["New game"] = '1';
    command_keys["Attack"] = '2';
    command_keys["Use ability"] = '3';
    command_keys["Save"] = '4';
    command_keys["Load"] = '5';
    command_keys["Exit"] = '6';
    command[command_keys["New game"]] = UserCommand::NewGame;
    command[command_keys["Attack"]] = UserCommand::Attack;
    command[command_keys["Use ability"]] = UserCommand::UseAbility;
    command[command_keys["Save"]] = UserCommand::Save;
    command[command_keys["Load"]] = UserCommand::Load;
    command[command_keys["Exit"]] = UserCommand::Exit;
}

bool UserInput::loadCommandsFromFile(std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) { return false; }
    
    nlohmann::json j;
    file >> j;
    if (!isValidCommands(j)) { return false; }

    for (auto& [key, value] : j.items()) 
    {
        char command_char = value.get<std::string>()[0];
        if (key == "Attack") 
        {
            command_keys["Attack"] = command_char;
            command[command_char] = UserCommand::Attack;
        } else if (key == "Use ability") {
            command_keys["Use ability"] = command_char;
            command[command_char] = UserCommand::UseAbility;
        } else if (key == "Save") {
            command_keys["Save"] = command_char;
            command[command_char] = UserCommand::Save;
        } else if (key == "Load") {
            command_keys["Load"] = command_char;
            command[command_char] = UserCommand::Load;
        } else if (key == "Exit") {
            command_keys["Exit"] = command_char;
            command[command_char] = UserCommand::Exit;
        }
        else if(key == "New game"){
            command_keys["New game"] = command_char;
            command[command_char] = UserCommand::NewGame;
        }
    }
    return true;
}

bool UserInput::isValidCommands(nlohmann::json &j) 
{
    std::vector<std::string> required_commands = {"Attack", "Use ability", "Save", "Load", "Exit", "New game"};
    for (const auto& command : required_commands) {
        if (j.find(command) == j.end()) {
            return false;
        }
    }
    std::unordered_set<char> used_keys;
    for (const auto& [command, key_json] : j.items()) {
        std::string key = key_json.get<std::string>();
        if (key.empty()) {
            return false;
        }
        char key_char = key[0];
        if (used_keys.find(key_char) != used_keys.end()) {
            return false;
        }
        used_keys.insert(key_char);
    }
    return true;
}

void UserInput::mainMenu()
{
    std::cout << "New Game\n";
    std::cout << "Start new game - [" << command_keys["New game"] << "]\n";
    std::cout << "Load - [" << command_keys["Load"] << "]\n";
    std::cout << "Exit - [" << command_keys["Exit"] << "]\n";
    std::cout << "Choose the game mode\n";
}

void UserInput::gameMenu()
{
    std::cout << "Your turn\n";
    std::cout << "Attack - [" << command_keys["Attack"] << "]\n";
    std::cout << "Use ability - [" << command_keys["Use ability"] << "]\n";
    std::cout << "Save - [" << command_keys["Save"] << "]\n";
    std::cout << "Load - [" << command_keys["Load"] << "]\n";
    std::cout << "Exit - [" << command_keys["Exit"] << "]\n";
    std::cout << "Choose the command\n";
}

void UserInput::clearInput() 
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int UserInput::getInt() 
{
    int value;
    while (true) 
    {
        std::cin >> value;

        if (!std::cin.fail()) { return value; }

        std::cout << "Error input for correctly number. Numbers must be integers.\n";
        clearInput();
    }
}

int UserInput::getPos() 
{
    int value;
    while (true) 
    {
        std::cin >> value;

        if (!std::cin.fail() && (value == 0 || value == 1)) { return value; }

        std::cout << "Error input for correctly position. Numbers must be 0 or 1.\n";
        clearInput();
    }
}

void UserInput::clear() { system("clear"); }