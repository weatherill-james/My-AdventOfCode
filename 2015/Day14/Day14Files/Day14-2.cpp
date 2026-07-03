#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <tuple>
#include <map>

using namespace std;

string nameFinder(string inputString) {
    int canLoc = inputString.find(" can ");

    string returnName = inputString.substr(0, canLoc);

    return returnName;
};

int speedFinder(string inputString) {
    int flyLoc = inputString.find(" fly ");
    int kmsLoc = inputString.find(" km/s ");

    int speedString = stoi(inputString.substr(flyLoc + 5, kmsLoc - (flyLoc + 5)));

    return speedString;
};

int accelerationTimeFinder(string inputString) {
    int forLoc = inputString.find("s for ");
    int secondsLoc = inputString.find(" seconds, ");

    int accelerationTimeString = stoi(inputString.substr(forLoc + 6, secondsLoc - (forLoc + 6)));

    return accelerationTimeString;
};

int restingTimeFinder(string inputString) {
    int restLoc = inputString.find("t for ");
    int secondsLoc = inputString.find(" seconds.");

    int restingTimeString = stoi(inputString.substr(restLoc + 6, secondsLoc - (restLoc + 6)));

    return restingTimeString;
};

int distanceTravelledFinder(int speed, int accelerationTime, int restingTime, int raceLength) {
    int loopTime = accelerationTime + restingTime;

    int loops = raceLength / loopTime;
    int loopsDistance = loops * speed * accelerationTime;

    int remainingTime = raceLength % loopTime;

    if (remainingTime >= accelerationTime) {
        loopsDistance += speed * accelerationTime;
    } else {
        loopsDistance += speed * remainingTime;
    };

    return loopsDistance;
};

int main() {
    clock_t startTime, finishTime;

    startTime = clock();

    ////////////////////////////////////////

    string pathName = "../../assets/input.txt";
    // string pathName = "../../assets/input2.txt";

    ifstream openFile(pathName);

    map<string, int> reindeerPointsMap;
    map<string, tuple<int, int, int, int>> reindeerStatsMap;

    int raceLength = 2503;

    string line;
    while(getline(openFile, line)) {
        string name = nameFinder(line);
        int speed = speedFinder(line);
        int accelerationTime = accelerationTimeFinder(line);
        int restingTime = restingTimeFinder(line);

        int loopTime = accelerationTime + restingTime;

        tuple<int, int, int, int> reindeerStats = make_tuple(speed, accelerationTime, restingTime, loopTime);

        reindeerPointsMap.insert({name, 0});
        reindeerStatsMap.insert({name, reindeerStats});
    };

    for (int currentTime = 1; currentTime <= raceLength; currentTime += 1) {
        vector<string> bestTempReindeers;
        int bestTempDistance = 0;

        for (auto reindeer : reindeerStatsMap) {
            string currentReindeerName = reindeer.first;
            int currentReindeerSpeed = get<0>(reindeer.second);
            int currentReindeerAccelerationTime = get<1>(reindeer.second);
            int currentReindeerRestingTime = get<2>(reindeer.second);
            int currentReindeerLoopTime = get<3>(reindeer.second);

            int distanceTravelled = distanceTravelledFinder(currentReindeerSpeed, currentReindeerAccelerationTime,
                                                            currentReindeerRestingTime, currentTime);

            if (distanceTravelled > bestTempDistance) {
                bestTempReindeers.clear();
                bestTempReindeers.push_back(currentReindeerName);

                bestTempDistance = distanceTravelled;
            } else if (distanceTravelled == bestTempDistance) {
                bestTempReindeers.push_back(currentReindeerName);
            };
        };

        for (string reindeer : bestTempReindeers) {
            reindeerPointsMap[reindeer] += 1;
        };
    };

    string winnerName;
    int winnerSpeed;
    int winnerAccelerationTime;
    int winnerRestingTime;
    int winnerDistance;
    int winnerPoints = 0;

    for (auto reindeer : reindeerPointsMap) {
        string currentReindeerName = reindeer.first;
        int currentReindeerPoints = reindeer.second;

        if (currentReindeerPoints > winnerPoints) {
            winnerName = currentReindeerName;
            winnerSpeed = get<0>(reindeerStatsMap[currentReindeerName]);
            winnerAccelerationTime = get<1>(reindeerStatsMap[currentReindeerName]);
            winnerRestingTime = get<2>(reindeerStatsMap[currentReindeerName]);
            winnerDistance = distanceTravelledFinder(winnerSpeed, winnerAccelerationTime, winnerRestingTime, raceLength);
            winnerPoints = currentReindeerPoints;
        };
    };

    cout << endl <<
    "The winning reindeer is..." << endl << endl <<
    "Name: " << winnerName << endl <<
    "Speed: " << winnerSpeed << endl <<
    "Acceleration Time: " << winnerAccelerationTime << endl <<
    "Resting Time: " << winnerRestingTime << endl <<
    "Distance: " << winnerDistance << endl <<
    "Points: " << winnerPoints << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
};
