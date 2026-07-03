#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int numberOfSurroundingONLights(int x, int y, vector<string> lightLines) {
    int numberOfONLights = 0;

    if (x == 0 and y == 0) {
        return 2;
    } else if (x == 0 and y == lightLines.size() - 1) {
        return 2;
    } else if (x == lightLines[y].size() - 1 and y == 0) {
        return 2;
    } else if (x == lightLines[y].size() - 1 and y == lightLines.size() - 1) {
        return 2;
    } else if (x == 0) {
        if (lightLines[y][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x + 1] == '#') {
            numberOfONLights += 1;
        };
    } else if (x == lightLines[y].size() - 1) {
        if (lightLines[y][x - 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x - 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x - 1] == '#') {
            numberOfONLights += 1;
        };
    } else if (y == 0) {
        if (lightLines[y][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y][x - 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x - 1] == '#') {
            numberOfONLights += 1;
        };
    } else if (y == lightLines.size() - 1) {
        if (lightLines[y][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y][x - 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x - 1] == '#') {
            numberOfONLights += 1;
        };
    } else {
        if (lightLines[y][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y][x - 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y + 1][x - 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x + 1] == '#') {
            numberOfONLights += 1;
        };

        if (lightLines[y - 1][x - 1] == '#') {
            numberOfONLights += 1;
        };
    };

    return numberOfONLights;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<string> lightLines;
    vector<string> tempLightLines;

    string line;
    while (getline(openFile, line)) {
        tempLightLines.push_back(line);
    };
    openFile.close();

    tempLightLines[0].replace(0, 1, "#");
    tempLightLines[0].replace(tempLightLines[0].size() - 1, 1, "#");
    tempLightLines[tempLightLines.size() - 1].replace(0, 1, "#");
    tempLightLines[tempLightLines.size() - 1].replace(tempLightLines[tempLightLines.size() - 1].size() - 1, 1, "#");

    int numberOfLoops = 100;

    for (int loopNumber = 0; loopNumber < numberOfLoops; loopNumber += 1) {
        lightLines = tempLightLines;

        for (int y = 0; y < lightLines.size(); y += 1) {
            for (int x = 0; x < lightLines[y].size(); x += 1) {
                int surroundingONLights = numberOfSurroundingONLights(x, y, lightLines);

                if (lightLines[y][x] == '#') {
                    if (surroundingONLights == 2 or surroundingONLights == 3) {
                        tempLightLines[y].replace(x, 1, "#");
                    } else {
                        tempLightLines[y].replace(x, 1, ".");
                    };
                } else {
                    if (surroundingONLights == 3) {
                        tempLightLines[y].replace(x, 1, "#");
                    } else {
                        tempLightLines[y].replace(x, 1, ".");
                    };
                };
            };
        };
    };

    int numberOfONLights = 0;
    for (string lightLine : tempLightLines) {
        for (char light : lightLine) {
            if (light == '#') {
                numberOfONLights += 1;
            };
        };
    };

    cout << endl << "The number of ON lights, after " << numberOfLoops << " loops, is: " << numberOfONLights << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
