#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <vector>
#include <cctype>

using namespace std;

bool isCapital(const string& word) {
   if (word.empty()) return false;

   unsigned char fc = word[0];
   return (fc >= 'A' && fc <= 'Z');
   //return isupper(fc);
}

bool startNum(const string& str) {
   if (str.empty() || str.length() < 3) return false;

   size_t dotPos = str.find(". ");
   if (dotPos == string::npos || dotPos == 0) return false;

   for (size_t i = 0; i < dotPos; ++i) {
       if (!isdigit(str[i])) return false;
   }

   return true;
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
   assert(header == "Students list");

   string line;
   int lineNum = 2;

   while (getline(file, line)) {
       if (line.empty()) continue;

       assert(startNum(line));

       size_t dotPos = line.find(". ");
       assert(dotPos != string::npos);

       string dataPart = line.substr(dotPos + 2);
       istringstream iss(dataPart);
       vector<string> name;
       string token;

       while (iss >> token) {
           name.push_back(token);
       }

       assert(name.size() == 5);

       assert(checkYear(name[3]));

       int year = stoi(name[3]);
       assert(year >= 1950 && year <= 2010);

       for (const auto& word : name) {
           //assert(isCapital(word));
       }

       lineNum++;
   }
}

int main() {
   //setlocale(LC_ALL, "rus");

   ifstream inFile("students1.txt");
   checkFile(inFile);
   inFile.close();

   return 0;
}
