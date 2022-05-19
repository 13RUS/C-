//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#include "../include/max.h"

Max :: Max()
        : m_max{std::numeric_limits<double>::max()}
        , is_already_used {false} {}

void Max ::update (double next) {
    // handling case with only one digit
    // так как мы не знааем диапазона ввода, то m_max инициализируется
    // максимально возможным числом; при вводе первого числа последовательности мы переопределяем m_max
    if (!is_already_used) {
        is_already_used = true;
        m_max = next;
    }
    if (next > m_max) {
        m_max = next;
    }
}

double Max :: eval() const  { return m_max; }

const char * Max :: name() const { return "max";}