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

    class SortExperimentsWorker {
    public:
        SortExperimentsWorker();
        void run();
    private:
        std::ofstream m_file;
        time_log::TimeLogger m_tlog;
        void char_sort(std::vector<char>& vec, std::list<char>& list, std::deque<char>& deq);
        void int_sort(std::vector<int>& vec, std::list<int>& list, std::deque<int>& deq);
        void double_sort(std::vector<double>& vec, std::list<double>& list, std::deque<double>& deq);
        void string_sort(std::vector<std::string>& vec, std::list<std::string>& list, std::deque<std::string>& deq);
    };

    class PopFExperimentsWorker {
    public:
        PopFExperimentsWorker();
        void run();
    private:
        std::ofstream m_file;
        time_log::TimeLogger m_tlog;
        void char_popf(std::vector<char>& vec, std::list<char>& list, std::deque<char>& deq);
        void int_popf(std::vector<int>& vec, std::list<int>& list, std::deque<int>& deq);
        void double_popf(std::vector<double>& vec, std::list<double>& list, std::deque<double>& deq);
        void string_popf(std::vector<std::string>& vec, std::list<std::string>& list, std::deque<std::string>& deq);
    };

    class PopBExperimentsWorker {
    public:
        PopBExperimentsWorker();
        void run();
    private:
        std::ofstream m_file;
        time_log::TimeLogger m_tlog;
        void char_popb(std::vector<char>& vec, std::list<char>& list, std::deque<char>& deq);
        void int_popb(std::vector<int>& vec, std::list<int>& list, std::deque<int>& deq);
        void double_popb(std::vector<double>& vec, std::list<double>& list, std::deque<double>& deq);
        void string_popb(std::vector<std::string>& vec, std::list<std::string>& list, std::deque<std::string>& deq);
    };

    class PushFExperimentsWorker {
    public:
        PushFExperimentsWorker();
        void run();
    private:
        std::ofstream m_file;
        time_log::TimeLogger m_tlog;
        void char_pushf(std::vector<char>& vec, std::list<char>& list, std::deque<char>& deq);
        void int_pushf(std::vector<int>& vec, std::list<int>& list, std::deque<int>& deq);
        void double_pushf(std::vector<double>& vec, std::list<double>& list, std::deque<double>& deq);
        void string_pushf(std::vector<std::string>& vec, std::list<std::string>& list, std::deque<std::string>& deq);
    };

    class PushBExperimentsWorker {
    public:
        PushBExperimentsWorker();
        void run();
    private:
        std::ofstream m_file;
        time_log::TimeLogger m_tlog;
        void char_pushb(std::vector<char>& vec, std::list<char>& list, std::deque<char>& deq);
        void int_pushb(std::vector<int>& vec, std::list<int>& list, std::deque<int>& deq);
        void double_pushb(std::vector<double>& vec, std::list<double>& list, std::deque<double>& deq);
        void string_pushb(std::vector<std::string>& vec, std::list<std::string>& list, std::deque<std::string>& deq);
    };
}
