#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int paperAreaFinder(string inputString) {
    vector<int> sideLengths;
    vector<int> faceAreas;
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

    int face1 = sideLengths[0] * sideLengths[1];
    int face2 = sideLengths[0] * sideLengths[2];
    int face3 = sideLengths[1] * sideLengths[2];

    int surfaceArea = 2 * face1 + 2 * face2 + 2 * face3;

    faceAreas.push_back(face1);
    faceAreas.push_back(face2);
    faceAreas.push_back(face3);

    int smallestFace = *min_element(faceAreas.begin(), faceAreas.end());

    int totalPaperArea = surfaceArea + smallestFace;

    return totalPaperArea;
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
            tempAns = paperAreaFinder(line);

            ans += tempAns;
        };
    } else {
        tempAns = 0;
    };

    cout << endl << "The total area of paper required is: " << ans << " square feet" << endl;

    ////////////////////////////////////////

    end = clock();

    double runtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
