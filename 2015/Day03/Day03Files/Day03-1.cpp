#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <set>

using namespace std;

int main() {
    clock_t start, finish;
    start = clock();

    ////////////////////////////////////////

    string pathname = "../../assets/input.txt";
    ifstream openFile(pathname);

    set<vector<int>> housesVisited;
    vector<int> currentLocation = {0, 0};

    housesVisited.insert(currentLocation);

    string santasPath;

    getline(openFile, santasPath);
    openFile.close();

    for (char chr : santasPath) {
        if (chr == '^') {
            currentLocation[0] += 1;

            housesVisited.insert(currentLocation);
        } else if (chr == 'v') {
            currentLocation[0] -= 1;

            housesVisited.insert(currentLocation);
        } else if (chr == '>') {
            currentLocation[1] += 1;

            housesVisited.insert(currentLocation);
        } else if (chr == '<') {
            currentLocation[1] -= 1;

            housesVisited.insert(currentLocation);
        };
    };

    int numberOfUniqueHouses = housesVisited.size();

    cout << endl << "Santa has visited: " << numberOfUniqueHouses << " different houses" << endl;

    ////////////////////////////////////////

    finish = clock();

    double runtime = ((double)(finish - start)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
