/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/2/2019
** Description:     Barbarian class file inherits from Character base class
**                  and has no special abilities
** Dependencies:    character.hpp                
** File name:       barbarian.hpp
*********************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include"character.hpp"

class Barbarian : public Character
{ 
    public:
        Barbarian();
        void recovery();
        
};

#endif
