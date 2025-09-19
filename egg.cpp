#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "suiji.h" 

using namespace std;

//creat an egg class(functions, outward a, crash)
class Egg
{
public:
    float Money = 200.0;
    Random rnd;

    void M()
    {
        cout << "money : " << Money << endl;
    }

    void Ap()
    {
        cout << "     **" << endl;
        cout << "   ******" << endl;
        cout << "  ********" << endl;
        cout << " **********" << endl;
        cout << "************" << endl;
        cout << "  ********" << endl;
        cout << "    ****" << endl;
        M();
    }

    void Smash()
    {
        system("clear");
        const char* frames[] = {
            "   ***   \n"
            "  *****  \n"
            "  *****  \n"
            "   ***   \n",

            "   ***   \n"
            "  * * *  \n"
            "  ** **  \n"
            "   ***   \n",

            "   * *   \n"
            "  * * *  \n"
            "  *   *  \n"
            "   * *   \n",

            " *  *  * \n"
            "  *   *  \n"
            " *     * \n"
            "  *   *  \n",

            "*   *   *\n"
            "   *   * \n"
            " *     * \n"
            "   *   * \n"
        };

        for (int i = 0; i < 5; i++) {
            system("clear"); 
            cout << frames[i] << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
            system("clear"); 
        }
    }

    void A(float add)
{
    float oldMoney = Money;
    float target = Money + add;

    for (int i = (int)oldMoney; i <= (int)target; i++) {
        system("clear");
        cout << "Money : " << i << "   $$$.  " << endl;
        this_thread::sleep_for(chrono::milliseconds(10)); 
    }

    Money = target;
    cin.get();
}

    void HatchDuck()
{
    const char* frames[10] = {
        // 1 蛋完整
        "   ***   \n"
        "  *****  \n"
        "  *****  \n"
        "   ***   \n",

        // 2 裂缝出现
        "   ***   \n"
        "  ** **  \n"
        "  *****  \n"
        "   ***   \n",

        // 3 裂缝加大
        "   * *   \n"
        "  * * *  \n"
        "  *****  \n"
        "   ***   \n",

        // 4 蛋壳掉一块
        "   * *   \n"
        "  *   *  \n"
        "  ** **  \n"
        "   ***   \n",

        // 5 小鸭头探出来
        "   ^ ^   \n"
        "  (o_o)  \n"
        "  ** **  \n"
        "   ***   \n",

        // 6 鸭子伸长
        "   ^ ^   \n"
        "  (o_o)  \n"
        "  /( )\\  \n"
        "   ***   \n",

        // 7 鸭子站起来
        "   ^ ^   \n"
        "  (o_o)  \n"
        "  /( )\\  \n"
        "   | |   \n",

        // 8 鸭子张开翅膀
        "  \\^ ^/  \n"
        "  (o_o)  \n"
        "  /( )\\  \n"
        "   | |   \n",

        // 9 鸭子展开翅膀
        " \\ ^ ^ / \n"
        "( (o_o) )\n"
        "  /( )\\  \n"
        "   | |   \n",

        // 10 完整小鸭
        "   ^ ^   \n"
        "  (o_o)  \n"
        " <( ) ( )>\n"
        "   | |   \n"
    };

    for (int i = 0; i < 10; i++) {
        system("clear");
        cout << frames[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "A duck is born! 🦆" << endl;
    cin.get();
}

    void Tree()
    {
        string input;

        cout << "you got a money tree!!!!" << endl;
        cin.get();
        cout << "but u need spend 300 $ to purchase it!" << endl;
        cout << "press Y if u want" << endl;
        getline(cin, input);
            if (input == "y" || input == "Y") {
                if (Money >= 300){
                    Money -= 300;
                    cout << "u got it!!!$" << endl;
                    A(100.0);           
                }
                else{
                    cout << "fail" << endl;
                }
            } else if(input == "q" || input == "Q") {
                cout << "ok" << endl;
            }
    }

    void None()
    {
        cout << "u got nothing" << endl;
    }
    
    void ST()
    {
        int i = rnd.randint(0, 3);
        switch(i)
        {
            case 0 : A(rnd.randfloat(200.0, 300.0)); break;
            case 1 : Tree(); M(); break;
            case 2 : HatchDuck(); M(); break;
            case 3 : None(); M(); break;
        }

    }
};

int main()
{
    Egg egg;
    string input;

    while (true) {   
        egg.Ap();
        cout << "Press Enter to smash it (or type Q to quit)" << endl;

        getline(cin, input);
        if (input == "q" || input == "Q") {
            cout << "Bye bye~" << endl;
            break; 
        }

        egg.Smash();
        egg.ST();

        cout << "\nPress Enter to continue, or Q to quit." << endl;
        getline(cin, input);
        if (input == "q" || input == "Q") {
            cout << "Game Over!" << endl;
            break;
        }
    }

    return 0;
}