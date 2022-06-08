//
// Created by Kutay Şenyiğit on 11.12.2021.
//

#include "FlowerList.h"


FlowerList::FlowerList() : size(0) , head(NULL){

}

// will test
FlowerList::FlowerList(const FlowerList &aList) {

    if (aList.head == NULL) {
        size = 0;
        head = NULL;
    } else {
        FlowerNode *newHead = new FlowerNode;
        head = newHead;

        size = aList.size;
        for (FlowerNode *current = aList.head ; current != NULL; current = current->next) {
            FlowerNode* createdNode = new FlowerNode;
             createdNode->f =  current->f;
             createdNode->next = current->next;
        }

    }


}
FlowerList:: ~FlowerList() {
        while(size != 0) {
            remove(1);
        }
}

bool FlowerList::isEmpty() const {
 return size == 0;
}

int FlowerList::getLength() const {
    return size;
}
bool FlowerList::add(string flowerName) {
    if (isFlowerExist(flowerName))  {
        return false;
    }
    else {

        FlowerNode *newFlowerNode = new FlowerNode();
        Flower newFlower(flowerName);
        newFlowerNode->f = newFlower;

        if (head == NULL) {
            head = newFlowerNode;
        } else {
            FlowerNode* current = head;
            if (current->f.compare(newFlower) > 0 ) {
                newFlowerNode->next = head;
                head = newFlowerNode;
            }
            else {
                while(current->next != NULL && current->next->f.compare(newFlower) < 0) {
                    current = current->next;
                }
                newFlowerNode->next = current->next;
                current->next = newFlowerNode;
            }
        }
        size ++;
        return true;
    }



}
bool FlowerList::remove(string flowerName) {
    Flower flower(flowerName);
    if (size == 1 || head->f.getFlowerName() == flowerName) {
        if (head->f.getFlowerName() == flowerName) {
            FlowerNode *temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        FlowerNode *prev = head;
        for (FlowerNode *current = head->next ;
             current->f.compare(flower) <= 0
                ; current = current->next) {
            if (current->f.compare(flower) == 0) {

                prev->next = current->next;
                current->next = NULL;
                --size;
                delete current;
                return true;
            }
            prev = prev->next;
        } // end of for
    }
    return false;
}

bool FlowerList::remove(int index) {
    // The cases when it returns false
    if (index < 1 || index > size) return false;
    // if head will be removed
    if (index == 1) {
        FlowerNode *temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    } //if it is not head
    else {

        FlowerNode *prev = head;
        FlowerNode *curr = head->next;
        int i = 2;
        while (i != index) {
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

bool FlowerList::retrieve(string flowerName, Flower &flower) const {
    FlowerNode* current = head;

    while (current != NULL && current->f.getFlowerName().compare(flowerName) != 0 ) {

        current = current->next;

    }
    if(current == NULL) {
        // does not exist
        return false;
    } else {
        flower = current->f;
        return true;
    }

}
bool FlowerList::retrieve(string flowerName, Flower *& flower) const {
    FlowerNode* current = head;

    while (current != NULL && current->f.getFlowerName().compare(flowerName) != 0 ) {

        current = current->next;

    }
    if(current == NULL) {
        // does not exist
        return false;
    } else {
        flower = &current->f;
        return true;
    }

}
string FlowerList::printSameFeatures(string feature) const {
    string result = feature + " flowers: ";
    bool isFirst = true;
    for (FlowerNode *flowerNode = head; flowerNode != NULL ; flowerNode = flowerNode->next) {

        if (flowerNode->f.isFeatureExist(feature)) {
            if (!isFirst) result+= ", ";
            result = result + flowerNode->f.getFlowerName() ;
            isFirst = false;
        }

    }
    if (result.compare(feature + " flowers: ") == 0) {
        result += "there is no such flower";
    }

    result += "\n";
    return result;
}

string FlowerList::printFlowers() const {

    string result = "";

    if (head == NULL) {
        result += " No flowers";
    }
    else {
        for (FlowerNode *flowerNode = head; flowerNode != NULL ; flowerNode = flowerNode->next) {
            result = result + flowerNode->f.printFlower() + "\n";
        }
    }
    return result ;
}

bool FlowerList::isFlowerExist(string flowerName) {

    for (FlowerNode *flowerNode = head; flowerNode != NULL ; flowerNode = flowerNode->next) {
        if (head->f.getFlowerName().compare(flowerName) == 0) {
            return true;
        }
    }
    return false;
}

