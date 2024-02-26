#include "Enemy.h"
#include <iostream>
#include <time.h>
Enemy::Enemy()
{
    this->x = 0;
    this->y = 0;
    this->attackEnergy = 2;
}

Enemy::~Enemy()
{
    //dtor
}
void Enemy::follow(int x, int y){
    int xDiff = x - this->x;
    int yDiff = y - this->y;
    if(xDiff != 0){
        if(xDiff > 0){this->x++;}
        else{this->x--;}
    }
    else if (xDiff == 0 && yDiff != 0) {
        if(yDiff > 0){this->y++;}
        else{this->y--;}
    }
}
void Enemy::move(int x, int y){
    this->x += x;
    this->y += y;
}
