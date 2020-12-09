#include <iostream>

#include "lineUp.hpp"
#include "losers.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    LineUp* team1 = new LineUp();
    Losers* losing = new Losers();

    string setSizeTeam1 = "How many members on team 1\n";

    int team1Size = getInteger(setSizeTeam1);

    for(int i = 0; i < team1Size; i++)
    {
        team1->addFighter();
    }

    team1->printForwards();

    for(int i = 0; i < team1Size; i++)
    {
        losing->push(team1->getChar());
        team1->addFighter(team1->getChar());
        team1->deleteFighter();
    }

    team1->printForwards();

    losing->printTopToBot();

    //losing->clean();

    team1->wipe();

    team1->printForwards();

    losing->clean();

    delete team1;

    return 0;
}