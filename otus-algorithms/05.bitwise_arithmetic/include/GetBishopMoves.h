//
// Created by Aleksey Leshchankin on 17.11.2022.
//

#pragma once

// ---------------------------------------
unsigned long GetBishopMoves (unsigned int position) {
    unsigned long bitmask;
    unsigned long tmp1, tmp2, tmpy;
    unsigned int y = 0;
    unsigned long K = 1UL << position;

    // -- Decteting y-coordinate --
    for (int i = 1; i < 9; i ++){
        if (position <= (i*8-1)) {
            y++;
            break;
        }
        y++;
    }

    bitmask = K;
    // -- Lower "Triangle" Generation --
    tmp1 = K; tmp2 = K;
    tmpy = y;
    while (tmpy > 1) {
        tmp1 = tmp1 & 0x7f7f7f7f7f7f7f7f; tmp1 >>= 7;
        tmp2 = tmp2 & 0xfefefefefefefefe; tmp2 >>= 9;
        bitmask = bitmask | tmp1 | tmp2;
        tmpy--;
    }

    // -- Lower "Triangle" Generation --
    tmp1 = K; tmp2 = K;
    tmpy = y;
    while (tmpy < 9) {
        tmp1 = tmp1 & 0xfefefefefefefefe; tmp1 <<= 7;
        tmp2 = tmp2 & 0x7f7f7f7f7f7f7f7f; tmp2 <<= 9;
        bitmask  = bitmask  | tmp1 | tmp2;
        tmpy++;
    }

    bitmask = bitmask ^ K;
    return bitmask;
}