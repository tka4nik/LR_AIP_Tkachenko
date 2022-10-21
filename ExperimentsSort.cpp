#include "Experiments.h"
#include "FilesFunctions.h"
#include <string>


experiments::SortExperimentsWorker::SortExperimentsWorker() {
    m_file.open("../sort_out.csv");
    m_tlog = time_log::TimeLogger();
}

experiments::SortExperimentsWorker::~SortExperimentsWorker() {
    m_file.close();
}

void experiments::SortExperimentsWorker::run() {
    std::cout << "Testing PopF with containers..\n";

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<char> vec = data::load_vector_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::list<char> list = data::load_list_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::deque<char> deq = data::load_deque_char("../python/char/char_" + std::to_string(i) + ".txt");

        char_sort(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<int> vec = data::load_vector_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::list<int> list = data::load_list_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::deque<int> deq = data::load_deque_int("../python/int/int_" + std::to_string(i) + ".txt");

        int_sort(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<double> vec = data::load_vector_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::list<double> list = data::load_list_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::deque<double> deq = data::load_deque_double("../python/double/double_" + std::to_string(i) + ".txt");

        double_sort(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<std::string> vec = data::load_vector_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::list<std::string> list = data::load_list_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::deque<std::string> deq = data::load_deque_string("../python/string/string_" + std::to_string(i) + ".txt");

        string_sort(vec, list, deq);
    }
}

void experiments::SortExperimentsWorker::char_sort(std::vector<char> &vec, std::list<char> &list, std::deque<char> &deq) {
    std::cout << "Testing char sort with vector..\n";
    m_tlog.reset_start();
    std::sort(vec.begin(), vec.end()); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "char", "vector");

    std::cout << "Testing char sort with list..\n";
    m_tlog.reset_start();
    list.sort(); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, list.size(), "char", "list");

    std::cout << "Testing char sort with deque..\n";
    m_tlog.reset_start();
    std::sort(deq.begin(), deq.end()); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, deq.size(), "char", "deque");
}

void experiments::SortExperimentsWorker::int_sort(std::vector<int> &vec, std::list<int> &list, std::deque<int> &deq) {
    std::cout << "Testing int sort with vector..\n";
    m_tlog.reset_start();
    std::sort(vec.begin(), vec.end()); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "int", "vector");

    std::cout << "Testing int sort with list..\n";
    m_tlog.reset_start();
    list.sort(); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, list.size(), "int", "list");

    std::cout << "Testing int sort with deque..\n";
    m_tlog.reset_start();
    std::sort(deq.begin(), deq.end()); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, deq.size(), "int", "deque");
}

void experiments::SortExperimentsWorker::double_sort(std::vector<double> &vec, std::list<double> &list, std::deque<double> &deq) {
    std::cout << "Testing double sort with vector..\n";
    m_tlog.reset_start();
    std::sort(vec.begin(), vec.end()); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "double", "vector");

    std::cout << "Testing double sort with list..\n";
    m_tlog.reset_start();
    list.sort(); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, list.size(), "double", "list");

    std::cout << "Testing double sort with deque..\n";
    m_tlog.reset_start();
    std::sort(deq.begin(), deq.end()); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, deq.size(), "double", "deque");
}

void experiments::SortExperimentsWorker::string_sort(std::vector<std::string> &vec, std::list<std::string> &list, std::deque<std::string> &deq) {
    std::cout << "Testing string sort with vector..\n";
    m_tlog.reset_start();
    std::sort(vec.begin(), vec.end()); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, vec.size(), "string", "vector");

    std::cout << "Testing string sort with list..\n";
    m_tlog.reset_start();
    list.sort(); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, list.size(), "string", "list");

    std::cout << "Testing string sort with deque..\n";
    m_tlog.reset_start();
    std::sort(deq.begin(), deq.end()); // Whitespace is not included into the generated symbols
    m_tlog.log_duration(m_file, deq.size(), "string", "deque");
}