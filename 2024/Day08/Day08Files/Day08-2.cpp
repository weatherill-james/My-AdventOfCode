#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <set>

using namespace std;

vector<vector<int>> antiNodeLoc(vector<string> antennaMap, char antennaID, int OGAntennaRow, int OGAntennaCol) {
    vector<vector<int>> antiNodeLocs;

    for (int rowNum = 0; rowNum < antennaMap.size(); rowNum += 1) {
        for (int colNum = 0; colNum < antennaMap[rowNum].size(); colNum += 1) {
            if (antennaMap[rowNum][colNum] == antennaID and (OGAntennaRow != rowNum or OGAntennaCol != colNum)) {
                antiNodeLocs.push_back({rowNum, colNum}); antiNodeLocs.push_back({OGAntennaRow, OGAntennaCol});
                if (rowNum > OGAntennaRow and colNum > OGAntennaCol) {
                    int rowDiff = abs(rowNum - OGAntennaRow);
                    int colDiff = abs(colNum - OGAntennaCol);

                    int antiNodeRow = rowNum + rowDiff;
                    int antiNodeCol = colNum + colDiff;

                    while (true) {
                        if (antiNodeRow < antennaMap.size() and antiNodeCol < antennaMap[rowNum].size()) {
                            antiNodeLocs.push_back({antiNodeRow, antiNodeCol});
                        } else {
                            break;
                        };

                        antiNodeRow += rowDiff;
                        antiNodeCol += colDiff;
                    };

                } else if (rowNum > OGAntennaRow and colNum < OGAntennaCol) {
                    int rowDiff = abs(rowNum - OGAntennaRow);
                    int colDiff = abs(colNum - OGAntennaCol);

                    int antiNodeRow = rowNum + rowDiff;
                    int antiNodeCol = colNum - colDiff;

                    while (true) {
                        if (antiNodeRow < antennaMap.size() and antiNodeCol >= 0) {
                            antiNodeLocs.push_back({antiNodeRow, antiNodeCol});
                        } else {
                            break;
                        };

                        antiNodeRow += rowDiff;
                        antiNodeCol -= colDiff;
                    };
                } else if (rowNum < OGAntennaRow and colNum > OGAntennaCol) {
                    int rowDiff = abs(rowNum - OGAntennaRow);
                    int colDiff = abs(colNum - OGAntennaCol);

                    int antiNodeRow = rowNum - rowDiff;
                    int antiNodeCol = colNum + colDiff;

                    while (true) {
                        if (antiNodeRow >= 0 and antiNodeCol < antennaMap[rowNum].length()) {
                            antiNodeLocs.push_back({antiNodeRow, antiNodeCol});
                        } else {
                            break;
                        };

                        antiNodeRow -= rowDiff;
                        antiNodeCol += colDiff;
                    };
                } else if (rowNum < OGAntennaRow and colNum < OGAntennaCol) {
                    int rowDiff = abs(rowNum - OGAntennaRow);
                    int colDiff = abs(colNum - OGAntennaCol);

                    int antiNodeRow = rowNum - rowDiff;
                    int antiNodeCol = colNum - colDiff;

                    while (true) {
                        if (antiNodeRow >= 0 and antiNodeCol >= 0) {
                            antiNodeLocs.push_back({antiNodeRow, antiNodeCol});
                        } else {
                            break;
                        };

                        antiNodeRow -= rowDiff;
                        antiNodeCol -= colDiff;
                    };
                } else if (rowNum == OGAntennaRow and colNum > OGAntennaRow) {
                    int colDiff = abs(colNum - OGAntennaCol);

                    int antiNodeRow = rowNum;
                    int antiNodeCol = colNum + colDiff;

                    while (true) {
                        if (antiNodeCol < antennaMap[rowNum].length()) {
                            antiNodeLocs.push_back({antiNodeRow, antiNodeCol});
                        } else {
                            break;
                        };

                        antiNodeCol += colDiff;
                    };
                } else if (rowNum == OGAntennaRow and colNum < OGAntennaRow) {
                    int colDiff = abs(colNum - OGAntennaCol);

                    int antiNodeRow = rowNum;
                    int antiNodeCol = colNum - colDiff;

                    while (true) {
                        if (antiNodeCol >= 0) {
                            antiNodeLocs.push_back({antiNodeRow, antiNodeCol});
                        } else {
                            break;
                        };

                        antiNodeCol -= colDiff;
                    };
                } else if (rowNum > OGAntennaRow and colNum == OGAntennaRow) {
                    int rowDiff = abs(rowNum - OGAntennaRow);

                    int antiNodeRow = rowNum + rowDiff;
                    int antiNodeCol = colNum;

                    while (true) {
                        if (antiNodeRow < antennaMap.size()) {
                            antiNodeLocs.push_back({antiNodeRow, antiNodeCol});
                        } else {
                            break;
                        };

                        antiNodeRow += rowDiff;
                    };
                } else if (rowNum < OGAntennaRow and colNum == OGAntennaRow) {
                    int rowDiff = abs(rowNum - OGAntennaRow);

                    int antiNodeRow = rowNum - rowDiff;
                    int antiNodeCol = colNum;

                    while (true) {
                        if (antiNodeRow >= 0) {
                            antiNodeLocs.push_back({antiNodeRow, antiNodeCol});
                        } else {
                            break;
                        };

                        antiNodeRow -= rowDiff;
                    };
                };
            };
        };
    };

    return antiNodeLocs;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<string> mapOfAntennas;

    string line;
    while (getline(openFile, line)) {
        mapOfAntennas.push_back(line);
    };
    openFile.close();

    set<vector<int>> allNodeLocs;

    for (int rowNum = 0; rowNum < mapOfAntennas.size(); rowNum += 1) {
        for (int colNum = 0; colNum < mapOfAntennas[rowNum].size(); colNum += 1) {
            if (mapOfAntennas[rowNum][colNum] != '.') {
                vector<vector<int>> antiNodeLocs = antiNodeLoc(mapOfAntennas, mapOfAntennas[rowNum][colNum], rowNum, colNum);

                for (vector<int> antiNodeLoc : antiNodeLocs) {
                    allNodeLocs.insert(antiNodeLoc);
                };
            };
        };
    };

    cout << endl << "The number of unique nodes is: " << allNodeLocs.size() << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
