#include "ConsoleView.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace ConsoleMVC::View
{
    void ConsoleView::Run()
    {
        bool running = true;
        while (running)
        {
            ShowMenu();

            int choice = -1;
            if (!(std::cin >> choice))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "잘못된 입력입니다. 숫자를 입력하세요.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice)
            {
            case 1:
                HandleRegisterSample();
                break;
            case 2:
                HandleListSamples();
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "잘못된 메뉴 번호입니다.\n";
                break;
            }
        }
    }

    void ConsoleView::ShowMenu() const
    {
        std::cout << "\n[1] 시료 등록   [2] 시료 목록 조회   [0] 종료\n";
        std::cout << "선택 > ";
    }

    void ConsoleView::HandleRegisterSample()
    {
        std::string sampleId, name;
        double avgProductionTime = 0.0;
        double yieldRate = 0.0;

        std::cout << "시료 ID > ";
        std::getline(std::cin, sampleId);
        std::cout << "시료명 > ";
        std::getline(std::cin, name);
        std::cout << "평균 생산시간(min/ea) > ";
        std::cin >> avgProductionTime;
        std::cout << "수율(0.0~1.0) > ";
        std::cin >> yieldRate;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        controller_.RegisterSample(sampleId, name, avgProductionTime, yieldRate);

        std::cout << "시료 등록 완료: " << sampleId << " (" << name << ")\n";
    }

    void ConsoleView::HandleListSamples() const
    {
        const auto& samples = controller_.GetAllSamples();

        std::cout << "\n등록 시료 목록 (총 " << samples.size() << "종)\n";
        std::cout << std::left
                   << std::setw(10) << "ID"
                   << std::setw(26) << "시료명"
                   << std::setw(24) << "평균생산시간"
                   << std::setw(12) << "수율"
                   << std::setw(10) << "현재재고" << "\n";

        for (const auto& sample : samples)
        {
            std::cout << std::left
                       << std::setw(10) << sample.sample_id
                       << std::setw(20) << sample.name
                       << std::setw(16) << sample.avg_production_time
                       << std::setw(8) << sample.yield_rate
                       << std::setw(10) << sample.current_stock << "\n";
        }
    }
}
