#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

using timepoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

timepoint timer() {
    return std::chrono::high_resolution_clock::now();
}

double time_taken(timepoint start_time, timepoint finish_time) {
    return std::chrono::duration<double, std::milli>(finish_time - start_time).count() / 1000;
}

std::vector<std::string> read_lines(fs::path temp_file_path) {
    std::ifstream temp_file(temp_file_path);

    std::vector<std::string> temp_lines_vec;
    std::string temp_line;

    while (std::getline(temp_file, temp_line)) {
        bool dots = true;

        for (int i = 0; i < temp_line.size(); i += 1) {
            if (temp_line[i] != '.') {
                if (temp_line[i] == 'S') {
                    temp_line[i] = '|';
                };

                dots = false;
                break;
            };
        };

        if (not dots) {
            temp_lines_vec.push_back(temp_line);
        };
    };

    temp_file.close();

    return temp_lines_vec;
}

int main(){
    timepoint start_time = timer();

    ////////////////////////////////////////

    fs::path dir_parent(".."), dir_assets("assets"), file_input1("input1.txt"), file_input2("input2.txt");

    // fs::path file_path = dir_parent / dir_assets / file_input1;
    fs::path file_path = dir_parent / dir_assets / file_input2;

    std::vector<std::string> lines_vec = read_lines(file_path);

    int split_counter = 0;

    for (int i = 1; i < lines_vec.size(); i += 1) {
        for (int j = 0; j < lines_vec[i].size(); j += 1) {
            if (lines_vec[i][j] == '^' and lines_vec[i - 1][j] == '|') {
                lines_vec[i][j - 1] = '|';
                lines_vec[i][j + 1] = '|';

                split_counter += 1;
            } else if (lines_vec[i][j] == '.' and lines_vec[i - 1][j] == '|') {
                lines_vec[i][j] = '|';
            };
        };
    };

    std::cout << std::endl << "There are: " << split_counter << " splits!" << std::endl;

    ////////////////////////////////////////

    timepoint finish_time = timer();

    std::cout << std::endl << "The code took: " << time_taken(start_time, finish_time) << " seconds to run!" << std::endl << std::endl;

    return 0;
}
