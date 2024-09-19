/*
    songSystem.cpp
    Author: M00789089
    Created: 14/03/2023
    Updated: 15/04/2023
*/

/* Including hash table header */
#include "hashTable.hpp"

/* 
      Main menu for song system.
      @return Status of program execution.
*/
int main() {

      /* 
            Hash table with a capacity of over 100 million.
            System can store songs from 100,000,007 unique artists/bands at maximum.
      */
      HashTable* hashTable = new HashTable(100000007);
      
      bool quit = false; // Exit program check.

      /* Loop menu until user decides to exit program. */
	while(quit == false){

        std::cout << std::endl << "\n************* MUSIC LIBRARY *************" << std::endl
                    << "\n1. Add songs to library" << std::endl
                    << "2. Search by artist" << std::endl
                    << "3. Remove a song from the library" << std::endl
                    << "4. Save the library to a file" << std::endl
                    << "5. Quit" << std::endl
                    << "\n*****************************************" << std::endl
                    << "\nEnter a number to choose an option: ";

		std::string Choice; 
            std::cin>>Choice; // Gets user choice input.
		
            /* Checking which choice was entered. */
		if(Choice == "1") {
            
                  /* Prompting user to enter a file name from which songs will be added. */
                  std::cout << "\nEnter filename: ";
                  std::string filename;
                  std::cin.ignore();

                  /* Used getline to allow for file names with spaces. */
                  std::getline(std::cin, filename);
                  std::cout << "\n";

                  /* Open the input file with given name */
                  std::ifstream infile(filename);

                  /* Prints error if file could not be opened. */
                  if (!infile.is_open()) {
                  std::cerr << "\n\nError: Unable to open file " << filename << std::endl;
                  }

                  std::string line;

                  /* 
                        Going through each line in file and checking positions of tabs.
                        Prints error message if tabs are not at expected positions.
                        Storing song details in their respective variables.
                        Creating new track object and adding its pointer to the hash table.
                  */
                  while (getline(infile, line)) {
                        size_t position1 = line.find('\t');
                        size_t position2 = line.rfind('\t');
                        if (position1 == std::string::npos || position2 == std::string::npos) {
                              std::cerr << "Error: Invalid input file format" << std::endl;
                        }

                        /* String manipulation to get song details into their respective variables. */
                        std::string songName = line.substr(0, position1);
                        std::string artistName = line.substr(position1 + 1, position2 - position1 - 1);
                        int duration = stoi(line.substr(position2 + 1));

                        /* Adding track to hash table. */
                        Track* T = new Track(songName, artistName, duration);
                        hashTable->add(T);
                  }

                  /* Closing the input file */
                  infile.close();
		}
		else if(Choice == "2") {

                  /* Search by artist/band name */
                  std::cout << "Enter the artist/band name to search for: ";
                  std::string artistName;
                  std::cin.ignore();
                  std::getline(std::cin, artistName); // Gets user input for artist name

                  /* Getting results from hash table with retrieval method of hash table. */
                  hashTable->search(artistName);
		}
		else if(Choice == "3") {

                  /* Remove specific song */
                  std::cin.ignore();
                  std::cout << "\n\nEnter the artist/band name of song: ";
                  std::string artistName;
                  std::getline(std::cin, artistName);

                  std::cout << "\n\nEnter the song name to be removed: ";
                  std::string songName;
                  std::getline(std::cin, songName); // Gets user input for song name

                  /* Using deletion method of hash table to remove track if it exists. */
                  hashTable->remove(artistName, songName);
		}
		else if(Choice == "4") {

                  /* Save system to an output file. */
                  std::cout << "\n\nEnter the output file name: ";
                  std::string outputFileName;
                  std::cin.ignore();
                  std::getline(std::cin, outputFileName); // Gets user input for output file name

                  /* Calls method from hash table to save tracks. */
                  hashTable->save(outputFileName);
		}
		else if(Choice == "5") {

                  /* Exit program */
                  std::cout<<"\n\nExiting System. Goodbye!"<<"\n\n\n";

                  /* Destroying hash table to free up memory */
                  hashTable->~HashTable();

                  /* Setting exit check variable to true */
                  quit = true;
		}
		else {

                  /* Error message when user inputs an invalid choice. */
                  std::cerr <<"\n\nPlease enter a valid number [1-5]"<<"\n";
		}
	}

	return 0; 
}