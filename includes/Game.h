#ifndef LAKLOK_GAME_H
#define LAKLOK_GAME_H

class Game {
    int money;
    int seeds;
    int items;
    int score;
public:
    Game(int = 0, int = 1, int = 0, int = 0);

    void setMoney(int);

    void setSeed(int);

    void setItem(int);

    void setScore(int);

    int getMoney();

    int getSeed();

    int getItem();

    int getScore();
};

#endif //LAKLOK_GAME_H
