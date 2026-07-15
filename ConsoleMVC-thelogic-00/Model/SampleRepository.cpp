#include "SampleRepository.h"

namespace ConsoleMVC::Model
{
    void SampleRepository::Add(const Sample& sample)
    {
        samples_.push_back(sample);
    }

    const std::vector<Sample>& SampleRepository::GetAll() const
    {
        return samples_;
    }
}
