//
// Created by Kutay Şenyiğit on 11.12.2021.
//

#include "Flower.h"
// Constructors

Flower::Flower() : size(0) , flowerName("") , head(NULL) {}

Flower::Flower(string flowerName) : size(0) , head(NULL) {

    this->flowerName = flowerName;
}

Flower::Flower(const Flower &aFlower) {
    /*
    Flower
        - struct Feature Node
            * string feature
            * FeatureNode* next
        - size
        - flowerName
        - FeatureNode* head
 */
    if (aFlower.head == NULL) {
        head = NULL;
        size = 0 ;
    } else {
        // First we need to create new reference to copy head
        head = new FeatureNode;
        // Head's fields should be deep copied
        // Head has two field feature and next
        // Feature copied
        head->feature = aFlower.head->feature;
        // Next will be copied
        // Firstly we are creating pointer that points the copied head
        FeatureNode *copyPtr = head;
        // We iterate all FeatureNodes of old Flower (aFlower)
        for (FeatureNode *oldptr = aFlower.head-> next;
             oldptr != NULL;
             oldptr = oldptr->next)
         {
            // We create new reference to every node's next for each FeatureNode
            copyPtr-> next = new FeatureNode;
            // Then to be able to pass we change the currentCopyNode
            copyPtr = copyPtr->next;
            // We copy every next's feature
            copyPtr->feature = oldptr->feature;
        } // End of the process of the copying head

        // Flower also have  size and flowerName except FeatureNode
        size = aFlower.size;
        flowerName = aFlower.flowerName;
    }
}
// Destructor
Flower::~Flower() {
    while (!isEmpty()) remove(1);
}

// Methods

bool Flower::remove(int item){
    // The cases when it returns false
    if (item < 1 || item > size) return false;
    // if head will be removed
    if (item == 1) {
        FeatureNode *temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    } //if it is not head
    else {

        FeatureNode *prev = head;
        FeatureNode *curr = head->next;
        int i = 2;
        while (i != item) {
            prev = prev-> next;
            curr = curr-> next;
            i++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        size--;

        return true;
    }

}

string Flower::getFlowerName() {
    return flowerName;
}
bool Flower::remove(string feature) {
    if (!isFeatureExist(feature)) return false;

    if (head->feature == feature) {
        FeatureNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    } else {
        FeatureNode *prev = head;
        FeatureNode *current = head->next;
        while (current != NULL) {
            if (current->feature.compare(feature) > 0) {
                break;
            } else if (current->feature.compare(feature) == 0) {
                prev->next = current->next;
                current->next = NULL;
                --size;
                delete current;
                return true;
            }
            prev = prev->next;
            current = current->next;
        }

    }
}

int Flower::getLength() const {
    return size;
}

bool Flower::isEmpty() const {
    return size == 0;
}

int Flower::compare(Flower &flower) {
    return flowerName.compare(flower.flowerName);
}
bool Flower::add(string feature) {

    if (!isEmpty()) {
        if (isFeatureExist(feature)) {
            return false;
        }
    }
    FeatureNode *newFeatureNode = new FeatureNode;
    newFeatureNode->feature = feature;

    //If head is null, new reference will be head
    if (head == NULL) {
        head = newFeatureNode;
        size++;
        head->next = NULL;
        return true;
    }
    // We need to iterate all nodes until we find a feature that is > than current
    else {
        FeatureNode * current = head;
        if (current->feature.compare(feature) > 0 ) {
            newFeatureNode->next = head;
            head  = newFeatureNode;

        }
        else {

            while(current->next != NULL && current->next->feature.compare(feature) < 0) {
                current = current->next;
            }
            newFeatureNode->next = current->next;
            current->next = newFeatureNode;
        }
        size ++;

        return true;


    } // end of else
    return false;
}  // end of add

string Flower::printFlower() const {
    string result = flowerName + ":";
    if (head == NULL) {
        result += " No feature";
    }
    else {
        for (FeatureNode *featureNode = head; featureNode != NULL ; featureNode = featureNode->next) {
            result =  result + " " + featureNode->feature ;
        }
    }
    return result ;
}

bool Flower::isFeatureExist(string feature) {
FeatureNode *currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->feature.compare(feature) == 0) {
            return true;
        }
        currentNode = currentNode->next;
    }


    return false;
}

