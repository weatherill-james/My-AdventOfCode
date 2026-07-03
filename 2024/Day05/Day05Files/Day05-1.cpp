#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <map>
#include <set>

using namespace std;

vector<int> chainsParser(string inputString) {
    vector<int> returnChain;
    string curNum = "";

    for (int i = 0; i < inputString.size(); i += 1) {
        if (inputString[i] == ',') {
            returnChain.push_back(stoi(curNum));
            curNum = "";
        } else {
            curNum += inputString[i];
        };
    };

    returnChain.push_back(stoi(curNum));

    return returnChain;
};

int middleNumFinder(vector<int> chain) {
    int middleIndex = chain.size() / 2;

    return chain[middleIndex];
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    map<int, set<int>> pageBeforePages;
    vector<vector<int>> chainsOfPages;

    string line;
    while (getline(openFile, line)) {
        int pipeLoc = line.find("|");
        int commaLoc = line.find(",");

        if (pipeLoc != string::npos) {
            int page = stoi(line.substr(0, pipeLoc));
            int afterPage = stoi(line.substr(pipeLoc + 1));

            pageBeforePages[page].insert(afterPage);
        } else if (commaLoc != string::npos) {
            chainsOfPages.push_back(chainsParser(line));
        };
    };

    vector<vector<int>> correctlyOrderedChains;

    for (vector<int> chain : chainsOfPages) {
        bool correctlyOrdered = true;

        for (int indexInChain = 0; indexInChain < chain.size() - 1; indexInChain += 1) {
            int keyNum = chain[indexInChain];
            int toFindNum = chain[indexInChain + 1];

            if (not pageBeforePages[keyNum].contains(toFindNum)) {
                correctlyOrdered = false;
                break;
            };
        };

        if (correctlyOrdered) {
            correctlyOrderedChains.push_back(chain);
        };
    };

    double middleNumberTotal = 0;

    for (vector<int> chain : correctlyOrderedChains) {
        middleNumberTotal += middleNumFinder(chain);
    };

    cout << endl << "The middle number total is: " << middleNumberTotal << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
