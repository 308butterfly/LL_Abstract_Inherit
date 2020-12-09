/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/2/2019
** Description:     Medusa class inherits from Character base class.
**                  It overides the attack and defense functions.  Has Glare 
**                  ability which instantly kills opponent when a combined 12 is 
**                  rolled.  
** Dependencies:    medusa.hpp                 
** File name:       medusa.cpp
*********************************************************************************/

#include"medusa.hpp"

Medusa::Medusa() : Character(6, 2, 6, 1, 3, 8, "Medusa")
{}

/************************************************************************************
Name:        attack        
Called by:   Medusa object
Calls:       glare, IntNumberGen
Passed:      nothing
Returns:     integer    
 
Description:  creates 2d6 die roll for Medusa attack along with glare ability that 
instantly kills opponent upon rolling a 12.
************************************************************************************/

int Medusa::attack()
{
    c_attack = 0;
    
    int roll = 0;
    
    for(int i = 0; i < c_aDieRolls; i++)
    {
        roll = IntNumberGen(1,c_aDieSides);
        c_attack += roll;
    }
    
    if(c_attack == 12)
    {
        glare();
    }

    return c_attack;
}

/************************************************************************************
Name:        glare       
Called by:   Attack
Calls:       setStrength
Passed:      nothing
Returns:     Only death.... only sweet, sweet, death.  Komm susser Toad.
             (void)    
 
Description:  sets opponents strength value to 0.  Instantly killing them.  
************************************************************************************/

void Medusa::glare()
{
    usedGlare = true;

    opponent->setStrength(0); //insta-kill;       
}

/************************************************************************************
Name:        recovery            
Called by:   nothing
Calls:       IntNumberGen
Passed:      nothing
Returns:     void    
 
Description: Medusa fully recovers if she used glare, otherwise she recovers a 
             percentage of lost strength.
************************************************************************************/

void Medusa::recovery()
{
    if(usedGlare)
    {
        strength = refStrength;
        usedGlare = false;
        cout << getName() << " the " << getType() << " used glare and therefore "
                             "recovers to full strength\n\n";
    }

    else
    {
        int recovery = IntNumberGen(0, refStrength - strength);
        cout << getName() << " the " << getType() << " recovers " << recovery 
             << " strength\n\n";
        
        strength += recovery;
    }

    cout << getName() << " the " << getType() << " has " << strength
            << " strength\n\n";  
}