import os
from time import time

########################################

start_time = time()

########################################

file_path = os.path.join(os.path.dirname(__file__), "..", "assets", "input1.txt")
# file_path = os.path.join(os.path.dirname(__file__), "..", "assets", "input2.txt")

with open(file_path, "r") as file:
    lines = file.read().splitlines()

split_counter = 1

for line_index in range(1, len(lines) - 1):
    for char_index in range(len(lines[line_index])):
        if lines[line_index][char_index] == "^" and lines[line_index - 1][char_index] == "|":
            split_counter += 1

        if lines[line_index - 1][char_index] == "|" and lines[line_index][char_index] != "^":
            lines[line_index] = lines[line_index][:char_index] + "|" + lines[line_index][char_index + 1:]
        elif char_index != len(lines[line_index]) - 1 and lines[line_index][char_index + 1] == "^":
            lines[line_index] = lines[line_index][:char_index] + "|" + lines[line_index][char_index + 1:]
        elif char_index != 0 and lines[line_index][char_index - 1] == "^":
            lines[line_index] = lines[line_index][:char_index] + "|" + lines[line_index][char_index + 1:]

print(f"\nThe number of splits is: {split_counter}\n")

########################################

finish_time = time()

print(f"The code took: {finish_time - start_time} seconds to run\n")
