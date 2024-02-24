#include <iostream>
#include <time.h>
#include <Charkter.h>
#include <windows.h>

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
void worldPrinter(const Charkter &player, char (&worldfield)[5][5]){
    for(int x = 0; x < 5; x++ ){
        for(int y = 0; y < 5; y++){
            if(player.x == x && player.y == y){
                cout <<" X";
                continue;
            }
            cout <<" " << worldfield[x][y];
        }
        cout<<""<<endl;
    }
}

int main()
{
    Charkter player1;
    int Level = 0;
    char worldfield[5][5];
    while(true){
        int relcPoints = worldGenerator(worldfield);
        worldPrinter(player1,worldfield);
        cout <<"HP: " << player1.lifePoints <<endl;
        cout<< "Relic Points: " << player1.relicPoint << endl;
        while(relcPoints != 0){
            cout<<"Current Level: "<< Level <<endl;
            if(player1.lifePoints <= 0){
                cout << "GAME OVER" << endl;
                cout << "You collected :" << player1.relicPoint << "Relic Points" << endl;
                return 0;
            }
            while(!player1.move()){

            }
            system("cls");
            switch (worldfield[player1.x][player1.y]){
                case 'H':
                    player1.heal();
                    break;
                case 'D':
                    player1.takeDamage();
                    break;
                case 'R':
                    player1.increaseRelicPoints();
                    relcPoints--;
                default:
                    break;
            }
            worldfield[player1.x][player1.y] = '-';
            worldPrinter(player1,worldfield);
            cout <<"HP: " << player1.lifePoints <<endl;
            cout<< "Relic Points: " << player1.relicPoint << endl;
        }
        system("cls");
        player1.x = 0;
        player1.y = 0;
        Level++;
    }

    return 0;
}

    // ... . -. -.. / .... . .-.. .--. / .--. .-.. ...    -Mostafa Mhanna
