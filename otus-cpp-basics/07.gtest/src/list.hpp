//
// Created by Aleksey Leshchankin on 19.06.2022.
//

#pragma once

#include <list>
#include <iostream>

namespace homeworkspace {

    template<typename T, typename Allocator = std::allocator<T>>
    struct List {
        List() = default;
        ~List() = default;

        void push_back(const T& value) {
            test_list.push_back(value);
        }

        void push_front(const T& value) {
            test_list.push_front(value);
        }

        void push_middle (const T& value) {
            std::list<size_t>::iterator it = test_list.begin();

            std::advance (it,test_list.size()/2);
            test_list.insert(it,value);
        }

        void pop_back() {
            test_list.pop_back();
        }

        void pop_front() {
            test_list.pop_front();
        }

        void pop_middle () {
            size_t current_size = test_list.size();
            test_list_backup.swap(test_list);

            std::list<size_t>::iterator it;
            it = test_list_backup.begin();

            for (size_t i = 0; i < test_list_backup.size(); ++i) {
                if (i == current_size/2-1) it++;
                else {
                    test_list.push_back(*it);
                    it++;
                }
            }
        }

       void begin () {
            test_list.begin();
        }


        std::size_t size() const noexcept {
            return test_list.size();
        }

        bool empty() const noexcept {
            return test_list.empty();
        }

        T& front() {
            return test_list.front();
        }

        T& back() {
            return test_list.back();
        }

    private:
        std::list<T, Allocator> test_list;
        std::list<T, Allocator> test_list_backup;
    };
}
