//
//  Disc.cpp
//  Project5
//
//  Created by Rudolf Musika on 3/22/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#include <iostream>
#include <memory>

#include "Disc.h"

Disc::Disc(){
    TrackListPtr = std::make_unique<LinkedList<std::shared_ptr<Track>>>();

}

Disc::~Disc(){
    std::cout<<"Disc Destructor called on Disc "<<title<<std::endl;
}

Disc::Disc(std::string Title,bool Multiartist,std::string Artist,int Year,std::string Genre) {
    TrackListPtr=std::make_unique<LinkedList<std::shared_ptr<Track>>>();
    title = Title;
    multiArtist = Multiartist;
    artist = Artist;
    year = Year;
    genre = Genre;
}

bool Disc::isEmpty() const{
    bool isEmpty(TrackListPtr == nullptr);
    return isEmpty;
}

int Disc::getNumberOfTracks() const{
    int numberOfTracks(TrackListPtr->getLength()+1);
    return numberOfTracks;
}

bool Disc::insertTrack(std::shared_ptr<Track> trackPtr){
    bool insertTrack(TrackListPtr->insert(TrackListPtr->getLength()+1,trackPtr));
    return insertTrack;
}

std::shared_ptr<Track> Disc::retrieveTrackByNumber(int trackNumber) const{
    std::shared_ptr<Track> retrievTrackByNumber(TrackListPtr->getEntry(trackNumber));
    return retrievTrackByNumber;
}

std::string Disc::getArtist() const{
    return artist;
}
std::string Disc::getTitle() const{
    return title;
}
bool Disc::isMultiArtist() const{
    return multiArtist;
}
void Disc::printDisc() const{
    std::cout << "Title: " << getTitle() << std::endl
    << "Artist: " << getArtist() << std::endl
    << "Year: " << year << std::endl
    << "Genre: " << genre << std::endl
    << "Number of tracks: " << TrackListPtr->getLength() << std::endl
    << "Total play time: " << totalPlayTime << std::endl
    << "Tracks: " ;
    for (int i = 1; i <= TrackListPtr->getLength(); i++) {
        std::cout << (i) << "..."<< std::endl;
        (TrackListPtr->getEntry(i))->printTrack();
        std::cout << std::endl;
    }
}
void Disc::addToTotalPlayTime(int time){
    totalPlayTime += time;
}
bool Disc::isLessThan(std::shared_ptr<Disc> aDisc) const{
    bool isLessThan(getNumberOfTracks() < aDisc->getNumberOfTracks());
    return isLessThan;
}
bool Disc::isLessThanOrEqualTo(std::shared_ptr<Disc> aDisc) const{
    bool isLessThanOrEqualTo(getNumberOfTracks() <= aDisc->getNumberOfTracks());
    return isLessThanOrEqualTo;
}
std::shared_ptr<Disc> Disc::getDiscFromUser(){
    std::string titleDisc,ArtistDisc,genreDisc;
    bool multiArtistDiscStatus;
    std::string multiArtistDisc;
    int yearDisc;
    char in;    
    std::cout << "Enter disc title: ";
    std::cin>>titleDisc;

    std::cout << "Is this disc multi-artist? (Y= yes or N = no): ";
    std::cin>>multiArtistDisc;

    if (multiArtistDisc== "y" or multiArtistDisc== "Y"){
        multiArtistDiscStatus = true;

    }
    else {
        multiArtistDiscStatus = false;
        std::cout << "Enter artist: ";
        std::cin>> ArtistDisc;
    }
    std::cout << "Enter year: ";
    std::cin >> yearDisc;
    std::cout << "Enter genre: ";
    std::cin >> genreDisc;
    std::cin.ignore(20, '\n');

    
    auto newDisc =  std::make_shared<Disc> (titleDisc,multiArtistDiscStatus,ArtistDisc,yearDisc,genreDisc);
    std::shared_ptr<Disc> weakDisc(newDisc);
    
    do {
        newDisc->insertTrack(Track::getTrackFromUser(weakDisc));
        std::cout << "Enter another? y/n: ";
        std::cin >> in;
        std::cin.ignore(20, '\n');
    }
    while(tolower(in) != 'n');
    
    return newDisc;
}

