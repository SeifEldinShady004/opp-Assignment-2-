#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Define a function named 'split' that takes two input strings:
// - 'target' is the string to be split.
// - 'delimiter' is the string used to split 'target'.
std::vector<std::string> split(const std::string& target, const std::string& delimiter) {
    // Create a vector of strings to store the result.
    std::vector<std::string> result;

    // Initialize position variables for string searching.
    size_t pos = 0;      // The current position in the 'target' string.
    size_t start = 0;    // The starting position for the next search.

    // Use a while loop to find all occurrences of 'delimiter' in 'target'.
    while ((pos = target.find(delimiter, start)) != std::string::npos) {
        // Push the substring between 'start' and 'pos' into the 'result' vector.
        result.push_back(target.substr(start, pos - start));

        // Move the 'start' position after the delimiter for the next search.
        start = pos + delimiter.length();
    }

    // Push the last substring (or the only substring if there are no delimiters) into the 'result'.
    result.push_back(target.substr(start));

    
    return result;
}

int main() {
    
    std::string input1 = "10,20,30";
    std::string delimiter1 = ",";
    std::vector<std::string> result1 = split(input1, delimiter1);

    // Print the result of splitting 'input1' using ',' as the delimiter.
    for (const std::string& s : result1) {
        std::cout << s << std::endl;
    }

   
    std::string input2 = "do re mi fa so la ti do";
    std::string delimiter2 = " ";
    std::vector<std::string> result2 = split(input2, delimiter2);

    // Print the result of splitting 'input2' using ' ' (space) as the delimiter.
    for (const std::string& s : result2) {
        std::cout << s << std::endl;
    }

   
    return 0;
}
