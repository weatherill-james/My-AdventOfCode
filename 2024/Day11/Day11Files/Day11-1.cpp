#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

vector<string> stoneParser(string startingStones) {
    vector<string> stones;

    string tempStone = "";

    for (int i = 0; i < startingStones.length(); i += 1) {
        if (startingStones[i] == ' ' and tempStone != "") {
            stones.push_back(tempStone);
            tempStone = "";
        } else {
            tempStone += startingStones[i];
        };
    };

    stones.push_back(tempStone);

    return stones;
};

string stringMultiplier(string num1, string num2) {
    vector<int> ansAsVect(num1.length() + num2.length(), 0);

    string num1Reversed = string(num1.rbegin(), num1.rend());
    string num2Reversed = string(num2.rbegin(), num2.rend());

    for (int i = 0; i < num1Reversed.length(); i += 1) {
        for (int j = 0; j < num2Reversed.length(); j += 1) {
            ansAsVect[i + j] += (num1Reversed[i] - '0') * (num2Reversed[j] - '0');
            ansAsVect[i + j + 1] += ansAsVect[i + j] / 10;
            ansAsVect[i + j] %= 10;
        };
    };

    string ansString = "";

    for (int i = ansAsVect.size() - 1; i >= 0; i -= 1) {
        if (ansAsVect[i] == 0 and ansString == "") {
            continue;
        } else {
            ansString += to_string(ansAsVect[i]);
        };
    };

    return ansString;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    string startingStones;
    getline(openFile, startingStones);
    openFile.close();

    int currentBlinks = 0;
    int goalBlinks = 25;

    vector<string> parsedStones = stoneParser(startingStones);
    vector<string> stones;

    for (string stone : parsedStones) {
        stones.push_back(stone);
    };

    while (currentBlinks < goalBlinks) {
        currentBlinks += 1;

        for (int stoneInd = 0; stoneInd < stones.size(); stoneInd += 1) {
            if (stones[stoneInd] == "0") {
                stones[stoneInd] = "1";
            } else if (stones[stoneInd].length() % 2 == 0) {;
                string firstStone = stones[stoneInd].substr(0, stones[stoneInd].length() / 2);
                string secondStone = stones[stoneInd].substr(stones[stoneInd].length() / 2);

                while (secondStone[0] == '0') {
                    if (secondStone.length() == 1) {
                        break;
                    } else {
                        secondStone = secondStone.substr(1);
                    };
                };

                stones[stoneInd] = secondStone;
                stones.insert(stones.begin() + stoneInd, firstStone);

                stoneInd += 1;
            } else {
                stones[stoneInd] = stringMultiplier(stones[stoneInd], "2024");
            };
        };
    };

    cout << endl << "The number of stones, after " << goalBlinks << " blinks, is: " << stones.size() << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
};
