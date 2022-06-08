//
// Created by Kutay Şenyiğit on 21.11.2021.
//

#include "Chemical.h"

using namespace std;

Chemical::Chemical(string type) {
   representation = type ;
   id = -1;
}
Chemical::Chemical(string type , int id) {
   this->id = id;
}
string Chemical::getRepresentation() {
    return representation ;
}

void Chemical::setId(int id) {
     this->id = id;
}

int Chemical::getId() {
    return id;
}

void Chemical::setRepresentation(string r) {
representation = r;
}

bool Chemical::isEmpty() {
    if (representation == "+") {
        return true;
    }
    return false;
}
