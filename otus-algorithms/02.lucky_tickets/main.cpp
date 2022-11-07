#include <iostream>
#include <chrono>
#include <fstream>
#include <filesystem>

// ---------------------------------------
int calculation (int n, int k){
    unsigned long long sum = 0;
    int l_right_border = 0;

    if (n==1) {
        if (k<=9) sum = 1;
        else sum = 0;
    }

    else {
        if (k<=9) l_right_border = k;
        else l_right_border = 9;
        for (int l = 0; l <= l_right_border; l++) {
            sum += calculation(n - 1, k - l);
        }
    }
    return sum;
}

// ---------------------------------------
unsigned long long runcalculation (int n) {
    unsigned long long sum = 0;
    unsigned long long tmp = 0;

    std::cout << "start calculation" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i_k=0; i_k<= n*9; i_k++) {
        tmp = calculation (n,i_k);
        tmp = tmp*tmp;
        sum+=tmp;
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "calculation time is " << elapsed_ms.count() << " microseconds\n";

    return sum;
}

// ---------------------------------------
void runtests (std::string path, int number_of_tests) {
    int iteration = 0;
    std::string inputPath;
    std::string outputPath;
    std::string num_of_digits;
    std::string expected_value;
    unsigned long long calculated_value;

    std::fstream inputstream;
    std::fstream  outputstream;

    while (iteration < number_of_tests) {
        inputPath = path+"test."+ std::to_string(iteration)+".in";
        outputPath = path+"test."+ std::to_string(iteration)+".out";

        // ---------------------------------------
        inputstream.open(inputPath);
        getline(inputstream,num_of_digits);

        outputstream.open(outputPath);
        getline(outputstream,expected_value);

        // ---------------------------------------
        std::cout <<"\nTEST " << iteration << std::endl;
        std::cout <<"n = " <<std::stoi(num_of_digits)<<std::endl;
        std::cout << "expected value = " << std::stoll(expected_value)<<std::endl;

        calculated_value = runcalculation(std::stoi(num_of_digits));

        std:: cout <<"calculated value = " <<calculated_value << std::endl;

        if (calculated_value == std::stoll(expected_value)) std::cout <<"PASSED" << std::endl;
        else std::cout <<"FAILED" << std::endl;

        // ---------------------------------------
        inputstream.close();
        outputstream.close();

        // ---------------------------------------
        iteration ++;
    }
}

// ---------------------------------------
int main ()
{
    int number_of_tests = 9;
    std::string path = "1.Tickets/";
    runtests (path,number_of_tests);
}