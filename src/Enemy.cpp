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
void Enemy::follow(){
    srand(time(0));
    while(true){
        int randPoistion = rand()%5;
        int xPoistion = this->x;
        int yPoistion = this->y;
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
    if(xPoistion < 5 && yPoistion < 5 && xPoistion > 0 && yPoistion >0){
        this->x = xPoistion;
        this->y = yPoistion;
        break;
    }
    }
}
void Enemy::move(int x, int y){
    this->x += x;
    this->y += y;
}
