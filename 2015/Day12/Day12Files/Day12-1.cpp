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

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string filePath = "../../assets/input.txt";

    ifstream openFile(filePath);

    int totalSum = 0;
    string tempString;

    string line;
    getline(openFile, line);

    for (char chr : line) {
        if (isDigitOrMinus(chr)) {
            tempString += chr;
        } else {
            if (!tempString.empty()) {
                totalSum += (stoi(tempString));
            };

            tempString.clear();
        };
    };

    cout << endl << "The sum off all numbers in this file, are: " << totalSum << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
