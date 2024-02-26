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
        bool move();
        void takeDamage(int x);
        void heal();
        void increaseRelicPoints();

    protected:

    private:
};

#endif // CHARKTER_H
