#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <map>

using namespace std;

string nameFinder(string inputString) {
    int colonLoc = inputString.find(":");

    string returnName = inputString.substr(0, colonLoc);
    return returnName;
};

int capacityFinder(string inputString) {
    int capacityLoc = inputString.find("capacity ");
    int durabilityLoc = inputString.find(", durability");

    int returnCapacity = stoi(inputString.substr(capacityLoc + 9, durabilityLoc - (capacityLoc + 9)));
    return returnCapacity;
};

int durabilityFinder(string inputString) {
    int durabilityLoc = inputString.find("durability ");
    int flavorLoc = inputString.find(", flavor");

    int returnDurability = stoi(inputString.substr(durabilityLoc + 11, flavorLoc - (durabilityLoc + 11)));
    return returnDurability;
};

int flavorFinder(string inputString) {
    int flavorLoc = inputString.find("flavor ");
    int textureLoc = inputString.find(", texture");

    int returnFlavor = stoi(inputString.substr(flavorLoc + 7, textureLoc - (flavorLoc + 7)));
    return returnFlavor;
};

int textureFinder(string inputString) {
    int textureLoc = inputString.find("texture ");
    int caloriesLoc = inputString.find(", calories");

    int returnTexture = stoi(inputString.substr(textureLoc + 8, caloriesLoc - (textureLoc + 8)));
    return returnTexture;
};

int caloriesFinder(string inputString) {
    int caloriesLoc = inputString.find("calories ");
    int inputStringLength = inputString.length();

    int returnCalories = stoi(inputString.substr(caloriesLoc + 9, inputStringLength - (caloriesLoc + 9)));
    return returnCalories;
};

int totalScoreCalculator(vector<string> ingredientNamesVect, map<string, vector<int>> ingredientsAndStatsMap,
                         vector<int> amountsVector) {
    int totalCapacity = 0;
    int totalDurability = 0;
    int totalFlavor = 0;
    int totalTexture = 0;
    int totalCalories = 0;

    for (int i = 0; i < ingredientNamesVect.size(); i += 1) {
        string ingredientName = ingredientNamesVect[i];
        vector<int> ingredientStats = ingredientsAndStatsMap[ingredientName];

        int amount = amountsVector[i];

        totalCapacity += ingredientStats[0] * amount;
        totalDurability += ingredientStats[1] * amount;
        totalFlavor += ingredientStats[2] * amount;
        totalTexture += ingredientStats[3] * amount;
        totalCalories += ingredientStats[4] * amount;
    };

    int totalScore;

    if (totalCapacity > 0 and totalDurability > 0 and totalFlavor > 0 and totalTexture > 0 and totalCalories == 500) {
        totalScore = totalCapacity * totalDurability * totalFlavor * totalTexture;
    } else {
        totalScore = 0;
    };

    return totalScore;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    vector<string> ingredientNames;

    map<string, vector<int>> ingredientsAndStats;

    string line;
    while (getline(openFile, line)) {
        string name = nameFinder(line);
        ingredientNames.push_back(name);

        int capacity = capacityFinder(line);
        int durability = durabilityFinder(line);
        int flavor = flavorFinder(line);
        int texture = textureFinder(line);
        int calories = caloriesFinder(line);

        ingredientsAndStats.insert({name, {capacity, durability, flavor, texture, calories}});
    };

    int amountsOfIngredients = 100;

    int bestScore = 0;

    // for input1.txt
    for (int number1 = 0; number1 <= amountsOfIngredients; number1 += 1) {
        for (int number2 = 0; number2 <= (amountsOfIngredients - number1); number2 += 1) {
            for (int number3 = 0; number3 <= (amountsOfIngredients - number1 - number2); number3 += 1) {
                int number4 = amountsOfIngredients - number1 - number2 - number3;
    
                vector<int> amountsVector = {number1, number2, number3, number4};
                int totalScore = totalScoreCalculator(ingredientNames, ingredientsAndStats, amountsVector);
    
                if (totalScore > bestScore) {
                   bestScore = totalScore;
                };
            };
        };
    };

    // for input2.txt
    // for (int number1 = 0; number1 <= amountsOfIngredients; number1 += 1) {
    //     int number2 = amountsOfIngredients - number1;

    //     vector<int> amountsVector = {number1, number2};

    //     int totalScore = totalScoreCalculator(ingredientNames, ingredientsAndStats, amountsVector);

    //     if (totalScore > bestScore) {
    //         bestScore = totalScore;
    //     };
    // };

    cout << endl << "The best possible score is: " << bestScore << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
}
