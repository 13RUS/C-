//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#include "../include/min.h"

Min :: Min()
        : m_min{std::numeric_limits<double>::min()}
        , is_already_used {false} {}

void Min ::update (double next) {
    // handling case with only one digit
    // так как мы не знаем диапазона ввода, то m_min инициализируется минимально возможным числом;
    // при вводе первого числа последовательности мы переопределяем m_min
    if (!is_already_used) {
        is_already_used = true;
        m_min = next;
    }
    if (next < m_min) {
        m_min = next;
    }
}

double Min :: eval() const  { return m_min; }

const char * Min :: name() const { return "min";}
