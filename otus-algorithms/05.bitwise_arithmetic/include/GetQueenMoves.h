//
// Created by Aleksey Leshchankin on 17.11.2022.
//

#pragma once

#include "GetRookMoves.h"
#include "GetBishopMoves.h"

// ---------------------------------------
unsigned long GetQueenMoves (unsigned int position) {
    return GetRookMoves(position) | GetBishopMoves(position);
}
