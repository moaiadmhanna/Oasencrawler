#include <iostream>
#include <time.h>

using namespace std;

int randomGenerator(){
    int x = rand()%10;
    return x;
}

int main()
{
    char worldfield[5][5];
        srand(time(0));
        bool emptyField = randomGenerator() <= 4? true:false;
        bool danger = randomGenerator() <= 4? true:false;
        bool burn = randomGenerator() <= 1? true:false;
        bool relic = randomGenerator() <= 1? true:false;
        cout << emptyField << endl;
        cout << danger << endl;
        cout << burn << endl;
        cout << relic << endl;
    while(true){
    }
    return 0;
}
