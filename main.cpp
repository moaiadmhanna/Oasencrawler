#include <iostream>
#include <time.h>
#include <Charkter.h>
#include <windows.h>
#include <Enemy.h>
#include <defaults.h>
#include <string>

using namespace std;
int  worldGenerator(char (&worldfield)[WORLD_LENGTH][WORLD_LENGTH])
{
    srand(time(0));
    int relicGenerated = 0; // R counter
    for(int x = 0; x < WORLD_LENGTH ; x++){
        for(int y = 0; y < WORLD_LENGTH; y++){
            int randomNumber = 1 + rand()%10;
            if(x == 0 && y == 0){
                worldfield[x][y] = '-';
                continue;
            }
            if(randomNumber <= 4){
                worldfield[x][y] = '-'; // Empty Field
            }
            else if(randomNumber <= 8 && randomNumber >4){
                worldfield[x][y] = '*'; // Danger Field
            }
            else if (randomNumber == 9){
                worldfield[x][y] = '+'; // Health Field
            }
            else{
                relicGenerated ++;
                worldfield[x][y] = 'R'; // Relic Field
            }
        }
    }
    // when there is no relic in the field
    if(!relicGenerated){
        int xPoistion = rand()%WORLD_LENGTH;
        int yPoistion = rand()%WORLD_LENGTH;
        relicGenerated++;
        worldfield[xPoistion][yPoistion] = 'R';
    }
    return relicGenerated;

}

char getRandomMove(int& x, int& y) {
    int randomNumber = 1 + rand() % 4;
    switch (randomNumber) {
        case 1: x--; return 'w';
        case 2: y++; return 'd';
        case 3: x++; return 's';
        case 4: y--; return 'a';
    }
    return '\0'; // Default case, should not happen
}

string agilityFieldGenrator(char (&agilityField)[AGILITY_FIELD_LENGTH][AGILITY_FIELD_LENGTH], int stepsCounter) {
    const int centerX = AGILITY_FIELD_LENGTH / 2;
    const int centerY = AGILITY_FIELD_LENGTH / 2;

    // Initialize the agilityField with '*'
    for (int x = 0; x < AGILITY_FIELD_LENGTH; x++) {
        for (int y = 0; y < AGILITY_FIELD_LENGTH; y++) {
            agilityField[x][y] = (x == centerX && y == centerY) ? 'X' : '*';
        }
    }

    string solution = "";
    int xPosition = centerX;
    int yPosition = centerY;
    srand(time(0));

    for (int i = 0; i < stepsCounter; i++) {
        int attempts = 0;

        while (true) {
            if (attempts > 4) {
                break;
            }

            int xTemp = xPosition;
            int yTemp = yPosition;
            char move = getRandomMove(xTemp, yTemp);

            if (xTemp >= 0 && yTemp >= 0 && xTemp < AGILITY_FIELD_LENGTH && yTemp < AGILITY_FIELD_LENGTH &&
                agilityField[xTemp][yTemp] != 'X' && agilityField[xTemp][yTemp] != '-') {

                solution += move;
                xPosition = xTemp;
                yPosition = yTemp;
                agilityField[xPosition][yPosition] = '-';
                break;
            }

            attempts++;
        }
    }

    agilityField[xPosition][yPosition] = 'O';
    return solution;
}
void agilityFieldPrinter(char (&agilityField)[AGILITY_FIELD_LENGTH][AGILITY_FIELD_LENGTH]){
    for(int i = 0; i<= (AGILITY_FIELD_LENGTH*2)+2 ; i++){
        cout << "-";
    }
    cout << "" << endl;
    for(int x = 0; x < AGILITY_FIELD_LENGTH; x++ ){
            cout << "|";
        for(int y = 0; y < AGILITY_FIELD_LENGTH; y++){
            cout <<" " << agilityField[x][y];
        }
        cout<<" |"<<endl;
    }
    for(int i = 0; i<= (AGILITY_FIELD_LENGTH*2)+2 ; i++){
        cout << "-";
    }
    cout << "" << endl;
}
void worldPrinter(Charkter* player, char (&worldfield)[WORLD_LENGTH][WORLD_LENGTH], Enemy* enemy = NULL){
    for(int i = 0; i<= (WORLD_LENGTH*2)+2 ; i++){
        cout << "-";
    }
    cout << "" << endl;
    for(int x = 0; x < WORLD_LENGTH; x++ ){
            cout << "|";
        for(int y = 0; y < WORLD_LENGTH; y++){
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
        cout<<" |"<<endl;
    }
    for(int i = 0; i<= (WORLD_LENGTH*2)+2 ; i++){
        cout << "-";
    }
    cout << "" << endl;
}
void enemyGenerator(char (&worldfield)[WORLD_LENGTH][WORLD_LENGTH],Enemy *enemy, int enemyDifficulty){
    srand(time(0));
        while(true){
            int xTemp = rand()%WORLD_LENGTH;
            int yTemp = 0;
            if(xTemp < 3){
                yTemp = (rand()%2)+3;
            }
            else{
                yTemp = rand()%WORLD_LENGTH;
            }
            if((worldfield[xTemp][yTemp] != 'R') && (worldfield[xTemp][yTemp] != 'Y')){
                enemy->move(xTemp,yTemp);
                enemy->setAttackEnergy(enemyDifficulty);
                break;
            }
        }
}
void objectMovement(Charkter* player,Enemy* enemy, bool enemyAlive, char (&worldfield)[WORLD_LENGTH][WORLD_LENGTH]){
    while(!player->move()){

    }
    if(enemyAlive){
        enemy->follow();
    }
    system("cls");
}
bool levelGamePlay(int relicPoints,Charkter* player, int enemyDifficulty, char (&worldfield)[WORLD_LENGTH][WORLD_LENGTH],int level){
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
        cout << "Current Agility : " << player->getAgility() << " Endurance: " << player->getEndurance() << " Knowledge: " << player->getKnowledge() << endl;
        cout << "Current Level : " << level << endl;
        objectMovement(player,enemy1,enemyAlive,worldfield);
        if( enemyAlive && player->getX() == enemy1->getX() && player->getY() == enemy1->getY()){
            player->takeDamage(enemy1->getAttackEnergey(),'Y');
            enemyAlive = false;
        }
        switch (worldfield[player->getX()][player->getY()]){
                case '+':
                    player->heal();
                    player->findItem();
                    break;
                case '*':
                    player->takeDamage(1,'*');
                    break;
                case 'R':
                    player->increaseRelicPoints();
                    relicPoints--;
                    player->findItem();
                default:
                    break;
            }
        worldfield[player->getX()][player->getY()] = '-';
    }
    return true;
};
int main2()
{
    Charkter* player1 = new Charkter();
    int level = 1;
    int enemyDifficulty = 0; // The Enemy Difficulty
    char worldfield[WORLD_LENGTH][WORLD_LENGTH];
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
int main(){
    char agilityField[AGILITY_FIELD_LENGTH][AGILITY_FIELD_LENGTH];
    cout << agilityFieldGenrator(agilityField,8)<<endl;
    agilityFieldPrinter(agilityField);
}
    // ... . -. -.. / .... . .-.. .--. / .--. .-.. ...    -Mostafa Mhanna
