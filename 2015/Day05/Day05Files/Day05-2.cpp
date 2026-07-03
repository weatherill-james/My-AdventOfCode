#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

bool overlappingPairs(string inputString) {
    int stringLength = inputString.length();

    string currentPair;
    string tempPair;

    for (int i = 0; i < (stringLength - 3); i += 1) {
        int tempCounter = 0;

        for (int j = (i + 2); j < (stringLength - 1); j += 1) {
            if (inputString[i] == inputString[j] and inputString[i + 1] == inputString[j + 1]) {
                return true;
            };
        };
    };

    return false;
};

bool doubleLetter(string inputString) {
    int stringLength = inputString.length();

    for (int i = 0; i < (stringLength - 2); i += 1) {
        if (inputString[i] == inputString[i + 2]) {
            return true;
        };
    };

    return false;
};

int main() {
    clock_t startTime, finishTime;
    startTime = clock();

    ////////////////////////////////////////

    string pathname = "../../assets/input.txt";
    ifstream openFile(pathname);

    int niceStrings = 0;

    string line;
    while (getline(openFile, line)) {
        if (overlappingPairs(line) and doubleLetter(line)) {
            niceStrings += 1;
        };
    };

    cout << endl << "There are " << niceStrings << " nice strings!" << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
