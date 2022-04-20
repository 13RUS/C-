//
// Created by Aleksey Leshchankin on 20.04.2022.
//

#include <cstdlib>
#include <ctime>

int target_value_generator (const int max_value) {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    const int random_value = std::rand() % max_value;
    return random_value;
}
