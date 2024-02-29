#include "Charkter.h"
#include <iostream>
#include <time.h>

using namespace std;
Charkter::Charkter()
{
    this->x = 0;
    this->y = 0;
    this->lifePoints = 1;
    this->relicPoints = 0;
}

Charkter::~Charkter()
{
    //dtor
}
int Charkter::getX() const{
    return this->x;
}
int Charkter::getY() const{
    return this->y;
}
int Charkter::getLifePoints() const{
    return this->lifePoints;
}
int Charkter::getRelicPoints() const {
    return this->relicPoints;
}
void Charkter::setX(int x){
    this->x = x ;
}
void Charkter::setY(int y){
    this->y = y;
}
void Charkter::setLifePoints(int lifePoint){
    this->lifePoints = lifePoint;
}
void Charkter::setRelicPoints(int relicPoint){
    this->relicPoints = relicPoint;
}
bool Charkter::move()
{
    cout << "Please enter your Movement (Up(w)-Down(s)-Left(a)-Right(d))" << endl;
    char input;
    cin >> input;
    switch (input)
    {
        case 'w':
        case 'W':
            if(this->getX() > 0){
               this->x--;
            }
            return true;
        case 's':
        case 'S':
            if(this->getX() < 4){
               this->x++;
            }
            return true;
        case 'a':
        case 'A':
            if(this->getY() > 0){
               this->y--;
            }
            return true;
        case 'd':
        case 'D':
            if(this->getY() < 4){
               this->y++;
            }
            return true;
        default:
            cout << "Invalid Move" << endl;
            return false;

    }
}
void Charkter::takeDamage(int x,char enemy){
    if(enemy == 'D'){
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
    this->relicPoints++;
}
