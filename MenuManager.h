#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <iostream>
#include "HelpfullMethods.h"

using namespace std;

class MenuManager
{
public:
    char static choiceOptionFromMainMenu();
    char static choiceOptionFromUserMenu();
    char static choiceOptionFromEditMenu();
};


#endif
