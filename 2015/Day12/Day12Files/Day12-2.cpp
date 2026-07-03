#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

bool isDigitOrMinus(char chr) {
    if (chr == '-' or chr == '0' or chr == '1' or chr == '2' or chr == '3' or chr == '4' or
        chr == '5' or chr == '6' or chr == '7' or chr == '8' or chr == '9') {
        return true;
    } else {
        return false;
    };
};

int stringIntsSum(string inputString) {
    string tempString;
    int returnSum = 0;

    for (char chr : inputString) {
        if (isDigitOrMinus(chr)) {
            tempString += chr;
        } else {
            if (!tempString.empty()) {
                returnSum += (stoi(tempString));
            };

            tempString.clear();
        };
    };

    return returnSum;
};

string dictionaryRemover(string inputString, string removeTerm) {
    string tempLine; tempLine = inputString;

    bool finished = false;
    while (not finished) {
        finished = true;

        int lineLength = tempLine.length();

        for (int i = 0; i < lineLength; i += 1) {
            string redSubstring = tempLine.substr(i, 5);

            if (redSubstring == removeTerm) {
                int curlyBracketCounter = 0;
                int squareBracketCounter = 0;

                bool leave = false;
                for (int j = i; j >= 0; j -= 1) {
                    if (tempLine[j] == '[') {
                        squareBracketCounter += 1;
                    } else if (tempLine[j] == ']') {
                        squareBracketCounter -= 1;
                    };

                    if (squareBracketCounter == 1 and curlyBracketCounter <= 0) {
                        break;
                    };

                    if (tempLine[j] == '{') {
                        curlyBracketCounter += 1;
                    } else if (tempLine[j] == '}') {
                        curlyBracketCounter -= 1;
                    };

                    if (curlyBracketCounter == 1) {
                        finished = false;

                        for (int k = (j + 1); k < lineLength; k += 1) {
                            if (tempLine[k] == '{') {
                                curlyBracketCounter += 1;
                            } else if (tempLine[k] == '}') {
                                curlyBracketCounter -= 1;
                            };

                            if (curlyBracketCounter == 0) {
                                leave = true;

                                string frontHalf = tempLine.substr(0, j);
                                string backHalf = tempLine.substr((k + 1), (lineLength - (k + 1)));

                                tempLine = frontHalf + backHalf;

                                break;
                            };
                        };
                    };

                    if (leave) {
                        break;
                    };
                };
            };

            if (not finished) {
                break;
            };
        };
    };

    return tempLine;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string filePath = "../../assets/input.txt";

    ifstream openFile(filePath);

    string line;
    getline(openFile, line);

    string unwantedString = "\"red\"";
    string ansLine = dictionaryRemover(line, unwantedString);

    int totalSum = 0;
    totalSum += stringIntsSum(ansLine);

    cout << endl << "The sum off all numbers in this file, are: " << totalSum << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
