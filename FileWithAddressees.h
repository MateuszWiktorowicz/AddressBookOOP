#ifndef FILEWITHADDRESSEES_H
#define FILEWITHADDRESSEES_H

#include <vector>

#include "Addressee.h"
#include "FileManager.h"

class FileWithAddressees : public FileManager
{
    string const NAME_OF_TEMPORARY_FILE_WITH_ADDRESSEE = "temporaryAddresseesFile.txt";
    int lastAddresseeId;

    string changeAddresseDataToLinesSeparatedByVerticalBar(Addressee addressee);
    int loadAddresseeIdFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar);
    Addressee getAddresseeData(string addresseeDatasSeparatedByBar);
    int getIdUserFromDataSeparatedByBars(string oneAddresseeDatasSeparatedByBar);
    void deleteOutOfDateFileWithAddressees();
    void changeTemporaryAddresseesFileNameToAddresseesFileName();
    int getFromFileLastAddresseeId();

public:
    FileWithAddressees(string fileName) : FileManager(fileName) {lastAddresseeId = 0;};
    vector <Addressee> loadAddresseesLogedInUserFromFile(int idLoggedInUser);
    void appendAddresseeToFile(Addressee addressee);
    int getLastAddresseeId();
    void deleteAddresseeFromFile(int deleteAddresseeId);
    void setLastAddresseeId(int id);
    void updateAddresseeDataInFile(Addressee addressee);


};

#endif
