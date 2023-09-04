#include "helpfullMethods.h"

string HelpfullMethods::convertIntoString(int num)
{
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}
