#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string filePath = "../../assets/input.txt";
    // string filePath = "../../assets/input2.txt";

    ifstream openFile(filePath);

    string line; getline(openFile, line);

    for (int loops = 0; loops < 40; loops += 1) {
        vector<pair<string, string>> stringBreakup;

        string tempChar = "a";
        string tempString;
        for (int i = 0; i < line.length(); i += 1) {
            if (tempChar == "a") {
                tempChar = line.substr(i, 1);
                tempString += line.substr(i, 1);
            } else if (tempChar == line.substr(i, 1)) {
                tempString += line.substr(i, 1);
            } else if (tempChar != line.substr(i, 1)) {
                stringBreakup.push_back({tempChar, to_string(tempString.length())});

                tempChar = line.substr(i, 1);
                tempString = line.substr(i, 1);
            };

            if (i == (line.length() - 1)) {
                stringBreakup.push_back({tempChar, to_string(tempString.length())});
            };
        };

        line.clear();
        for (auto pair : stringBreakup) {
            line += pair.second;
            line += pair.first;
        };

        tempString.clear();
    };

    cout << endl << "The length of the answer is: " << line.length() << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
