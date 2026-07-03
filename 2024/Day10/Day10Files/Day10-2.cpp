#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <set>

using namespace std;

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<string> topographicalMap;

    string line;
    while (getline(openFile, line)) {
        topographicalMap.push_back(line);
    };
    openFile.close();

    set<vector<int>> all0Locs; set<vector<int>> all1Locs; set<vector<int>> all2Locs;
    set<vector<int>> all3Locs; set<vector<int>> all4Locs; set<vector<int>> all5Locs;
    set<vector<int>> all6Locs; set<vector<int>> all7Locs; set<vector<int>> all8Locs;
    set<vector<int>> all9Locs;

    int totalTrails = 0;

    for (int rowNum = 0; rowNum < topographicalMap.size(); rowNum += 1) {
        for (int colNum = 0; colNum < topographicalMap[rowNum].length(); colNum += 1) {
            if (topographicalMap[rowNum][colNum] == '0') {
                all0Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '1') {
                all1Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '2') {
                all2Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '3') {
                all3Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '4') {
                all4Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '5') {
                all5Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '6') {
                all6Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '7') {
                all7Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '8') {
                all8Locs.insert({rowNum, colNum});
            } else if (topographicalMap[rowNum][colNum] == '9') {
                all9Locs.insert({rowNum, colNum});
            };
        };
    };

    for (vector<int> loc : all0Locs) {
        vector<vector<int>> tempLocs0 = {{loc[0] - 1, loc[1]}, {loc[0] + 1, loc[1]}, {loc[0], loc[1] - 1}, {loc[0], loc[1] + 1}};

        for (vector<int> tempLoc0 : tempLocs0) {
            if (all1Locs.contains(tempLoc0)) {
                vector<vector<int>> tempLocs1 = {{tempLoc0[0] - 1, tempLoc0[1]}, {tempLoc0[0] + 1, tempLoc0[1]}, {tempLoc0[0], tempLoc0[1] - 1}, {tempLoc0[0], tempLoc0[1] + 1}};

                for (vector<int> tempLoc1 : tempLocs1) {
                    if (all2Locs.contains(tempLoc1)) {
                        vector<vector<int>> tempLocs2 = {{tempLoc1[0] - 1, tempLoc1[1]}, {tempLoc1[0] + 1, tempLoc1[1]}, {tempLoc1[0], tempLoc1[1] - 1}, {tempLoc1[0], tempLoc1[1] + 1}};

                        for (vector<int> tempLoc2 : tempLocs2) {
                            if (all3Locs.contains(tempLoc2)) {
                                vector<vector<int>> tempLocs3 = {{tempLoc2[0] - 1, tempLoc2[1]}, {tempLoc2[0] + 1, tempLoc2[1]}, {tempLoc2[0], tempLoc2[1] - 1}, {tempLoc2[0], tempLoc2[1] + 1}};

                                for (vector<int> tempLoc3 : tempLocs3) {
                                    if (all4Locs.contains(tempLoc3)) {
                                        vector<vector<int>> tempLocs4 = {{tempLoc3[0] - 1, tempLoc3[1]}, {tempLoc3[0] + 1, tempLoc3[1]}, {tempLoc3[0], tempLoc3[1] - 1}, {tempLoc3[0], tempLoc3[1] + 1}};

                                        for (vector<int> tempLoc4 : tempLocs4) {
                                            if (all5Locs.contains(tempLoc4)) {
                                                vector<vector<int>> tempLocs5 = {{tempLoc4[0] - 1, tempLoc4[1]}, {tempLoc4[0] + 1, tempLoc4[1]}, {tempLoc4[0], tempLoc4[1] - 1}, {tempLoc4[0], tempLoc4[1] + 1}};

                                                for (vector<int> tempLoc5 : tempLocs5) {
                                                    if (all6Locs.contains(tempLoc5)) {
                                                        vector<vector<int>> tempLocs6 = {{tempLoc5[0] - 1, tempLoc5[1]}, {tempLoc5[0] + 1, tempLoc5[1]}, {tempLoc5[0], tempLoc5[1] - 1}, {tempLoc5[0], tempLoc5[1] + 1}};

                                                        for (vector<int> tempLoc6 : tempLocs6) {
                                                            if (all7Locs.contains(tempLoc6)) {
                                                                vector<vector<int>> tempLocs7 = {{tempLoc6[0] - 1, tempLoc6[1]}, {tempLoc6[0] + 1, tempLoc6[1]}, {tempLoc6[0], tempLoc6[1] - 1}, {tempLoc6[0], tempLoc6[1] + 1}};

                                                                for (vector<int> tempLoc7 : tempLocs7) {
                                                                    if (all8Locs.contains(tempLoc7)) {
                                                                        vector<vector<int>> tempLocs8 = {{tempLoc7[0] - 1, tempLoc7[1]}, {tempLoc7[0] + 1, tempLoc7[1]}, {tempLoc7[0], tempLoc7[1] - 1}, {tempLoc7[0], tempLoc7[1] + 1}};

                                                                        for (vector<int> tempLoc8 : tempLocs8) {
                                                                            if (all9Locs.contains(tempLoc8)) {
                                                                                totalTrails += 1;
                                                                            };
                                                                        };
                                                                    };
                                                                };
                                                            };
                                                        };
                                                    };
                                                };
                                            };
                                        };
                                    };
                                };
                            };
                        };
                    };
                };
            };
        };
    };

    cout << endl << "The total number of trails is: " << totalTrails << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
