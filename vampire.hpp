/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/3/2019
** Description:     Vampire class which inherits from the character class and  
**                  overrides attack and defense.  Vampire has Charm ability to 
**                  give opponent a 50% chance to not attack. 
** Dependencies:    character.hpp                 
** File name:       vampire.hpp
*********************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include"character.hpp"

class Vampire : public Character
{
    private:        
        int backupStrength;
    
    public:
        Vampire();

        int defense();
        void charm();
        void recovery();
};

#endif
