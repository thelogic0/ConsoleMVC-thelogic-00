#pragma once

#include <string>

namespace ConsoleMVC::Model
{
    struct Sample
    {
        std::string sample_id;
        std::string name;
        double avg_production_time = 0.0;
        double yield_rate = 0.0;
        int current_stock = 0;
    };
}
