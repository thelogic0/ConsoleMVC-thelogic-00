#include <Windows.h>

#include "View/ConsoleView.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ConsoleMVC::View::ConsoleView view;
    view.Run();
    return 0;
}
