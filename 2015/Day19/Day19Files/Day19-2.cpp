#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

using namespace std;

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<pair<string, string>> elementReplacements;

    string finalChain;

    string line;
    while (getline(openFile, line)) {
        int arrowLoc = line.find(" => ");

        if (arrowLoc != string::npos) {
            string key = line.substr(arrowLoc + 4);
            string value = line.substr(0, arrowLoc);

            elementReplacements.push_back(pair(key, value));
        } else if (line.length() > 0) {
            finalChain = line;
        };
    };

    string originalFinalChain = finalChain;

    int counter = 0;

    while (true) {
        int finalChainLength = finalChain.length();

        bool leave = false;

        for (auto item : elementReplacements) {
            string key = item.first;
            string value = item.second;

            int keyLength = key.length();

            for (int i = 0; i < finalChainLength - keyLength + 1; i += 1) {
                string tempSubstring = finalChain.substr(i, keyLength);

                if (tempSubstring == key) {
                    finalChain.replace(i, keyLength, value);

                    counter += 1;

                    leave = true;

                    break;
                };
            };

            if (leave) {
                break;
            };
        };

        if (not leave) {
            counter = 0;

            finalChain = originalFinalChain;

            shuffle(elementReplacements.begin(), elementReplacements.end(), default_random_engine(time(0)));
        } else if (finalChain == "e") {
            break;
        };
    };

    cout << endl << "The number of steps to get to 'e', from the starting chain is: " << counter << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
