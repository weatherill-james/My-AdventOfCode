#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <set>
#include <map>

using namespace std;

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<pair<string, string>> elementReplacements;

    string startingChain;

    string line;
    while (getline(openFile, line)) {
        int arrowLoc = line.find(" => ");

        if (arrowLoc != string::npos) {
            string key = line.substr(0, arrowLoc);
            string value = line.substr(arrowLoc + 4);

            elementReplacements.push_back(pair(key, value));
        } else if (line.length() > 0) {
            startingChain = line;
        };
    };

    set<string> replacedChains;

    for (auto item : elementReplacements) {
        string key = item.first;
        string value = item.second;

        int keyLength = key.length();

        for (int i = 0; i < startingChain.length() - keyLength + 1; i += 1) {
            string newChain = startingChain;

            string tempSubstring = startingChain.substr(i, keyLength);

            if (tempSubstring == key) {
                newChain.replace(i, keyLength, value);

                replacedChains.insert(newChain);
            };
        };
    };

    cout << endl << "The number of possible replacements is: " << replacedChains.size() << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
