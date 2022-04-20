//
// Created by Aleksey Leshchankin on 20.04.2022.
//

#include <iostream>
#include <fstream>

int write_new_high_score (const std::string high_scores_filename, const std::string player_name, const int attempts_count) {
    //std::cout << high_scores_filename << " " << player_name << " " << attempts_count << std::endl;

    //Attemption to open target file for writing
    std::ofstream file_to_write_in {high_scores_filename, std::ios_base::app};
    if (!file_to_write_in.is_open()) {
        std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        return -1;
    }

    //Appending result to the table
    file_to_write_in << player_name << ' ';
    file_to_write_in << attempts_count;
    file_to_write_in << std::endl;

    return 0;
}
