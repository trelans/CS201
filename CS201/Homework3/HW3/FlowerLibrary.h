//
// Created by Kutay Şenyiğit on 11.12.2021.
//

#ifndef HOMEWORK3_FLOWERLIBRARY_H
#define HOMEWORK3_FLOWERLIBRARY_H


#include "FlowerList.h"
class FlowerLibrary{
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(string name);
    void removeFlower(string name);
    void listFlowers() const;
    void listFeatures(string name) const;
    void addFeature(string name,string feature);
    void removeFeature(string name, string feature);
    void findFlowers(string feature) const;
    string toLowerCase(string s);
private:
    FlowerList flowers;
// ...
//you may define additional member functions and data members, if necessary
};

#endif //HOMEWORK3_FLOWERLIBRARY_H
