//
// Created by Nawin Aswin Kalpana Sakthivelan  on 5/5/22.
//

#ifndef PROBLEM5_LINKEDNODE_H
#define PROBLEM5_LINKEDNODE_H

#endif //PROBLEM5_LINKEDNODE_H

// to make a template class for Sorted list data structure you only have to change LinkedNode class what type of data
// the node's value is going to store.
template <class T>
class LinkedNode {
private :
    T m_nodeValue;
    LinkedNode* m_prevNode ;
    LinkedNode* m_nextNode ;
public :

    LinkedNode ( T value , LinkedNode* prev , LinkedNode* next ) {
        m_prevNode = prev;
        m_nodeValue = value;
        m_nextNode = next;}
    int getValue () const{
        return m_nodeValue;}
    LinkedNode* getPrev() const{
        return m_prevNode;}
    LinkedNode* getNext() const{
        return m_nextNode;}
    void setPreviousPointerToNull(){
        m_prevNode = nullptr;}
    void setNextPointerToNull(){
        m_nextNode = nullptr;}
    void setBeforeAndAfterPointers (LinkedNode* next, LinkedNode* prev){
        m_nextNode = next;
        m_prevNode = prev;
    }
    void setPrevPointer(LinkedNode* node){
        m_prevNode = node->getPrev();
    }
    void setNextPointer(LinkedNode* node){
        m_nextNode = node->getNext();
    }

};
