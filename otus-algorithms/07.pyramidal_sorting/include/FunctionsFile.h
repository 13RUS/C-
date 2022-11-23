//
// Created by Aleksey Leshchankin on 18.11.2022.
//

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "vector"

// ---------------------------------------
std::vector<int> ReadArray (std::string path, int fileNumber) {

    // -- Variables for working with file stream --
    std::string inputPath;
    std::fstream inputstream;
    std::vector<int> v;
    int AmountOfNumbers;

    // -- Variables for working with separate line from file stream --
    std::string tmpStringVariable;
    std::string SeparateNumberFromFile;

    // -- Open file stream -------------------
    inputPath = path+"test."+ std::to_string(fileNumber)+".in";
    inputstream.open(inputPath);

    // -- Read Size --------------------------
    getline(inputstream, tmpStringVariable);

    // -- Read Array -------------------------
    AmountOfNumbers = 0;
    while (std::getline (inputstream, tmpStringVariable)){
        std::stringstream strStream(tmpStringVariable);

        while (std::getline(strStream, SeparateNumberFromFile, ' ')) {
            v.push_back(std::stoi(SeparateNumberFromFile));
            AmountOfNumbers++;
        }
    }
    // -- Close file stream ------------------
    inputstream.close();

    return v;
}

// ---------------------------------------
void WritingToFile (const std::vector<int> & arrayToWrite, std::string FileName) {
    std::ofstream writingstream;
    writingstream.open(FileName, std::ios::trunc);

    for (const auto & value : arrayToWrite) writingstream << std::to_string(value) + " ";

    writingstream.close();
}