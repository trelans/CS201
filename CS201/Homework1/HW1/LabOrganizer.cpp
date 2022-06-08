//
// Created by Kutay Şenyiğit on 9.11.2021.
//
#include <iostream>

using namespace std;
#include "LabOrganizer.h"


LabOrganizer::LabOrganizer() {

    numberOfCabinets = 0;
    cabinets = NULL;
}
void LabOrganizer::addCabinet(int id, int rows, int columns) {
    if (rows <= 9 && rows >= 1 && columns <= 9 && columns >= 1 ) {
        // It requires the row and columns
        if (checkUniqueId(id) != -1) {
            // Everything is okay
            Cabinet*  c = new Cabinet  ( checkUniqueId(id), rows ,columns);
            if (numberOfCabinets == 0) {
                cabinets = new Cabinet*[1];
                cabinets[0] = c;
            } else{
                addCabinetsToCabinet (c);
            }
            numberOfCabinets++;
          //  cabinets[numberOfCabinets - 1 ] = c;
            cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
        } else{
            // cabinet id has taken
            cout << "Cannot add the cabinet: ID " << id << " already in the system" << endl;
        }
    } else {
        // Column and row number is wrong
        cout << "Cannot add the cabinet: dimensions are out of bounds" << endl;
    }


}
void LabOrganizer::removeCabinet(int id) {
    int indexOfCabinet = getCabinetIndex(id);
    if (indexOfCabinet == -1) {
        cout << "Cabinet " << id  << " does not exist in the system" <<  endl;
    }
    else {
        // remove
        deleteCabinetInCabinets(id);
         numberOfCabinets--;
        cout << "Cabinet " << id << " has been removed" << endl;
        // delete cabinets[indexOfCabinet];
    }

}
void LabOrganizer::listCabinets() {
    cout << "List of all cabinets:" << endl;

    for (int i = 0; i < numberOfCabinets; ++i) {

        // Getting information of cabinets
        int currentId = cabinets[i]->getId();
        int currentRow = cabinets[i]->getRow();
        int currentColumns = cabinets[i]->getColumns();
        int currentEmptySlotCount= cabinets[i]->countEmptySpaces();

        cout << "ID: " << currentId << ", Dim:" << currentRow << "x" << currentColumns << ", Number of empty slots: " << currentEmptySlotCount << endl;


        }
    }

void LabOrganizer::cabinetContents(int id) {

    int index =  getCabinetIndex(id);
    if (index != -1 ) {
        cout << cabinets[index]->toString();
    }
    else {
        cout << "Cabinet " << id << " is not in the system" << endl;
    }


}
void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    bool isUnique = true;
    //location is like A2
    int rowIndex , columnsIndex;
    itemLocationConverter(location,rowIndex,columnsIndex);
    int index = getCabinetIndex(cabinetId);
    if (index == -1) {
        cout << "Cabinet " << cabinetId << " is not in the system" << endl;
    }
    else {
        // checks if it is a unique id
        for (int i = 0; i < numberOfCabinets; ++i) {
            if (!cabinets[i]->isChemicalIdUnique(chemID)) {
                // Chem Id is not unique
                isUnique = false;
                cout << "Chemical with ID " << chemID << " already exists in the system!" << endl;
            }
        }
        if (isUnique) {
            if (  cabinets[index]->getItem(rowIndex,columnsIndex) != NULL ) {
                if (cabinets[index]->getItem(rowIndex,columnsIndex)->getRepresentation() == "+") {
                    // is empty
                    if (chemType == "retardant") {
                        // does not check just places
                        cabinets[index]->getItem(rowIndex,columnsIndex)->setId( chemID );
                        cabinets[index]->getItem(rowIndex,columnsIndex)->setRepresentation("r");
                        cout << "Retardant chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << cabinetId << endl;
                    }
                    else if (chemType == "combustive") {
                        if (cabinets[index]->isItOkayToPlaceCombustive(location)) {
                            // places
                            cabinets[index]->getItem(rowIndex,columnsIndex)->setId( chemID );
                            cabinets[index]->getItem(rowIndex,columnsIndex)->setRepresentation("c");
                            cout << "Combustive chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << cabinetId << endl;
                        }
                        else {
                            // finds possible places and prints it
                            string possibleLocations = cabinets[index]->getNearestPossiblePlaces(location);
                            cout << "Location " << location << " in cabinet " << cabinetId << " is not suitable for a combustive chemical. Nearest possible locations for this chemical:" << possibleLocations << endl;
                            // maybe I cann add print for no possible locations nearby
                        }
                    }
                    else {
                        cout << "Invalid element type!";
                    }

                }
                else {
                    cout << "Location " <<  location << " in cabinet " << cabinetId << " is already occupied. " << endl;
                    // todo nearest possible
                }


            }
            else {
                cout << "Dimension " << location << " does not exist in the cabinet" << endl;
            }
        }

    }


}
void LabOrganizer::itemLocationConverter(const string place, int &rowIndex, int &columnsIndex) {
    string letter = "ABCDEFGHI";
    for (int i = 0; i < letter.length(); ++i) {
        if (place[0] == letter[i] ){
            rowIndex = i ;
        }
    }
     columnsIndex = place[1] - 49;
    columnsIndex++;
    rowIndex++;
    }


