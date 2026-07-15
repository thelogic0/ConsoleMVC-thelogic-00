#pragma once

#include <vector>

#include "Sample.h"

namespace ConsoleMVC::Model
{
    class SampleRepository
    {
    public:
        void Add(const Sample& sample);
        const std::vector<Sample>& GetAll() const;

    private:
        std::vector<Sample> samples_;
    };
}
