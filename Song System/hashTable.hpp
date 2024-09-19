/*
    hash.hpp
    Author: M00789089
    Created: 14/03/2023
    Updated: 15/04/2023
*/

/* Opening header guard */
#ifndef _HASHTABLE_HPP_
#define _HASHTABLE_HPP_

/* 
    Including header files from standard library for:
    - Input and output functionality
    - String operations and memcpy
    - File handling
*/
#include <iostream>
#include <cstring>
#include <fstream>

/* Including linked list header file */
#include "list.hpp"

/*
    Hash table used as the data structure.
    Strong hashing technique used to generate hash keys.
    Uses separate chaining method with linked lists for collision handling.
    Member functions designed for insertion, retrieval, and deletion of data in the system.
*/
class HashTable {

    /* Declaring private member variables and function */
    private:
        int capacity; // Storage capacity of unique buckets in the hash table
        int size; // Counter for total number of tracks in the hash table
        LinkedList* table; // Array of linked lists for chaining
        
        /* Hash function */
        int hash(std::string artistName) const;

    /* Declaring public member functions */
    public:
        // Constructor
        HashTable(int capacity);
        
        // Destructor
        ~HashTable();

        // Getters
        int getCapacity();
        int getSize();
        
        // Member functions
        void add(Track* track);
        void search(std::string artistName);
        void save(std::string outputFileName) const;
        void remove(std::string artistName, std::string songName);
};

/* Closing header guard */
#endif