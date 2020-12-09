#include "lineUp.hpp"

LineUp::LineUp()
{
    this->head = nullptr;
    this->tail = nullptr;
}

LineUp::~LineUp()
{}

Character* LineUp::getChar()
{
    return head->member;
}

Fighter* LineUp::getFighter()
{
    return head;
}

void LineUp::setHead(Fighter* here)
{
    head = here;
}

void LineUp::addFighter()
{    
    current = new Fighter();
    cout << current << endl;

    string choices[5] = {"Barbarian\n", 
                        "Blue Men\n", 
                        "Harry Potter\n", 
                        "Medusa\n", 
                        "Vampire\n"};

    string message1 = "CHOOSE YOUR FIGHTER\n\n"
                  "1-" + choices[0] + 
                  "2-" + choices[1] +
                  "3-" + choices[2] +
                  "4-" + choices[3] +
                  "5-" + choices[4];

    bool flag = true;

    while(flag)
    {
      int choice = getInteger(message1);
      
      enum charTypes {BAR = 1, BLU, HAR, MED, VAM};

      switch (choice)
      {
            case BAR:
            {
                cout << "You chose a " << choices[0] << endl;
                current->member = new Barbarian();
                flag = false;
                break;
            }

            case BLU:
            {
                cout << "You chose " << choices[1] << endl;
                current->member = new BlueMen();
                flag = false;
                break;
            }

            case HAR:
            {
                cout << "You chose " << choices[2] << endl;
                current->member = new HarryPotter();
                flag = false;
                break;
            }

            case MED:
            {
                cout << "You chose " << choices[3] << endl;
                current->member = new Medusa();
                flag = false;
                break;
            }

            case VAM:
            {
                cout << "You chose a " << choices[4] << endl;
                current->member = new Vampire();
                flag = false;
                break;
            }

            default:
            {
                cout << "Invalid choice\n\n";
                break;
            }
        }
        
    }

    current->member->setName();


    if(tail == nullptr)
    {
        // // -> //O//
        tail = current;
        head = tail;
        //head->next = tail;
        return;
    }

    //O// -> //O ... O//
    tail->next = current;
    tail = current;
}

void LineUp::addFighter(Character* loser)
{
    current = new Fighter();
    current->member = loser;
    cout << current << endl;

    if(tail == nullptr)
    {
        tail = current;
        head = tail;
        //head->next = tail;
        return;
    }

    tail->next = current;
    tail = current;
}

void LineUp::deleteFighter()
{
    if(head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    current = head;
    cout << "Deleted head is " << current << endl;
    head = head->next;
    cout << "Currrent head is" << head << endl;

   // delete current->member;
    delete current;

    if(head == nullptr)
    {
        tail = nullptr;
    }

}

void LineUp::printForwards()
{
    current = head;

    cout << endl;

    while (current != nullptr)
    {
        cout << current->member->getName() << " the " << current->member->getType() << endl;
        current = current->next;
    }
}

void LineUp::movWinner()
{
    head = head->next;
}


void LineUp::wipe()
{
    if(head == nullptr)
    {
        cout << "list is empty.\n";
        return;
    }
    
    current = head;
    
    while(current != nullptr)
    {
        Fighter* garbage = current;
        current = current->next;
        delete garbage->member;
        delete garbage;
        cout << "DELETING\n";
    }

    head = nullptr;
}


