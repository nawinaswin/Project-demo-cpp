//
// Created by Nawin Aswin Kalpana Sakthivelan  on 5/5/22.
//

#ifndef PROBLEM5_SORTEDLIST_H
#define PROBLEM5_SORTEDLIST_H

#endif //PROBLEM5_SORTEDLIST_H

#include "LinkedNode.h"
#include "std_lib_facilities.h"

template <class T>
class SortedList {
private :
    LinkedNode<T>* m_head ;
    LinkedNode<T>* m_tail ;
public :
    SortedList () {m_head = nullptr; m_tail = nullptr;}
    SortedList ( const SortedList& source ) ;
    SortedList& operator=(const SortedList& rhs ) ;
    int getNumElems () const ;
    pair<bool , int> getElemAtIndex ( int index ) const ;
    void insertValue (LinkedNode<T>* newNode,  LinkedNode<T>** head_ref ) ;
    pair<bool , int> removeFront ( ) ;
    pair<bool , int> removeBack ( ) ;
    void printForward (LinkedNode<T>* head) const ;
    void printBackward (LinkedNode<T>* tail) const ;

    void clear( ){};
    ~SortedList ( ) ;
};

template<class T>
pair<bool, int> SortedList<T>::getElemAtIndex(int index) const {

    //LinkedNode<double> tempNode();
}

template<class T>
void SortedList<T>::printForward (LinkedNode<T>* head) const{
    LinkedNode<double>* Traverser = head;
    while(Traverser != nullptr) {
        cout<<Traverser->getValue();
        Traverser = Traverser->getNext();
    }
}

template<class T>
void SortedList<T>::printBackward(LinkedNode<T>* tail) const{
    LinkedNode<double>* Traverser = tail;
    while(Traverser != nullptr) {
        cout<<Traverser->getValue();
        Traverser = Traverser->getPrev();
    }
}

template<class T>
void SortedList<T>::insertValue(LinkedNode<T>* newNode,  LinkedNode<T>** head_ref) {

    LinkedNode<double>* current;

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

