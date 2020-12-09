/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/16/2019
** Description:     The methods necessary for a fantasy battle tournament
** Dependencies:    barbarian.hpp, blueMen.hpp, harryPotter.hpp, medusa.hpp,
**                  vampire.hpp, fighters.hpp        
** File name:       game.hpp
*********************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "lineUp.hpp"
#include "losers.hpp"

class Game
{
    private:

        int team1Size = 0;
        int team2Size = 0;
        int battleNum = 0;
        int team1Score = 0;
        int team2Score = 0;

        bool isTeam2 = false;
        bool isPlayAgain = false;

        LineUp* team1;
        LineUp* team2;
        Losers* losers;
        
    public:
        Game(); 
        ~Game(); 

        void gameMenu();
        void battle();
        bool showLosersMenu();
};

#endif
