#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <tuple>
#include <map>

using namespace std;

pair< vector<tuple<string, int, int>>, map<int, bool>> stringBreakdown(string diskMapString) {
    vector<tuple<string, int, int>> brokenDownString;
    map<int, bool> idMapYesNo;

    int idNum = 0;
    for (int i = 0; i < diskMapString.size(); i += 1) {
        if (i % 2 == 0) {
            brokenDownString.push_back(make_tuple("num", idNum, stoi(diskMapString.substr(i, 1))));
            idMapYesNo[idNum] = true;
            idNum += 1;
        } else {
            brokenDownString.push_back(make_tuple("dot", -1, stoi(diskMapString.substr(i, 1))));
        };
    };

    return {brokenDownString, idMapYesNo};
};

vector<tuple<string, int, int>> sortVector(vector<tuple<string, int, int>> inputVector, map<int, bool> idMapYesNo) {
    bool replace = true;
    bool join;

    while (replace) {
        join = true;

        while (join) {
            join = false;

            for (int i = 0; i < inputVector.size() - 1; i += 1) {
                if (get<0>(inputVector[i]) == "dot" and get<0>(inputVector[i + 1]) == "dot") {
                    tuple<string, int, int> tempTuple = {"dot", -1, get<2>(inputVector[i]) + get<2>(inputVector[i + 1])};
                    inputVector[i] = tempTuple;
                    inputVector.erase(inputVector.begin() + i + 1);

                    join = true;
                };

                if (join) {
                    break;
                };
            };
        };

        replace = false;

        for (int i = inputVector.size() - 1; i >= 0; i -= 1) {
            if (get<0>(inputVector[i]) == "num" and idMapYesNo[get<1>(inputVector[i])]) {
                idMapYesNo[get<1>(inputVector[i])] = false;

                for (int j = 0; j < i; j += 1) {
                    if (get<0>(inputVector[j]) == "dot" and get<2>(inputVector[j]) >= get<2>(inputVector[i])) {
                        tuple<string, int, int> firstTuple = {"num", get<1>(inputVector[i]), get<2>(inputVector[i])};
                        tuple<string, int, int> secondTuple = {"dot", -1, get<2>(inputVector[j]) - get<2>(inputVector[i])};
                        tuple<string, int, int> endTuple = {"dot", -1, get<2>(inputVector[i])};

                        inputVector[j] = secondTuple;
                        inputVector.insert(inputVector.begin() + j, firstTuple);
                        inputVector[i + 1] = endTuple;

                        replace = true;
                        break;
                    };
                };
            };

            if (replace) {
                break;
            };
        };
    };

    return inputVector;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    string diskMapString;
    getline(openFile, diskMapString);
    openFile.close();

    pair< vector<tuple<string, int, int>>, map<int, bool> > brokenDownStringAndMap = stringBreakdown(diskMapString);

    vector<tuple<string, int, int>> brokenDownString = brokenDownStringAndMap.first;
    map<int, bool> idMapYesNo = brokenDownStringAndMap.second;

    vector<tuple<string, int, int>> sortedVector = sortVector(brokenDownString, idMapYesNo);

    string ansString = "";

    int stringLengthCalc = 0;

    int multiplier = 0;

    long long ans = 0;

    for (int i = 0; i < sortedVector.size(); i += 1) {
        stringLengthCalc += get<2>(sortedVector[i]);

        if (get<0>(sortedVector[i]) == "num") {
            for (int j = 0; j < get<2>(sortedVector[i]); j += 1) {
                ans += (multiplier * get<1>(sortedVector[i]));
                multiplier += 1;
            };
        } else {
            for (int j = 0; j < get<2>(sortedVector[i]); j += 1) {
                multiplier += 1;
            };
        };
    };

    cout << endl << "The check sum is: " <<  ans << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
