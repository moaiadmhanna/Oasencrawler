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
    this->lifePoints = 5;
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
    cout << "Please enter your Movement (Up(U)-Down(D)-Left(L)-Right(R))" << endl;
    char input;
    cin >> input;
    switch (input)
    {
        case 'U':
            if(this->getX() > 0){
               this->setX(this->getX() - 1);
            }
            return true;
        case 'D':
            if(this->getX() < 4){
               this->setX(this->getX() + 1);
            }
            return true;
        case 'L':
            if(this->getY() > 0){
               this->setY(this->getY() - 1);
            }
            return true;
        case 'R':
            if(this->getY() < 4){
               this->setY(this->getY() + 1);
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
            this->setLifePoints(this->getLifePoints() - 1);
        }
    }
    else{
        this->setLifePoints(this->getLifePoints() - x);
    }
}
void Charkter::heal(){
    this->setLifePoints(this->getLifePoints() + 1);
}
void Charkter::increaseRelicPoints(){
    this->setRelicPoints(this->getRelicPoints() + 1);
}
