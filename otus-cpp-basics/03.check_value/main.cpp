#include <iostream>

#include "target_value_generator.h"
#include "write_new_high_score.h"
#include "read_the_high_score_file.h"

int main(int argc, char** argv) {

    const std::string high_scores_filename = "high_scores.txt";
    int max_random_value = 100;

    //Handling command line options
    if (argc > 1) {
        std::string argv1_value{argv[1]};
        //std::cout << "argv[1] = " << argv[1] << std::endl;
        if (argv1_value == "-table") {
            read_the_high_score_file(high_scores_filename);
            return 0;
        }
        if (argv1_value == "-max") {
            //std::cout << "argv[2] = " << argv[2] << std::endl;
            std::string argv2_value{argv[2]};
            max_random_value = std::stoi(argv2_value);
        }

    }

    //Enabler variables
    //const int target_value = 54;
    int target_value = target_value_generator(max_random_value);
    std::cout << "target value: "<< target_value << std::endl;
    int current_value = 0;
    bool not_win = true;

    //Business logic variables
    std::string player_name;
    int attempts_count = 0;

    //Request to introduce user
    std::cout << "Enter your name: ";
    std::cin >> player_name;

    //Guessing block of code
    std::cout << "Enter your guess:" << std::endl;

    do {
        std::cin >> current_value;
        attempts_count++;

        if (current_value < target_value) {
            std::cout << "less than " << current_value << " try again!" << std::endl;
        }
        else if (current_value > target_value) {
            std::cout << "greater than " << current_value << " try again!" << std::endl;
        }
        else {
            std::cout << "you win!" << std::endl;
            break;
        }

    } while(true);
    //End of the guessing block of code

    //Appending #player_name and #attmepts_count to the file with a table of records
    std::cout << player_name <<" used " << attempts_count <<" attempts" << std::endl;
    write_new_high_score (high_scores_filename, player_name, attempts_count);

    //Displaying the full content of the high scores table
    read_the_high_score_file(high_scores_filename);

    return 0;
}