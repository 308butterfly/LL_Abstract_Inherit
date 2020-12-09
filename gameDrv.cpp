/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/27/2019
** Description:     Project 4 CS162 Spring 2019, Fantasy Tournament Fighter where 
**                  the winner can recover between matches.  
** Dependencies:    game.hpp               
** File name:       gameDrv.cpp
*********************************************************************************/

#include"game.hpp"

/*********************************************************************************
To run main put barbarian.hpp, barbarian.cpp, blueMen.hpp, blueMen.cpp, 
character.hpp, character.cpp, fighter.hpp, fighter.cpp, game.hpp, game.cpp, 
gameDrv.cpp, harryPotter.hpp, harryPotter.cpp, lineUp.hpp, LineUp.cpp, losers.hpp,
losers.cpp, medusa.hpp, medusa.cpp, validate.hpp, validate.cpp, vampire.hpp, 
vampire.cpp in the same directory and use Makefile.  Run with ./proj4 
*********************************************************************************/

int main()
{
    srand(time(0));

    Game game1;
    game1.gameMenu();
    return 0;
}