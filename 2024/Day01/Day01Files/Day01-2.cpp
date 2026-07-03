#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <set>
#include <map>

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

    set<int> leftNumsSet;

    string line;
    while (getline(openFile, line)) {
        vector<int> tempVect = lineParser(line);

        leftNums.push_back(tempVect[0]);
        rightNums.push_back(tempVect[1]);

        leftNumsSet.insert(tempVect[0]);
    };
    openFile.close();

    map<int, int> leftNumsInRightVolume;

    for (int leftNum : leftNumsSet) {
        leftNumsInRightVolume[leftNum] = 0;

        for (int rightNum : rightNums) {
            if (leftNum == rightNum) {
                leftNumsInRightVolume[leftNum] += 1;
            };
        };
    };

    int ans = 0;

    for (int leftNum : leftNums) {
        ans += leftNum * leftNumsInRightVolume[leftNum];
    };

    cout << endl << "The similarity score is: " << ans << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
