#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<int> permGuardStartingLoc;
    vector<string> permGuardPathLines;

    int rowCounter = 0;

    string line;
    while (getline(openFile, line)) {
        if (line.find("^") != string::npos) {
            int rowIndex = rowCounter;
            int colIndex = line.find("^");

            permGuardStartingLoc = {rowIndex, colIndex};
        };

        rowCounter += 1;
        permGuardPathLines.push_back(line);
    };
    openFile.close();

    permGuardPathLines[permGuardStartingLoc[0]][permGuardStartingLoc[1]] = 'X';

    vector<bool> permGuardDirection = {true, false, false, false};

    vector<string> tempGuardPathLines;
    vector<bool> tempGuardDirection;
    vector<int> tempGuardLoc;

    int succesfulPoints = 0;

    for (int rowNum = 0; rowNum < permGuardPathLines.size(); rowNum += 1) {
        for (int colNum = 0; colNum < permGuardPathLines[rowNum].length(); colNum += 1) {
            int tempCounter = 0;

            tempGuardPathLines = permGuardPathLines;
            tempGuardDirection = permGuardDirection;
            tempGuardLoc = permGuardStartingLoc;

            if (tempGuardPathLines[rowNum][colNum] == '.') {
                tempGuardPathLines[rowNum][colNum] = '#';

                while (true) {
                    if (tempGuardDirection[0]) {
                        if (tempGuardPathLines[tempGuardLoc[0] - 1][tempGuardLoc[1]] == '#') {
                            tempGuardDirection = {false, true, false, false};
                        } else {
                            tempGuardLoc[0] -= 1;
                            tempCounter += 1;
                        };
                    } else if (tempGuardDirection[1]) {
                        if (tempGuardPathLines[tempGuardLoc[0]][tempGuardLoc[1] + 1] == '#') {
                            tempGuardDirection = {false, false, true, false};
                        } else {
                            tempGuardLoc[1] += 1;
                            tempCounter += 1;
                        };
                    } else if (tempGuardDirection[2]) {
                        if (tempGuardPathLines[tempGuardLoc[0] + 1][tempGuardLoc[1]] == '#') {
                            tempGuardDirection = {false, false, false, true};
                        } else {
                            tempGuardLoc[0] += 1;
                            tempCounter += 1;
                        };
                    } else if (tempGuardDirection[3]) {
                        if (tempGuardPathLines[tempGuardLoc[0]][tempGuardLoc[1] - 1] == '#') {
                            tempGuardDirection = {true, false, false, false};
                        } else {
                            tempGuardLoc[1] -= 1;
                            tempCounter += 1;
                        };
                    };

                    if (tempGuardLoc[0] == 0 or tempGuardLoc[0] == tempGuardPathLines.size() - 1 or
                        tempGuardLoc[1] == 0 or tempGuardLoc[1] == tempGuardPathLines[tempGuardLoc[0]].length() - 1) {
                        break;
                    };

                    if (tempCounter == 10000) {
                        succesfulPoints += 1;
                        break;
                    };
                };
            };
        };
    };

    cout << endl << "The number of successful points is: " << succesfulPoints << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
