#include <iostream>
#include "include/RunTests.h"
#include "include/GetKingMoves.h"
#include "include/GetKnightMoves.h"
#include "include/GetBishopMoves.h"
#include "include/GetRookMoves.h"

// ---------------------------------------
int main() {

    unsigned int number_of_tests = 10;
    std::string path;

    unsigned long position = 0;
    //unsigned long bitmask = GetBishopMoves (position);

    std::cout << "\nKING TESTING" << std::endl;
    path = "../0.BITS/1.Bitboard - Король/";
    runtests_type(path, number_of_tests, GetKingMoves);

    std::cout << "\nROOK TESTING" << std::endl;
    path = "../0.BITS/3.Bitboard - Ладья/";
    runtests_type(path, number_of_tests, GetRookMoves);

    std::cout << "\nKNIGHT TESTING" << std::endl;
    path = "../0.BITS/2.Bitboard - Конь/";
    runtests_type(path, number_of_tests, GetKnightMoves);

    std::cout << "\nBISHOP TESTING" << std::endl;
    path = "../0.BITS/4.Bitboard - Слон/";
    runtests_type(path, number_of_tests, GetBishopMoves);


//    unsigned long bitmask = GetKingMoves (position);
//    std::cout << "bitmask = " << bitmask << std::endl;
//    num_of_moves = CountingSingleBits3(bitmask);
//    std::cout << "num of moves = " << num_of_moves << std::endl;

    return 0;
}
