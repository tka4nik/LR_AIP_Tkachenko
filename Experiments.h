#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

#include "TimeLogger.h"

namespace experiments {
    class FindExperimentsWorker {
    public:
        FindExperimentsWorker();
        void run();
    private:
        std::ofstream m_file;
        time_log::TimeLogger m_tlog;
        void char_find(const std::vector<char>& vec, const std::list<char>& list, const std::deque<char>& deq);
        void int_find(const std::vector<int>& vec, const std::list<int>& list, const std::deque<int>& deq);
        void double_find(const std::vector<double>& vec, const std::list<double>& list, const std::deque<double>& deq);
        void string_find(const std::vector<std::string>& vec, const std::list<std::string>& list, const std::deque<std::string>& deq);
    };
}
