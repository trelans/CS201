//
// Created by Kutay Şenyiğit on 15.11.2021.
//
#include <iostream>
#include "Cabinet.h"
#include "Chemical.h"
using namespace std;



Cabinet::Cabinet(int id , int row = 0, int columns = 0) {


    this->columns =  columns ;
    this->row = row ;
    this->id =  id ;

    // English Alphabet for naming rows
    string englishAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Generating cabinet 2D array
    row++;
    columns++;
    v_row = row;
    v_columns = columns;


    // Creating the 2d array

    cabinet = new Chemical ** [ row ];

    for ( int i = 0; i < row; i++ ) {
        cabinet[i] = new Chemical* [columns];
    }

    // Filling the cabinet
    for (int i = 0; i < v_row; ++i) {
        for (int j = 0; j < v_columns; ++j) {
            string currentStr = " ";
            if (j == 0 && i != 0) {
                currentStr[0] = englishAlphabet[i-1];
                cabinet[i][j] = new Chemical(currentStr) ;

            }
            else if ( i == 0 && j != 0) {
                currentStr[0] = 48 + j;
                cabinet[i][j] = new Chemical( currentStr) ;
            }
            else if( i == 0 && j == 0) {
                cabinet[i][j] = new Chemical( " ") ;
            }
            else {
                cabinet[i][j] = new Chemical( "+") ;
            }

        }
    }

}
Cabinet::Cabinet(const Cabinet& old) : columns(old.columns) , row(old.row) , id(old.id) , index(old.id) , v_row(old.v_row) , v_columns(old.v_columns) {
    if (columns > 0 && row > 0) {
        // creating 2d array
        cabinet = new Chemical **[v_row];
        for (int i = 0; i < v_row; ++i) {
            cabinet[i] = new Chemical* [v_columns];
        }
        // copying
        for (int i = 0; i < v_row; ++i) {
            for (int j = 0; j < v_columns; ++j) {
                cabinet[i][j]->setRepresentation(old.cabinet[i][j]->getRepresentation()) ;
            }
        }
    }
    else {
        cabinet = NULL;
    }

}
Cabinet::Cabinet() {
    columns = 0;
    row = 0;
    cabinet = NULL;
    id = 0;

}

string Cabinet::toString() {
    int t_row = row + 1;
    int t_columns = columns + 1;

    string s = "";
    for (int i = 0; i < t_columns; ++i) {
        for (int j = 0; j < t_row; ++j) {
            s = s + cabinet[i][j]->getRepresentation();
        }
        s = s + "\n";
    }
    return s;
}
// Getters and Setters

int Cabinet::getId() {
    return id;
}

void Cabinet::setId(int no) {
    id = no;
}

int Cabinet::getColumns() {
    return columns;
}

void Cabinet::setColumns(int no) {
    columns = no;
}

int Cabinet::getRow() {

    return row;
}

void Cabinet::setRow(int no) {
    row = no;
}

Cabinet::~Cabinet() {
    if (cabinet) {
        for (int i = 0; i < row; ++i) {
            delete [] cabinet[i];
        }
        delete [] cabinet;
    }

}

Chemical* Cabinet::getItem(int row, int columns) {
    if (row >= 0 && row <= this->getRow()  && columns >= 0 && columns <= this->getColumns() ) {
        return   cabinet[row][columns];
    }

    return NULL;
}

bool Cabinet::isChemicalIdUnique(int id) {
    int currentId = -1;
    for (int i = 0; i < v_row; ++i) {
        for (int j = 0; j < v_columns; ++j) {
            currentId = cabinet[i][j]->getId();
            if ( currentId == id) {
                return false;
            }
        }
    }
    return true;
}

Cabinet& Cabinet::operator=(const Cabinet& right) {
    cout << "hey";
    if ( &right != this ) { // to avoid self-assignment
        if (cabinet != NULL)
            delete [] cabinet;
        id = right.id;
        index = right.index;
        row = right.row;
        v_row = right.v_row;
        v_columns = right.v_columns;
        columns = right.columns;
        cabinet = new Chemical** [v_row];
        for ( int i = 0; i < v_row; i++ ) {
            cabinet[i] = right.cabinet[i];
        }
    }
    return *this; // to allow cascading

}

