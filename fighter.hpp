#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include "character.hpp"

struct Fighter
{
    Character* member;

    Fighter* next;

    Fighter(Character* thisChar = nullptr, Fighter* fNext = nullptr)
    {
        member = thisChar;
        next = fNext;
    };
};

#endif