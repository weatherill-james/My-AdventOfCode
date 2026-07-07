#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <variant>
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

std::vector<std::vector<std::string>> read_lines(fs::path temp_file_path) {
    std::ifstream temp_file(temp_file_path);

    std::vector<std::vector<std::string>> temp_lines_vec;
    std::vector<std::string> temp_line_vec;

    std::string temp_line;

    while (std::getline(temp_file, temp_line)) {
        bool dots = true;

        temp_line_vec.clear();

        for (int i = 0; i < temp_line.size(); i += 1) {
            if (temp_line[i] == '.') {
                temp_line_vec.push_back(std::string("0"));
            } else if (temp_line[i] == '^') {
                dots = false;
                temp_line_vec.push_back(std::string("^"));
            } else {
                dots = false;
                temp_line_vec.push_back(std::string("1"));
            };
        };

        if (not dots) {
            temp_lines_vec.push_back(temp_line_vec);
        };
    };

    temp_file.close();

    return temp_lines_vec;
}

std::string add_string(std::string string_1, std::string string_2) {
    std::string string_sum;

    int i = string_1.size() - 1, j = string_2.size() - 1;
    int carry = 0;

    int digit_1, digit_2, cur_sum;
    while (i >= 0 or j >= 0 or carry != 0) {
        if (i >= 0) {
            digit_1 = string_1[i] - '0';
            i -= 1;
        } else {
            digit_1 = 0;
        };

        if (j >= 0) {
            digit_2 = string_2[j] - '0';
            j -= 1;
        } else {
            digit_2 = 0;
        };

        cur_sum = digit_1 + digit_2 + carry;
        carry = cur_sum / 10;
        string_sum.push_back(char(cur_sum % 10 + '0'));
    };

    std::reverse(string_sum.begin(), string_sum.end());
    return string_sum;
}

int main(){
    timepoint start_time = timer();

    ////////////////////////////////////////

    fs::path dir_parent(".."), dir_assets("assets"), file_input1("input1.txt"), file_input2("input2.txt");

    // fs::path file_path = dir_parent / dir_assets / file_input1;
    fs::path file_path = dir_parent / dir_assets / file_input2;

    std::vector<std::vector<std::string>> lines_vec_vec = read_lines(file_path);

    for (int i = 1; i < lines_vec_vec.size(); i += 1) {
        for (int j = 0; j < lines_vec_vec[i].size(); j += 1) {
            if (lines_vec_vec[i][j] == "^" and lines_vec_vec[i - 1][j] != "^") {
                lines_vec_vec[i][j - 1] = add_string(lines_vec_vec[i - 1][j], lines_vec_vec[i][j - 1]);
                lines_vec_vec[i][j + 1] = add_string(lines_vec_vec[i - 1][j], lines_vec_vec[i][j + 1]);
            } else if (lines_vec_vec[i - 1][j] != "^" and lines_vec_vec[i - 1][j] != "0") {
                lines_vec_vec[i][j] = add_string(lines_vec_vec[i - 1][j], lines_vec_vec[i][j]);
            };
        };
    };

    int end_idx = lines_vec_vec.size() - 1;

    std::string ans = "0";

    for (int i = 0; i < lines_vec_vec[end_idx].size(); i += 1) {
        if (lines_vec_vec[end_idx][i] != "^") {
            ans = add_string(ans, lines_vec_vec[end_idx][i]);
        };
    };

    std::cout << std::endl << "The number of timelines is: " << ans << std::endl;

    ////////////////////////////////////////

    timepoint finish_time = timer();

    std::cout << std::endl << "The code took: " << time_taken(start_time, finish_time) << " seconds to run!" << std::endl << std::endl;

    return 0;
}
