/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/4/2019
** Description:     Character base class
** Dependencies:    IntNumberGen from validate.hpp                
** File name:       character.hpp
*********************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include"validate.hpp"

#include<string>

using std::string;
using std::cout;
using std::endl;

class Character
{
    protected:
        int c_aDieSides;
        int c_aDieRolls;
        int c_dDieSides;
        int c_dDieRolls;
        int c_attack;
        int c_defense;
        int armor;
        int refStrength;
        int strength;

        std::string name;
        std::string type;

        Character* opponent = nullptr;

    public:
        Character(int charAttackDieSides, int charAttackDieRolls, int charDefenseDieSides, int charDefenseDieRolls,
                  int char_armor, int char_strength, std::string char_name );      
        
        virtual ~Character();

        virtual void recovery() = 0;

        int getArmor();
        int getStrength();
        int getAttack();

        void setAttack(int newAttack);
        void setStrength(int strengthAdj);
        void setName();
        
        void setOpponent(Character* opp);
        
        std::string getName();
        std::string getType();
                
        virtual int attack();
        virtual int defense();   
};

#endif