void Cabinet::appendString(string & a, int b) {
      a = a + "A";
     int size = a.length();
     a[size-1] = (b + 48);
}
void Cabinet::findCloseLocations(const string location , int &closeLocationCount, string &closeLocations) {
    int rowIndex;
    int columnIndex;
    itemLocationConverter(location, rowIndex , columnIndex);
     //  1,1  | 0,1  0,0  0,2  1,0  1,2 2,1  2,1,  2,0  2,2
     // finding close locations count
     int count  = 0;
     closeLocations = "";

    if (!isWall(rowIndex - 1,columnIndex)) {
        count++;
        string r = "";
        string c = "";
        appendString(r,(rowIndex-1));
        appendString(r,(columnIndex));


        closeLocations += r + "" + c + ",";

    }
    if (!isWall(rowIndex,columnIndex - 1)) {
        count++;
        string r =  "";
        string c = "";
        appendString(r,(rowIndex));
        appendString(r,(columnIndex-1));
        closeLocations += r + "" + c + ",";

    }
    if (!isWall(rowIndex - 1,columnIndex - 1)) {
        count++;
        string r = "";
        string c = "";
        appendString(r,(rowIndex-1));
        appendString(r,(columnIndex-1));
        closeLocations += r + "" + c + ",";
    }
    if (!isWall(rowIndex + 1,columnIndex)) {
        count++;
        string r = "";
        string c = "";
        appendString(r,(rowIndex+1));
        appendString(r,(columnIndex));
        closeLocations += r + "" + c + ",";
    }
    if (!isWall(rowIndex ,columnIndex + 1)) {
        count++;
        string r = "";
        string c = "";
        appendString(r,(rowIndex));
        appendString(r,(columnIndex+1));
        closeLocations += r + "" + c + ",";
    }
    if (!isWall(rowIndex + 1,columnIndex + 1)) {
        count++;
        string r = "";
        string c = "";
        appendString(r,(rowIndex+1));
        appendString(r,(columnIndex+1));
        closeLocations += r + "" + c + ",";
    }
    if (!isWall(rowIndex - 1,columnIndex + 1)) {
        count++;
        string r = "";
        string c = "";
        appendString(r,(rowIndex-1));
        appendString(r,(columnIndex+1));
        closeLocations += r + "" + c + ",";
    }
    if (!isWall(rowIndex + 1,columnIndex - 1)) {
        count++;
        string r = "";
        string c = "";
        appendString(r,(rowIndex+1));
        appendString(r,(columnIndex-1));
        closeLocations += r + "" + c + ",";
    }
    closeLocationCount = count;

}

bool Cabinet::isItOkayToPlaceCombustive(string location ) {
    int r , c;
    itemLocationConverter(location , r , c);
    if (!cabinet[r][c]->isEmpty()) {
        return false;
    }
    int count;
    string closeLocations; // 34,23,23,23
    findCloseLocations(location , count ,closeLocations );
    int a = 0, b = 1;
    int currentRowIndex;
    int currentColumnIndex;
    for (int i = 0; i < count; ++i) {
       currentRowIndex = closeLocations[a] - 48;
       currentColumnIndex = closeLocations[b] - 48;
        if (cabinet[currentRowIndex][currentColumnIndex]->getRepresentation() == "c") {
            return false;
        }
        a = a + 3;
        b = b + 3;
    }
    return true;
}

string Cabinet::getNearestPossiblePlaces(string location) {
    string result = "";
    string currentLocation;
    int count;
    string closeLocations; // 34,23,23,23
    findCloseLocations(location , count ,closeLocations );
    int a = 0, b = 1;
    int currentRowIndex;
    int currentColumnIndex;
    for (int i = 0; i < count; ++i) {
        currentRowIndex = closeLocations[a] - 48;
        currentColumnIndex = closeLocations[b] - 48;
        currentLocation = indexToStringConverter(currentRowIndex , currentColumnIndex);
        if (isItOkayToPlaceCombustive(currentLocation) == true) {
            result = result + currentLocation + ",";
        }
        a = a + 3;
        b = b + 3;
    }
    return result;
}

string Cabinet::indexToStringConverter(const int row, const int columns) {
    string letter = "ABCDEFGHI";
    string result = "";
    int b = columns;
    string l = "A";
    int r = row - 1 ;
    l[0] = letter[r];
    string s = "";
    appendString(s,b);
    result = l + s;
    return result;
}
 bool Cabinet::isWall(int row, int columns) {
    if ( row == 0 || columns == 0 || row == v_row || columns == v_columns ) {
        return true;
    }
     return false;
}

void Cabinet::itemLocationConverter(const string place, int &rowIndex, int &columnsIndex) {

    string letter = "ABCDEFGHI";
    for (int i = 0; i < letter.length(); ++i) {
        if (place[0] == letter[i] ){
            rowIndex = i;
        }
    }
    columnsIndex = place[1] - 49;
    columnsIndex++;
    rowIndex++;
}

bool Cabinet::getChemicalIndex(int id , string& location) {
    for (int i = 0; i < v_row; ++i) {
        for (int j = 0; j < v_columns; ++j) {
            if (cabinet[i][j]->getId() == id) {
                location = indexToStringConverter(i,j);
                return true;
            }
        }
    }
    return false;
}
int Cabinet::countEmptySpaces() {
    int a = 0;
    for (int i = 0; i < v_row; ++i) {
        for (int j = 0; j < v_columns ; ++j) {
            if( cabinet[i][j]->getRepresentation() == "+") {
                a++;
            }

        }
    }
    return a;
}
int Cabinet::getV_columns() { return v_columns;}
int Cabinet::getV_rows() {return v_row;}