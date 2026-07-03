#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int auntSueXYZFinder(string inputString, int realAuntSueXYZ, string searchFor) {
    int searchForLength = searchFor.length();
    int searchForLoc = inputString.find(searchFor);

    if (searchForLoc != string::npos) {
        string numberAsString = "";

        for (int i = searchForLoc + searchForLength; i < inputString.length(); i += 1) {
            if (inputString[i] == ',') {
                break;
            } else {
                numberAsString += inputString[i];
            };
        };

        return stoi(numberAsString);
    } else {
        if (searchFor == " cats: ") {
            return realAuntSueXYZ + 1;
        } else if (searchFor == " trees: ") {
            return realAuntSueXYZ + 1;
        } else if (searchFor == " pomeranians: ") {
            return realAuntSueXYZ - 1;
        } else if (searchFor == " goldfish: ") {
            return realAuntSueXYZ - 1;
        } else {
            return realAuntSueXYZ;
        };
    };
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    int auntSueChildren = 3;
    int auntSueCats = 7;
    int auntSueSamoyeds = 2;
    int auntSuePomeranians = 3;
    int auntSueAkitas = 0;
    int auntSueVizslas = 0;
    int auntSueGoldfish = 5;
    int auntSueTrees = 3;
    int auntSueCars = 2;
    int auntSuePerfumes = 1;

    string pathName = "../../assets/input.txt";

    ifstream openFile(pathName);

    int auntSueNumber = 0;

    string line;
    while (getline(openFile, line)) {
        auntSueNumber += 1;

        int currentChildren = auntSueXYZFinder(line, auntSueChildren, " children: ");
        int currentCats = auntSueXYZFinder(line, auntSueCats, " cats: ");
        int currentSamoyeds = auntSueXYZFinder(line, auntSueSamoyeds, " samoyeds: ");
        int currentPomeranians = auntSueXYZFinder(line, auntSuePomeranians, " pomeranians: ");
        int currentAkitas = auntSueXYZFinder(line, auntSueAkitas, " akitas: ");
        int currentVizslas = auntSueXYZFinder(line, auntSueVizslas, " vizslas: ");
        int currentGoldfish = auntSueXYZFinder(line, auntSueGoldfish, " goldfish: ");
        int currentTrees = auntSueXYZFinder(line, auntSueTrees, " trees: ");
        int currentCars = auntSueXYZFinder(line, auntSueCars, " cars: ");
        int currentPerfumes = auntSueXYZFinder(line, auntSuePerfumes, " perfumes: ");

        if (currentChildren == auntSueChildren and
            currentCats > auntSueCats and
            currentSamoyeds == auntSueSamoyeds and
            currentPomeranians < auntSuePomeranians and
            currentAkitas == auntSueAkitas and
            currentVizslas == auntSueVizslas and
            currentGoldfish < auntSueGoldfish and
            currentTrees > auntSueTrees and
            currentCars == auntSueCars and
            currentPerfumes == auntSuePerfumes) {
            break;
        };
    };

    cout << endl << "The REAL REAL Aunt Sue's number is: " << auntSueNumber << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;
}
