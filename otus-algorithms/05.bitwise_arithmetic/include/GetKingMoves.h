//
// Created by Aleksey Leshchankin on 17.11.2022.
//

#pragma once

// ---------------------------------------
unsigned long GetKingMoves (unsigned int position)
{
    unsigned long bitmask;
    unsigned long K = 1UL << position;
    unsigned long Ka = K & 0xfefefefefefefefe;;
    unsigned long Kh = K & 0x7f7f7f7f7f7f7f7f;

    bitmask =
            (Ka << 7) | (K << 8) | (Kh << 9) |
            (Ka >> 1) |            (Kh << 1) |
            (Ka >> 9) | (K >> 8) | (Kh >> 7) ;

    return bitmask;
}
