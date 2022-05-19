//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#pragma once

#include <vector>
#include "istatistics.h"

class Pct90 : public IStatistics {
public:
    Pct90 ();

    void update(double next) override;

    double eval() const override;

    const char * name() const override;

private:
    double m_pct90;
    int const percentile = 90;
    std::vector<double> series;
};
