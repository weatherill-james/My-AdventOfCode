#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";
    ifstream openFile(pathName);

    int totalChars = 0;
    int completedStringChars = 0;

    string line;
    while (getline(openFile, line)) {
        int lineLength = line.length();
        totalChars += lineLength;

        int i = 0;
        while (i != lineLength) {
            if (line[i] == '\"') {
                i += 1;
            } else if (line[i] == '\\') {
                if (line[i + 1] == '\"' or line[i + 1] == '\\') {
                    completedStringChars += 1;
                    i += 2;
                } else if (line[i + 1] == 'x') {
                    completedStringChars += 1;
                    i += 4;
                };
            } else {
                completedStringChars += 1;
                i += 1;
            };
        };
    };

    cout << endl <<
    "     Original Length : " << totalChars << endl <<
    "        Fixed Length : " << completedStringChars << endl <<
    "Character Difference : " << totalChars - completedStringChars << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
