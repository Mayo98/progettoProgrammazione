//
// Created by Giacomo Magistrato on 07/12/21.
//

#include "AbstractSubject.h"


bool AbstractSubject::notify() {
    //scorro lista observers e invoco il loro update
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++)
    {
        if((*itr)->update())
            continue;
        else {
            remove(*itr);
            return false;
        }
    }
    return true;
}