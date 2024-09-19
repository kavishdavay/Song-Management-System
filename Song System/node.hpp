/*
    node.hpp
    Author: M00789089
    Created: 12/03/2023
    Updated: 15/04/2023
*/

/* Opening header guard */
#ifndef _NODE_HPP_
#define _NODE_HPP_

/* Including track class header */
#include "track.hpp"

/* 
    Node class to create nodes in linked list.
    Each node object contains:
    - Pointer to Track object currently in the node.
    - Pointer to the next node in the linked list.
*/
class Node {

    /* Declaring private member variables */
    private:
        Track* track; // Pointer to track object.
        Node* next; // Pointer to next node in linked list.

    /* Declaring public member functions */
    public:
        /* Constructor */
        Node(Track* newTrack);
        
        /* Destructor */
        ~Node();
        
        /* Getters */
        Track* getTrack() const;
        Node* getNext() const;
        
        /* Setters */
        void setTrack(Track* newTrack);
        void setNext(Node* nextNode);
};

/* Closing header guard */
#endif