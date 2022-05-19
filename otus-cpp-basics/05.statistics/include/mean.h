//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#pragma once

#include <iostream>
#include "istatistics.h"

class Mean : public IStatistics {
public:
    Mean();

    void update(double next) override;

    double eval() const override;

    const char * name() const override;

private:
    double m_mean;
    bool is_already_used;
    double sum;
    int count;
};
