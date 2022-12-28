//
// Created by Nawin Aswin Kalpana Sakthivelan  on 4/26/22.
//

#ifndef PROBLEM4_LINKEDNODE_H
#define PROBLEM4_LINKEDNODE_H

#endif //PROBLEM4_LINKEDNODE_H

class LinkedNode {
private :
    int m_nodeValue ;
    LinkedNode* m_prevNode ;
    LinkedNode* m_nextNode ;
public :

    LinkedNode ( int value , LinkedNode* prev , LinkedNode* next ) {
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
    void setBeforeAndAfterPointers (LinkedNode* node){
        m_nextNode = node->getNext();
        m_prevNode = node->getPrev();
    }
    void setPrevPointer(LinkedNode* node){
        m_prevNode = node->getPrev();
    }
    void setNextPointer(LinkedNode* node){
        m_nextNode = node->getNext();
    }

};
