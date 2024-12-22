#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "Game.h"
#include "UserInput.h"
#include "Exceptions.h"

template <typename Input, typename Display>
class GameController 
{
private:
    Game& game;
    Input& input;
    Display& display;

public:
    GameController(Game& game, Input& input, Display& display) 
        : game(game), input(input), display(display)
    {}

    void start(GameState* state) 
    { 
        game.setState(state);
        input.clear();
        input.mainMenu();

        switch (input.getCommand())
        {
            case (UserInput::UserCommand::NewGame):
            {
                game.setNewGame(true);
                game.setNewRound(false);
                return loop();
            }
            case (UserInput::UserCommand::Load):
            {
                game.setNewGame(false);
                game.setNewRound(false);
                
                auto name = input.saveName();
                if(game.loadGame(name)) { return loop(); }
                return start(game.getState());
            }
            case (UserInput::UserCommand::Exit): { std::exit(EXIT_SUCCESS); }
            
            default: { return start(game.getState()); }
        }
    }

    void loop() 
    {
        bool flag = true;
        while (flag)
        {
            if (game.isNewGame()) 
            {
                display.displayShips(game.getPlayerShipManager());
                auto params = input.setParams(game.getPlayerShipManager().getNumShips());
                game.placeShips(params);
                game.placeEnemyShipsRandom();
                game.setNewGame(false);
            } else if (game.isNewRound()) { 
                game.placeEnemyShipsRandom();
                game.setNewRound(false);
            }
            
            while (flag) 
            {
                input.clear();
                display.displayMessage("~~~~~~~~~~~~~~~~~~~~~ Round " + std::to_string(game.getCurrentRound()) + " ~~~~~~~~~~~~~~~~~~~~~");
                display.displayMessage("Your ability: ");
                game.getLogHolder().printLastAbility();
                display.displayMessage("--------------------My Field--------------------");
                display.displayField(game.getPlayerField(), true);

                display.displayMessage("--------------------Enemy Field--------------------");
                display.displayField(game.getEnemyField(), true);

                display.displayMessage("---------------------------------------------------");
                
                if (move()) { enemyMove(); }

                if (game.isPlayerLose() || game.isEnemyLose()) { flag = false; }
            }
            
            if (game.isEnemyLose()) 
            { 
                game.setNewRound(true); 
                game.setCurrentRound(game.getCurrentRound() + 1);
                game.setEnemyLose(false);
                return loop();
            } else { 
                game.setNewGame(true); 
                game.setPlayerLose(false);
                return start(game.getState());
            }
        }
    }

    bool move() 
    {
        input.gameMenu();
        switch (input.getCommand()) 
        {
            case (UserInput::UserCommand::Attack):
            {
                auto [x, y] = input.attackCoordinates();
                
                try 
                { 
                    if(game.getState()->attack(x, y)) { game.setEnemyLose(true); } 
                } catch (AttackOutException& e) { 
                    std::cerr << e.what() << '\n'; 
                    return false;
                }
                return true;
            }
            case (UserInput::UserCommand::UseAbility):
            {
                if(!game.getState()->useAbility()) { return false; }
                return true;
            }
            case (UserInput::UserCommand::Save):
            { 
                display.displayMessage("Saving game...");
                auto name = input.saveName();
                game.saveGame(name);
                return false;
            }
            case (UserInput::UserCommand::Load):
            {
                display.displayMessage("Loading game...");
                auto name = input.saveName();
                game.loadGame(name);
                display.displayMessage("Round " + std::to_string(game.getCurrentRound()) + " - Starting");
                return false;
            }
            case (UserInput::UserCommand::Exit): { std::exit(EXIT_SUCCESS); }
            default: { return false; }
        }
    }

    void enemyMove()
    {
        try {
            if (game.getState()->attack(0, 0)) { game.setPlayerLose(true); }
        } catch (AttackOutException& e) {
            std::cerr << e.what() << '\n';
        }
    }
};
#endif