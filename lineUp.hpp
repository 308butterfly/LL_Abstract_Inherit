#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "fighter.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"


class LineUp
{
    protected:
        Fighter* head;
        Fighter* tail;
        Fighter* current;

    public:
        LineUp(/* args */);
        ~LineUp();

        //getCharacter
        Character* getChar();
        
        //getFirstFighter
        Fighter* getFighter();

        void setHead(Fighter* here);
        
        void addFighter();
        void addFighter(Character* loser);

        void deleteFighter();
        
        //moveWinnertoBack
        void movWinner();

        //print list backwards
       // void printBackwards();

        //print list forwards
        void printForwards();
        
        //delete the list
        void wipe();
};




#endif