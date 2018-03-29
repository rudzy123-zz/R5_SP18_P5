//
//  main.cpp
//  Project5
//
//  Created by Rudolf Musika on 3/21/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

#include "DiscList.h"
#include "Disc.h"

void listDiscs(DiskList& discList);
void addDisc(DiskList& discList);
void removeDisc(DiskList& discList);
void printDisc(DiskList& discList);

void listDiscs(DiskList& discList) {
    bool canList( !discList.isEmpty() );
    if (canList) {
        for (int i = 1; i <= discList.getNumberOfDiscs(); i++) {
            std::cout << "Disc " << i << " ...  " << std::endl
            << (discList.retrieveDisc(i))->getTitle() << std::endl;
        }
    }
}

void addDisc(DiskList& discList) {
    std::shared_ptr<Disc> newDisc(Disc::getDiscFromUser() );
    std::cout << "inserted?: " << discList.insertDisc(newDisc) << std::endl;
}

void removeDisc(DiskList& discList) {
    int number;
    std::cout << "Enter disc number: ";
    std::cin >> number;
    std::cout<<"deleted?: " <<  discList.removeDisc(discList.retrieveDisc(number)) << std::endl;
}

void printDisc(DiskList& discList){
    int number;
    std::cout << "Enter disc number: ";
    std::cin >> number;
    (discList.retrieveDisc(number))->printDisc();
}

int main() {
    
    DiskList discList;
    char option;
    do{
        std::cout << "MAIN MENU" << std::endl
        << "(L)ist discs" << std::endl
        << "(A)dd disc" << std::endl
        << "(R)emove disc" << std::endl
        << "(P)rint disc" << std::endl
        << "(Q)uit" << std::endl
        << "Enter option: ";
        std::cin >> option;
        switch (tolower(option)) {
            case ('l'): listDiscs(discList); break;
            case ('a'): addDisc(discList); break;
            case ('r'): removeDisc(discList); break;
            case ('p'): printDisc(discList); break;
            default : break;
        }
    }
    while(option != tolower('q'));
    
    return EXIT_SUCCESS;
}
