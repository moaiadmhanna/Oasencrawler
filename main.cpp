#include <iostream>
#include <time.h>
#include <Charkter.h>
#include <windows.h>
#include <Enemy.h>

using namespace std;

int randomGenerator(){
    int x = 1 + rand()%10;
    return x;
}
int  worldGenerator(char (&worldfield)[5][5])
{
    srand(time(0));
    int relicGenerated = 0; // R counter
    for(int x = 0; x < 5 ; x++){
        for(int y = 0; y < 5; y++){
            int randomNumber = randomGenerator();
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
        worldfield[xPoistion][yPoistion] = 'R';
    }
    return relicGenerated;

}
void worldPrinter(const Charkter &player, char (&worldfield)[5][5], int cnt , const Enemy *enemy){
    for(int x = 0; x < 5; x++ ){
        for(int y = 0; y < 5; y++){
            bool checker = false;
            if(player.x == x && player.y == y){
                cout <<" X";
                continue;
            }
            for(int i = 0; i < cnt; i++){
                if(enemy->x == x && enemy->y == y){
                    cout << " Y";
                    checker = true;
                    continue;
                }
            }
            if(checker == true){continue;}
            cout <<" " << worldfield[x][y];
        }
        cout<<""<<endl;
    }
}
void enemyGenerator(int level, char (&worldfield)[5][5],Enemy *enemy){
    srand(time(0));
    for(int i = 0; i < level; i++){
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
                break;
            }
        }
    }
}
int main()
{
    Charkter player1;
    int level = 1;
    char worldfield[5][5];
    int cnt = 1;
    while(true){
        int relcPoints = worldGenerator(worldfield);
        if(level % 10 == 0){cnt++;}
        Enemy *enemy1 = new Enemy();
        enemyGenerator(cnt,worldfield,enemy1);
        worldPrinter(player1,worldfield,cnt,enemy1);
        cout <<"HP: " << player1.lifePoints <<endl;
        cout<< "Relic Points: " << player1.relicPoint << endl;
        while(relcPoints != 0){
            cout<<"Current level: "<< level <<endl;
            if(player1.lifePoints <= 0){
                cout << "GAME OVER" << endl;
                cout << "You collected : " << player1.relicPoint << "Relic Points" << endl;
                return 0;
            }
            while(!player1.move()){

            }
            for(int i = 0; i < cnt ; i++){
                enemy1->follow();
            }
            system("cls");
            switch (worldfield[player1.x][player1.y]){
                case 'H':
                    player1.heal();
                    break;
                case 'D':
                    player1.takeDamage(1);
                    break;
                case 'R':
                    player1.increaseRelicPoints();
                    relcPoints--;
                default:
                    break;
            }
            if(player1.x == enemy1->x && player1.y == enemy1->y){
                player1.takeDamage(2);
                delete(enemy1);
            }
            worldfield[player1.x][player1.y] = '-';
            worldPrinter(player1,worldfield,cnt,enemy1);
            cout <<"HP: " << player1.lifePoints <<endl;
            cout<< "Relic Points: " << player1.relicPoint << endl;
        }
        system("cls");
        player1.x = 0;
        player1.y = 0;
        level++;
    }

    return 0;
}
    // ... . -. -.. / .... . .-.. .--. / .--. .-.. ...    -Mostafa Mhanna
