#ifndef CHARKTER_H
#define CHARKTER_H
#include <iostream>
using namespace std;



class Charkter
{
    public:
        Charkter();
        virtual ~Charkter();
        int getX() const;
        int getY() const;
        int getRelicPoints() const;
        int getLifePoints() const;
        void setX(int x);
        void setY(int y);
        void setRelicPoints(int relicPoint);
        void setLifePoints(int lifePoint);
        bool move();
        void takeDamage(int x);
        void heal();
        void increaseRelicPoints();

    protected:

    private:
        int x = 0;
        int y = 0;
        int lifePoints = 0;
        int relicPoints = 0;
};

#endif // CHARKTER_H
