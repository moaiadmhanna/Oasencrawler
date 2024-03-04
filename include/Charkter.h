#ifndef CHARKTER_H
#define CHARKTER_H
#include <iostream>
using namespace std;



class Charkter
{
    public:
        Charkter();
        ~Charkter();
        int getX() const;
        int getY() const;
        int getRelicPoints() const;
        int getLifePoints() const;
        int getAgility() const;
        int getEndurance() const;
        int getKnowledge() const;
        void setX(int x);
        void setY(int y);
        void setRelicPoints(int relicPoint);
        void setLifePoints(int lifePoint);
        void setAgility(int agilityPoint);
        void setEndurance(int endurancePoint);
        void setKnowledge(int knowledgePoint);
        bool move();
        void takeDamage(int x,char enemy);
        void findItem();
        void heal();
        void increaseRelicPoints();

    protected:

    private:
        int x;
        int y;
        int lifePoints;
        int relicPoints;
        int agility;
        int endurance;
        int knowledge;
};

#endif // CHARKTER_H
