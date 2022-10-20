#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-unused-return-value"

#include "Experiments.h"
#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-result"
experiments::FindExperimentsWorker::FindExperimentsWorker() {
    m_file.open("find_out.csv");
    m_tlog = time_log::TimeLogger();
}

void experiments::FindExperimentsWorker::run() {

}

void experiments::FindExperimentsWorker::char_find(const std::vector<char> &vec, const std::list<char> &list, const std::deque<char> &deq) {
    std::cout << "Testing char find with vector..";
    m_tlog.reset_start();
    std::find(vec.begin(), vec.end(), ' '); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "char", "vector");

    std::cout << "Testing char find with list..";
    m_tlog.reset_start();
    std::find(list.begin(), list.end(), ' '); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, list.size(), "char", "list");

    std::cout << "Testing char find with vector..";
    m_tlog.reset_start();
    std::find(deq.begin(), deq.end(), ' '); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, deq.size(), "char", "deque");
}

void experiments::FindExperimentsWorker::int_find(const std::vector<int> &vec, const std::list<int> &list, const std::deque<int> &deq) {
    std::cout << "Testing int find with vector..";
    m_tlog.reset_start();
    std::find(vec.begin(), vec.end(), 100001); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "int", "vector");

    std::cout << "Testing int find with list..";
    m_tlog.reset_start();
    std::find(list.begin(), list.end(), 100001);
    m_tlog.log_duration(m_file, list.size(), "int", "list");

    std::cout << "Testing int find with vector..";
    m_tlog.reset_start();
    std::find(deq.begin(), deq.end(), 100001);
    m_tlog.log_duration(m_file, deq.size(), "int", "deque");
}

void experiments::FindExperimentsWorker::double_find(const std::vector<double> &vec, const std::list<double> &list, const std::deque<double> &deq) {
    std::cout << "Testing double find with vector..";
    m_tlog.reset_start();
    std::find(vec.begin(), vec.end(), 100001.0);
    m_tlog.log_duration(m_file, vec.size(), "double", "vector");

    std::cout << "Testing double find with list..";
    m_tlog.reset_start();
    std::find(list.begin(), list.end(), 100001.0);
    m_tlog.log_duration(m_file, list.size(), "double", "list");

    std::cout << "Testing double find with vector..";
    m_tlog.reset_start();
    std::find(deq.begin(), deq.end(), 100001.0);
    m_tlog.log_duration(m_file, deq.size(), "double", "deque");
}

void experiments::FindExperimentsWorker::string_find(const std::vector<std::string> &vec, const std::list<std::string> &list, const std::deque<std::string> &deq) {
    std::cout << "Testing string find with vector..";
    m_tlog.reset_start();
    std::find(vec.begin(), vec.end(), ",,,,,,,,,,,,,,,,,,,,"); // Punctuation is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "string", "vector");

    std::cout << "Testing string find with list..";
    m_tlog.reset_start();
    std::find(list.begin(), list.end(), ",,,,,,,,,,,,,,,,,,,,"); // Punctuation is not included into the generated symbols
    m_tlog.log_duration(m_file, list.size(), "string", "list");

    std::cout << "Testing string find with vector..";
    m_tlog.reset_start();
    std::find(deq.begin(), deq.end(), ",,,,,,,,,,,,,,,,,,,,"); // Punctuation is not included into the generated symbols
    m_tlog.log_duration(m_file, deq.size(), "string", "deque");
}



#pragma clang diagnostic pop
#pragma clang diagnostic pop