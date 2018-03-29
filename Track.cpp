//
//  Track.cpp
//  Project5
//
//  Created by Rudolf Musika on 3/22/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//
#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include "Track.h"
#include "Disc.h"

Track::Track(std::shared_ptr<Disc> aDiscPtr){
    std::string trackName;
    std::string artistSong;
    std::string playTimeSong;
    std::string locationSong;
    
    name = trackName;
    artist = artistSong;
    location = locationSong;
    weakDiscPtr = aDiscPtr;
    if(!aDiscPtr -> isMultiArtist()){
        artist = aDiscPtr->getArtist();
    }
    number += getNumber() + 1;
}

Track::~Track() {
    std::cerr<< "Track Destructor Called on: " << name << std::endl;
}

void Track::printTrack(){
    std::cout<< "Track Name: "<<name<<std::endl
            <<"Artist: "<<artist<<std::endl
            <<"Playtime: "<<playTime<<std::endl
            <<"Location: "<<location<<std::endl
            <<"Track Number: "<<number<<std::endl;
}
bool Track::isLessThan(Track aTrack) const{
    return number < aTrack.getNumber();
}
int Track::getNumber() const{
    return number;
}
int Track::getPlayTime() const{
    return playTime;
}
std::string Track::getTrack() const{
    return name;
}
int Track::readPlayTime (std::string time){
    std::string min,sec;
    unsigned long int end = time.length();
    unsigned long int finderSemiColon;
    finderSemiColon = time.find(":");
    min = time.substr(0,finderSemiColon);
    sec = time.substr(finderSemiColon+1,end);
    
    int Min,Sec;
    Min = std::stoi(min);
    Sec = std::stoi(sec);
    
    return Min * 60 + Sec;
}
std::shared_ptr<Track> Track::getTrackFromUser(std::shared_ptr<Disc> discPtr){
    std::string trackName,artistSong,locationSong,playTimeSong;
    static int actualTime;
    const auto aTrack = std::make_shared<Track>(discPtr);

    std::cout<<"Enter Track name: ";
    std::getline(std::cin, trackName);

    auto anArtist = std::make_shared<Track>(discPtr);

    if(discPtr->isMultiArtist()){
    std::cout<<"Enter Artist of Track "
        <<aTrack->name<<":";
    std::getline(std::cin,aTrack->artist);
    }
    else{
        aTrack->artist = discPtr->getArtist();
    }
    
    std::cout<<"Enter Playtime Minutes:Seconds format ";
    std::cin >> playTimeSong;
    std::cin.ignore(20, '\n');
    discPtr->addToTotalPlayTime(aTrack->
                                readPlayTime(playTimeSong));
    
    std::cout<<"Enter Location of Track "
    <<aTrack->name<<":"<<std::endl;
    std::cin>>aTrack->location;
    actualTime = aTrack->readPlayTime(playTimeSong);
    aTrack->number = discPtr->getNumberOfTracks();
    aTrack->name =discPtr->getTitle();
    aTrack->playTime = actualTime;
    return aTrack;
}

