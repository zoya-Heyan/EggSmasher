#include "EggGame.h"
#include "Terminal.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

EggGame::EggGame()
    : money(200), ducks(0), luckyCharm(false) {
    shop.push_back({"Lucky Charm", 300, "Increase rare egg chance"});
}

void EggGame::HUD() {
    cout << CYAN << "===============================" << endl;
    cout << "     EGG SMASHER V3.0          " << endl;
    cout << "===============================" << RESET << endl;
    cout << YELLOW << "Money: $" << money << RESET << endl;
    cout << GREEN << "Ducks: " << ducks << " (+" << ducks * 20 << "/turn)" << RESET << endl;
    cout << (luckyCharm ? GREEN : RED)
         << "Lucky Charm: " << (luckyCharm ? "ON" : "OFF")
         << RESET << endl << endl;
}

void EggGame::drawEgg() {
    cout << "     **" << endl;
    cout << "   ******" << endl;
    cout << "  ********" << endl;
    cout << " **********" << endl;
    cout << "************" << endl;
    cout << "  ********" << endl;
    cout << "    ****" << endl;
}

void EggGame::smashAnimation() {
    clear();
    cout << "* CRASH *" << endl;
    this_thread::sleep_for(chrono::milliseconds(300));
}

Rarity EggGame::rollRarity() {
    int roll = rnd.randint(1, 100);
    if (luckyCharm) roll += 10;

    if (roll <= 55) return Rarity::COMMON;
    if (roll <= 80) return Rarity::RARE;
    if (roll <= 95) return Rarity::EPIC;
    return Rarity::LEGENDARY;
}

void EggGame::randomEvent() {
    Rarity r = rollRarity();
    cout << BOLD << "Egg Rarity: " << rarityName(r) << RESET << endl;

    switch (r) {
        case Rarity::COMMON:
            gainMoney(rnd.randfloat(50, 150));
            break;
        case Rarity::RARE:
            hatchDuck();
            break;
        case Rarity::EPIC:
            gainMoney(500);
            break;
        case Rarity::LEGENDARY:
            gainMoney(1000);
            ducks += 2;
            cout << GREEN << "Two ducks joined you!" << RESET << endl;
            break;
    }
}

void EggGame::gainMoney(float amount) {
    money += amount;
    cout << GREEN << "+$" << amount << RESET << endl;
}

void EggGame::hatchDuck() {
    ducks++;
    cout << GREEN << "A duck is born! 🦆" << RESET << endl;
}

void EggGame::nextTurn() {
    money += ducks * 20;
}

void EggGame::openShop() {
    clear();
    cout << CYAN << "--- SHOP ---" << RESET << endl;
    for (size_t i = 0; i < shop.size(); ++i) {
        cout << i + 1 << ". " << shop[i].name
             << " ($" << shop[i].price << ") - "
             << shop[i].desc << endl;
    }
    cout << "Enter item number or 0 to exit: ";
    int c; cin >> c; cin.ignore();
    if (c == 1 && money >= shop[0].price) {
        money -= shop[0].price;
        luckyCharm = true;
        cout << GREEN << "Lucky Charm purchased!" << RESET << endl;
    }
}

void EggGame::run() {
    string input;
    while (true) {
        clear();
        HUD();
        drawEgg();
        cout << CYAN << "[Enter] Smash  [S] Shop  [Q] Quit" << RESET << endl;
        getline(cin, input);

        if (input == "q" || input == "Q") break;
        if (input == "s" || input == "S") {
            openShop();
            continue;
        }

        smashAnimation();
        randomEvent();
        nextTurn();

        cout << CYAN << "Press Enter to continue..." << RESET << endl;
        getline(cin, input);
    }
}
