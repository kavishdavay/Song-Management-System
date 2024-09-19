/*
    track.cpp
    Author: M00789089
    Created: 12/03/2023
    Updated: 15/04/2023
*/

#include "track.hpp"

/* 
    Constructor that initializes the track object with the song name, artist name, and duration.
    @param name Name of track
    @param artist Name of artist
    @param length Duration of track 
*/
Track::Track(std::string name, std::string artist, int length) {
    songName = name;
    artistName = artist;
    duration = length;
}

/* Destructor */
Track::~Track() {}

/* 
    Getter method for song name of Track object.
    @return Song name of track
*/
std::string Track::getSongName() const {
    return songName;
}

/* 
    Getter method for artist/band name of Track object.
    @return Artist/band name of track
*/
std::string Track::getArtistName() const {
    return artistName;
}

/* 
    Getter method for duration of Track object.
    @return Duration of track
*/
int Track::getDuration() const {
    return duration;
}