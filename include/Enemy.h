#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        int getX() const;
        int getY() const;
        int getAttackEnergey() const;
        void setX(int x);
        void setY(int y);
        void setAttackEnergy(int attackEnergy);
        void follow();
        void move(int x, int y);

    protected:

    private:
        int x;
        int y;
        int attackEnergy;
};

#endif // ENEMY_H
