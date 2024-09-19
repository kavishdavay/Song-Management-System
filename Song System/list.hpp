/*
    list.hpp
    Author: M00789089
    Created: 12/03/2023
    Updated: 15/04/2023
*/

/* Opening header guard */
#ifndef _LIST_HPP_
#define _LIST_HPP_

/* Including node header */
#include "node.hpp"

/*
    Linked list class uses nodes from node class to form a singly linked list object.
    Has insertion, traversal and deletion methods to manipulate and retrieve data from the list.
*/
class LinkedList {

    /* Declaring private member variables */
    private:
        Node* head; // Pointer to the first node in the linked list.
        int size; // Counter for number of nodes created in list.

    /* Declaring public member functions */
    public:
        /* Constructor */
        LinkedList();
        
        /* Destructor */
        ~LinkedList();
        
        /* Getters */
        int getSize() const;
        Node* getHead() const;
        
        /* Member functions */
        void insert(Track* track);
        void remove(Track* track);
        Node* find(std::string songName) const;
};

/* Closing header guard */
#endif