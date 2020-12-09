/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/3/2019
** Description:     Vampire class which inherits from the character class and  
**                  overrides attack, defense and setStrength methods.  Vampire 
**                  has Charm ability to give opponent a 50% chance to not attack.           
** Dependencies:    vampire.hpp                 
** File name:       vampire.cpp
*********************************************************************************/

#include"vampire.hpp"

Vampire::Vampire():Character(12, 1, 6, 1, 1, 18, "Vampire")
{
    this->backupStrength = strength;
}

/************************************************************************************
Name:        defense           
Called by:   vampire object
Calls:       charm, IntNumberGen
Passed:      nothing
Returns:     integer   
 
Description:  creates 1d6 die roll for Vampire defense.  If a 6 is rolled the vampire
uses the "charm" ability to give the opponent a 50% chance to not attack.
************************************************************************************/

int Vampire::defense()
{
    c_defense = 0;
    
    int roll = 0;
    
    for(int i = 0; i < c_dDieRolls; i++)
    {
        roll = IntNumberGen(1, c_dDieSides);
        c_defense += roll;
    }
    
    if(c_defense == 6)
    {
        charm();   
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

    if(strength != 0)
    {
        backupStrength = strength;
    }
    
    return c_defense;
}

/************************************************************************************
Name:        charm         
Called by:   defense
Calls:       setAttack, IntNumberGen
Passed:      nothing
Returns:     void   
 
Description: Charms an opponent into not attacking by setting their attack to zero, 
or reversing a special abilty performed on them. 
************************************************************************************/

void Vampire::charm()
{
    int miss = IntNumberGen(1,100);
    
    if(miss % 2 == 0)
    {
        /************************************************************************************
        Because the attacker can first attack or use special abilities, 
        the vampire has a chance to stop the attack or negate the special ability,
        because charm trumps special abilites
        ************************************************************************************/

        if(strength == 0)
        {
            strength = backupStrength;
        }
        
        opponent->setAttack(0);
    }
    
}

/************************************************************************************
Name:        recovery           
Called by:   nothing
Calls:       nothing
Passed:      nothing
Returns:     void    
 
Description: vampire recovery, the vampire recovers all of his health after a battle
             because he is one handsome bastard.  I am jealous.  
************************************************************************************/

void Vampire::recovery()
{
    strength = refStrength;

    int recovery = IntNumberGen(0, refStrength - strength);
        
    cout << getName() << " the " << getType() << " recovers "
            << recovery << " strength.\n";

    strength += recovery;

    cout << getName() << " the " << getType() << " has "
            << strength << " strength.\n";

}

