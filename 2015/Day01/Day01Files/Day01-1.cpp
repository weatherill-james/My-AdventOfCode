#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int brackets2Numbers(string inputString) {
    int stringLength = inputString.length();

    int floorNum = 0;

    for (int i = 0; i < stringLength; i += 1) {
        char currentChar = inputString[i];

        if (currentChar == '(') {
            floorNum += 1;
        } else {
            floorNum -= 1;
        };
    };

    return floorNum;
};

int main() {
    clock_t start, end;
    start = clock();

    ////////////////////////////////////////

    string filePath = "../../assets/input.txt";

    ifstream openFile(filePath);

    int ans = 0;

    if (openFile.is_open()) {
        string bracketString;

        getline(openFile, bracketString);

        ans = brackets2Numbers(bracketString);
    } else {
        ans = 0;
    };

    cout << endl << "Santa must go to: Floor " << ans << endl;

    ////////////////////////////////////////

    end = clock();

    double runtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}

