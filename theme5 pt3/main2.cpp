#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <vector>
#include <cctype>

using namespace std;

bool startNum(const string& str) {
    if (str.empty() || str.length() < 3) return false;

    size_t dotPos = str.find(". ");
    if (dotPos == string::npos || dotPos == 0) return false;

    for (size_t i = 0; i < dotPos; ++i) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

bool allCapital(const string& str) {
    if (str.empty()) return false;

    istringstream iss(str);
    string word;

    while (iss >> word) {
        if (word.empty()) continue;
        unsigned char firstChar = word[0];
        if (!isupper(firstChar)) {
            return false;
        }
    }
    return true;
}

bool isCapital(const string& word) {
    if (word.empty()) return false;

    unsigned char fc = word[0];
    return (fc >= 'A' && fc <= 'Z');
    //return isupper(fc);
}

bool checkYear(const string& str) {
    if (str.length() != 4) return false;

    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void checkFile(ifstream& file) {
    assert(file.is_open());

    string header;
    getline(file, header);
    assert(header == "Список литературы");

    string line;
    int lineNum = 2;

    while (getline(file, line)) {
        if (line.empty()) continue;

        assert(startNum(line));

        size_t firstDotPos = line.find('.');
        string dataPart = line.substr(firstDotPos + 1);

        dataPart.erase(0, dataPart.find_first_not_of(" "));

        vector<string> groups;
        size_t start = 0;
        size_t end = dataPart.find(". ");

        while (end != string::npos && groups.size() < 2) {
            groups.push_back(dataPart.substr(start, end - start));
            start = end + 2;
            end = dataPart.find(". ", start);
        }

        if (start < dataPart.length()) {
            groups.push_back(dataPart.substr(start));
        }

        assert(groups.size() == 3);

        string authorGroup = groups[0];
        string titleGroup = groups[1];
        string yearGroup = groups[2];

        authorGroup.erase(0, authorGroup.find_first_not_of(" "));
        authorGroup.erase(authorGroup.find_last_not_of(" ") + 1);

        titleGroup.erase(0, titleGroup.find_first_not_of(" "));
        titleGroup.erase(titleGroup.find_last_not_of(" ") + 1);

        yearGroup.erase(0, yearGroup.find_first_not_of(" "));
        yearGroup.erase(yearGroup.find_last_not_of(" ") + 1);


        assert(checkYear(yearGroup));
        //assert(allCapital(authorGroup));
        //assert(isCapital(titleGroup));

        lineNum++;
    }
}

int main() {

    ifstream inFile("students2.txt");
    checkFile(inFile);
    inFile.close();

    return 0;
}