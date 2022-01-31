//
// Created by Giacomo Magistrato on 07/12/21.
//

#include "LoadingHandler.h"

void LoadingHandler::upload(int initial, int speed) {

    if(initial >= 0 and initial <= 100 and speed >= 0)
    {
        setState(initial);
        setSpeed(speed);

        for(int i = 0; i < (100-initial); i++)
        {
            if(!observers.empty())
            {
                if(!setState(state+1))
                {
                    break;
                }
                else break;
            }
        }
    }

}