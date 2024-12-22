#include "GamePlayerState.h"

GamePlayerState::GamePlayerState(Game& game) : game(game)
{}

bool GamePlayerState::attack(int x, int y) 
{
    if (game.getEnemyField().attackCell(x, y, &game.getLogHolder())) 
    {
        game.getAbilityManager().addRandomAbility();
    }

    if (!game.getEnemyShipManager().hasAliveShips()) 
    {
        game.changeState();
        endRound();
        return true;
    }
    game.changeState();
    return false;
}

bool GamePlayerState::useAbility() 
{ 
    try 
    { 
        game.getAbilityManager().useAbility(); 
    } catch (AbilityException& e) { 
        std::cerr << e.what() << '\n';
        return false; 
    }
    game.changeState();
    return true; 

}

GameState* GamePlayerState::newStateMove() { return new GameEnemyState(game); }

void GamePlayerState::endRound() 
{
    std::cout << "You win!\n";
    game.getEnemyShipManager().reset();
    game.getEnemyField().updateField();
}