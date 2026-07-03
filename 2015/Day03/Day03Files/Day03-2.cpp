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
    vector<int> realSantaLocation = {0, 0};
    vector<int> roboSantaLocation = {0, 0};

    housesVisited.insert(realSantaLocation);

    string thePath;

    getline(openFile, thePath);
    openFile.close();

    int thePathLength = thePath.length();

    for (int i = 0; i < thePathLength; i += 1) {
        if (i % 2 == 0) {
            if (thePath[i] == '^') {
                realSantaLocation[0] += 1;

                housesVisited.insert(realSantaLocation);
            } else if (thePath[i] == 'v') {
                realSantaLocation[0] -= 1;

                housesVisited.insert(realSantaLocation);
            } else if (thePath[i] == '>') {
                realSantaLocation[1] += 1;

                housesVisited.insert(realSantaLocation);
            } else if (thePath[i] == '<') {
                realSantaLocation[1] -= 1;

                housesVisited.insert(realSantaLocation);
            };
        } else {
            if (thePath[i] == '^') {
                roboSantaLocation[0] += 1;

                housesVisited.insert(roboSantaLocation);
            } else if (thePath[i] == 'v') {
                roboSantaLocation[0] -= 1;

                housesVisited.insert(roboSantaLocation);
            } else if (thePath[i] == '>') {
                roboSantaLocation[1] += 1;

                housesVisited.insert(roboSantaLocation);
            } else if (thePath[i] == '<') {
                roboSantaLocation[1] -= 1;

                housesVisited.insert(roboSantaLocation);
            };
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
