//
// Created by Kutay Şenyiğit on 11.12.2021.
//

#include "FlowerLibrary.h"

FlowerLibrary::FlowerLibrary() {

}
FlowerLibrary:: ~FlowerLibrary() {
    flowers.~FlowerList();

}

void FlowerLibrary::addFlower(string name) {
    name = toLowerCase(name);
    if (flowers.add(name)) {
        cout << name << " has been added into the library." << endl;
    } else {
        cout << name << " cannot be added into the library because it already exists." << endl;
    }

}

void FlowerLibrary::removeFlower(string name) {
    name = toLowerCase(name);
    if (flowers.remove(name)) {
        cout << name << " has been removed from the library." << endl;
    } else {
        cout << name << " cannot be removed because it's not in the library." << endl;
    }

}

void FlowerLibrary::listFlowers() const {
    if (flowers.isEmpty()) {
    cout << "Library is empty." << endl;
    } else {
        cout << flowers.printFlowers();
    }

}

void FlowerLibrary::listFeatures(string name) const {
    Flower *f;
    if (flowers.retrieve(name , f) ) {
        cout << f->printFlower() << endl;
    } else {
        cout << name << " isn't found in library";
    }

}

void FlowerLibrary::addFeature(string name, string feature) {
    name = toLowerCase(name);
    Flower *f ;
    if (flowers.retrieve(name , f) == true) {
        if (f->add(feature)) {
            // success
            cout << feature <<" is added into " << name << endl;
        }
        else {
            cout << feature << " already exists in" << name << endl;
        }

    } else {
        // error
        cout << name << " isn't found in library" << endl;
    }
}

void FlowerLibrary::removeFeature(string name, string feature) {
    Flower* f;
    if (flowers.retrieve(name , f) == true) {
        if ( f->remove(feature)) {
            cout << feature << " is removed from " << name << endl;
        }
        else {
            cout << feature << " doesn't exist in " << name << endl;
        }

    } else {
        // error
        cout << name << " isn't found in library" << endl;
    }
}

void FlowerLibrary::findFlowers(string feature) const {
   cout << flowers.printSameFeatures(feature);
}
string FlowerLibrary::toLowerCase(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ')
            s[i] = tolower(s[i]);
    }

    return s;
}