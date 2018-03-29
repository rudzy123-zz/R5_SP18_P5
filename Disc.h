//
//  Disc.h
//  Project5
//
//  Created by Rudolf Musika on 3/22/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#ifndef Disc_h
#define Disc_h

#include <vector>
#include <string>
#include <memory>

#include "LinkedList.h"
#include "Track.h"

class Track;

class Disc {
 private:
    std::string title,artist,genre;
    int year;
    int totalPlayTime=0;
    bool multiArtist;
    std::unique_ptr<LinkedList<std::shared_ptr<Track>>> TrackListPtr;

 public:
    Disc();
    ~Disc();
    /** This is a deep copy constructor for the Disc()
     *
     * @pre Ensure that you have the constructor already made.
     *
     * @param Title The title belongs to title
     * @param Multiartist belongs to artist
     * @param Artist belongs to artist
     * @param Year belongs to artist
     * @param Genre belongs to artist
     */
    Disc(std::string Title,bool Multiartist,std::string Artist,int Year,std::string Genre);
    
    virtual bool isEmpty() const;
    virtual int getNumberOfTracks() const;
    virtual bool insertTrack(std::shared_ptr<Track> trackPtr);
    std::shared_ptr<Track> retrieveTrackByNumber(int trackNumber) const;
    virtual std::string getArtist() const;
    virtual std::string getTitle() const;
    virtual bool isMultiArtist() const;
    virtual void printDisc() const;
    /** This is a deep copy constructor for the Disc()
     *
     * @pre Ensure that you have the constructor already made.
     *
     * @param time The title belongs to title

     */
    virtual void addToTotalPlayTime(int time);
    virtual bool isLessThan(std::shared_ptr<Disc> aDisc) const;
    virtual bool isLessThanOrEqualTo(std::shared_ptr<Disc> aDisc) const;
    
    static std::shared_ptr<Disc> getDiscFromUser();
};
#endif /* Disc_h */
