//
//  DiscLIst.h
//  Project5
//
//  Created by Rudolf Musika on 3/14/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#ifndef DiscList_h
#define DiscList_h

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "LinkedList.h"
#include "Disc.h"

class DiskList {

private:
    std::unique_ptr<LinkedList<std::shared_ptr<Disc>>> DiscListPtr;
    int findDiscPosition(std::shared_ptr<Disc> aDiscPtr) const;
public:
    /** Default constructor
     *
     * Creates the smart pointer, discListPtr, to an empty LinkedList.
     */
    DiskList();
    
    /** Destructor
     *
     * Outputs that it has been called.
     */
    ~DiskList();
    
    /** Locates the node at the specified position in this list.
     *
     *  @return Indicates whether this DiscList has any Discs.
     */
    virtual bool isEmpty() const;
    
    /** GetNumberOfDiscs
     *
     *  @return Returns the number of Discs on this DiscList.
     */
    virtual int getNumberOfDiscs() const;
    
    /** Inserts the Disc pointed to by the smart pointer discPtr in
     *  this DiscList
     *
     *  the Discs in this list are sorted in ascending order by the
     *  title of the Discs.
     *  @return bool whether true or false after checking
     */
    virtual bool insertDisc(std::shared_ptr<Disc> aDiscPtr);
    
    /** RemovesDisc
     *
     *  Removes the Disc pointed to by the smart pointer discPtr
     *  from this DiscList
     *  @return bool whether true or false after checking
     */
    virtual bool removeDisc(std::shared_ptr<Disc> aDiscPtr);
    
    /** RetrievesDiscs
     *
     *
     *  @return number A smart pointer  to the nth Disc on this DiscList.
     */
    std::shared_ptr<Disc> retrieveDisc(int number) const;
};

#endif /* DiscList_h */

