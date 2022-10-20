#include <iostream>
#include "TimeLogger.h"
#include <fstream>
#include <Windows.h>
#include <thread>

int main() {
    std::ofstream fout("../file.txt");
    time_log::TimeLogger timer;
    timer.reset_start();
    Sleep(2000);
    timer.log_duration(fout, "100000", "string", "Message");

    using namespace std::chrono_literals;
    timer.reset_start();
    std::this_thread::sleep_for(3s);
    timer.log_duration(std::cout);
    return 0;
}
