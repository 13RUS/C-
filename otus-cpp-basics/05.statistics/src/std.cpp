//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#include "../include/std.h"
#include <cmath>

Std :: Std()
        : m_std{0.0}
        , is_already_used{false}
        , sum{0.0}
        , count{0}
        , average{0.0} {}

void Std ::update (double next) {
    // handling case with only one digit
    if (!is_already_used) {
        is_already_used = true;
        sum = next;
        series.push_back(next);
        m_std = 0;
    } else {
        m_std = 0;
        series.push_back(next);
        sum += next;
        count = series.size();
        average = sum/count;

        for (const auto &x : series){
            m_std += (x-average)*(x-average);
        }
        m_std = sqrt (m_std / count);
    }
}

double Std :: eval() const  { return m_std; }

const char * Std :: name() const { return "std";}