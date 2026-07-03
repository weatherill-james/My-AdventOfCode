#! /opt/homebrew/bin/python3

from time import time

startTime = time()

########################################

fixedList = []
file1 = open("input.txt", "r")
file2 = open("testInput.txt", "r")
fileReadList = file2.readlines()
for item in fileReadList:
    fixedList.append(item.replace("\n", ""))
for i in range(len(fixedList)):
    fixedList[i] = fixedList[i].split(" ")
    fixedList[i][0] = list(fixedList[i][0])
    fixedList[i][1] = fixedList[i][1].split(",")
    for j in range(len(fixedList[i][1])):
        fixedList[i][1][j] = int(fixedList[i][1][j])
    fixedList[i][0] = fixedList[i][0] + ["?"] + fixedList[i][0] + ["?"] + fixedList[i][0] + ["?"] + fixedList[i][0] + ["?"] + fixedList[i][0]
    fixedList[i][1] = fixedList[i][1] + fixedList[i][1] + fixedList[i][1] + fixedList[i][1] + fixedList[i][1]

########################################

print(fixedList[0])

def generateCombinations(symbolList, index = 0):
    resultList = []

    def backtrack():
        resultList.append(symbolList.copy())

    if index == len(symbolList):
        backtrack()
        return resultList

    if symbolList[index] == "?":
        for value in [".", "#"]:
            symbolList[index] = value
            resultList.extend(generateCombinations(symbolList, index + 1))
            symbolList[index] = "?"
    else:
        resultList.extend(generateCombinations(symbolList, index + 1))

    return resultList

def matchesConstraints(constraint, combination):
    lengthOfChain = 0
    theLayout = []
    for i in range(len(combination)):
        if combination[i] == "#":
            lengthOfChain += 1

        elif combination[i] == ".":
            if lengthOfChain > 0:
                theLayout.append(lengthOfChain)
            lengthOfChain = 0

        if combination[i] == "#" and i == len(combination)-1:
            theLayout.append(lengthOfChain)

    if theLayout == constraint:
        return True
    else:
        return False

ans = 0

for item in fixedList:

    combinations = generateCombinations(item[0])

    for thing in combinations:
        if matchesConstraints(item[1], thing):
            ans += 1

print(ans)

########################################

finishTime = time()

print(f"\nThe code took: {finishTime-startTime} seconds, to run!")

