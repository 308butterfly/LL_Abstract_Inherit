/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/16/2019
** Description:     The methods necessary for a fantasy battle tournament
** Dependencies:    game.hpp     
** File name:       game.cpp
*********************************************************************************/
#include"game.hpp"

Game::Game()
{}

Game::~Game()
{}

/************************************************************************************
Name:        gameMenu          
Called by:   main
Calls:       battle, getInteger
Passed:      nothing
Returns:     void    
 
Description:  Menu for Fantasy Tournament fighter.  The menu switches to ask the user
              to continue again.
************************************************************************************/
void Game::gameMenu()
{
    string choices[2] = {"","Exit\n"};

    if(!isPlayAgain)
    {
        choices[0] = {"Play\n"};
    }

    else
    {
        choices[0] = {"Play again\n"};
    }

    string message1 = "Fantasy Combat Tournament\n"
                    "1-" + choices[0] +
                    "2-" + choices[1];

    bool flag = true;
    
    while(flag)
    {   
        int choice = getInteger(message1);  
         
        enum choiceTitles {PLAY = 1, LEAVE};

        switch(choice)
        {
            case PLAY:
            {
                cout << choices[0] << endl;
                flag = false;
                isPlayAgain = true;
                battle();
                break;
            }   

            case LEAVE:
            {
                cout << choices[1] << endl;
                flag = false;
                break;
            }

            default:
            {
                cout << "Invalid choice\n";
                break;
            }
        }
    }
}

/************************************************************************************
************************************************************************************/

bool Game::showLosersMenu()
{
    bool gate = false;

    bool flag = true;

    string choices[2] = {"Yes\n", "No\n"};
    
    string message1 = "Show Losers\n"
                    "1-" + choices[0] +
                    "2-" + choices[1];
    while(flag)
    {
        int choice = getInteger(message1);

        enum yesNo{YES = 1, NO};

        switch(choice)
        {
            case YES:
            {
                gate = true;
                flag = false;
                break;
            }

            case NO:
            {
                flag = false;
                break;
            }

            default:
            {
                cout << "Invalid Choice.\n";
                break;
            }
        }
    }

    return gate;
}

/************************************************************************************
Name:        battle          
Called by:   gameMenu
Calls:       showLosersMenu, gameMenu
Passed:      nothing
Returns:     void    
 
Description: The battle function sets up the two teams to do battle.  After battling
             The list of each team is deleted and user is prompted to show the list 
             of the fighters that were defeated.  Afterwards the user is prompted
             again to play again or quit

************************************************************************************/

void Game::battle()
{
    LineUp* team1 = new LineUp();
    LineUp* team2 = new LineUp();
    Losers* losers = new Losers();

    string setSizeTeam1 = "How many members on team 1\n";
    string setSizeTeam2 = "How many members on team 2\n";

    team1Size = getInteger(setSizeTeam1);
    team2Size = getInteger(setSizeTeam2);

    for(int i = 0; i < team1Size; i++)
    {
        team1->addFighter();
    }
 
    for(int i = 0; i < team2Size; i++)
    {
        team2->addFighter();
    }

    cout << "LET THE BATTLE BEGIN!!!\n";

    while(team1->getFighter() != nullptr && team2->getFighter() != nullptr)
    {
        team1->getChar()->setOpponent(team2->getChar());
        team2->getChar()->setOpponent(team1->getChar());

        cout << "\nBattle " << ++battleNum << endl;
        cout << "-------------------------------------------------------\n";
        cout << "///////////////////////////////////////////////////////\n";
        cout << team1->getChar()->getName() << " the " << team1->getChar()->getType() << endl << endl
                << "battles" << endl << endl
                << team2->getChar()->getName() << " the " << team2->getChar()->getType()
                << endl;
        cout << "///////////////////////////////////////////////////////\n";

        while(team1->getChar()->getStrength() > 0 && team2->getChar()->getStrength() > 0)
        {
            
            if(team1->getChar()->getStrength() > 0)
            {
                team1->getChar()->attack();

                team2->getChar()->defense();
            }   

            if(team2->getChar()->getStrength() > 0)
            {   
                team2->getChar()->attack();

                team1->getChar()->defense();
            }
        }

        //team1 member wins
        if(team1->getChar()->getStrength() > 0)
        {
            cout << team1->getChar()->getName() << " the " << team1->getChar()->getType() << " wins!\n";
            cout << team1->getChar()->getName() << " the " << team1->getChar()->getType() 
                << " has " << team1->getChar()->getStrength() << " strength remaining.\n\n";

            team1->getChar()->recovery();
            team1Score += 2;

            cout << team1->getChar()->getName() << " the " << team1->getChar()->getType() << " gives"
                    " Team 1  two points!\n";
            cout << "Team 1 has a score of " << team1Score <<endl;

            team1->addFighter(team1->getChar());
            team1->deleteFighter();
            cout << "Winner moved.\n";

            losers->push(team2->getChar());
            cout << "Loser moved.\n";
            
            team2->deleteFighter();
            cout << "Loser deleted.\n";

        }

        //team2 member wins
        else
        {
            cout << team2->getChar()->getName() << " the " << team2->getChar()->getType() << " wins!\n";
            cout << team2->getChar()->getName() << " the " << team2->getChar()->getType() 
                << " has " << team2->getChar()->getStrength() << " strength remaining.\n\n";

            team2->getChar()->recovery();
            team2Score += 2;

            cout << team2->getChar()->getName() << " the " << team2->getChar()->getType() << " gives"
                    " Team 2 two points!\n";
            cout << "Team 2 has a score of " << team2Score <<endl;

            team2->addFighter(team2->getChar());
            team2->deleteFighter();
            cout << "Winner moved.\n";

            losers->push(team1->getChar());
            cout << "Loser moved.\n";
            
            team1->deleteFighter();
            cout << "Loser deleted.\n";
        }
/* 
        //team1->printBackwards();
        team1->printForwards();
        //team2->printBackwards();
        team2->printForwards();
        //losers->printBackwards();
*/
    }

    battleNum = 0;
    team1Score = 0;
    team2Score = 0;

    if(team1Score > team2Score)
    {
        cout << "Team 1 wins with a score of " << team1Score << " to " << team2Score << endl << endl;
    }

    else if(team2Score > team1Score)
    {
        cout << "Team 2 wins with a score of " << team2Score << " to " << team1Score << endl << endl;
    }

    else
    {
        cout << "Team 1 and Team 2 tie with scores of " << team1Score << endl;
    }

    if(showLosersMenu())
    {
        losers->printTopToBot();
    }

    team1->wipe();
    team2->wipe();
    losers->clean();
    
    gameMenu(); 

    delete team1;
    delete team2;

    delete losers;
}


