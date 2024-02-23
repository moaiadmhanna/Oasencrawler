#ifndef CHARKTER_H
#define CHARKTER_H
#include <iostream>
using namespace std;



class Charkter
{
    public:
        Charkter();
        virtual ~Charkter();
        int x;
        int y;
        int lifePoints;
        int relicPoint;
        void move();
        void takeDamage();
        void heal();
        void increaseRelicPoints();

    protected:

    private:
};

#endif // CHARKTER_H
