#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

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

    int raceLength = 2503;

    string winnerName;
    int winnerSpeed;
    int winnerAccelerationTime;
    int winnerRestingTime;
    int winnerDistance = 0;

    string line;
    while(getline(openFile, line)) {
        string name = nameFinder(line);
        int speed = speedFinder(line);
        int accelerationTime = accelerationTimeFinder(line);
        int restingTime = restingTimeFinder(line);

        int loopTime = accelerationTime + restingTime;

        int distanceTravelled = distanceTravelledFinder(speed, accelerationTime, restingTime, raceLength);

        if (winnerDistance < distanceTravelled) {
            winnerName = name;
            winnerSpeed = speed;
            winnerAccelerationTime = accelerationTime;
            winnerRestingTime = restingTime;
            winnerDistance = distanceTravelled;
        };
    };

    cout << endl <<
    "Name: " << winnerName << endl <<
    "Speed: " << winnerSpeed << endl <<
    "Acceleration Time: " << winnerAccelerationTime << endl <<
    "Resting Time: " << winnerRestingTime << endl <<
    "Hence, distance travelled: " << winnerDistance << endl;

    ////////////////////////////////////////

    finishTime = clock();

    double runtime = (double)(finishTime - startTime) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run" << endl << endl;

    return 0;
};
