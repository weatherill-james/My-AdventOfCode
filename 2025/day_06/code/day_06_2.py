import os
from time import time

########################################

start_time = time()

########################################

def fix_lines(lines):
    full_list = []
    temp_addition = []

    for index in range(len(lines[0])):
        if lines[-1][index] != " ":
            if len(temp_addition) > 0:
                full_list.append([[int(num) for num in temp_addition[0] if num.strip().isnumeric()], temp_addition[1]])
                temp_addition = []

            temp_col = ""
            for line in lines[:-1]:
                temp_col += line[index]
            temp_addition.append([temp_col])

            temp_addition.append(lines[-1][index])
        else:
            temp_col = ""
            for line in lines[:-1]:
                temp_col += line[index]
            temp_addition[0].append(temp_col)

    if len(temp_addition) > 0:
        full_list.append([[int(num) for num in temp_addition[0] if num.strip().isnumeric()], temp_addition[1]])
    
    return full_list


path_name = os.path.join(os.path.dirname(__file__), "..", "assets", "input1.txt")
# path_name = os.path.join(os.path.dirname(__file__), "..", "assets", "input2.txt")

with open(path_name, "r") as file:
    lines = file.read()

lines = lines.split("\n")[:-1]

lines = fix_lines(lines)

ans = 0

for lst in lines:
    if lst[1] == "*":
        temp_calc = 1
        for num in lst[0]:
            temp_calc *= num
    else:
        temp_calc = 0
        for num in lst[0]:
            temp_calc += num

    ans += temp_calc

print(f"\nThe calculation result is: {ans}\n")

########################################

finish_time = time()

print(f"The code took {finish_time - start_time} seconds to run\n")
