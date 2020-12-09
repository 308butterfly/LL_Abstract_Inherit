/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/1/2019
** Description:     Blue men class file inherits from Character base class.  
**                  It overrides the attack and defense functions and implements 
**                  "mob" by reducing the number of die rolls base on the Blue 
**                  Mens strength.
** Dependencies:    character.hpp                 
** File name:       blueMen.hpp
*********************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include"character.hpp"

class BlueMen : public Character
{
    public:
        BlueMen();
        
        int defense();
        
        void mob();
        void recovery();   
};

#endif
