/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/2/2019
** Description:     HarryPotter class file inherits from Character base class.  
**                  It overides the attack and defense functions from the 
**                  character class.  Has special ability Hogwarts which sets 
**                  strength to 20 when Harry Potter's inital strength goes to 0. 
** Dependencies:    character.hpp                
** File name:       harryPotter.hpp
*********************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include"character.hpp"

class HarryPotter : public Character
{
    private:
        bool canUseHogwarts = true;
    
    public:
        HarryPotter();
        
        int defense();
        void hogwarts();
        void recovery();
};

#endif
