/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/2/2019
** Description:     HarryPotter class file inherits from Character base class.  
**                  It overides the attack and defense functions from the 
**                  character class.  Has special ability Hogwarts which sets 
**                  strength to 20 when Harry Potter's inital strength goes to 0. 
** Dependencies:    harryPotter.hpp                 
** File name:       harryPotter.cpp
*********************************************************************************/

#include"harryPotter.hpp"

HarryPotter::HarryPotter():Character(6, 2, 6, 2, 0, 10, "Harry Potter")
{}

/************************************************************************************
Name:        defense           
Called by:   HarryPotter object
Calls:       IntNumberGen
Passed:      nothing
Returns:     void  
 
Description:  creates 2d6 die roll for Harry Potter's defense.
************************************************************************************/

int HarryPotter::defense()
{
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

    if(strength == 0)
    {
        hogwarts();
    }

    return strength;    
}

/************************************************************************************
Name:        hogwarts        
Called by:   defense
Calls:       none
Passed:      integer
Returns:     void    
 
Description:  sets Harry Potter's strength to 20 the first time it goes to zero.  
Ability only works one time.
************************************************************************************/

void HarryPotter::hogwarts()
{


    if(canUseHogwarts)
    {
        strength = 20;

        opponent->setAttack(0);
        
        canUseHogwarts = false;
    }
}

/************************************************************************************
Name:        recovery            
Called by:   nothing
Calls:       nothing
Passed:      nothing
Returns:     void    
 
Description: When Harry Potter recovers he can use Hogwarts again.  His strength
             returns to the original strength before using hogwarts, and he recovers
             a percentage of strength lost.  
************************************************************************************/

void HarryPotter::recovery()
{
    if(strength > 10)
    {
        strength = refStrength;
        cout << getName() << " the " << getType() << " used Hogwarts and returns to "
             << strength << " strength.\n\n";
    }

    else
    {
        int recovery = IntNumberGen(0, refStrength - strength);
        
        cout << getName() << " the " << getType() << " recovers "
             << recovery << " strength.\n";
        
        strength += recovery;
        
        cout << getName() << " the " << getType() << " has "
             << strength << " strength.\n";
    }
    
    canUseHogwarts = true;
}