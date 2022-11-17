//
// Created by Aleksey Leshchankin on 17.11.2022.
//

#pragma once

#include "GetRookMoves.h"
#include "GetBishopMoves.h"

// ---------------------------------------
unsigned long GetQueenMoves (unsigned int position) {
    unsigned long bitmask = 0;
    unsigned long bitmasktmp;
    unsigned long K = 1UL << position;
    unsigned int y = 0;

    // -- Decteting y-coordinate --
    for (int i = 1; i < 9; i ++){
        if (position <= (i*8-1)) {
            y++;
            break;
        }
        y++;
    }

    //std::cout <<"position =  " << K << std::endl;
    bitmasktmp = GetRookMoves(position);
   // std::cout <<"Rook Mask  =  " << bitmasktmp << std::endl;

    bitmask = bitmask | bitmasktmp;
    bitmasktmp = GetBishopMoves(position);
   // std::cout <<"Bishop Mask  =  " << bitmasktmp << std::endl;
    bitmask = bitmask | bitmasktmp;

  // std::cout <<"Queen Mask  =  " << bitmask << std::endl;

    return bitmask;
}
