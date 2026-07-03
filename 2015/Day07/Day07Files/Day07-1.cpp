#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>
#include <time.h>
#include <map>

#define AND_16(x, y) ((uint16_t)((x) & (y)) & 0xFFFF)
#define OR_16(x, y) ((uint16_t)((x) | (y)) & 0xFFFF)
#define NOT_16(x) ((uint16_t)(~(x)) & 0xFFFF)
#define RSHIFT_16(x, n) ((uint16_t)((x) >> (n)) & 0xFFFF)
#define LSHIFT_16(x, n) ((uint16_t)((x) << (n)) & 0xFFFF)

using namespace std;

string stringReplacer(string inputString, string replaceString, string replaceWith) {
    bool leave = false;

    while (not leave) {
        int aStringFrontLength = inputString.length();

        auto replaceStringLoc = inputString.find(replaceString);

        if (replaceStringLoc >= aStringFrontLength or replaceStringLoc < 0) {
            leave = true;
        } else {
            inputString.replace(replaceStringLoc, replaceString.length(), replaceWith);
        };
    };

    return inputString;
};

bool canCalculate(string inputString) {
    int inputStringLength = inputString.length();

    auto ANDLoc = inputString.find("AND");
    auto ORLoc = inputString.find("OR");
    auto NOTLoc = inputString.find("NOT");
    auto RSHIFTLoc = inputString.find("RSHIFT");
    auto LSHIFTLoc = inputString.find("LSHIFT");

    int frontHalfLength, backHalfLength;
    string frontHalf, backHalf;

    if (ANDLoc > 0 and ANDLoc < inputStringLength) {
        frontHalfLength = ANDLoc - 1;
        frontHalf = inputString.substr(0, frontHalfLength);

        backHalfLength = inputStringLength - (ANDLoc + 4);
        backHalf = inputString.substr(ANDLoc + 4, backHalfLength);
    } else if (ORLoc > 0 and ORLoc < inputStringLength) {
        frontHalfLength = ORLoc - 1;
        frontHalf = inputString.substr(0, frontHalfLength);

        backHalfLength = inputStringLength - (ORLoc + 3);
        backHalf = inputString.substr(ORLoc + 3, backHalfLength);
    } else if (NOTLoc >= 0 and NOTLoc < inputStringLength) {
        frontHalf = "0";

        backHalfLength = inputStringLength - (NOTLoc + 4);
        backHalf = inputString.substr(NOTLoc + 4, backHalfLength);
    } else if (RSHIFTLoc > 0 and RSHIFTLoc < inputStringLength) {
        frontHalfLength = RSHIFTLoc - 1;
        frontHalf = inputString.substr(0, frontHalfLength);

        backHalf = "0";
    } else if (LSHIFTLoc > 0 and LSHIFTLoc < inputStringLength) {
        frontHalfLength = LSHIFTLoc - 1;
        frontHalf = inputString.substr(0, frontHalfLength);

        backHalf = "0";
    } else {
        frontHalf = inputString;

        backHalf = "0";
    };

    if (all_of(frontHalf.begin(), frontHalf.end(), ::isdigit) and all_of(backHalf.begin(), backHalf.end(), ::isdigit)) {
        return true;
    } else {
        return false;
    };
};

