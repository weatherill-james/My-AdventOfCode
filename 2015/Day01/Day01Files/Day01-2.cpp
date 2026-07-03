#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

int brackets2Numbers(string inputString) {
    int stringLength = inputString.length();

    int floorNum = 0;
    int position = 0;

    for (int i = 0; i < stringLength; i += 1) {
        char currentChar = inputString[i];

        if (currentChar == '(') {
            floorNum += 1;
        } else {
            floorNum -= 1;
        };

        if (floorNum == -1) {
            position = i + 1;
            break;
        };
    };

    return position;
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

    cout << endl << "Santa enters the basement at position: " << ans << endl;

    ////////////////////////////////////////

    end = clock();

    double runtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
