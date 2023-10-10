#include "HelpfullMethods.h"

string HelpfullMethods::convertIntegerToString(int num)
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

char HelpfullMethods::readSign()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int HelpfullMethods::readNumber()
{
    string input = "";
    int num = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> num)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return num;
}
