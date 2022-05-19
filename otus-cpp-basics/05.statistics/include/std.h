//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#pragma once

#include <vector>
#include "istatistics.h"

class Std : public IStatistics {
public:
    Std();

    void update(double next) override;

    double eval() const override;

    const char * name() const override;

private:
    double m_std;
    bool is_already_used;
    double average;
    double sum;
    int count;
    std::vector<double> series;
};
