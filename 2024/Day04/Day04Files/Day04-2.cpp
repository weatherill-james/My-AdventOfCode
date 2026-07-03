#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

bool upAndLeft(vector<string> inputVect, int colNum, int rowNum) {
    if (inputVect[rowNum + 1][colNum + 1] == 'M' and inputVect[rowNum - 1][colNum - 1] == 'S') {
        return true;
    } else {
        return false;
    };
};

bool upAndRight(vector<string> inputVect, int colNum, int rowNum) {
    if (inputVect[rowNum + 1][colNum - 1] == 'M' and inputVect[rowNum - 1][colNum + 1] == 'S') {
        return true;
    } else {
        return false;
    };
};

bool downAndLeft(vector<string> inputVect, int colNum, int rowNum) {
    if (inputVect[rowNum - 1][colNum + 1] == 'M' and inputVect[rowNum + 1][colNum - 1] == 'S') {
        return true;
    } else {
        return false;
    };
};

bool downAndRight(vector<string> inputVect, int colNum, int rowNum) {
    if (inputVect[rowNum - 1][colNum - 1] == 'M' and inputVect[rowNum + 1][colNum + 1] == 'S') {
        return true;
    } else {
        return false;
    };
};

int numberOfCROSSMAS(vector<string> inputVect, int colNum, int rowNum) {
    int CROSSMASCounter = 0;

    if (colNum >= 1 and colNum < inputVect[rowNum].length() - 1 and rowNum >= 1 and rowNum < inputVect.size() - 1) {
        upAndLeft(inputVect, colNum, rowNum) ? CROSSMASCounter += 1 : CROSSMASCounter += 0;
        upAndRight(inputVect, colNum, rowNum) ? CROSSMASCounter += 1 : CROSSMASCounter += 0;
        downAndLeft(inputVect, colNum, rowNum) ? CROSSMASCounter += 1 : CROSSMASCounter += 0;
        downAndRight(inputVect, colNum, rowNum) ? CROSSMASCounter += 1 : CROSSMASCounter += 0;
    };

    return CROSSMASCounter;
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

    int totalCROSSMAS = 0;

    for (int rowNum = 0; rowNum < wordSearchLines.size(); rowNum += 1) {
        for (int colNum = 0; colNum < wordSearchLines[rowNum].length(); colNum += 1) {
            if (wordSearchLines[rowNum][colNum] == 'A') {
                int CROSSMASValue = numberOfCROSSMAS(wordSearchLines, colNum, rowNum);

                if (CROSSMASValue == 2) {
                    totalCROSSMAS += 1;
                };
            };
        };
    };

    cout << endl << "The total number of cross-shaped 'MAS's found is: " << totalCROSSMAS << endl;

    ////////////////////////////////////////

    finishTime = clock();
    
    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
