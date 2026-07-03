#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <set>
#include <map>

using namespace std;

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string filePath = "../../assets/input.txt";
    // string filePath = "../../assets/input2.txt";

    ifstream openFile(filePath);

    map<string, int> distancesMap;

    vector<pair<string, int>> pathwaysVector;

    set<string> placesSet;

    string line;
    while (getline(openFile, line)) {
        int lineLength = line.length();

        int TOLoc = line.find(" to ");
        int EQUALSLoc = line.find(" = ");

        int distanceLength = lineLength - (EQUALSLoc + 3);

        int place1Length = TOLoc;
        int place2Length = EQUALSLoc - (TOLoc + 4);

        int distance = stoi(line.substr(EQUALSLoc + 3, distanceLength));

        string place1 = line.substr(0, place1Length);
        string place2 = line.substr(TOLoc + 4, place2Length);

        distancesMap.insert({place1 + place2, distance});
        distancesMap.insert({place2 + place1, distance});

        placesSet.insert(place1); placesSet.insert(place2);
    };

    vector<string> placesVector(placesSet.begin(), placesSet.end());

    do {
        string tempString = "";

        for (string str : placesVector) {
            tempString += str;
        };

        pathwaysVector.push_back({tempString, 0});
    } while (next_permutation(placesVector.begin(), placesVector.end()));

    for (auto locationsDistance : distancesMap) {
        for (int i = 0; i < pathwaysVector.size(); i += 1) {
             int fullPathwayFirstLength = (pathwaysVector[i].first).length();

            auto subPathInFullPath = (pathwaysVector[i].first).find(locationsDistance.first);

            if ((subPathInFullPath < fullPathwayFirstLength) and subPathInFullPath >= 0) {
                pathwaysVector[i].second += locationsDistance.second;
            };
        };
    };

    int longestDistance = 0;

    for (auto item : pathwaysVector) {
        if (item.second > longestDistance) {
            longestDistance = item.second;
        };
    };

    cout << endl << "The shortest distance is: " << longestDistance << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
};
