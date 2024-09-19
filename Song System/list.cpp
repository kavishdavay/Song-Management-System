/*
    list.cpp
    Author: M00789089
    Created: 12/03/2023
    Updated: 15/04/2023
*/

#include "list.hpp"

/* Constructor that initializes an empty linked list */
LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

/* Destructor */
LinkedList::~LinkedList() {
    /* Deleting all of the nodes in the list to free up memory. */
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

/* 
    Getter method to get the size of the linked list.
    @return size Number of nodes in linked list.
*/
int LinkedList::getSize() const {
    return size;
}

/* 
    Getter method to get the pointer to the first node in the linked list.
    @return head Pointer to first node in linked list.
*/
Node* LinkedList::getHead() const {
    return head;
}

/* 
    Insertion method to add new tracks to the linked list.
    @param track Pointer to track object.
*/
void LinkedList::insert(Track* track) {
    /* Pointer to the new node created with the given track */
    Node* newNode = new Node(track);
    
    /* Add the new node to the front of the linked list */
    newNode->setNext(head);
    head = newNode;
    
    /* Increment counter for linked list */
    size++;
}

/*
    Deletion method to remove a track from the list.
    @param track Pointer to the track object.
*/
void LinkedList::remove(Track* track) {
    
    /*
        Checks if the linked list is empty first, then checks if track is in the first node,
        otherwise traverses through linked list to find track and deletes node when found.
    */
    if (head == nullptr) {
        return;
    } 
    else if (head->getTrack() == track) {
        /* Setting second node as head and deleting head node. */
        Node* oldHead = head;
        head = head->getNext();
        delete oldHead;
        size--;
        return;
    } 
    else {
        Node* current = head; // Pointer to node currently being traversed

        /* Traversing linked list */
        while (current->getNext() != nullptr) {

            /* 
                When the pointer to track in the next node to be traversed matches with the given track pointer, 
                it is considered to be the node to be removed.
                Set pointer to next node of the current node as the pointer to the node following the node to be removed,
                delete the node to be removed and decrement size counter.
            */
            if (current->getNext()->getTrack() == track) {
                Node* nodeToRemove = current->getNext();
                current->setNext(nodeToRemove->getNext());
                delete nodeToRemove;
                size--;
                return;
            }
            current = current->getNext();
        }
    }
}

/* 
    Traversal method to find a track in the linked list using the song name.
    @param songName Name of track.
    @return Pointer to a node in the list.
*/
Node* LinkedList::find(std::string songName) const {
    Node* current = head; // Pointer to current node being traversed

    /* Loop to go through all nodes in list */
    while (current != nullptr) {

        /* Returning pointer to node if song name in node matches given song name */
        if (current->getTrack()->getSongName() == songName) {
            return current;
        }
        current = current->getNext();
    }
    /* Returns a null pointer if the song is not found in the list */
    return nullptr;
}