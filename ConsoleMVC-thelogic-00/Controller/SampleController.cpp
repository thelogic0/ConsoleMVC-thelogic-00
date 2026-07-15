#include "SampleController.h"

namespace ConsoleMVC::Controller
{
    void SampleController::RegisterSample(const std::string& sampleId, const std::string& name,
                                           double avgProductionTime, double yieldRate)
    {
        Model::Sample sample;
        sample.sample_id = sampleId;
        sample.name = name;
        sample.avg_production_time = avgProductionTime;
        sample.yield_rate = yieldRate;
        sample.current_stock = 0;

        repository_.Add(sample);
    }

    const std::vector<Model::Sample>& SampleController::GetAllSamples() const
    {
        return repository_.GetAll();
    }
}
