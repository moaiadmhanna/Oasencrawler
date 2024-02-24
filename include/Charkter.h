#ifndef CHARKTER_H
#define CHARKTER_H
#include <iostream>
using namespace std;



class Charkter
{
    public:
        Charkter();
        virtual ~Charkter();
        bool move();
        int x;
        int y;
        void takeDamage();
        void heal();
        void increaseRelicPoints();

    protected:

    private:
        int lifePoints;
        int relicPoint;
};

#endif // CHARKTER_H
