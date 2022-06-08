//
// Created by Kutay Şenyiğit on 9.11.2021.
//

#ifndef HOMEWORK1_LABORGANIZER_H
#define HOMEWORK1_LABORGANIZER_H

#include "Cabinet.h"

class LabOrganizer{
public:
    LabOrganizer();
    ~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);
    int checkUniqueId(int id);
    int getId();
    int getRow();
    int getColumns();
    int getEmptySlots();
    int getCabinetIndex(int id);
    void addCabinetsToCabinet( Cabinet* willAdded  );
    void deleteCabinetInCabinets(int id);
    void setCabinets(int* temp);
    void itemLocationConverter(const string place , int& rowIndex , int& columnsIndex);

private:
    int numberOfCabinets;
    Cabinet** cabinets;



};


#endif //HOMEWORK1_LABORGANIZER_H
