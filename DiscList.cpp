//
//  DiskList.cpp
//  Project5
//
//  Created by Rudolf Musika on 3/21/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//


#include "DiscList.h"

DiskList::DiskList()
{
    DiscListPtr = std::make_unique<LinkedList<std::shared_ptr<Disc>>>();
}
DiskList::~DiskList()
{
    std::cout<<"DiscList Destructor Called!"<<std::endl;
}

int DiskList::findDiscPosition(std::shared_ptr<Disc> aDiscPtr) const
{
    int discPosition = -1, i = 1;
    bool canFindDisc(getNumberOfDiscs()>0), found = false;
    if (canFindDisc){
        
        while (i<=getNumberOfDiscs() && !found){
            if(aDiscPtr== DiscListPtr->getEntry(i)){
                found = true;
                discPosition = i;
            }
            else{
                i++;
            }
        }
    }
    return discPosition;
}
bool DiskList::isEmpty() const
{
    return DiscListPtr->isEmpty();
}
int DiskList::getNumberOfDiscs() const
{
    return DiscListPtr->getLength();
}
bool DiskList::insertDisc(std::shared_ptr<Disc> aDiscPtr )
{
    return DiscListPtr->insert(getNumberOfDiscs()+1, aDiscPtr);
}
bool DiskList::removeDisc(std::shared_ptr<Disc> aDiscPtr)
{
    return DiscListPtr->remove(findDiscPosition(aDiscPtr));
}
std::shared_ptr<Disc> DiskList::retrieveDisc(int number) const
{
    return DiscListPtr->getEntry(number);
}
