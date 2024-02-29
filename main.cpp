#include <iostream>
#include <time.h>
#include <Charkter.h>
#include <windows.h>
#include <Enemy.h>

using namespace std;
int  worldGenerator(char (&worldfield)[5][5])
{
    srand(time(0));
    int relicGenerated = 0; // R counter
    for(int x = 0; x < 5 ; x++){
        for(int y = 0; y < 5; y++){
            int randomNumber = 1 + rand()%10;
            if(x == 0 && y == 0){
                worldfield[x][y] = '-';
                continue;
            }
            if(randomNumber <= 4){
                worldfield[x][y] = '-'; // Empty Field
            }
            else if(randomNumber <= 8 && randomNumber >4){
                worldfield[x][y] = 'D'; // Danger Field
            }
            else if (randomNumber == 9){
                worldfield[x][y] = 'H'; // Health Field
            }
            else{
                relicGenerated ++;
                worldfield[x][y] = 'R'; // Relic Field
            }
        }
    }
    // when there is no relic in the field
    if(!relicGenerated){
        int xPoistion = rand()%5;
        int yPoistion = rand()%5;
        relicGenerated++;
        worldfield[xPoistion][yPoistion] = 'R';
    }
    return relicGenerated;

}
void worldPrinter(Charkter* player, char (&worldfield)[5][5], Enemy* enemy = NULL){
    for(int x = 0; x < 5; x++ ){
        for(int y = 0; y < 5; y++){
            if(player->getX() == x && player->getY() == y){
                cout <<" X";
                continue;
            }
            if(enemy != NULL && enemy->getX() == x && enemy->getY() == y){
                cout <<" Y";
                continue;
            }
            cout <<" " << worldfield[x][y];
        }
        cout<<""<<endl;
    }
}
void enemyGenerator(char (&worldfield)[5][5],Enemy *enemy, int enemyDifficulty){
    srand(time(0));
        while(true){
            int xTemp = rand()%5;
            int yTemp = 0;
            if(xTemp < 3){
                yTemp = (rand()%2)+3;
            }
            else{
                yTemp = rand()%5;
            }
            if((worldfield[xTemp][yTemp] != 'R') && (worldfield[xTemp][yTemp] != 'Y')){
                enemy->move(xTemp,yTemp);
                enemy->setAttackEnergy(enemyDifficulty);
                break;
            }
        }
}
void objectMovement(Charkter* player,Enemy* enemy, bool enemyAlive, char (&worldfield)[5][5]){
    while(!player->move()){

    }
    if(enemyAlive){
        enemy->follow();
    }
    system("cls");
}
bool levelGamePlay(int relicPoints,Charkter* player, int enemyDifficulty, char (&worldfield)[5][5],int level){
    Enemy* enemy1 = new Enemy();
    enemyGenerator(worldfield,enemy1,enemyDifficulty);
    bool enemyAlive = false;
    if(enemyDifficulty > 0){
        enemyAlive = true;
    }
    while(relicPoints != 0){
        if(player->getLifePoints() <= 0){
            cout << "Game Over " << endl;
            cout << "You Collected : " << player->getRelicPoints() << " Relic Points" << endl;
            cout << "You Reached Level :" << level << endl;
            return false;
        }
        if(enemyAlive){
            cout << "A New Enemy has Appear he moves randomly Watch out he also deals a " << enemy1->getAttackEnergey() << " HP Damage !!!" <<endl;
            worldPrinter(player,worldfield,enemy1);
        }
        else{
            worldPrinter(player,worldfield);
        }
        cout << "HP : " << player->getLifePoints() << endl;
        cout << "Relic collected : " << player->getRelicPoints() << endl;
        cout << "Current Level : " << level << endl;
        objectMovement(player,enemy1,enemyAlive,worldfield);
        if( enemyAlive && player->getX() == enemy1->getX() && player->getY() == enemy1->getY()){
            player->takeDamage(enemy1->getAttackEnergey(),'Y');
            enemyAlive = false;
        }
        switch (worldfield[player->getX()][player->getY()]){
                case 'H':
                    player->heal();
                    break;
                case 'D':
                    player->takeDamage(1,'D');
                    break;
                case 'R':
                    player->increaseRelicPoints();
                    relicPoints--;
                default:
                    break;
            }
        worldfield[player->getX()][player->getY()] = '-';
    }
    return true;
};
int main()
{
    Charkter* player1 = new Charkter();
    int level = 5;
    int enemyDifficulty = 0; // The Enemy Difficulty
    char worldfield[5][5];
    while(true){
        int relicPoints = worldGenerator(worldfield);
        if(level % 5 == 0){enemyDifficulty++;}
        if(!levelGamePlay(relicPoints,player1,enemyDifficulty,worldfield,level)){break;}
        player1->setX(0);
        player1->setY(0);
        level++;
    }
    return 0;
}
    // ... . -. -.. / .... . .-.. .--. / .--. .-.. ...    -Mostafa Mhanna
