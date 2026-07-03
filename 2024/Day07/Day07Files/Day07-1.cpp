#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <map>

using namespace std;

string ansFinder(string inputString) {
    int colonLoc = inputString.find(":");

    string ans = inputString.substr(0, colonLoc);

    return ans;
};

vector<int> inputsFinder(string inputString) {
    vector<int> inputs;

    int colonLoc = inputString.find(":");

    string inputsSubstring = inputString.substr(colonLoc + 2);

    string tempNum = "";
    for (int i = 0; i < inputsSubstring.size(); i++) {
        if (inputsSubstring[i] == ' ' and tempNum != "") {
            inputs.push_back(stoi(tempNum));
            tempNum = "";
        } else {
            tempNum += inputsSubstring[i];
        };
    };

    inputs.push_back(stoi(tempNum));

    return inputs;
};

bool testInputOnOperators(string goalNum, vector<int> inputs) {
    for (int i = 0; i < 2 * pow(2, inputs.size() - 2); i += 1) {
        string binaryString = bitset<16>(i).to_string().substr(16 - (inputs.size() - 1));

        long long tempAns = inputs[0];

        int index = 1;
        for (char chr : binaryString) {
            if (chr == '0') {
                tempAns += inputs[index];
            } else {
                tempAns *= inputs[index];
            };

            index += 1;
        };

        if (to_string(tempAns) == goalNum) {
            return true;
        };
    };

    return false;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    map<string, vector<int>> ansAndInputs;

    string line;
    while (getline(openFile, line)) {
        string ans = ansFinder(line);
        vector<int> inputs = inputsFinder(line);

        ansAndInputs[ans] = inputs;
    };
    openFile.close();

    long long totalResult = 0;
    for (auto mapElement : ansAndInputs) {
        if (testInputOnOperators(mapElement.first, mapElement.second)) {
            totalResult += stoll(mapElement.first);
        };
    };

    cout << endl << "The total result of the correct lines is: " << totalResult << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
