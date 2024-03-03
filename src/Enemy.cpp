#include "Enemy.h"
#include <iostream>
#include <time.h>
#include "defaults.h"
Enemy::Enemy()
{
    this->x = 0;
    this->y = 0;
    this->attackEnergy = 0;
}

Enemy::~Enemy()
{
    //dtor
}
int Enemy::getX() const{
    return this->x;
}
int Enemy::getY() const{
    return this->y;
}
int Enemy::getAttackEnergey() const {
    return this->attackEnergy;
}
void Enemy::setX(int x){
    this->x = x;
}
void Enemy::setY(int y){
    this->y = y;
}
void Enemy::follow(){
    srand(time(0));
    while(true){
        int randPoistion = rand()%5;
        int xPoistion = this->getX();
        int yPoistion = this->getY();
        switch (randPoistion){
        case 0:
            break;
        case 1:
            xPoistion--;
            break;
        case 2:
            yPoistion++;
            break;
        case 3:
            xPoistion++;
            break;
        case 4:
            yPoistion--;
            break;
    }
    if(xPoistion < WORLD_LENGTH && yPoistion < WORLD_LENGTH && xPoistion > 0 && yPoistion >0){
        this->setX(xPoistion);
        this->setY(yPoistion);
        break;
    }
    }
}
void Enemy::setAttackEnergy(int attackEnergy){
    this->attackEnergy = attackEnergy;
}
void Enemy::move(int x, int y){
    this->x += x;
    this->y += y;
}
