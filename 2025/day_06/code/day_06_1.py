import os
from time import time

########################################

start_time = time()

########################################

def fix_lines(lines):
    while True:
        start_len = len(lines)

        lines = lines.replace("  ", " ")
        if len(lines) == start_len:
            lines = lines.split("\n")[:-1]
            break

    lines = [line.replace(" ", ",") for line in lines]

    for line_num in range(len(lines)):
        if lines[line_num][0] == ",":
            lines[line_num] = lines[line_num][1:]
        if lines[line_num][-1] == ",":
            lines[line_num] = lines[line_num][:-1]

    lines = [line.split(",") for line in lines]

    lines = [[int(item) if item.isnumeric() else item for item in line] for line in lines]

    return lines

path_name = os.path.join(os.path.dirname(__file__), "..", "assets", "input1.txt")
# path_name = os.path.join(os.path.dirname(__file__), "..", "assets", "input2.txt")

with open(path_name, "r") as file:
    lines = file.read()

lines = fix_lines(lines)

numbers = lines[:-1]
operations = lines[-1]

ans = 0

for index in range(len(operations)):
    op = operations[index]

    if op == "*":
        temp_calc = 1
        for lst in numbers:
            temp_calc *= lst[index]
    else:
        temp_calc = 0
        for lst in numbers:
            temp_calc += lst[index]

    ans += temp_calc

print(f"\nThe calculation result is: {ans}\n")

########################################

finish_time = time()

print(f"The code took {finish_time - start_time} seconds to run\n")
