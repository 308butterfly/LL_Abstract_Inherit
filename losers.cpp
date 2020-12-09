#include "losers.hpp"

Losers::Losers()
{
    top = nullptr;
}

Losers::~Losers()
{

}

void Losers::push(Character* loser)
{
    current = new Fighter(loser);
    current->member = loser;
    
    if(top == nullptr)
    {
        top = current;
        top->next = nullptr;
        return;
    }

    current->next = top;
    top = current;

}

void Losers::pop()
{
    current = top;

    if(top == nullptr)
    {
        cout << "Stack is empty.\n";
        return;
    }

    top = top->next;

    delete current->member;

    delete current;

}

void Losers::printTopToBot()
{
    current = top;


    cout << endl;
    while(current != nullptr)
    {
        cout << current->member->getName() << " the " << current->member->getType() << endl;
        current = current->next;
    }

}

void Losers::clean()
{
    while(top != nullptr)
    {
        pop();
    }

    top = nullptr;
}
