#pragma once

#include "../Controller/SampleController.h"

namespace ConsoleMVC::View
{
    class ConsoleView
    {
    public:
        void Run();

    private:
        void ShowMenu() const;
        void HandleRegisterSample();
        void HandleListSamples() const;

        Controller::SampleController controller_;
    };
}
