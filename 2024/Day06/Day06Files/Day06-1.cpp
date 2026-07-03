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

    vector<string> guardPathLines;

    int rowIndex;
    int colIndex;

    int rowCounter = 0;

    string line;
    while (getline(openFile, line)) {
        if (line.find("^") != string::npos) {
            rowIndex = rowCounter;
            colIndex = line.find("^");
        };

        rowCounter += 1;
        guardPathLines.push_back(line);
    };
    openFile.close();

    vector<int> guardLoc = {rowIndex, colIndex};

    vector<bool> guardDirection = {true, false, false, false};

    while (true) {
        if (guardDirection[0]) {
            if (guardPathLines[guardLoc[0] - 1][guardLoc[1]] == '#') {
                guardDirection = {false, true, false, false};
            } else {
                guardPathLines[guardLoc[0]][guardLoc[1]] = 'X';
                guardLoc[0] -= 1;
            };
        } else if (guardDirection[1]) {
            if (guardPathLines[guardLoc[0]][guardLoc[1] + 1] == '#') {
                guardDirection = {false, false, true, false};
            } else {
                guardPathLines[guardLoc[0]][guardLoc[1]] = 'X';
                guardLoc[1] += 1;
            };
        } else if (guardDirection[2]) {
            if (guardPathLines[guardLoc[0] + 1][guardLoc[1]] == '#') {
                guardDirection = {false, false, false, true};
            } else {
                guardPathLines[guardLoc[0]][guardLoc[1]] = 'X';
                guardLoc[0] += 1;
            };
        } else if (guardDirection[3]) {
            if (guardPathLines[guardLoc[0]][guardLoc[1] - 1] == '#') {
                guardDirection = {true, false, false, false};
            } else {
                guardPathLines[guardLoc[0]][guardLoc[1]] = 'X';
                guardLoc[1] -= 1;
            };
        };

        if (guardLoc[0] < 0 or guardLoc[0] >= guardPathLines.size() or
            guardLoc[1] < 0 or guardLoc[1] >= guardPathLines[0].length()) {
            break;
        };
    };

    int uniqueLocations = 0;

    for (int rowNum = 0; rowNum < guardPathLines.size(); rowNum += 1) {
        for (int colNum = 0; colNum < guardPathLines[rowNum].length(); colNum += 1) {
            if (guardPathLines[rowNum][colNum] == 'X') {
                uniqueLocations += 1;
            };
        };
    };

    cout << endl << "The number of unique locations visited by the guard is: " << uniqueLocations << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
