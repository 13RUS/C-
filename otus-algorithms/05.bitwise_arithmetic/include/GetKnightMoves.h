//
// Created by Aleksey Leshchankin on 17.11.2022.
//

#pragma once

// ---------------------------------------
unsigned long GetKnightMoves (unsigned int position)
{
    unsigned long bitmask;
    unsigned long K = 1UL << position;
    unsigned long nota  = 0xFeFeFeFeFeFeFeFe;;
    unsigned long notab = 0xFcFcFcFcFcFcFcFc;
    unsigned long noth  = 0x7f7f7f7f7f7f7f7f;
    unsigned long notgh = 0x3f3f3f3f3f3f3f3f;

    bitmask =
            notgh & (K << 6  | K >> 10) |
            noth  & (K << 15 | K >> 17) |
            nota  & (K << 17 | K >> 15)  |
            notab & (K << 10 | K >> 6) ;

    return bitmask;
}