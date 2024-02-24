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
    this->lifePoints = 1;
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
        case 'u':
            if(this->x > 0){
               this->x--;
            }
            return true;
        case 'D':
        case 'd':
            if(this->x < 4){
               this->x++;
            }
            return true;
        case 'L':
        case 'l':
            if(this->y > 0){
               this->y--;
            }
            return true;
        case 'R':
        case 'r':
            if(this->y < 4){
               this->y++;
            }
            return true;
        default:
            cout << "Invalid Move" << endl;
            return false;

    }
}
void Charkter::takeDamage(){
    srand(time(0));
    int randomNumber = 1 + rand()%6;
    if(randomNumber == 1){
        this->lifePoints--;
    }
}
void Charkter::heal(){
    this->lifePoints++;
}
void Charkter::increaseRelicPoints(){
    this->relicPoint++;
}
