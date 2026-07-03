#include <iostream>
#include <numeric>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <time.h>

using namespace std;

vector<int> rotateVector(vector<int> inputVector, int numberOfRotations) {
    vector<int> rotatedVector = inputVector;

    for (int i = 0; i < numberOfRotations; i += 1) {
        int tempInt = rotatedVector[0];
        rotatedVector.erase(rotatedVector.begin());
        rotatedVector.push_back(tempInt);
    };

    return rotatedVector;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    int goal = 150;
    vector<int> containerSizes;

    string line;
    while (getline(openFile, line)) {
        containerSizes.push_back(stoi(line));
    };
    openFile.close();

    int numberOfContainers = containerSizes.size();

    vector<string> binaryNums;
    for (int i = 0; i < pow(2, numberOfContainers); i += 1) {
        string binaryNum = (bitset<32>(i).to_string()).substr(32 - numberOfContainers, numberOfContainers);
        binaryNums.push_back(binaryNum);
    };

    int validCombinations = 0;
    for (string binString : binaryNums) {
        int sum = 0;

        for (int i = 0; i < binString.size(); i += 1) {
            if (binString[i] == '1') {
                sum += containerSizes[i];
            };
        };

        if (sum == goal) {
            validCombinations += 1;
        };
    };

    cout << endl << "The number of valid combinations is: " << validCombinations << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;
}
