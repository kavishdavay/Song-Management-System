/*
    track.hpp
    Author: M00789089
    Created: 12/03/2023
    Updated: 15/04/2023
*/

/* Opening header guard */
#ifndef _TRACK_HPP_
#define _TRACK_HPP_

/* Including string header for string operations */
#include <string>

/*
    Track class which represents a track object in the song system.
    Each track has details about song name, artist/band name, and
    duration in seconds.
*/
class Track {

    /* Declaring private member variables */
    private:
        std::string songName;
        std::string artistName; 
        int duration;

    /* Declaring public member functions */
    public:
        /* Constructor */
        Track(std::string name, std::string artist, int length);

        /* Destructor */
        ~Track();

        /* Getters */
        std::string getSongName() const;
        std::string getArtistName() const;
        int getDuration() const;
};

/* Closing header guard */
#endif