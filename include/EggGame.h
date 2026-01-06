#ifndef EGGGAME_H
#define EGGGAME_H

#include <vector>
#include "suiji.h"
#include "Rarity.h"
#include "Item.h"

class EggGame {
private:
    float money;
    int ducks;
    bool luckyCharm;
    Random rnd;
    std::vector<Item> shop;

    void HUD();
    void drawEgg();
    void smashAnimation();
    void randomEvent();
    void gainMoney(float amount);
    void hatchDuck();
    void nextTurn();
    Rarity rollRarity();
    void openShop();

public:
    EggGame();
    void run();
};

#endif