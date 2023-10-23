#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>

#include "HelpfullMethods.h"



#include <fstream>

using namespace std;

class FileManager
{
    const string FILE_NAME;
protected:
    FileManager(string fileName) : FILE_NAME(fileName) {}
    bool isFileEmpty(fstream &textFile);
    string getFileName();
};


#endif
