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
