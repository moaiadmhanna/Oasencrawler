#include <iostream>
#include <time.h>
#include <Charkter.h>

using namespace std;

int randomGenerator(){
    int x = 1 + rand()%10;
    return x;
}
void worldGenerator(char (&worldfield)[5][5])
{
    srand(time(0));
    bool relicGenerated = false;
    for(int x = 0; x < 5 ; x++){
        for(int y = 0; y < 5; y++){
            int randomNumber = randomGenerator();
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
                relicGenerated = true;
                worldfield[x][y] = 'R'; // Relic Field
            }
        }
    }
    if(!relicGenerated){
        int xPoistion = rand()%5;
        int yPoistion = rand()%5;
        worldfield[xPoistion][yPoistion] = 'R';
    }

}
void worldPrinter(const Charkter& player, char (&worldfield)[5][5]){
    for(int x = 0; x < 5; x++ ){
        for(int y = 0; y < 5; y++){
            cout <<" " << worldfield[x][y];
        }
        cout<<""<<endl;
    }
}

int main()
{
    char worldfield[5][5];
    worldGenerator(worldfield);
    Charkter player1;
    worldPrinter(player1,worldfield);

    return 0;
}
