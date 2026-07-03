from time import time
from copy import deepcopy as copy
from itertools import product, repeat

startTime = time()

########################################

fixedList = []
file1 = open("input.txt", "r")
file2 = open("testInput.txt", "r")
fileReadList = file1.readlines()
for item in fileReadList:
    fixedList.append(item.replace("\n", ""))
for i in range(len(fixedList)):
    fixedList[i] = fixedList[i].split(" ")
    fixedList[i][0] = list(fixedList[i][0])
    fixedList[i][1] = fixedList[i][1].split(",")
    for j in range(len(fixedList[i][1])):
        fixedList[i][1][j] = int(fixedList[i][1][j])

########################################

def findBrokenLayout(inputList):
    tempList = []

    brokenCount = 0

    for i, char in enumerate(inputList):
        if char == "#":
            brokenCount += 1
        elif char == ".":
            if brokenCount != 0:
                tempList.append(brokenCount)
                brokenCount = 0
        if char == "#" and i == len(inputList)-1:
            tempList.append(brokenCount)

    return tempList

ans = 0

for fixedItem in fixedList:
    numberOfQuestionMarks = fixedItem[0].count("?")

    for combination in product([".", "#"], repeat=numberOfQuestionMarks):
        copyList = copy(fixedItem[0])
        counter = 0

        for j, char in enumerate(copyList):
            if char == "?":
                copyList[j] = combination[counter]
                counter += 1

        if findBrokenLayout(copyList) == fixedItem[1]:
            ans += 1

print(ans)

########################################

finishTime = time()

print(f"\nThe code took: {finishTime-startTime} seconds, to run!")

