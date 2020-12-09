/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/3/2019
** Description:     Medusa class inherits from Character base class.
**                  It overides the attack and defense functions.  Has Glare 
**                  ability which instantly kills opponent when a 12 is 
**                  rolled.  
** Dependencies:    character.hpp              
** File name:       medusa.hpp
*********************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include"character.hpp"

class Medusa : public Character
{   
    private:
        bool usedGlare = false;
    
    public:
        Medusa();
        
        int attack();
        void glare();  
        void recovery();     
};

#endif
