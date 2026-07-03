#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <map>

using namespace std;

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string filePath = "../../assets/input.txt";

    ifstream openFile(filePath);

    string line;
    getline(openFile, line);
    openFile.close();

    int goal = stoi(line);

    map<int, int> housesAndPresents;

    int bestHouseNumber = 0;

    bool leave = false;
    for (int elfNo = 1; elfNo <= goal; elfNo += 1) {
        for (int houseNo = elfNo; houseNo <= 1000000; houseNo += elfNo) {
            housesAndPresents[houseNo] += elfNo * 10;

            if (houseNo == elfNo and housesAndPresents[houseNo] >= goal) {
                bestHouseNumber = houseNo;

                leave = true;
                break;
            };
        };

        if (leave) {
            break;
        };
    };

    cout << endl <<
    "House Number: " << bestHouseNumber << endl << 
    "is the lowest number to reach the goal of: " << goal << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
