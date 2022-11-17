//
// Created by Aleksey Leshchankin on 17.11.2022.
//

#pragma once

// ---------------------------------------
unsigned long GetRookMoves (unsigned int position)
{
    unsigned long bitmask;
    int tmpPosition = position;
    unsigned long K = 1UL << position;
    unsigned long tmpK = 0;
    unsigned long up_row_filled = 0xff;
    unsigned int y = 0;
    unsigned int x = K;

    // -- Decteting y-coordinate --
    for (int i = 1; i < 9; i ++){
        if (position <= (i*8-1)) {
            y++;
            break;
        }
        y++;
    }

    // -- Row Moving --
    up_row_filled <<= 8*(y-1);

    // -- Column Fill in --
    // -- Filliтg in up direction--
    while (tmpPosition >= 0) {
        tmpK = K;
        tmpK >>= 8;
        K = K | tmpK;
        tmpPosition = tmpPosition - 8;
    }

    // -- Fillimg in down direction--
    while (tmpPosition <=63) {
        tmpK = K;
        tmpK <<= 8;
        K = K | tmpK;
        tmpPosition = tmpPosition + 8;
    }

    // -- Bitmask --
    bitmask = K ^ up_row_filled;

    return bitmask;
}