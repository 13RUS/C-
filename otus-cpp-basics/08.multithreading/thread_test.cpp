//
// Created by Aleksey Leshchankin on 31.07.2022.
//

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <future>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <map>
#include <vector>

// ------- variables specification -------
//const size_t TOPK = 10;
using Counter = std::map<std::string, std::size_t>;

// ------- functions specification -------
void print_topk(std::ostream& stream, const Counter&, const size_t k);
std::string tolower(const std::string &str);
Counter count_words(const std::string& filepath);

// -------- main function ----------------
int main(int argc, char *argv[]) {
    auto start = std::chrono::high_resolution_clock::now();

    // ---------------------------------------
    std::vector<std::future<Counter>> tasks;

    Counter merged_dict;
    Counter temp_dict;

    // -------- multithreading launch---------
    for (int i = 1; i < argc; ++i) {
        tasks.push_back(std::async(count_words, argv[i]));
    }
    merged_dict = tasks[0].get();

    // -------- maps merging -----------------
    for (int i = 1; i < int(tasks.size()); ++i) {
        temp_dict = tasks[i].get();
        for (const auto &[key, value] : temp_dict) {
            merged_dict[key] += value;
        }
    }
    // ---------------------------------------
    std::cout << "the most frequent words:" << std::endl;
    print_topk(std::cout, merged_dict, 10);

    // ---------------------------------------
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";

   return 0;
}

// -------- functions description --------
Counter count_words(const std::string &filepath) {
    std::clog << "run in thread id" << std::this_thread::get_id() << std::endl;
    Counter freq_dict;
    std::ifstream stream{filepath};
    //std::clog << "filepath" << filepath;

    if (!stream.is_open()) {
        throw std::runtime_error{"Failed to open '" + filepath + "'"};
    }
    //std::cout << "count_words alive" << std::endl;

    std::for_each(std::istream_iterator<std::string>(stream),
                  std::istream_iterator<std::string>(),
                  [&freq_dict](const std::string &s) { ++freq_dict[tolower(s)]; });
    return freq_dict;
}

// ---------------------------------------
std::string tolower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
};

// ---------------------------------------
void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());

    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
            std::begin(words), std::begin(words) + k, std::end(words),
            [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
            std::begin(words), std::begin(words) + k,
            [&stream](const Counter::const_iterator &pair) {
                stream << std::setw(4) << pair->second << " " << pair->first
                       << '\n';
            });
}

