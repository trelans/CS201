//
// Created by Kutay Şenyiğit on 15.11.2021.
//

#ifndef HOMEWORK1_CABINET_H
#define HOMEWORK1_CABINET_H
#include "Chemical.h";

using namespace std;

class Cabinet {
public:
    Cabinet(int id , int row , int columns);
    Cabinet(const Cabinet&);
    Cabinet();
    ~Cabinet();
    string toString();
    int getId();
    void setId(int no);
    int getRow();
    void setRow(int no);
    int getColumns();
    void setColumns(int no);
    int getV_columns();
    int getV_rows();
    bool isChemicalIdUnique(int id);
    Chemical* getItem(int row , int columns);
    Cabinet& operator=( const Cabinet&);
    void findCloseLocations (const string location , int& closeLocationCount , string& closeLocations);
    bool isItOkayToPlaceCombustive(string location);
    string getNearestPossiblePlaces(string location);
    string indexToStringConverter(const int row , const int columns);
    void itemLocationConverter(const string place , int& rowIndex , int& columnsIndex);
    bool isWall(int row, int columns);
    void appendString(string& , int );
    bool getChemicalIndex(int id , string& location );
    int countEmptySpaces();


private:
    int id;
    int index;
    int row;
    int columns;
    int v_row;
    int v_columns;
    Chemical*** cabinet;

};


#endif //HOMEWORK1_CABINET_H
