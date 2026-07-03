#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

bool upAndLeft(vector<string> inputVect, int colNum, int rowNum) {
    if (rowNum - 1 >= 0 and colNum - 1 >= 0 and inputVect[rowNum - 1][colNum - 1] == 'M') {
        if (rowNum - 2 >= 0 and colNum - 2 >= 0 and inputVect[rowNum - 2][colNum - 2] == 'A') {
            if (rowNum - 3 >= 0 and colNum - 3 >= 0 and inputVect[rowNum - 3][colNum - 3] == 'S') {
                return true;
            } else {
                return false;
            };
        } else {
            return false;
        };
    } else {
        return false;
    };
};

bool up(vector<string> inputVect, int colNum, int rowNum) {
    if (rowNum - 1 >= 0 and inputVect[rowNum - 1][colNum] == 'M') {
        if (rowNum - 2 >= 0 and inputVect[rowNum - 2][colNum] == 'A') {
            if (rowNum - 3 >= 0 and inputVect[rowNum - 3][colNum] == 'S') {
                return true;
            } else {
                return false;
            };
        } else {
            return false;
        };
    } else {
        return false;
    };
};

bool upAndRight(vector<string> inputVect, int colNum, int rowNum) {
    if (rowNum - 1 >= 0 and colNum + 1 < inputVect[rowNum].length() and inputVect[rowNum - 1][colNum + 1] == 'M') {
        if (rowNum - 2 >= 0 and colNum + 2 < inputVect[rowNum].length() and inputVect[rowNum - 2][colNum + 2] == 'A') {
            if (rowNum - 3 >= 0 and colNum + 3 < inputVect[rowNum].length() and inputVect[rowNum - 3][colNum + 3] == 'S') {
                return true;
            } else {
                return false;
            };
        } else {
            return false;
        };
    } else {
        return false;
    };
};

bool left(vector<string> inputVect, int colNum, int rowNum) {
    if (colNum - 1 >= 0 and inputVect[rowNum][colNum - 1] == 'M') {
        if (colNum - 2 >= 0 and inputVect[rowNum][colNum - 2] == 'A') {
            if (colNum - 3 >= 0 and inputVect[rowNum][colNum - 3] == 'S') {
                return true;
            } else {
                return false;
            };
        } else {
            return false;
        };
    } else {
        return false;
    };
};

bool right(vector<string> inputVect, int colNum, int rowNum) {
    if (colNum + 1 < inputVect[rowNum].length() and inputVect[rowNum][colNum + 1] == 'M') {
        if (colNum + 2 < inputVect[rowNum].length() and inputVect[rowNum][colNum + 2] == 'A') {
            if (colNum + 3 < inputVect[rowNum].length() and inputVect[rowNum][colNum + 3] == 'S') {
                return true;
            } else {
                return false;
            };
        } else {
            return false;
        };
    } else {
        return false;
    };
};

bool downAndLeft(vector<string> inputVect, int colNum, int rowNum) {
    if (rowNum + 1 < inputVect.size() and colNum - 1 >= 0 and inputVect[rowNum + 1][colNum - 1] == 'M') {
        if (rowNum + 2 < inputVect.size() and colNum - 2 >= 0 and inputVect[rowNum + 2][colNum - 2] == 'A') {
            if (rowNum + 3 < inputVect.size() and colNum - 3 >= 0 and inputVect[rowNum + 3][colNum - 3] == 'S') {
                return true;
            } else {
                return false;
            };
        } else {
            return false;
        };
    } else {
        return false;
    };
};

bool down(vector<string> inputVect, int colNum, int rowNum) {
    if (rowNum + 1 < inputVect.size() and inputVect[rowNum + 1][colNum] == 'M') {
        if (rowNum + 2 < inputVect.size() and inputVect[rowNum + 2][colNum] == 'A') {
            if (rowNum + 3 < inputVect.size() and inputVect[rowNum + 3][colNum] == 'S') {
                return true;
            } else {
                return false;
            };
        } else {
            return false;
        };
    } else {
        return false;
    };
};

bool downAndRight(vector<string> inputVect, int colNum, int rowNum) {
    if (rowNum + 1 < inputVect.size() and colNum + 1 < inputVect[rowNum].length() and inputVect[rowNum + 1][colNum + 1] == 'M') {
        if (rowNum + 2 < inputVect.size() and colNum + 2 < inputVect[rowNum].length() and inputVect[rowNum + 2][colNum + 2] == 'A') {
            if (rowNum + 3 < inputVect.size() and colNum + 3 < inputVect[rowNum].length() and inputVect[rowNum + 3][colNum + 3] == 'S') {
                return true;
            } else {
                return false;
            };
        } else {
            return false;
        };
    } else {
        return false;
    };
};

int numberOfXMAS(vector<string> inputVect, int colNum, int rowNum) {
    int XMASCounter = 0;

    upAndLeft(inputVect, colNum, rowNum) ? XMASCounter += 1 : XMASCounter += 0;
    up(inputVect, colNum, rowNum) ? XMASCounter += 1 : XMASCounter += 0;
    upAndRight(inputVect, colNum, rowNum) ? XMASCounter += 1 : XMASCounter += 0;
    left(inputVect, colNum, rowNum) ? XMASCounter += 1 : XMASCounter += 0;
    right(inputVect, colNum, rowNum) ? XMASCounter += 1 : XMASCounter += 0;
    downAndLeft(inputVect, colNum, rowNum) ? XMASCounter += 1 : XMASCounter += 0;
    down(inputVect, colNum, rowNum) ? XMASCounter += 1 : XMASCounter += 0;
    downAndRight(inputVect, colNum, rowNum) ? XMASCounter += 1 : XMASCounter += 0;

    return XMASCounter;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<string> wordSearchLines;

    string line;
    while (getline(openFile, line)) {
        wordSearchLines.push_back(line);
    };
    openFile.close();

    int totalXMAS = 0;

    for (int rowNum = 0; rowNum < wordSearchLines.size(); rowNum += 1) {
        for (int colNum = 0; colNum < wordSearchLines[rowNum].length(); colNum += 1) {
            if (wordSearchLines[rowNum][colNum] == 'X') {
                int xmasValue = numberOfXMAS(wordSearchLines, colNum, rowNum);

                totalXMAS += xmasValue;
            };
        };
    };

    cout << endl << "The total number of XMAS found is: " << totalXMAS << endl;

    ////////////////////////////////////////

    finishTime = clock();
    
    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
