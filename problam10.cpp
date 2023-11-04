#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
int main() {
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";
    map<string, string> wordReplacements;
    ifstream lookupFile("lookup_table.txt");
    if (!lookupFile.is_open()) {
        cerr << "Failed to open lookup table file." << endl;
        return 1;
    }
    string line;
    while (getline(lookupFile, line)) {
        size_t spacePos = line.find(' ');
        if (spacePos != string::npos) {
            string word = line.substr(0, spacePos);
            string alternative = line.substr(spacePos + 1);
            wordReplacements[word] = alternative;
        }
    }
    lookupFile.close();
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Failed to create output file." << endl;
        return 1;
    }
    string word;
    while (inputFile >> word) {
        auto it = wordReplacements.find(word);
        if (it != wordReplacements.end()) {
            outputFile << it->second << " ";
        } else {
            outputFile << word << " ";
        }
    }
    inputFile.close();
    outputFile.close();
    cout << "Message alteration completed. The result is in 'output.txt'." << endl;
    return 0;
}
