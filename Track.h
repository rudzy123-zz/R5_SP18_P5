//
//  Track.h
//  Project5
//
//  Created by Rudolf Musika on 3/22/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#ifndef Track_h
#define Track_h

#include <vector>
#include <memory>
#include <string>

#include "Disc.h"
#include "LinkedList.h"

class Disc;

class Track {
private:
    std::string name;
    std::string artist;
    std::string location;

    int playTime=0;
    int number = 0;
    
    std::weak_ptr<Disc> weakDiscPtr;
    Track() = delete;
    /** GetPlayTime
     *
     *  @return time the playTime count in seconds in 'minutes:seconds'
     */
    int readPlayTime (std::string time);
    std::string getTrack() const;
public:
    /** Destructor that outputs meesage when called.
     *  the name of the Track that is being destroyed.
     */
    ~Track();
    
    /** Tracks the next pointer in this node.
     *
     * @pre None.
     *
     * @post The next pointer in this node has been set to
     *       aDiscPtr.
     *
     * @param aDiscPtr The new pointer that this node should point
     *        at. */
//    Track(std::weak_ptr<Disc> aDiscPtr);
    Track(std::shared_ptr<Disc> aDiscPtr);
    /** Prints the Track */
    void printTrack();
    
    /** Inserts a new entry into this list at a given position.
     *
     *  @pre None.
     *
     *  @post If number < track->getNumber() the insertion
     *        is successful, track is stored at the given position
     *        in this list.
     *
     *  @param aTrack The list position at which to insert
     *         track entry.
     *
     *  @return True if insertion was successful, or false if not. */
    bool isLessThan(Track aTrack) const;
//    std::shared_ptr<Disc> retrieveDisc(int number) const;
    
    /** GetNumberOfTrack
     *
     *  @return Returns the number of Discs on this DiscList.
     */
    int getNumber() const;
    /** GetPlayTime
     *
     *  @return Returns the playTime count on this Track.
     */
    int getPlayTime() const;

    /** Tracks the next pointer in this node.
     *
     * @pre None.
     * Internally, it needs to prompt the user for and reads in from stdin:
     * the Track name;artist (if a multi-artist Disc); play time (in min:sec format);
     * and the path/filename (location) where this Track is stored in the
     * file system.
     *
     * smart Pointer of new created class The new pointer that
     * this node should point
     *        at. */
    static std::shared_ptr<Track> getTrackFromUser(std::shared_ptr<Disc> discPtr);
};
#endif /* Track_h */

