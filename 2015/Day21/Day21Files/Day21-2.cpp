#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <map>

using namespace std;

bool fightLose(map<string, int> player, map<string, int> enemy) {
    bool returnBool;

    int damageToEnemy = player["Damage"] - enemy["Armor"];
    int damageToPlayer = enemy["Damage"] - player["Armor"];

    if (damageToEnemy <= 0) {
        damageToEnemy = 1;
    };
    
    if (damageToPlayer <= 0) {
    	damageToPlayer = 1;
    };

    while (true) {
        enemy["Hit Points"] -= damageToEnemy;

        if (enemy["Hit Points"] <= 0) {
            returnBool = false;
            break;
        };

        player["Hit Points"] -= damageToPlayer;

        if (player["Hit Points"] <= 0) {
            returnBool = true;
            break;
        };
    };

    return returnBool;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    map<string, tuple<int, int, int>> shopWeapons;
        shopWeapons["Dagger"] = make_tuple(8, 4, 0);
        shopWeapons["Shortsword"] = make_tuple(10, 5, 0);
        shopWeapons["Warhammer"] = make_tuple(25, 6, 0);
        shopWeapons["Longsword"] = make_tuple(40, 7, 0);
        shopWeapons["Greataxe"] = make_tuple(74, 8, 0);

    map<string, tuple<int, int, int>> shopArmor;
        shopArmor["No Armor"] = make_tuple(0, 0, 0);
        shopArmor["Leather"] = make_tuple(13, 0, 1);
        shopArmor["Chainmail"] = make_tuple(31, 0, 2);
        shopArmor["Splintmail"] = make_tuple(53, 0, 3);
        shopArmor["Bandedmail"] = make_tuple(75, 0, 4);
        shopArmor["Platemail"] = make_tuple(102, 0, 5);

    vector<string> shopRingNames = {"No Ring 1", "No Ring 2", "Damage +1", "Damage +2", "Damage +3", "Defense +1", "Defense +2", "Defense +3"};
    map<string, tuple<int, int, int>> shopRings;
        shopRings["No Ring 1"] = make_tuple(0, 0, 0);
        shopRings["No Ring 2"] = make_tuple(0, 0, 0);
        shopRings["Defense +1"] = make_tuple(20, 0, 1);
        shopRings["Damage +1"] = make_tuple(25, 1, 0);
        shopRings["Defense +2"] = make_tuple(40, 0, 2);
        shopRings["Damage +2"] = make_tuple(50, 2, 0);
        shopRings["Defense +3"] = make_tuple(80, 0, 3);
        shopRings["Damage +3"] = make_tuple(100, 3, 0);

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    map<string, int> bossStats;

    string line;
    while (getline(openFile, line)) {
        int colonLoc = line.find(":");

        string key = line.substr(0, colonLoc);
        int value = stoi(line.substr(colonLoc + 2));

        bossStats.insert({key, value});
    };
    openFile.close();

    int highestCost = 0;

    int counter = 0;

    for (auto tempWeapon : shopWeapons) {
        for (auto tempArmor : shopArmor) {
            for (int tempRing1Num = 0; tempRing1Num < shopRings.size(); tempRing1Num += 1) {
                for (int tempRing2Num = tempRing1Num + 1; tempRing2Num < shopRings.size(); tempRing2Num += 1) {
                    counter += 1;

                    tuple<int, int, int> tempRing1 = shopRings[shopRingNames[tempRing1Num]];
                    tuple<int, int, int> tempRing2 = shopRings[shopRingNames[tempRing2Num]];

                    int cost = get<0>(tempWeapon.second) + get<0>(tempArmor.second) +
                               get<0>(tempRing1) + get<0>(tempRing2);

                    int playerHealth = 100;
                    int playerDamage = get<1>(tempWeapon.second) + get<1>(tempRing1) + get<1>(tempRing2);
                    int playerArmor = get<2>(tempArmor.second) + get<2>(tempRing1) + get<2>(tempRing2);

                    map<string, int> playerStats;
                    playerStats.insert({"Hit Points", playerHealth});
                    playerStats.insert({"Damage", playerDamage});
                    playerStats.insert({"Armor", playerArmor});

                    if (fightLose(playerStats, bossStats)) {
                        if (cost > highestCost) {
                        	highestCost = cost;
                        };
                    };
                };
            };
        };
    };

    cout << counter << endl;

    cout << endl << "The cost of the highest losing setup is: " << highestCost << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
