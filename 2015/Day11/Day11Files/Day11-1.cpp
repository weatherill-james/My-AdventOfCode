#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <set>

using namespace std;

bool firstRequirement(string inputString) {
    string allLetters = "abcdefghijklmnopqrstuvwxyz";
    int allLettersLength = allLetters.length();

    int inputStringLength = inputString.length();

    for (int i = 0; i < (inputStringLength - 3); i += 1) {
        string tempSubstring = inputString.substr(i, 3);

        if (allLetters.find(tempSubstring) >= 0 and
            allLetters.find(tempSubstring) < (allLettersLength - 2)) {
            return true;
        };
    };

    return false;
};

bool secondRequirement(string inputString) {
    int inputStringLength = inputString.length();

    if (inputString.find('i') >= 0 and inputString.find('i') < inputStringLength) {
        return false;
    } else if (inputString.find('o') >= 0 and inputString.find('o') < inputStringLength) {
        return false;
    } else if (inputString.find('l') >= 0 and inputString.find('l') < inputStringLength) {
        return false;
    } else {
        return true;
    };
};

bool thirdRequirement(string inputString) {
    int inputStringLength = inputString.length();

    set<string> pairsSet;

    for (int i = 0; i < (inputStringLength - 1); i += 1) {
        if (inputString[i] == inputString[i + 1]) {
            pairsSet.insert(inputString.substr(i, 2));
        };
    };

    if (pairsSet.size() >= 2) {
        return true;
    } else {
        return false;
    };
};

string incrementPassword(string inputString) {
    int inputStringLength = inputString.length();

    string lettersString = "abcdefghijklmnopqrstuvwxyz";

    for (int i = (inputStringLength - 1); i >= 0; i -= 1) {
        char currentLetter = inputString[i];

        if (currentLetter == 'z') {
            inputString.replace(i, 1, "a");
        } else {
            int currentLetterLETTERSLoc = lettersString.find(currentLetter);
            string nextLetter = lettersString.substr(currentLetterLETTERSLoc + 1, 1);

            inputString.replace(i, 1, nextLetter);

            break;
        };
    };

    return inputString;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";
    // string pathName = "../../assets/input3.txt";

    ifstream openFile(pathName);

    string line; getline(openFile, line);

    while (true) {
        if (firstRequirement(line) == true and
            secondRequirement(line) == true and
            thirdRequirement(line) == true) {
            break;
        } else {
            line = incrementPassword(line);
        };
    };

    cout << endl << "The next password is: " << line << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
