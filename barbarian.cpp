/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/29/2019
** Description:     Barbarian class inherits from Character and overrieds attack 
**                  and defense methods.
** Dependencies:    character.hpp                 
** File name:       barbarian.hpp
*********************************************************************************/

#include"barbarian.hpp"

Barbarian::Barbarian():Character(6, 2, 6, 2, 0, 12, "Barbarian")
{}

/************************************************************************************
Name:        recovery            
Called by:   nothing
Calls:       nothing
Passed:      nothing
Returns:     void    
 
Description: Barbarian recovers strength based on the last defense die roll.  If it
             is greater, then it is swapped with the current strength.
************************************************************************************/

void Barbarian::recovery()
{   
    if(c_defense > strength)
    {
        cout << getName() << " the " << getType() <<  " recovers " 
             << c_defense - strength << " strength.\n"; 
        
        strength = c_defense;
    }

    else
    {
        cout << getName() << " the " << getType() <<  " was hit too hard and recovers"
        " no strength.\n"; 
    }

    cout << getName() << " the " << getType() <<  " has " 
             << strength << " strength.\n\n"; 
    
}