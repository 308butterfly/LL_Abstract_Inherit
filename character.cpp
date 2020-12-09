/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     Character base class
** Dependencies:    IntNumberGen from validate.hpp                
** File name:       character.cpp
*********************************************************************************/

#include"character.hpp"

Character::Character(int charAttackDieSides, int charAttackDieRolls, int charDefenseDieSides, int charDefenseDieRolls,
          int char_armor, int char_strength, std::string char_type ) 
{   
    this->c_aDieSides = charAttackDieSides;
    this->c_aDieRolls = charAttackDieRolls;
    this->c_dDieSides = charDefenseDieSides;
    this->c_dDieRolls = charDefenseDieRolls;
    this->armor = char_armor;
    this->strength = char_strength;
    this->refStrength = char_strength;
    this->type = char_type;
    this->c_attack = 0;
    this->c_defense = 0;
}

Character::~Character()
{
    opponent = nullptr;
}

int Character::getArmor()
{
    return armor;
}

int Character::getStrength()
{
    return strength;
}

int Character::getAttack()
{
    return c_attack;
}

void Character::setAttack(int trumpAttack)
{
    c_attack = trumpAttack;
}

void Character::setStrength(int strengthAdj)
{
    strength = strengthAdj;
}

void Character::setName()
{
    cout << "Name the fighter\n";
    getline(std::cin, name); 
}

std::string Character::getName()
{
    return name;
}

std::string Character::getType()
{
    return type;
}

/************************************************************************************
Name:       setOpponent            
Called by:  Character object
Calls:      nothing
Passed:     pointer to Character object
Returns:    void    
 
Description:  Used to let a character access an opponent's attack for the vampire's
charm or strength for Medusa's glare.
************************************************************************************/
void Character::setOpponent(Character* opp)
{   
    opponent = opp;
}

//virtual fxn
//overridden by Medusa
/************************************************************************************
Name:       attack            
Called by:  nothing
Calls:      nothing
Passed:     nothing
Returns:    void    
 
Description:  Used to calculate character's attack
************************************************************************************/

int Character::attack()
{
    c_attack = 0;
    
    int roll = 0;
    
    for(int i = 0; i < c_aDieRolls; i++)
    {
        roll = IntNumberGen(1,c_aDieSides);
        c_attack += roll;
    }
        
    return c_attack;
}
    
//virtual fxn
//overridden by Vampire and HarryPotter
/************************************************************************************
Name:       defense            
Called by:  nothing
Calls:      nothing
Passed:     nothing
Returns:    void    
 
Description:  Used to calculate remaining strength of character
************************************************************************************/

int Character::defense()
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

    return strength;
}

//pure virtual fxn
//overridden by all derived classes
/************************************************************************************
Name:       recovery          
Called by:  Character object
Calls:      intRandNum
Returns:    void    
 
Description:  recovers strength of character after a fight.  The ammount of strength 
recovered will depend on the character, and number of fights before fighting again.  
************************************************************************************/

void Character::recovery()
{}

