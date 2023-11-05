// File: A2_S6_20220160_Problem1.cpp
// Purpose: This program will correct the spacing, capitalization, and ensure the sentence ends with a period as described in your request. It treats line breaks as spaces and compresses multiple spaces into a single space. 
// Author:seif eldin shady abdelsalam
// Section:S6
// ID:20220160
// TA:maya ahmed 
// Date: 5 Nov 2023
#include <iostream>
#include <string>

using namespace std;

string correctSentence(string sentence)
{
    // Replace multiple spaces, line breaks, and tabs with a single space
    string corrected_sentence = "";
    bool isSpace = false; // To track consecutive spaces

    for (char c : sentence)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            // If it's a space, set the flag to true
            isSpace = true;
        }
        else
        {
            // If it's not a space, add a space to the corrected sentence if needed
            if (isSpace)
            {
                corrected_sentence += ' ';
                isSpace = false;
            }
            // Append the lowercase character to the corrected sentence
            corrected_sentence += tolower(c);
        }
    }

    // Capitalize the first letter of the sentence
    if (!corrected_sentence.empty())
    {
        corrected_sentence[0] = toupper(corrected_sentence[0]);
    }

    // Ensure the sentence ends with a period
    if (!corrected_sentence.empty() && corrected_sentence.back() != '.')
    {
        corrected_sentence += '.';
    }

    return corrected_sentence;
}

int main()
{
    cout << "Enter a sentence (up to 100 characters): ";
    string input_sentence;
    getline(cin, input_sentence);

    if (input_sentence.length() <= 100)
    {
        string corrected_output = correctSentence(input_sentence);
        cout << corrected_output << endl;
    }
    else
    {
        cout << "Input sentence is too long. Please keep it within 100 characters." << endl;
    }

    return 0;
}
