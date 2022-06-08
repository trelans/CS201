//
// Created by Kutay Şenyiğit on 30.12.2021.
//


#include "Stack.h"

template<typename StackItemType>
    // default constructor
    Stack<StackItemType>::Stack() : topPtr(NULL){

    }
template<typename StackItemType>
    // copy constructor
    Stack<StackItemType>::Stack(const Stack<StackItemType>& aStack){

        if (aStack.topPtr == NULL)
            topPtr = NULL;  // original stack is empty

        else {
            // copy first node
            topPtr = new StackNode;
            topPtr->item = aStack.topPtr->item;

            // copy rest of stack
            StackNode *newPtr = topPtr;
            for (StackNode *origPtr = aStack.topPtr->next;
                 origPtr != NULL;
                 origPtr = origPtr->next){
                newPtr->next = new StackNode;
                newPtr = newPtr->next;
                newPtr->item = origPtr->item;
            }
            newPtr->next = NULL;
        }
    }
template<typename StackItemType>
    // destructor
    Stack<StackItemType>::~Stack(){

        // pop until stack is empty
        while (!isEmpty())
            pop();

    }
template<typename StackItemType>

    bool Stack<StackItemType>::isEmpty() const {

        return topPtr == NULL;

    }
template<typename StackItemType>
    bool Stack<StackItemType>::push(StackItemType newItem) {

        // create a new node
        StackNode *newPtr = new StackNode;

        // set data portion  of new node
        newPtr->item = newItem;

        // insert the new node
        newPtr->next = topPtr;
        topPtr = newPtr;

        return true;
    }
template<typename StackItemType>
    bool Stack<StackItemType>::pop() {

        if (isEmpty())
            return false;

            // stack is not empty; delete top
        else{
            StackNode *temp = topPtr;
            topPtr = topPtr->next;

            // return deleted node to system
            temp->next = NULL;  // safeguard
            delete temp;
            return true;
        }
    }
template<typename StackItemType>
    bool Stack<StackItemType>::pop(StackItemType& stackTop) {

        if (isEmpty())
            return false;

            // not empty; retrieve and delete top
        else{
            stackTop = topPtr->item;
            StackNode *temp = topPtr;
            topPtr = topPtr->next;

            // return deleted node to system
            temp->next = NULL;  // safeguard
            delete temp;
            return true;
        }
    }
template<typename StackItemType>
    bool Stack<StackItemType>::getTop(StackItemType& stackTop)
    const {

        if (isEmpty())
            return false;

            // stack is not empty; retrieve top
        else {
            stackTop = topPtr->item;
            return true;
        }

    }

    template class Stack<char>;
    template class Stack<int>;
    template class Stack<string>;