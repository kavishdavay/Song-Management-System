/*
    hash.cpp
    Author: M00789089
    Created: 14/03/2023
    Updated: 15/04/2023
*/

#include "hashTable.hpp"

/* 
    Hash function to generate hash keys from artist name.
    Based on MurmurHash3 algorithm to reduce chances of unwanted collisions.
    Uses bit shifting, XOR and multiplication methods to generate unique hash keys.
    Each change in character or position of character in the artist name causes a change in the generated hash key.

    @param artistName Artist name of track
    @return Generated hash key
*/
int HashTable::hash(std::string artistName) const {
    const uint64_t primeNum = 0xc6a4a7935bd1e995; // Constant large prime number in hex
    const uint64_t seed = 0xe17a1465; // 64-bit seed to improve distribution
    const int rotation = 47; // Rotation constant

    /* 
        Initialized using multiplication hashing method with length of artist name and prime number.
        XOR result of multiplication with seed.
    */
    uint64_t hashKey = seed ^ (artistName.length() * primeNum);

    /*
        Iterating over each position in artist name and storing integer representation of character at the position in variable 'code'.
        Using multiplication, bit-shifting and XOR operations to generate hash value based on character value and position in artist name.
    */
    for (unsigned int i = 0; i < artistName.length(); i++) {
        uint64_t code = artistName[i];
        code *= primeNum; 
        code ^= code >> rotation; // Right-shifting with rotation constant and XOR-ing 'code' with rotated value.
        code *= primeNum;
        hashKey ^= code;
        hashKey *= primeNum;
    }

    /* Performing further right-shifting, multiplication and bitwise XOR on resultant hash key to generate well distributed key */
    hashKey ^= hashKey >> rotation;
    hashKey *= primeNum;
    hashKey ^= hashKey >> rotation;

    /* 
        Performing modulo operation to ensure generated key falls within range of buckets in hash table.
        Casting from uint64_t to int and returning resultant hash key.
    */
    return static_cast<int>(hashKey % capacity);
}

/* 
    Constructor that initializes an empty hash table with a given capacity.
    @param capacity Size of the hash table.
*/
HashTable::HashTable(int capacity) : capacity(capacity), size(0) {
    /* Allocate memory for the array of linked lists */
    table = new LinkedList[capacity];
}

// Destructor
HashTable::~HashTable() {
    delete[] table;
}

/* 
    Getter method for capacity of hash table.
    @return Capacity of hash table
*/
int HashTable::getCapacity() {
    return capacity;
}

/* 
    Getter method for size of hash table.
    @return Size of hash table
*/
int HashTable::getSize() {
    return size;
}

/* 
    Insertion method which gets generated hash key using artist name, 
    checks if track already exists in linked list at hashed index, 
    otherwise insert into linked list at hashed index.

    @param track Pointer to track object
*/
void HashTable::add(Track* track) {

    int index = hash(track->getArtistName());
    
    /* Pointer to track in the linked list at the hashed index */
    Node* current = table[index].find(track->getSongName());

    /* If the track already exists the pointer stored in 'current' variable will not be null */
    if (current != nullptr) {
        std::cout << "Already exists | " << track->getSongName() << " - " << track->getArtistName() << std::endl;
    } else {
        /* Inserting the track into the linked list at the hashed index */
        table[index].insert(track);
        std::cout << "Added : " << track->getSongName() << " - " << track->getArtistName() << " | Duration: " << track->getDuration() << "s" << std::endl;
        /* Incrementing the size count */
        size++;
    }
}

/* 
    Retrieval method which uses the artist name to locate a specific track in the array of linked lists.
    Stores all of the tracks found in an array and prints searched results.

    @param artistName Artist name of track.
*/
void HashTable::search(std::string artistName) {

    /* 
        Double pointer to array for results.
        Initialized with the size of total number of tracks in the hash table. 
    */
    Track** result = new Track*[size];

    /* Counter for number of results found. */
    int count = 0;
    
    /* Gets hash index using artist name. */
    int index = hash(artistName);
    
    /* Gets pointer to first node in linked list at hashed index. */
    Node* current = table[index].getHead();
    
    /* 
        Loop for traversal of linked list. 
        Storing found tracks in result array and incrementing count. 
    */
    while (current != nullptr) {
        result[count++] = current->getTrack();
        current = current->getNext();
    }
    
    /* Initializing array with size of actual number of tracks found. */
    Track** resizedResult = new Track*[count];

    /* Copying tracks from result array to resized array. */
    std::memcpy(resizedResult, result, count * sizeof(Track*));

    /* Checking if no tracks were found and printing message */
    if (count == 0) {
        std::cout << "\n\nNo songs found by artist/band: " << artistName << std::endl;
    }
    /* If there are tracks found, go through array, get track details, and print results in a user friendly format. */
    else {
        std::cout << "\n\nSearch results for artist/band: " << artistName << ":\n\n" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << resizedResult[i]->getSongName() << " - " << resizedResult[i]->getArtistName() << " (" << resizedResult[i]->getDuration() << "s)" << std::endl;
        }
    }

    /* Deleting arrays used to prevent memory leaks. */
    delete[] result;
    delete[] resizedResult;
}

/* 
    Retrieval method to get all of the tracks stored in the hash table and saving to a file.

    @param outputFileName Name of the file where tracks should be saved.
*/
void HashTable::save(std::string outputFileName) const {

    /* Double pointer to an array with the size of total number of tracks stored in hash table. */
    Track** result = new Track*[size];

    /* Initializing count for tracks found */
    int count = 0;

    /* Add all tracks from all linked lists in the hash table to array */
    for (int i = 0; i < capacity; i++) {
        Node* current = table[i].getHead();
        while (current != nullptr) {
            result[count++] = current->getTrack();
            current = current->getNext();
        }
    }

    /* 
        Writing results to the output file.
        Each line has a single track.
        Song name, artist name and duration are all separated by a tab.
    */
    std::ofstream outfile(outputFileName);
    if (outfile) {
        for (int i = 0; i < count; i++) {
            Track* track = result[i];
            outfile << track->getSongName() << "\t" << track->getArtistName() << "\t" << track->getDuration() << std::endl;
        }
        std::cout << "\n\nSuccessfully saved to: " << outputFileName << std::endl;
    } else {
        std::cout << "\n\nUnable to open file '" << outputFileName << "' for writing" << std::endl;
    }

    /* Deleting array to prevent memory leaks */
    delete[] result;
}

/* 
    Deletion method using song and artist names.
    Goes to the hashed index using the artist name, 
    and traverses through linked list until song name is found.
    Uses deletion method from linked list to remove track from list and decrements size counter.

    @param artistName Artist name of track.
    @param songName Name of track.
*/
void HashTable::remove(std::string artistName, std::string songName) {
    /* Gets the hash code for the artist name */
    int index = hash(artistName);
    
    /* Searching for the track in the linked list at the hashed index */
    Node* current = table[index].find(songName);

    /* Checks if track exists or not and prints message */
    if (current == nullptr) {
        std::cerr << "\n\n" << songName << " was not found!" << std::endl;
    } else {
        /* Remove the track from the linked list */
        table[index].remove(current->getTrack());
        size--;
        std::cout << "\n\n'" << songName << "' was removed!" << std::endl;
    }
}