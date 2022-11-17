//
// Created by Aleksey Leshchankin on 16.11.2022.
//

// ---------------------------------------
unsigned int CountingSingleBits1 (unsigned long bitmask) {
    unsigned int num_of_moves = 0;

    while (bitmask > 0) {
        if ((bitmask & 1) == 1) num_of_moves ++;
        bitmask >>= 1;
    }

    return num_of_moves;
};

// ---------------------------------------
unsigned int CountingSingleBits2 (unsigned long bitmask) {
    unsigned int num_of_moves = 0;

    while (bitmask > 0) {
        num_of_moves ++;
        bitmask &= bitmask - 1;
    }

    return num_of_moves;
};

// ---------------------------------------
unsigned int *InitBits(){
    unsigned int bits [256];
    for (int i = 0; i < 256; i++)
        bits[i] = CountingSingleBits1(i);
    return bits;
}

// ---------------------------------------
unsigned int CountingSingleBits3 (unsigned long bitmask) {

    unsigned int *bits = InitBits();
    unsigned int num_of_moves = 0;

    while (bitmask > 0) {
        num_of_moves += bits[bitmask & 255];
        bitmask >>= 8;
    }

    return num_of_moves;
};