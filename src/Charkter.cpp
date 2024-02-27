#include "Charkter.h"
#include <iostream>
#include <time.h>

using namespace std;
enum movement{
    Up,
    Down,
    Left,
    Right
};

Charkter::Charkter()
{
    this->x = 0;
    this->y = 0;
    this->lifePoints = 4;
    this->relicPoint =0;
}

Charkter::~Charkter()
{
    //dtor
}
bool Charkter::move()
{
    cout << "Please enter your Movement (Up(U)-Down(D)-Left(L)-Right(R))" << endl;
    char input;
    cin >> input;
    switch (input)
    {
        case 'U':
            if(this->x > 0){
               this->x--;
            }
            return true;
        case 'D':
            if(this->x < 4){
               this->x++;
            }
            return true;
        case 'L':
            if(this->y > 0){
               this->y--;
            }
            return true;
        case 'R':
            if(this->y < 4){
               this->y++;
            }
            return true;
        default:
            cout << "Invalid Move" << endl;
            return false;

    }
}
void Charkter::takeDamage(int x){
    if(x == 1){
        srand(time(0));
        int randomNumber = 1 + rand()%6;
        if(randomNumber == 1){
            this->lifePoints--;
        }
    }
    else{
        this->lifePoints -= x;
    }
}
void Charkter::heal(){
    this->lifePoints++;
}
void Charkter::increaseRelicPoints(){
    this->relicPoint++;
}
