#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <map>
#include <set>

using namespace std;

string name1Finder(string inputString) {
    int wouldLoc = inputString.find(" would ");

    string returnString = inputString.substr(0, wouldLoc);

    return returnString;
};

string name2Finder(string inputString) {
    int toLoc = inputString.find(" to ");
    int fullStopLoc = inputString.find(".");

    int returnStringLength = fullStopLoc - (toLoc + 4);

    string returnString = inputString.substr(toLoc + 4, returnStringLength);

    return returnString;
};

int happinessGainedFinder(string inputString) {
    int inputStringLength = inputString.length();

    bool isGain;

    int gainOrLoseLoc;

    auto gainLoc = inputString.find(" gain ");
    if (gainLoc < 0 or gainLoc > inputStringLength) {
        isGain = false;

        gainOrLoseLoc = inputString.find(" lose ");
    } else {
        isGain = true;

        gainOrLoseLoc = gainLoc;
    };

    int happinessLoc = inputString.find(" happiness ");

    int returnIntLength = happinessLoc - (gainOrLoseLoc + 6);

    int returnInt = stoi(inputString.substr(gainOrLoseLoc + 6, returnIntLength));

    if (isGain) {
        return returnInt;
    } else {
        return ((-1) * returnInt);
    };
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    map<string, int> totalHappinessMap;
    map<string, int> happinessPairsMap;

    set<string> namesSet;

    string line;
    while(getline(openFile, line)) {
        string name1 = name1Finder(line);
        string name2 = name2Finder(line);

        int happinessGained = happinessGainedFinder(line);

        namesSet.insert(name1);

        happinessPairsMap.insert({name1 + name2, happinessGained});
    };

    vector<string> namesVector(namesSet.begin(), namesSet.end());

    do {
        string tempString = "";

        for (string name : namesVector) {
            tempString += name;
        };

        tempString += namesVector[0];

        reverse(namesVector.begin(), namesVector.end());

        for (string name : namesVector) {
            tempString += name;
        };

        reverse(namesVector.begin(), namesVector.end());

        totalHappinessMap.insert({tempString, 0});
    } while (next_permutation(namesVector.begin(), namesVector.end()));

    for (auto group1 : happinessPairsMap) {
        for (auto group2 : totalHappinessMap) {
            int group2FirstLength = (group2.first).length();

            auto group2FindGroup1 = (group2.first).find(group1.first);

            if (group2FindGroup1 >= 0 and group2FindGroup1 < group2FirstLength) {
                totalHappinessMap[group2.first] += group1.second;
            };
        };
    };

    string matchingOrder;
    int highestHappiness;

    for (auto group : totalHappinessMap) {
        if (group.second > highestHappiness) {
            matchingOrder = group.first;
            highestHappiness = group.second;
        };
    };

    cout << endl <<
    "The order:" << endl <<
    matchingOrder << "," << endl <<
    "has total happiness: " << highestHappiness << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
