#ifndef HELPFULLMETHODS_H
#define HELPFULLMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class HelpfullMethods
{
public:
   static string convertIntegerToString(int num);
   static string readLine();
   static string uppercaseFirstLetterLowercaseElseLetters(string text);
   static string getNumber(string text, int signPosition);
   static int convertStringIntoInt(string num);
   static char readSign();
   static int readNumber();
};

#endif