void LabOrganizer::findChemical(int id) {
    string location;
    bool isFound = false;
    for (int i = 0; i < numberOfCabinets; ++i) {
        if (cabinets[i]->getChemicalIndex(id, location)) {
            int cabinetId = cabinets[i]->getId();
            cout << "Chemical " << id << " is at location " << location << " in cabinet " << cabinetId << endl;
            isFound = true;
        }
    }
    if(!isFound) {
        cout << "Chemical "<< id << "is not in the system " << endl;
    }
}
void LabOrganizer::removeChemical(int id) {
    int cabinetNo;
    string location;
    bool isRemoved = false;
    for (int i = 0; i < numberOfCabinets; ++i) {
        if (cabinets[i]->getChemicalIndex(id, location)) {
            int row , columns;
            int cabinetId = cabinets[i]->getId();
            cabinets[i]->itemLocationConverter(location,row , columns);
            cabinets[i]->getItem(row , columns)->setRepresentation("+");
            cabinets[i]->getItem(row , columns)->setId(-1);
            cout << "Chemical " << id << " removed from cabinet " << cabinetId << endl;
            isRemoved = true;

        }
    }
    if(!isRemoved) {
        cout << "Chemical "<< id << "is not in the system " << endl;
    }

}
int LabOrganizer::checkUniqueId(int id) {
    for (int i = 0; i < numberOfCabinets; ++i) {
        if ( cabinets[i]->getId() == id) {
            // id has taken
            return -1;
        }
    }
    return id;
}

int LabOrganizer::getCabinetIndex(int id) {
    for (int i = 0; i < numberOfCabinets; ++i) {
        if (cabinets[i]->getId() == id) {
            return i;
        }
    }

        return -1;

}

void LabOrganizer::addCabinetsToCabinet(Cabinet* willAdded) {
    int newSize = numberOfCabinets + 1;

    Cabinet **temp = new Cabinet*[numberOfCabinets];
    temp = cabinets;
    cabinets = new Cabinet*[newSize];
    for (int i = 0; i < newSize; ++i) {
        if (i != numberOfCabinets)
             cabinets[i] = temp[i];
        else
             cabinets[i] = willAdded;
    }

   delete [] temp;

}

void LabOrganizer::deleteCabinetInCabinets(int id) {
    int newSize = numberOfCabinets - 1;
    int indexDeleting = getCabinetIndex(id);
    Cabinet** temp = cabinets;
    cabinets = new Cabinet* [newSize];
    int j = 0;
    for (int i = 0; i < numberOfCabinets; ++i) {
        if (i == indexDeleting) {
            i++;
        }
        cabinets[j] = temp[i];

        j++;
    }
   delete [] temp;

}

LabOrganizer::~LabOrganizer() {
 delete [] cabinets;
}

