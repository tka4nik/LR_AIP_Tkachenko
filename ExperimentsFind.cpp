#include "Experiments.h"
#include "FilesFunctions.h"
#include <string>


experiments::FindExperimentsWorker::FindExperimentsWorker() {
    m_file.open("../find_out.csv");
    m_tlog = time_log::TimeLogger();
}

void experiments::FindExperimentsWorker::run() {
    std::cout << "Testing Find with containers..\n";

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<char> vec = data::load_vector_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::list<char> list = data::load_list_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::deque<char> deq = data::load_deque_char("../python/char/char_" + std::to_string(i) + ".txt");

        char_find(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<int> vec = data::load_vector_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::list<int> list = data::load_list_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::deque<int> deq = data::load_deque_int("../python/int/int_" + std::to_string(i) + ".txt");

        int_find(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<double> vec = data::load_vector_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::list<double> list = data::load_list_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::deque<double> deq = data::load_deque_double("../python/double/double_" + std::to_string(i) + ".txt");

        double_find(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<std::string> vec = data::load_vector_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::list<std::string> list = data::load_list_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::deque<std::string> deq = data::load_deque_string("../python/string/string_" + std::to_string(i) + ".txt");

        string_find(vec, list, deq);
    }
}

void experiments::FindExperimentsWorker::char_find(const std::vector<char> &vec, const std::list<char> &list, const std::deque<char> &deq) {
    std::cout << "Testing char find with vector..\n";
    m_tlog.reset_start();
    std::find(vec.begin(), vec.end(), ' '); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "char", "vector");

    std::cout << "Testing char find with list..\n";
    m_tlog.reset_start();
    std::find(list.begin(), list.end(), ' '); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, list.size(), "char", "list");

    std::cout << "Testing char find with deque..\n";
    m_tlog.reset_start();
    std::find(deq.begin(), deq.end(), ' '); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, deq.size(), "char", "deque");
}

void experiments::FindExperimentsWorker::int_find(const std::vector<int> &vec, const std::list<int> &list, const std::deque<int> &deq) {
    std::cout << "Testing int find with vector..\n";
    m_tlog.reset_start();
    std::find(vec.begin(), vec.end(), 100001); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "int", "vector");

    std::cout << "Testing int find with list..\n";
    m_tlog.reset_start();
    std::find(list.begin(), list.end(), 100001);
    m_tlog.log_duration(m_file, list.size(), "int", "list");

    std::cout << "Testing int find with deque..\n";
    m_tlog.reset_start();
    std::find(deq.begin(), deq.end(), 100001);
    m_tlog.log_duration(m_file, deq.size(), "int", "deque");
}

void experiments::FindExperimentsWorker::double_find(const std::vector<double> &vec, const std::list<double> &list, const std::deque<double> &deq) {
    std::cout << "Testing double find with vector..\n";
    m_tlog.reset_start();
    std::find(vec.begin(), vec.end(), 100001.0);
    m_tlog.log_duration(m_file, vec.size(), "double", "vector");

    std::cout << "Testing double find with list..\n";
    m_tlog.reset_start();
    std::find(list.begin(), list.end(), 100001.0);
    m_tlog.log_duration(m_file, list.size(), "double", "list");

    std::cout << "Testing double find with deque..\n";
    m_tlog.reset_start();
    std::find(deq.begin(), deq.end(), 100001.0);
    m_tlog.log_duration(m_file, deq.size(), "double", "deque");
}

void experiments::FindExperimentsWorker::string_find(const std::vector<std::string> &vec, const std::list<std::string> &list, const std::deque<std::string> &deq) {
    std::cout << "Testing string find with vector..\n";
    m_tlog.reset_start();
    std::find(vec.begin(), vec.end(), ",,,,,,,,,,,,,,,,,,,,"); // Punctuation is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "string", "vector");

    std::cout << "Testing string find with list..\n";
    m_tlog.reset_start();
    std::find(list.begin(), list.end(), ",,,,,,,,,,,,,,,,,,,,"); // Punctuation is not included into the generated symbols
    m_tlog.log_duration(m_file, list.size(), "string", "list");

    std::cout << "Testing string find with deque..\n";
    m_tlog.reset_start();
    std::find(deq.begin(), deq.end(), ",,,,,,,,,,,,,,,,,,,,"); // Punctuation is not included into the generated symbols
    m_tlog.log_duration(m_file, deq.size(), "string", "deque");
}