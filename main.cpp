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
void worldPrinter(Charkter* player, char (&worldfield)[5][5]){
    for(int x = 0; x < 5; x++ ){
        for(int y = 0; y < 5; y++){
            if(player->getX() == x && player->getY() == y){
                cout <<" X";
                continue;
            }
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
    Charkter* player1 = new Charkter();
    int level = 1;
    char worldfield[5][5];
    worldGenerator(worldfield);
    worldPrinter(player1, worldfield);
    return 0;
}
    // ... . -. -.. / .... . .-.. .--. / .--. .-.. ...    -Mostafa Mhanna
