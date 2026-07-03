#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

vector<int> instructions(string inputString) {
    vector<int> coords;

    if (inputString.find("turn on") == 0) {
        inputString.replace(0, 8, "");
    } else if (inputString.find("turn off") == 0) {
        inputString.replace(0, 9, "");
    } else {
        inputString.replace(0, 7, "");
    };

    string currentCoord;
    for (char chr : inputString) {
        if (chr == ',') {
            coords.push_back(stoi(currentCoord));

            currentCoord.clear();
        } else {
            currentCoord += chr;
        };
    };

    coords.push_back(stoi(currentCoord));

    return coords;
};

int locationFinder(int iLoc, int jLoc, int desiredLength) {
    string iString = to_string(iLoc); string jString = to_string(jLoc);

    int location = stoi(iString.insert(0, desiredLength - iString.length(), '0') +
                        jString.insert(0, desiredLength - jString.length(), '0'));

    return location;
};

int main() {
    clock_t startTime, finishtime;
    startTime = clock();

    ////////////////////////////////////////

    string filepath = "../../assets/input.txt";
    ifstream openFile(filepath);

    vector<vector<int>> lights;

    for (int i = 0; i <= 999; i += 1) {
        for (int j = 0; j <= 999; j += 1) {
            vector<int> tempVect;
            tempVect.push_back(i); tempVect.push_back(j); tempVect.push_back(0);

            lights.push_back(tempVect);
        };
    };

    int desiredLength = 3;

    string line;

    while (getline(openFile, line)) {
        string fixedLine = line;
        fixedLine.replace(fixedLine.find(" through "), 9, ",");

        vector<int> tempVect = instructions(fixedLine);

        int x_1 = tempVect[0]; int y_1 = tempVect[1];
        int x_2 = tempVect[2]; int y_2 = tempVect[3];

        if (fixedLine.find("turn on") == 0) {
            for (int i = x_1; i <= x_2; i += 1) {
                for (int j = y_1; j <= y_2; j += 1) {
                    int location = locationFinder(i, j, desiredLength);

                    lights[location][2] = 1;
                };
            };
        } else if (fixedLine.find("turn off") == 0) {
            for (int i = x_1; i <= x_2; i += 1) {
                for (int j = y_1; j <= y_2; j += 1) {
                    int location = locationFinder(i, j, desiredLength);

                    lights[location][2] = 0;
                };
            };
        } else {
            for (int i = x_1; i <= x_2; i += 1) {
                for (int j = y_1; j <= y_2; j += 1) {
                    int location = locationFinder(i, j, desiredLength);

                    if (lights[location][2] == 1) {
                        lights[location][2] = 0;
                    } else {
                        lights[location][2] = 1;
                    };
                };
            };
        };
    };

    int onLights = 0;

    for (vector<int> vect : lights) {
        if (vect[2] == 1) {
            onLights += 1;
        };
    };

    cout << endl << "The number of lights that are turned on, is: " << onLights << endl;

    ////////////////////////////////////////

    finishtime = clock();

    double runtime = ((double)(finishtime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
