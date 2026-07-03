#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

string stringBreakdown(string diskMapString) {
    string brokenDownString;

    int idNum = 0;
    for (int i = 0; i < diskMapString.size(); i += 1) {
        if (i % 2 == 0) {
            string tempString = "";
            for (int j = 0; j < stoi(diskMapString.substr(i, 1)); j += 1) {
                tempString += ('(' + to_string(idNum) + ')');
            };
            brokenDownString += tempString;
            idNum += 1;
        } else {
            string tempString = "";
            for (int j = 0; j < stoi(diskMapString.substr(i, 1)); j += 1) {
                tempString += '.';
            };
            brokenDownString += tempString;
        };
    };

    return brokenDownString;
};

string stringSort(string diskMapString) {
    string sortedString = diskMapString;

    for (int i = 0; i < sortedString.size(); i += 1) {
        if (sortedString[i] == '.') {
            int closeBracketLoc = 0;
            int openBracketLoc = 0;

            for (int j = sortedString.length() - 1; j > i; j -= 1) {
                if (sortedString[j] == ')') {
                    closeBracketLoc += j;
                } else if (sortedString[j] == '(') {
                    openBracketLoc += j;
                    break;
                };
            };

            if (closeBracketLoc == 0 and openBracketLoc == 0) {
                break;
            };

            string bracketsSubstring = sortedString.substr(openBracketLoc, closeBracketLoc - openBracketLoc + 1);

            sortedString.replace(openBracketLoc, closeBracketLoc - openBracketLoc + 1, ".");
            sortedString.replace(i, 1, bracketsSubstring);
        };
    };

    sortedString.erase(remove(sortedString.begin(), sortedString.end(), '.'), sortedString.end());

    return sortedString;
};

long long checkSum(string sortedString) {
    long long checkSum = 0;

    int idNum = 0;
    while (sortedString.size() > 0) {
        int openBracketLoc;
        int closeBracketLoc;

        for (int i = 0; i < sortedString.size(); i += 1) {
            if (sortedString[i] == '(') {
                openBracketLoc = i;
            } else if (sortedString[i] == ')') {
                closeBracketLoc = i;
                break;
            };
        };

        int numberInBrackets = stoi(sortedString.substr(openBracketLoc + 1, closeBracketLoc - openBracketLoc - 1));

        checkSum += (idNum * numberInBrackets);
        idNum += 1;

        sortedString.erase(openBracketLoc, closeBracketLoc - openBracketLoc + 1);
    };

    return checkSum;
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

    string brokenDownString = stringBreakdown(diskMapString);
    string sortedString = stringSort(brokenDownString);

    long long checkSumValue = checkSum(sortedString);

    cout << endl << "The check sum value is: " << checkSumValue << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
