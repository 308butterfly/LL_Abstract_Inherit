#ifndef LOSERS_HPP
#define LOSERS_HPP

#include "fighter.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"

class Losers
{
    private:
    protected:
        Fighter* top;
        Fighter* current;
        
    public:
        Losers();
        ~Losers();

        void push(Character* loser);
        void pop();

        void printTopToBot();

        void clean();

};

#endif