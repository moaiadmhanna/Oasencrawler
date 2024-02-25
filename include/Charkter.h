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
        int lifePoints;
        int relicPoint;
        void takeDamage();
        void heal();
        void increaseRelicPoints();

    protected:

    private:
};

#endif // CHARKTER_H
