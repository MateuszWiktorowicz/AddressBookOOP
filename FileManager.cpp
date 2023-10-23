#include "FileManager.h"

bool FileManager::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string FileManager::getFileName()
{
    return FILE_NAME;
}




