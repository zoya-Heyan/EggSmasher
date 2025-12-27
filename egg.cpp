#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "suiji.h"

using namespace std;

// ===== Terminal Utils =====
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

void clear() {
    cout << "\033[2J\033[H";
}

// ===== Game Class =====
class EggGame {
private:
    float money = 200.0f;
    int ducks = 0;
    Random rnd;

public:
    void HUD() {
        cout << CYAN << "===============================\n";
        cout << "      EGG SMASHER V2.0         \n";
        cout << "===============================" << RESET << endl;
        cout << YELLOW << "Money: $" << money << RESET << endl;
        cout << GREEN << "Ducks: " << ducks << " ( +" << ducks * 20 << "/turn )" << RESET << endl;
        cout << endl;
    }

    void drawEgg() {
        cout << "     **" << endl;
        cout << "   ******" << endl;
        cout << "  ********" << endl;
        cout << " **********" << endl;
        cout << "************" << endl;
        cout << "  ********" << endl;
        cout << "    ****" << endl;
    }

    void smashAnimation() {
        vector<string> frames = {
            "   ***   \n  *****  \n  *****  \n   ***   \n",
            "   ***   \n  * * *  \n  ** **  \n   ***   \n",
            "   * *   \n  * * *  \n  *   *  \n   * *   \n",
            " *  *  * \n  *   *  \n *     * \n  *   *  \n",
            "*   *   *\n   *   * \n *     * \n   *   * \n"
        };
        for (auto &f : frames) {
            clear();
            cout << f << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    }

    void gainMoney(float amount) {
        float start = money;
        float end = money + amount;
        for (int i = (int)start; i <= (int)end; i += 5) {
            clear();
            cout << YELLOW << "Money: $" << i << RESET << endl;
            this_thread::sleep_for(chrono::milliseconds(15));
        }
        money = end;
    }

    void hatchDuck() {
        ducks++;
        cout << GREEN << BOLD << "A duck is born! 🦆" << RESET << endl;
    }

    void randomEvent() {
        int roll = rnd.randint(1, 100);
        if (roll <= 50) {
            float reward = rnd.randfloat(100, 300);
            cout << GREEN << "You found coins!" << RESET << endl;
            gainMoney(reward);
        } else if (roll <= 75) {
            hatchDuck();
        } else if (roll <= 90) {
            cout << RED << "Nothing happened..." << RESET << endl;
        } else {
            cout << BOLD << YELLOW << "LEGENDARY EGG!!!" << RESET << endl;
            gainMoney(1000);
        }
    }

    void nextTurn() {
        money += ducks * 20;
    }

    void run() {
        string input;
        while (true) {
            clear();
            HUD();
            drawEgg();
            cout << CYAN << "Press Enter to smash (Q to quit)" << RESET << endl;
            getline(cin, input);
            if (input == "q" || input == "Q") break;

            smashAnimation();
            randomEvent();
            nextTurn();

            cout << CYAN << "\nPress Enter to continue..." << RESET << endl;
            getline(cin, input);
        }
        cout << "Game Over. Thanks for playing!" << endl;
    }
};

int main() {
    EggGame game;
    game.run();
    return 0;
}
