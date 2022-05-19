//
// Created by Aleksey Leshchankin on 19.05.2022.
//

#pragma once

#include <iostream>
#include <limits>
#include "istatistics.h"

class Min : public IStatistics {
public:
    Min();

    void update(double next) override;

    double eval() const override;

    const char * name() const override;

private:
    double m_min;
    bool is_already_used;
};
