#pragma once

#include <string>
#include <vector>

#include "../Model/Sample.h"
#include "../Model/SampleRepository.h"

namespace ConsoleMVC::Controller
{
    class SampleController
    {
    public:
        void RegisterSample(const std::string& sampleId, const std::string& name,
                             double avgProductionTime, double yieldRate);
        const std::vector<Model::Sample>& GetAllSamples() const;

    private:
        Model::SampleRepository repository_;
    };
}
