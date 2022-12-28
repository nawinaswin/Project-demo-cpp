//
// Created by Nawin Aswin Kalpana Sakthivelan  on 4/26/22.
//

#ifndef PROBLEM4_SORTEDLIST_H
#define PROBLEM4_SORTEDLIST_H

#endif //PROBLEM4_SORTEDLIST_H

#include "LinkedNode.h"
#include "std_lib_facilities.h"

class SortedList {
private :
    LinkedNode* m_head ;
    LinkedNode* m_tail ;
public :
    SortedList () {m_head = nullptr; m_tail = nullptr;}
    SortedList ( const SortedList& source ) ;
    SortedList& operator=(const SortedList& rhs ) ;
    int getNumElems () const ;
    pair<bool , int> getElemAtIndex ( int index ) const ;
    void insertValue (LinkedNode* newNode,  LinkedNode** head_ref ) ;
    pair<bool , int> removeFront ( ) ;
    pair<bool , int> removeBack ( ) ;
    void printForward (LinkedNode* head) const ;
    void printBackward (LinkedNode* tail) const ;

    void clear( ){};
    ~SortedList ( ) ;
};

pair<bool, int> SortedList::getElemAtIndex(int index) const {

     //LinkedNode tempNode();
}

void SortedList::printForward (LinkedNode* head) const{
    LinkedNode* Traverser = head;
    while(Traverser != nullptr) {
        cout<<Traverser->getValue();
        Traverser = Traverser->getNext();
    }
}

void SortedList::printBackward(LinkedNode* tail) const{
    LinkedNode* Traverser = tail;
    while(Traverser != nullptr) {
        cout<<Traverser->getValue();
        Traverser = Traverser->getPrev();
    }
}


void SortedList::insertValue(LinkedNode* newNode,  LinkedNode** head_ref) {

    LinkedNode* current;

    // if list is empty
    if (*head_ref == NULL)
        *head_ref = newNode;

        // if the node is to be inserted at the beginning
        // of the doubly linked list
    else if ((*head_ref)->getValue() >= newNode->getValue()) {
        newNode->setNextPointer( *head_ref);
        newNode->getNext()->setPrevPointer(newNode);
        *head_ref = newNode;
    }

    else {
        current = *head_ref;

        // locate the node after which the new node
        // is to be inserted
        while (current->getNext() != NULL &&
               current->getNext()->getValue() < newNode->getValue())
            current = current->getNext();

        /* Make the appropriate links */
        newNode->setNextPointer(current);

        // if the new node is not inserted
        // at the end of the list
        if (current->getNext() != NULL)
            newNode->getNext()->setPrevPointer(newNode);

        current->setNextPointer(newNode);
        newNode->setPrevPointer(current);
    }
}

