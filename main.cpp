#include <iostream>
#include <time.h>
#include <Charkter.h>
#include <windows.h>
#include <Enemy.h>
#include <defaults.h>
#include <string>

using namespace std;
void knowledgeChallenge(Charkter* player){
    cout <<"You got a mathe equation you need to solve it Right to not lose 1 HP"<<endl;
    srand(time(0));
    int firstRandomNumber = 100 + rand()%1000;
    int secondRandomNumber = 100 + rand()%1000;
    int solution = firstRandomNumber+secondRandomNumber;
    cout << firstRandomNumber << "+" << secondRandomNumber <<endl;
    char input = '.';
    if(player->getKnowledge()>=1){
        cout << "you have Einstein potion item do you want to use it (y/n) you will lose one knowledge point" << endl;
        while(true){
            cin >> input;
            input = tolower(input);
            if(input ==  'y' || input == 'n'){
                break;
            }
            else{
                cout << "invalid input" << endl;
            }
        }
    }
    if(input == 'y'){
        cout << "OK Einstein will make it easier for you" << endl;
        firstRandomNumber = 10 + rand()%100;
        secondRandomNumber = 100 + rand()%100;
        solution = firstRandomNumber + secondRandomNumber;
        player->setKnowledge((player->getKnowledge())-1);
        cout << firstRandomNumber << " + " << secondRandomNumber <<endl;
    }
    int userInput;
    cout <<"=";
    cin >> userInput;
    if(userInput == solution){
        cout << "Amazing you got it right" << endl;
    }
    else{
        cout << "No thats not right" << endl;
        player->takeDamage(1,'k');
        cout << "The right answer was: " << solution << endl;
    }
    Sleep(2000);
}
void enduranceFieldGenrator(char (&enduranceField)[ENDURANCEX][ENDURANCEY]){
    enduranceField[0][0]='-';
    enduranceField[0][2]='-';
    enduranceField[0][1]='-';
    enduranceField[4][0]='-';
    enduranceField[4][2]='-';
    enduranceField[4][1]='E';
    int firstBomb = 0;
    int secondBomb = 0;
    srand(time(0));
    for(int x = 1 ; x < ENDURANCEX-1; x++){
        int randomNumber = 1 + rand()%3;
        switch(randomNumber){
        case 1:
            firstBomb = 1;
            secondBomb = 2;
            break;
        case 2:
            firstBomb = 0;
            secondBomb = 2;
            break;
        case 3:
            firstBomb = 0;
            secondBomb = 1;
            break;
        }
        enduranceField[x][firstBomb] = '*';
        enduranceField[x][secondBomb] = '*';
    }
}
void enduranceFieldPrinter(char (&enduranceField)[ENDURANCEX][ENDURANCEY], Charkter* challengePlayer){
    int current = 1;
    for(int i = 0; i<= (ENDURANCEY*2)+2 ; i++){
        cout << "-";
    }
    cout << "" << endl;
    for(int x = 0; x < ENDURANCEX; x++ ){
            cout << "|";
        for(int y = 0; y < ENDURANCEY; y++){
            if(challengePlayer->getX() == x && challengePlayer->getY() == y){
                cout<<" X";
                if(x > 0){
                    current++;
                }
                continue;
            }
            if(x == 0 || x == ENDURANCEX-1){
                cout <<" "<<enduranceField[x][y];
                continue;
            }
            else{
                cout <<" "<<current;
            }
            current++;
        }
        cout<<" |"<<endl;
    }
    for(int i = 0; i<= (ENDURANCEY*2)+2 ; i++){
        cout << "-";
    }
    cout << "" << endl;
}
void enduracneChallenge(Charkter* player){
    cout << "You entered a dungeon you should reach E to exit the dungeon" << endl;
    cout << "Watch out while moving it could be bombs under the numbers" << endl;
    char enduranceField[ENDURANCEX][ENDURANCEY];
    enduranceFieldGenrator(enduranceField);
    Charkter* endurancePlayer = new Charkter();
    endurancePlayer->setY(1);
    int cnt = 1;
    for(int i = 0; i < 3 ; i++){
        enduranceFieldPrinter(enduranceField,endurancePlayer);
        if(enduranceField[endurancePlayer->getX()][endurancePlayer->getY()] == '*'){
            cout << "You stepped on a bomb You will lose 1 HP" << endl;
            player->takeDamage(1,'e');
            Sleep(2000);
            return;
        }
        char itemInput = '.';
        if(player->getEndurance() >= 1 && i != 3){
            cout << "you have Hint item do you want to use it (y/n) you will lose one Endurance point" << endl;
            while(true){
                cin >> itemInput;
                itemInput = tolower(itemInput);
                if(itemInput ==  'y' || itemInput == 'n'){
                    break;
                }
                else{
                    cout << "invalid Input" << endl;
                }
            }
        }
        if(itemInput == 'y'){
            if(enduranceField[(endurancePlayer->getX())+1][endurancePlayer->getY()] == '*'){
                cout << "Do'nt go down there is a bomb"<<endl;
            }
            else{
                cout << "You can go down its safe"<<endl;
            }
            player->setEndurance(player->getEndurance()-1);
        }
        int input;
        while(true){
            cout << "Which field do you want to go to(" << cnt <<"-"<< cnt+1 <<"-"<< cnt+2 << ")"<<endl;
            cin >> input;
            if(input == cnt || input == cnt+1 || input == cnt+2){
                break;
            }
        }
        if(input == cnt){
            endurancePlayer->setX(endurancePlayer->getX()+1);
            endurancePlayer->setY(0);
        }
        else if (input == cnt+1){
            endurancePlayer->setX(endurancePlayer->getX()+1);
            endurancePlayer->setY(1);
        }
        else{
            endurancePlayer->setX(endurancePlayer->getX()+1);
            endurancePlayer->setY(2);
        }
       cnt+=3;
    }
    endurancePlayer->setX(4);
    endurancePlayer->setY(1);
    enduranceFieldPrinter(enduranceField,endurancePlayer);
    cout << "Congratulations you exit the dungeon" << endl;
    Sleep(2000);
}
char getRandomMove(int& x, int& y) {
    int randomNumber = 1 + rand() % 4;
    switch (randomNumber) {
        case 1: x--; return 'w';
        case 2: y++; return 'd';
        case 3: x++; return 's';
        case 4: y--; return 'a';
    }
}
string agilityFieldGenrator(char (&agilityField)[AGILITY_FIELD_LENGTH][AGILITY_FIELD_LENGTH], int stepsCounter) {
    const int centerX = AGILITY_FIELD_LENGTH / 2;
    const int centerY = AGILITY_FIELD_LENGTH / 2;

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
void agilityChallenge(int level,Charkter* player){
    char agilityField[AGILITY_FIELD_LENGTH][AGILITY_FIELD_LENGTH];
    string solution = agilityFieldGenrator(agilityField,7+level);
    cout << "You entered a maze you should collect the apple to exit"<<endl;
    agilityFieldPrinter(agilityField);
    char input;
    if(player->getAgility()>0){
        cout << "you have Step Reducer item do you want to use it (y/n) you will lose one Agility point" << endl;
        while(true){
            cin >> input;
            input = tolower(input);
            if(input ==  'y' || input == 'n'){
                break;
            }
            else{
                cout << "invalid input" << endl;
            }
        }
    }
    if(input == 'y'){
        solution = agilityFieldGenrator(agilityField,4+level);
        agilityFieldPrinter(agilityField);
        player->setAgility(player->getAgility()-1);
    }
    cout << "The way to move is a little bit diffrent you should type all of your moves at once (Up(w)-Down(s)-Left(a)-Right(d))"<<endl;
    cout << "if you did'nt type it correctly you will get a damage" << endl;
    string userInput;
    cin >> userInput;
    if(userInput != solution){
        player->takeDamage(1,'a');
        cout << "You did'nt get it correctly you lost 1 HP" << endl;
    }
    else{
        cout << "You got it correctly" <<endl;
    }
    Sleep(2000);
}
void challengesMode(int level,Charkter* player){
    system("cls");
    srand(time(0));
    int randomNumber = 1+rand()%4;
    switch (randomNumber){
        case 1:
            player->takeDamage(1,'*');
            break;
        case 2:
            agilityChallenge(level,player);
            break;
        case 3:
            enduracneChallenge(player);
            break;
        case 4:
            knowledgeChallenge(player);
            break;
    }
    system("cls");
}
int  worldGenerator(char (&worldfield)[WORLD_LENGTH][WORLD_LENGTH]){
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
        cout << "[X]: Player [R]: Relic Point [H]: Health point [*]: Danger Field [Y]: Enemy"<<endl;
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
                    challengesMode(level,player);
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
int main()
{
    Charkter* player1 = new Charkter();
    int level = 1;
    int enemyDifficulty = 0; // The Enemy Difficulty
    char worldfield[WORLD_LENGTH][WORLD_LENGTH];
    while(true){
        int relicPoints = worldGenerator(worldfield);
        if(!levelGamePlay(relicPoints,player1,enemyDifficulty,worldfield,level)){break;}
        player1->setX(0);
        player1->setY(0);
        level++;
        enemyDifficulty++;
    }
    return 0;
}
    // ... . -. -.. / .... . .-.. .--. / .--. .-.. ...    -Mostafa Mhanna
