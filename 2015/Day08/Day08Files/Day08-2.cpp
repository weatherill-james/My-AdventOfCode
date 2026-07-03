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

    int extendedStringChars = 0;
    int originalStringChars = 0;

    string line;
    while (getline(openFile, line)) {
        int lineLength = line.length();
        originalStringChars += lineLength;

        extendedStringChars += 2;

        for (char chr : line) {
            extendedStringChars += 1;

            if (chr == '\\') {
                extendedStringChars += 1;
            } else if (chr == '\"') {
                extendedStringChars += 1;
            };
        };
    };

    cout << endl <<
    "    Exetended Length : " << extendedStringChars << endl <<
    "     Original Length : " << originalStringChars << endl <<
    "Character Difference : " << extendedStringChars - originalStringChars << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
