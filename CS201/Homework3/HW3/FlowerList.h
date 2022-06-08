//
// Created by Kutay Şenyiğit on 11.12.2021.
//

#ifndef HOMEWORK3_FLOWERLIST_H
#define HOMEWORK3_FLOWERLIST_H


#include "Flower.h"
class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    bool remove(int index);
    string printFlowers() const;
    string printSameFeatures(string feature) const;
    bool isFlowerExist(string flowerName ) ;
    bool retrieve(string flowerName, Flower*& flower) const;

private:
    struct FlowerNode{
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head; //the flowers are stored in a sorted singly linear linked list
// ...
//you may define additional member functions and data members, if necessary
};

#endif //HOMEWORK3_FLOWERLIST_H
