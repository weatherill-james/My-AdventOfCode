#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int ribbonLengthFinder(string inputString) {
    vector<int> sideLengths;
    vector<int> facePerimeters;
    vector<int> ansVector;

    char delim = 'x';
    string substring;

    for (char chr : inputString) {
        if (chr == delim) {
            if (not substring.empty()) {
                sideLengths.push_back(stoi(substring));
            };

            substring.clear();
        } else {
            substring += chr;
        };
    };

    if (not substring.empty()) {
        sideLengths.push_back(stoi(substring));
    };

    sort(sideLengths.begin(), sideLengths.end());
    
    int smallestPerimeter = 2 * (sideLengths[0] + sideLengths[1]);

    int volume = sideLengths[0] * sideLengths[1] * sideLengths[2];

    int totalRibbonLength = smallestPerimeter + volume;

    return totalRibbonLength;
};

int main() {
    clock_t start, end;
    start = clock();

    ////////////////////////////////////////

    string filePath = "../../assets/input.txt";
    ifstream openFile(filePath);

    int ans = 0;
    int tempAns;

    if (openFile.is_open()) {
        string line;

        while (getline(openFile, line)) {
            tempAns = ribbonLengthFinder(line);

            ans += tempAns;
        };
    } else {
        tempAns = 0;
    };

    cout << endl << "The total length of ribbon required is: " << ans << " feet" << endl;

    ////////////////////////////////////////

    end = clock();

    double runtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
