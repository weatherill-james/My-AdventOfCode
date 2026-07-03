#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <regex>

using namespace std;

int processMultiplication(string input) {
    int openBracketLoc = input.find("(");
    int commaLoc = input.find(",");
    int closeBracketLoc = input.find(")");

    int firstNum = stoi(input.substr(openBracketLoc + 1, commaLoc - (openBracketLoc + 1)));
    int secondNum = stoi(input.substr(commaLoc + 1, closeBracketLoc - (commaLoc + 1)));

    int returnVal = firstNum * secondNum;

    return returnVal;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    string completeFile;

    string line;
    while (getline(openFile, line)) {
        completeFile += line;
    };
    openFile.close();

    regex pattern(R"(mul\(\d{1,3},\d{1,3}\))");

    int ansSum = 0;
    for (int i = 0; i < completeFile.size(); i += 1) {
        if (completeFile[i] == 'm') {
            string tempSubstring = completeFile.substr(i);

            smatch matchSMATCH; regex_search(tempSubstring, matchSMATCH, pattern);

            string matchSTRING = matchSMATCH.str();
            if (tempSubstring.find(matchSTRING) == 0) {
                ansSum += processMultiplication(matchSTRING);
            };
        };
    };

    cout << endl << "The sum of the multiplications are: " << ansSum << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
