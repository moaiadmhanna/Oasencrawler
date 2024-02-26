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
    int xPoistion = this->x;
    int yPoistion = this->y;
    while(true){
        int randPoistion = rand()%8 +1;
        switch (randPoistion){
        case 1:
            this->x--;
            break;
        case 2:
            this->x--;
            this->y++;
            break;
        case 3:
            this->y++;
            break;
        case 4:
            this->x++;
            this->y++;
            break;
        case 5:
            this->x++;
            break;
        case 6:
            this->x++;
            this->y--;
            break;
        case 7:
            this->y--;
            break;
        case 8:
            this->x--;
            this->y--;
            break;
    }
    if(this->x < 5 && this->y < 5){
        break;
    }
    }
}
void Enemy::move(int x, int y){
    this->x += x;
    this->y += y;
}
