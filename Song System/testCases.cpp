/*
    testCases.cpp
    Author: M00789089
    Created: 14/03/2023
    Updated: 21/04/2023
*/

#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "hashTable.hpp"

TEST_CASE("HashTable constructor creates an array of linked lists with given capacity") {
    // Test case with capacity of 10
    int capacity = 10;
    HashTable hashTable(capacity);
    REQUIRE(hashTable.getCapacity() == capacity);
    REQUIRE(hashTable.getSize() == 0);
}

TEST_CASE("Add function - Adding a new track to an empty HashTable") {
    HashTable table(5);
    Track* track1 = new Track("Song1", "Artist1", 180);
    
    table.add(track1);
    
    REQUIRE(table.getSize() == 1);
}

TEST_CASE("Add function - Adding a track that already exists in the HashTable") {
    HashTable table(5);
    Track* track1 = new Track("Song1", "Artist1", 180);
    Track* track2 = new Track("Song1", "Artist1", 240);
    
    table.add(track1);
    table.add(track2);
    
    REQUIRE(table.getSize() == 1);
}

TEST_CASE("Add function - Adding multiple tracks to the HashTable") {
    HashTable table(5);
    Track* track1 = new Track("Song1", "Artist1", 180);
    Track* track2 = new Track("Song2", "Artist2", 240);
    Track* track3 = new Track("Song3", "Artist3", 120);
    
    table.add(track1);
    table.add(track2);
    table.add(track3);
    
    REQUIRE(table.getSize() == 3);
}


TEST_CASE("Remove a track from the hash table") {
    // Initialize hash table and add some tracks
    HashTable table(10);
    Track t1("Track1", "Artist1", 180);
    Track t2("Track2", "Artist2", 240);
    table.add(&t1);
    table.add(&t2);

    // Remove a track that exists in the hash table
    table.remove("Artist1", "Track1");
    REQUIRE(table.getSize() == 1);

    // Try to remove a track that doesn't exist in the hash table
    table.remove("Artist1", "Track1");
    REQUIRE(table.getSize() == 1);
}

#endif