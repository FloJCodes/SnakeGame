#include <iostream>
#include "Game.h"

int main()
{
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