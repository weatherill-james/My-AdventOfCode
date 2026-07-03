#include <iostream>
#include <md5_converter.h>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main() {
    clock_t start, finish;
    start = clock();

    ////////////////////////////////////////

    string pathname = "../../assets/input.txt";
    ifstream openFile(pathname);

    string inputCode;
    getline(openFile, inputCode);
    openFile.close();

    int i = 0;
    string iString;
    string md5Hash;
    while (true) {
        iString = to_string(i);

        string fullCode = inputCode + iString;

        md5Hash = MD5Converter::to_md5(fullCode);

        if (md5Hash[0] == '0' and
            md5Hash[1] == '0' and
            md5Hash[2] == '0' and
            md5Hash[3] == '0' and
            md5Hash[4] == '0' and
            md5Hash[5] == '0') {
            break;
        };
        
        i += 1;
    };

    cout << endl << "The trailing number that makes:  " << md5Hash << ", is: " << i << endl;

    ////////////////////////////////////////

    finish = clock();

    double runtime = ((double)(finish - start)) / CLOCKS_PER_SEC;

    cout << endl << "The code took: " << runtime << " seconds to run!" << endl << endl;

    return 0;
}
