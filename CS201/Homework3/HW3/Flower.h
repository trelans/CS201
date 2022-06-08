//
// Created by Kutay Şenyiğit on 11.12.2021.
//
#include <iostream>
#ifndef HOMEWORK3_FLOWER_H
#define HOMEWORK3_FLOWER_H

using namespace std;

class Flower{
public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower& aFlower);
    ~Flower();
    bool isEmpty() const;
    int getLength() const ;
    bool add(string feature);
    bool remove(string feature);
    bool remove(int item) ;
    string printFlower() const;
    int compare(Flower &Flower);
    string getFlowerName();
    bool isFeatureExist(string feature);

private:
    struct FeatureNode{
        string feature;
        FeatureNode* next;
    };
    int size;
    string flowerName;
    FeatureNode *head;

    //the features are stored in a sorted singly linear linked list
// ...
//you may define additional member functions and data members, if necessary
};

#endif //HOMEWORK3_FLOWER_H
