#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        int x;
        int y;
        int attackEnergy;
        void follow();
        void move(int x, int y);

    protected:

    private:
};

#endif // ENEMY_H
