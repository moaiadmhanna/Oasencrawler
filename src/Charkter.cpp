#include "Charkter.h"
#include <iostream>
#include <time.h>
#include "defaults.h"

using namespace std;
Charkter::Charkter()
{
    this->x = 0;
    this->y = 0;
    this->lifePoints = 5;
    this->relicPoints = 0;
    this->agility = 0;
    this->endurance = 0;
    this->knowledge = 0;
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
int Charkter::getAgility() const{
    return this->agility;
}
int Charkter::getEndurance() const{
    return this->endurance;
}
int Charkter::getKnowledge() const{
    return this->knowledge;
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
void Charkter::setAgility(int agilityPoint){
    this->agility = agilityPoint;
}
void Charkter::setEndurance(int endurancePoint){
    this->endurance = endurancePoint;
}
void Charkter::setKnowledge(int knowledgePoint){
    this->knowledge = knowledgePoint;
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
            if(this->getX() < WORLD_LENGTH-1){
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
            if(this->getY() < WORLD_LENGTH-1){
               this->y++;
            }
            return true;
        default:
            cout << "Invalid Move" << endl;
            return false;

    }
}
void Charkter::takeDamage(int x,char enemy){
    if(enemy == '*'){
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
void Charkter::findItem(){
    srand(time(0));
    int randomNumber = 1 + rand()%6;
    switch (randomNumber){
    case 2:
        cout << "You Found 1 item: (Step Reducer)   Agility increased"<<endl;
        this->agility++;
        break;
    case 3:
        cout << "You Found 1 item: (Hint)  Endurance increased"<<endl;
        this->endurance++;
        break;
    case 4:
        cout << "You Found 1 item: (Einstein potion) Knowledge increased"<<endl;
        this->knowledge++;
        break;
    default:
        break;
    }
}
