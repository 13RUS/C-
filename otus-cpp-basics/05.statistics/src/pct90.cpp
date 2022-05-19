//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#include "../include/pct90.h"
#include "vector"

Pct90 :: Pct90 () : m_pct90{0.0} {}

void Pct90 :: update (double next) {
    series.push_back(next);
    m_pct90 = percentile / 100.0 * series.size();

    // с целью экономии ресурсов - в целом нет смысла сортировать вектор при каждом добавлении нового элемента -
    // данный кусок целесообразно перенести в функцию eval()
    // но при переносе выдает ошибку - см ниже
    std::sort(series.begin(), series.end());
}

double Pct90 :: eval() const  {
    // при вызове данной функции выдается ошибка
    // "error: no matching function for call to 'swap' swap(*__first, *__last);"
    // std::sort(series.begin(), series.end());
    return series[(int) m_pct90];
}

const char * Pct90 :: name() const { return "pct90";}