#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#include <map>

using namespace std;

map<string, int> inputParser(string pathName) {
    ifstream openFile(pathName);

    map<string, int> tempMap;

    string line;
    while (getline(openFile, line)) {
        int colonLoc = line.find(":");
        string key = line.substr(0, colonLoc);
        string value = line.substr(colonLoc + 2);

        tempMap.insert({key, stoi(value)});
    };
    openFile.close();

    return tempMap;
};

map<string, tuple<int, int, int, int, int, int>> spellParser(string pathName) {
    ifstream openFile(pathName);
    
    map<string, tuple<int, int, int, int, int, int>> tempMap;

    string line;
    while (getline(openFile, line)) {
        int manaLoc = line.find(": Mana = ");
        int damageLoc = line.find(", Damage = ");
        int HitPointsINCLoc = line.find(", HitPointsINC = ");
        int ArmorINCLoc = line.find(", ArmorINC = ");
        int ManaINCLoc = line.find(", ManaINC = ");
        int DurationLoc = line.find(", Duration = ");

        string key = line.substr(0, manaLoc);
        int mana = stoi(line.substr(manaLoc + 9, damageLoc - (manaLoc + 9) ));
        int damage = stoi(line.substr(damageLoc + 11, HitPointsINCLoc - (damageLoc + 11) ));
        int hitPointsINC = stoi(line.substr(HitPointsINCLoc + 17, ArmorINCLoc - (HitPointsINCLoc + 17) ));
        int armorINC = stoi(line.substr(ArmorINCLoc + 13, ManaINCLoc - (ArmorINCLoc + 13) ));
        int manaINC = stoi(line.substr(ManaINCLoc + 12, DurationLoc - (ManaINCLoc + 12) ));
        int duration = stoi(line.substr(DurationLoc + 13));

        tempMap.insert({key, make_tuple(mana, damage, hitPointsINC, armorINC, manaINC, duration)});
    };
    openFile.close();

    return tempMap;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string bossStatsPathName = "../../assets/input.txt";
    string spellListPathName = "../../assets/spells.txt";

    map<string, int> bossStatsPerm = inputParser(bossStatsPathName);
    map<string, tuple<int, int, int, int, int, int>> spellList = spellParser(spellListPathName);

    map<string, int> bossStats = bossStatsPerm;

    map<string, int> playerStatsPerm;
    playerStatsPerm.insert({"Hit Points", 50}); playerStatsPerm.insert({"Mana", 500}); playerStatsPerm.insert({"Armor", 0});
    map<string, int> playerStats = playerStatsPerm;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
