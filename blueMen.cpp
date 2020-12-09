/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/1/2019
** Description:     Blue men class file inherits from Character base class.  
**                  It overrides the attack and defense functions and implements 
**                  "mob" by reducing the number of die rolls base on the Blue 
**                  Mens strength.
** Dependencies:    blueMen.hpp                 
** File name:       blueMen.cpp
*********************************************************************************/

#include"blueMen.hpp"

BlueMen::BlueMen() : Character(10,2, 6,3, 3, 12, "Blue Men")
{}

/************************************************************************************
Name:        mob           
Called by:   defense
Calls:       IntNumberGen
Passed:      nothing
Returns:     void  
 
Description:  inmplements mob for defense by having 3d6 roll when strength is above
              8, 2d6 when strength is between 8 and , and 1d6 when strength is 
              between 4 and 1
************************************************************************************/


void BlueMen::mob()
{
    if(strength > 8)
    {
        c_dDieRolls = 3;
    }

    else if(strength > 4)
    {
        c_dDieRolls = 2;
    }

    else
    {
        c_dDieRolls = 1;
    }

}

/************************************************************************************
Name:        defense          
Called by:   BlueMen object
Calls:       mob
Passed:      nothing
Returns:     int  
 
Description:  inmplements mob for defense by having 3d6 roll when strength is above
              8, 2d6 when strength is between 8 and , and 1d6 when strength is 
              between 4 and 1
************************************************************************************/

int BlueMen::defense()
{
    mob();

    c_defense = 0;
    
    int roll = 0;
    
    for(int i = 0; i < c_dDieRolls; i++)
    {
        roll = IntNumberGen(1, c_dDieSides);
        c_defense += roll;
    }
    
    int damage = opponent->getAttack() - armor - c_defense;

    if(damage < 0)
    {
        damage = 0;
    }

    strength -= damage;

    if(strength < 0)
    {
        strength = 0;
    }

    return c_defense;
}


/************************************************************************************
Name:        recovery          
Called by:   nothing
Calls:       nothing
Passed:      nothing
Returns:     void    
 
Description: Since blue men lose a die roll if strength goes below 8 or two rolls
             when strength goes below 4, recovery is limited how many die rolls are
             left.
************************************************************************************/

void BlueMen::recovery()
{
    if(strength < 4)
    {
        strength = 4;
    }

    else if(strength < 8)
    {
        strength = 8;
    }

    else 
    {
        strength = 12;
    }

    cout << getName() << " the " << getType() <<  " can only recover to " 
    << strength << " strength.\n\n"; 
}