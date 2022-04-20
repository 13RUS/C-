//
// Created by Aleksey Leshchankin on 20.04.2022.
//

#include <iostream>
#include <fstream>

int read_the_high_score_file (const std::string high_scores_filename) {

    //Attemption to open target file for reading
    std::ifstream file_to_read_out {high_scores_filename};

    if (!file_to_read_out.is_open()) {
        std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
        return -1;
    }

    //Reading results from file
    std::cout <<"Please look at the high scores table: " << std::endl;
    std::string player_name;
    int player_score;

    while (true) {
        file_to_read_out >> player_name;
        file_to_read_out >> player_score;
        file_to_read_out.ignore();

        if (file_to_read_out.fail()){
            break;
        }

        std::cout << player_name << '\t' << player_score << std::endl;
        
    }

    return 0;
}