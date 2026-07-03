#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

vector<int> lineParser(string line) {
    vector<int> returnVect;
    string number = "";

    int lineLength = line.length();

    for (int i = 0; i < lineLength; i += 1) {
        if (line[i] == ' ' and number != "") {
            returnVect.push_back(stoi(number));
            number = "";
        } else if (line[i] != ' ') {
            number += line[i];
        };
    };

    returnVect.push_back(stoi(number));

    return returnVect;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<int> leftNums;
    vector<int> rightNums;

    string line;
    while (getline(openFile, line)) {
        vector<int> tempVect = lineParser(line);

        leftNums.push_back(tempVect[0]);
        rightNums.push_back(tempVect[1]);
    };
    openFile.close();

    sort(leftNums.begin(), leftNums.end());
    sort(rightNums.begin(), rightNums.end());

    int leftAndRightSize = leftNums.size();

    vector<int> differenceVect;

    for (int i = 0; i < leftAndRightSize; i += 1) {
        differenceVect.push_back(abs(rightNums[i] - leftNums[i]));
    };

    int differenceVectorSum = accumulate(differenceVect.begin(), differenceVect.end(), 0);

    cout << endl << "The sum of the differences is: " << differenceVectorSum << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
