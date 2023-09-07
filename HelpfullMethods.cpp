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
