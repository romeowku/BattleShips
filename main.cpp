#include "Game.h"
#include "GameStates/GameState.h"
#include "GameStates/GamePlayerState.h"
#include "UserInput.h"
#include "ConsoleRenderer.h"
#include "GameDisplay.h"
#include "GameController.h"
int main() 
{
    srand (time(NULL));

    Game* game = new Game();
    GameState* state = new GamePlayerState(*game);
   
    std::string commands_filename = "commands.json";
    UserInput input = UserInput(commands_filename);
    ConsoleRenderer renderer = ConsoleRenderer();
    GameDisplay display = GameDisplay(renderer);
    
    GameController controller = GameController(*game, input, display);
    controller.start(state);
    
    delete state;
    delete game;

    return 0;
}