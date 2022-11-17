#include <iostream>
#include "include/RunTests.h"
#include "include/GetKingMoves.h"
#include "include/GetKnightMoves.h"
#include "include/GetBishopMoves.h"
#include "include/GetRookMoves.h"
#include "include/GetQueenMoves.h"

// ---------------------------------------
int main() {

    unsigned int number_of_tests = 10;
    std::string path;

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

    std::cout << "\nQUEEN TESTING" << std::endl;
    path = "../0.BITS/5.Bitboard - Ферзь/";
    runtests_type(path, number_of_tests, GetQueenMoves);
    
    return 0;
}
