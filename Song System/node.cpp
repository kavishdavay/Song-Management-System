/*
    node.cpp
    Author: M00789089
    Created: 12/03/2023
    Updated: 15/04/2023
*/

#include "node.hpp"

/* 
    Constructor that initializes node with a track.
    @param newTrack Pointer to track object. 
*/
Node::Node(Track* newTrack) {
    track = newTrack;
    next = nullptr;
}

/* Destructor */
Node::~Node() {}

/* 
    Getter method for pointer of track object currently in node
    @return Pointer to track object currently in node
*/
Track* Node::getTrack() const {
    return track;
}

/* 
    Getter method for pointer of next node in linked list
    @return Pointer to next node
*/
Node* Node::getNext() const {
    return next;
}

/* 
    Setter method for pointer to track object in node
    @param newTrack Pointer to current track object
*/
void Node::setTrack(Track* newTrack) {
    track = newTrack;
}

/* 
    Setter method for pointer to next node in linked list
    @param nextNode Pointer to next node in linked list
*/
void Node::setNext(Node* nextNode) {
    next = nextNode;
}