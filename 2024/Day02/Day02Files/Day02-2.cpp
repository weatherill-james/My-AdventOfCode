#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

bool isSafe(vector<int> inputVect) {
    bool safe = false;

    int inputVectSize = inputVect.size();

    bool growBool;
    if (inputVect[0] < inputVect[1]) {
        growBool = true;
    } else if (inputVect[0] > inputVect[1]) {
        growBool = false;
    } else {
        safe = false;
    };

    for (int i = 0; i < (inputVectSize - 1); i += 1) {
        int firstTempNum = inputVect[i];
        int secondTempNum = inputVect[i + 1];

        if (growBool) {
            if ( (firstTempNum + 1 == secondTempNum) or
                 (firstTempNum + 2 == secondTempNum) or
                 (firstTempNum + 3 == secondTempNum) ) {
                safe = true;
            } else {
                safe = false;
                break;
            };
        } else if (not growBool) {
            if ( (firstTempNum - 1 == secondTempNum) or
                 (firstTempNum - 2 == secondTempNum) or
                 (firstTempNum - 3 == secondTempNum) ) {
                safe = true;
            } else {
                safe = false;
                break;
            };
        };
    };

    if (safe) {
        return true;
    } else {
        return false;
    };
};

vector<int> lineParser(string inputLine) {
    vector<int> tempVect;
    string tempString;

    for (int i = 0; i < inputLine.size(); i += 1) {
        if (inputLine[i] == ' ' and tempString != "") {
            tempVect.push_back(stoi(tempString));
            tempString = "";
        } else {
            tempString += inputLine[i];
        };
    };

    tempVect.push_back(stoi(tempString));

    return tempVect;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    int safeCounter = 0;

    string line;
    while (getline(openFile, line)) {
        vector<int> tempVect = lineParser(line);

        int tempVectSize = tempVect.size();

        vector<vector<int>> iterationsVect;
        iterationsVect.push_back(tempVect);

        vector<int> tempVect2;

        for (int avoidIndex = 0; avoidIndex < tempVectSize; avoidIndex += 1) {
            for (int itemIndex = 0; itemIndex < tempVectSize; itemIndex += 1) {
                if (itemIndex != avoidIndex) {
                    tempVect2.push_back(tempVect[itemIndex]);
                };
            };

            iterationsVect.push_back(tempVect2);
            tempVect2.clear();
        };

        for (vector<int> lineVect : iterationsVect) {
            if (isSafe(lineVect)) {
                safeCounter += 1;
                break;
            };
        };
    };

    cout << endl << "The number of safe lines is: " << safeCounter << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
