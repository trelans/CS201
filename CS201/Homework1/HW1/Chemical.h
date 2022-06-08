//
// Created by Kutay Şenyiğit on 21.11.2021.
//


#ifndef HOMEWORK1_CHEMICAL_H
#define HOMEWORK1_CHEMICAL_H

#include <string>

using namespace std;
class Chemical {
public:
    Chemical(string type);
    Chemical(string type , int id);
    int getId();
    void setId(int id);
    string getRepresentation();
    void setRepresentation(string r);
    bool isEmpty();
private:
    int id;
    string representation;
};


#endif //HOMEWORK1_CHEMICAL_H
