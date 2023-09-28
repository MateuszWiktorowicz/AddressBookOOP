#include "HelpfullMethods.h"

string HelpfullMethods::convertIntoString(int num)
{
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

string HelpfullMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string HelpfullMethods::uppercaseFirstLetterLowercaseElseLetters(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string HelpfullMethods::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

int HelpfullMethods::convertStringIntoInt(string num)
{
    int intNumber;
    istringstream iss(num);
    iss >> intNumber;

    return intNumber;
}
