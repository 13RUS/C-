//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#include "../include/mean.h"

Mean :: Mean()
        : m_mean{0.0}
        , sum{0.0}
        , count{0}
        , is_already_used{false} {}

void Mean ::update (double next) {
    // handling case with only one digit
    if (!is_already_used) {
        is_already_used = true;
        m_mean = next;
        sum = m_mean;
        count = 1;
    } else {
        count ++;
        sum = sum + next;
        m_mean = sum/count;
    }
}

double Mean :: eval() const  { return m_mean; }

const char * Mean :: name() const { return "mean";}