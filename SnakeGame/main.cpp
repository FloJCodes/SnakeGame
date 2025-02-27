#include <iostream>
#include "Game.h"

int main()
{
    std::srand(static_cast<unsigned>(time(NULL)));

    //Init Game engine
    Game game;

    while (game.running() && !game.getEndGame())
    {
        //Update
        game.update();

        //Render
        game.render();
    }

    return 0;
}