string calculate(string inputString) {
    int inputStringLength = inputString.length();

    auto ANDLoc = inputString.find("AND");
    auto ORLoc = inputString.find("OR");
    auto NOTLoc = inputString.find("NOT");
    auto RSHIFTLoc = inputString.find("RSHIFT");
    auto LSHIFTLoc = inputString.find("LSHIFT");

    int frontHalfLength, backHalfLength;
    int frontHalf, backHalf;

    string returnString;

    if (ANDLoc > 0 and ANDLoc < inputStringLength) {
        frontHalfLength = ANDLoc - 1;
        frontHalf = stoi(inputString.substr(0, frontHalfLength));

        backHalfLength = inputStringLength - (ANDLoc + 4);
        backHalf = stoi(inputString.substr(ANDLoc + 4, backHalfLength));

        returnString = to_string(AND_16(frontHalf, backHalf));
    } else if (ORLoc > 0 and ORLoc < inputStringLength) {
        frontHalfLength = ORLoc - 1;
        frontHalf = stoi(inputString.substr(0, frontHalfLength));

        backHalfLength = inputStringLength - (ORLoc + 3);
        backHalf = stoi(inputString.substr(ORLoc + 3, backHalfLength));

        returnString = to_string(OR_16(frontHalf, backHalf));
    } else if (NOTLoc >= 0 and NOTLoc < inputStringLength) {
        backHalfLength = inputStringLength - (NOTLoc + 4);
        backHalf = stoi(inputString.substr(NOTLoc + 4, backHalfLength));

        returnString = to_string(NOT_16(backHalf));
    } else if (RSHIFTLoc > 0 and RSHIFTLoc < inputStringLength) {
        frontHalfLength = RSHIFTLoc - 1;
        frontHalf = stoi(inputString.substr(0, frontHalfLength));

        backHalfLength = inputStringLength - (RSHIFTLoc + 7);
        backHalf = stoi(inputString.substr(RSHIFTLoc + 7, backHalfLength));

        returnString = to_string(RSHIFT_16(frontHalf, backHalf));
    } else if (LSHIFTLoc > 0 and LSHIFTLoc < inputStringLength) {
        frontHalfLength = LSHIFTLoc - 1;
        frontHalf = stoi(inputString.substr(0, frontHalfLength));

        backHalfLength = inputStringLength - (LSHIFTLoc + 7);
        backHalf = stoi(inputString.substr(LSHIFTLoc + 7, backHalfLength));

        returnString = to_string(LSHIFT_16(frontHalf, backHalf));
    } else {
        returnString = inputString;
    };

    return returnString;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string filePath = "../../assets/input.txt";
    // string filePath = "../../assets/input2.txt";
    ifstream openFile(filePath);

    map<string, string> pairsMap;
    map<string, string> answersMap;

    string line;
    while (getline(openFile, line)) {
        string tempKey;
        string tempObject;

        int arrowLoc = line.find(" -> ");
        int tempKeyLength = line.length() - (arrowLoc + 4);
        int tempObjectLength = arrowLoc;

        tempKey = line.substr(arrowLoc + 4, tempKeyLength);
        tempObject = line.substr(0, tempObjectLength);

        pairsMap.insert({tempKey, tempObject});
    };

    while (!answersMap.contains("a")) {
        for (auto pair = pairsMap.begin(); pair != pairsMap.end(); ++pair) {
            string tempString = pair->second;

            if (all_of(tempString.begin(), tempString.end(), ::isdigit)) {
                answersMap.insert({pair->first, pair->second});
            };
        };

        for (auto pair1 = answersMap.begin(); pair1 != answersMap.end(); ++pair1) {
            int pair1FirstLength = (pair1->first).length();

            if (pairsMap.contains(pair1->first)) {
                pairsMap.erase(pair1->first);
            };

            for (auto pair2 = pairsMap.begin(); pair2 != pairsMap.end(); ++pair2) {
                int pair2SecondLength = (pair2->second).length();

                auto pair2SecondKeyLoc = (pair2->second).find(pair1->first);

                if (0 <= pair2SecondKeyLoc and pair2SecondKeyLoc < pair2SecondLength and
                ((pair2SecondKeyLoc - 1 == -1 and (pair2->second)[pair2SecondKeyLoc + pair1FirstLength] == ' ') or
                (pair2SecondKeyLoc + pair1FirstLength == pair2SecondLength and (pair2->second)[pair2SecondKeyLoc - 1] == ' ') or
                (pair1->first == pair2->second))) {
                    pairsMap[pair2->first].replace((pair2->second).find(pair1->first), pair1FirstLength, pair1->second);
                };
            };
        };

        for (auto pair = pairsMap.begin(); pair != pairsMap.end(); ++pair) {
            if (canCalculate(pair->second)) {
                pairsMap[pair->first] = calculate(pair->second);
            };
        };
    };

    cout << endl << "The value of 'a' is: " << answersMap["a"] << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = ((double)(finishTime - startTime)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
