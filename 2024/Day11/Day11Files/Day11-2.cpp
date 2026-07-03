#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <map>

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

map<pair<string, int>, long long> singleDigitRemainingCreator(string pathName) {
    map<pair<string, int>, long long> singleDigitRemaining;

    ifstream tempOpenFile(pathName);   

    string line;
    while (getline(tempOpenFile, line)) {
        int barLoc = line.find("|");
        int colonLoc = line.find(":");
        int dotLoc = line.find(".");

        string stoneVal = line.substr(0, barLoc);
        int noOfRemainingBlinks = stoi(line.substr(barLoc + 1, colonLoc - barLoc - 1));
        long long howManyWillBeAdded = stoll(line.substr(colonLoc + 1, dotLoc - colonLoc - 1));

        singleDigitRemaining[{stoneVal, noOfRemainingBlinks}] = howManyWillBeAdded;
    };
    tempOpenFile.close();

    return singleDigitRemaining;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathNameForSingleDigitRemaining = "../../assets/singleDigits0TO75.txt";

    map<pair<string, int>, long long> singleDigitRemaining = singleDigitRemainingCreator(pathNameForSingleDigitRemaining);

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";
    // string pathName = "../../assets/input3.txt";

    ifstream openFile(pathName);

    string startingStones;
    getline(openFile, startingStones);
    openFile.close();

    int currentBlinks = 0;

    vector<string> parsedStones = stoneParser(startingStones);
    vector<string> stones;

    for (string stone : parsedStones) {
        stones.push_back(stone);
    };

    long long ans = 0;
    
    // for (int tempStoneNum = 8793800; tempStoneNum <= 8793800; tempStoneNum += 1) {
    //     for (int goalBlinks = 75; goalBlinks <= 75; goalBlinks += 1) {
    //         stones.clear();
    //         stones.push_back(to_string(tempStoneNum));

            ans = 0;
            currentBlinks = 0;
            int goalBlinks = 75;

            while (currentBlinks < goalBlinks) {
                currentBlinks += 1;

                for (int stoneInd = 0; stoneInd < stones.size(); stoneInd += 1) {
                    if (singleDigitRemaining.contains({stones[stoneInd], goalBlinks - currentBlinks + 1})) {
                        ans += singleDigitRemaining[{stones[stoneInd], goalBlinks - currentBlinks + 1}];
                        stones.erase(stones.begin() + stoneInd);
                        stoneInd -= 1;
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

            ans += stones.size();

            cout << endl << "The answer is: " << ans << endl;

            // ofstream tempOpenFile(pathNameForSingleDigitRemaining, ios::app);

            // tempOpenFile << tempStoneNum << "|" << goalBlinks << ":" << ans << "." << endl;

            // tempOpenFile.close();
    //     };
    // };

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
};
