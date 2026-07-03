#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

bool ABcdPQxy(string inputString) {
    if (inputString.find("ab") < 100 or inputString.find("cd") < 100 or
        inputString.find("pq") < 100 or inputString.find("xy") < 100) {

        return false;
    } else {
        return true;
    };
};

bool doubleLetter(string inputString) {
    int stringLength = inputString.length();

    for (int i = 0; i < (stringLength - 1); i += 1) {
        if (inputString[i] == inputString[i + 1]) {
            return true;
        };
    };

    return false;
};

bool numberOfVowels(string inputString) {
    int counter = 0;

    for (char chr : inputString) {
        if (chr == 'a' or chr == 'e' or chr == 'i' or chr == 'o' or chr == 'u') {
            counter += 1;
        };
    };

    if (counter >= 3) {
        return true;
    } else {
        return false;
    };
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
        if (ABcdPQxy(line) and doubleLetter(line) and numberOfVowels(line)) {
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
