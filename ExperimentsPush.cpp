#include "Experiments.h"
#include "FilesFunctions.h"
#include <string>


experiments::PushFExperimentsWorker::PushFExperimentsWorker() {
    m_file.open("../pushf_out.csv");
    m_tlog = time_log::TimeLogger();
}

experiments::PushFExperimentsWorker::~PushFExperimentsWorker() {
    m_file.close();
}

void experiments::PushFExperimentsWorker::run() {
    std::cout << "Testing PushF with containers..\n";

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<char> vec = data::load_vector_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::list<char> list = data::load_list_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::deque<char> deq = data::load_deque_char("../python/char/char_" + std::to_string(i) + ".txt");

        char_pushf(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<int> vec = data::load_vector_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::list<int> list = data::load_list_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::deque<int> deq = data::load_deque_int("../python/int/int_" + std::to_string(i) + ".txt");

        int_pushf(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<double> vec = data::load_vector_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::list<double> list = data::load_list_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::deque<double> deq = data::load_deque_double("../python/double/double_" + std::to_string(i) + ".txt");

        double_pushf(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<std::string> vec = data::load_vector_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::list<std::string> list = data::load_list_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::deque<std::string> deq = data::load_deque_string("../python/string/string_" + std::to_string(i) + ".txt");

        string_pushf(vec, list, deq);
    }
}

void experiments::PushFExperimentsWorker::char_pushf(std::vector<char> &vec, std::list<char> &list, std::deque<char> &deq) {
    std::cout << "Testing char pushf with vector..\n";
    std::vector<char> vec_tmp;
    m_tlog.reset_start();
    for (const char value : vec) {
        vec_tmp.insert(vec_tmp.begin(), value);
    }
    m_tlog.log_duration(m_file, vec.size(), "char", "vector");

    vec_tmp.clear();
    vec_tmp.reserve(vec.size());
    m_tlog.reset_start();
    for (const char value : vec) {
        vec_tmp.insert(vec_tmp.begin(), value);
    }
    m_tlog.log_duration(m_file, vec.size(), "char", "vector_reserve");

    std::cout << "Testing char pushf with list..\n";
    std::list<char> list_tmp;
    m_tlog.reset_start();
    for (const char value : vec) {
        list_tmp.push_front(value);
    }
    m_tlog.log_duration(m_file, list.size(), "char", "list");

    std::cout << "Testing char pushf with deque..\n";
    std::deque<char> dec_tmp;
    m_tlog.reset_start();
    for (const char value : vec) {
        dec_tmp.push_front(value);
    }
    m_tlog.log_duration(m_file, deq.size(), "char", "deque");
}

void experiments::PushFExperimentsWorker::int_pushf(std::vector<int> &vec, std::list<int> &list, std::deque<int> &deq) {
    std::cout << "Testing int pushf with vector..\n";
    std::vector<int> vec_tmp;
    m_tlog.reset_start();
    for (const int value : vec) {
        vec_tmp.insert(vec_tmp.begin(), value);
    }
    m_tlog.log_duration(m_file, vec.size(), "int", "vector");

    vec_tmp.clear();
    vec_tmp.reserve(vec.size());
    m_tlog.reset_start();
    for (const int value : vec) {
        vec_tmp.insert(vec_tmp.begin(), value);
    }
    m_tlog.log_duration(m_file, vec.size(), "int", "vector_reserve");

    std::cout << "Testing int pushf with list..\n";
    std::list<int> list_tmp;
    m_tlog.reset_start();
    for (const int value : vec) {
        list_tmp.push_front(value);
    }
    m_tlog.log_duration(m_file, list.size(), "int", "list");

    std::cout << "Testing int pushf with deque..\n";
    std::deque<int> dec_tmp;
    m_tlog.reset_start();
    for (const int value : vec) {
        dec_tmp.push_front(value);
    }
    m_tlog.log_duration(m_file, deq.size(), "int", "deque");
}

void experiments::PushFExperimentsWorker::double_pushf(std::vector<double> &vec, std::list<double> &list, std::deque<double> &deq) {
    std::cout << "Testing double pushf with vector..\n";
    std::vector<double> vec_tmp;
    m_tlog.reset_start();
    for (const double value : vec) {
        vec_tmp.insert(vec_tmp.begin(), value);
    }
    m_tlog.log_duration(m_file, vec.size(), "double", "vector");

    vec_tmp.clear();
    vec_tmp.reserve(vec.size());
    m_tlog.reset_start();
    for (const double value : vec) {
        vec_tmp.insert(vec_tmp.begin(), value);
    }
    m_tlog.log_duration(m_file, vec.size(), "double", "vector_reserve");

    std::cout << "Testing double pushf with list..\n";
    std::list<double> list_tmp;
    m_tlog.reset_start();
    for (const double value : vec) {
        list_tmp.push_front(value);
    }
    m_tlog.log_duration(m_file, list.size(), "double", "list");

    std::cout << "Testing double pushf with deque..\n";
    std::deque<double> dec_tmp;
    m_tlog.reset_start();
    for (const double value : vec) {
        dec_tmp.push_front(value);
    }
    m_tlog.log_duration(m_file, deq.size(), "double", "deque");
}

void experiments::PushFExperimentsWorker::string_pushf(std::vector<std::string> &vec, std::list<std::string> &list, std::deque<std::string> &deq) {
    std::cout << "Testing string pushf with vector..\n";
    std::vector<std::string> vec_tmp;
    m_tlog.reset_start();
    for (const std::string& value : vec) {
        vec_tmp.insert(vec_tmp.begin(), value);
    }
    m_tlog.log_duration(m_file, vec.size(), "string", "vector");

    vec_tmp.clear();
    vec_tmp.reserve(vec.size());
    m_tlog.reset_start();
    for (const std::string& value : vec) {
        vec_tmp.insert(vec_tmp.begin(), value);
    }
    m_tlog.log_duration(m_file, vec.size(), "string", "vector_reserve");

    std::cout << "Testing string pushf with list..\n";
    std::list<std::string> list_tmp;
    m_tlog.reset_start();
    for (const std::string& value : vec) {
        list_tmp.push_front(value);
    }
    m_tlog.log_duration(m_file, list.size(), "string", "list");

    std::cout << "Testing string pushf with deque..\n";
    std::deque<std::string> dec_tmp;
    m_tlog.reset_start();
    for (const std::string& value : vec) {
        dec_tmp.push_front(value);
    }
    m_tlog.log_duration(m_file, deq.size(), "string", "deque");
}
////////////////////////////////////////////////////////////////////////////

experiments::PushBExperimentsWorker::PushBExperimentsWorker() {
    m_file.open("../pushb_out.csv");
    m_tlog = time_log::TimeLogger();
}

experiments::PushBExperimentsWorker::~PushBExperimentsWorker() {
    m_file.close();
}

void experiments::PushBExperimentsWorker::run() {
    std::cout << "Testing PushB with containers..\n";

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<char> vec = data::load_vector_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::list<char> list = data::load_list_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::deque<char> deq = data::load_deque_char("../python/char/char_" + std::to_string(i) + ".txt");

        char_pushb(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<int> vec = data::load_vector_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::list<int> list = data::load_list_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::deque<int> deq = data::load_deque_int("../python/int/int_" + std::to_string(i) + ".txt");

        int_pushb(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<double> vec = data::load_vector_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::list<double> list = data::load_list_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::deque<double> deq = data::load_deque_double("../python/double/double_" + std::to_string(i) + ".txt");

        double_pushb(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<std::string> vec = data::load_vector_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::list<std::string> list = data::load_list_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::deque<std::string> deq = data::load_deque_string("../python/string/string_" + std::to_string(i) + ".txt");

        string_pushb(vec, list, deq);
    }
}

void experiments::PushBExperimentsWorker::char_pushb(std::vector<char> &vec, std::list<char> &list, std::deque<char> &deq) {
    std::cout << "Testing char pushb with vector..\n";
    std::vector<char> vec_tmp;
    m_tlog.reset_start();
    for (const char value : vec) {
        vec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, vec.size(), "char", "vector");

    vec_tmp.clear();
    vec_tmp.reserve(vec.size());
    m_tlog.reset_start();
    for (const char value : vec) {
        vec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, vec.size(), "char", "vector_reserve");

    std::cout << "Testing char pushb with list..\n";
    std::list<char> list_tmp;
    m_tlog.reset_start();
    for (const char value : vec) {
        list_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, list.size(), "char", "list");

    std::cout << "Testing char pushb with deque..\n";
    std::deque<char> dec_tmp;
    m_tlog.reset_start();
    for (const char value : vec) {
        dec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, deq.size(), "char", "deque");
}

void experiments::PushBExperimentsWorker::int_pushb(std::vector<int> &vec, std::list<int> &list, std::deque<int> &deq) {
    std::cout << "Testing int pushb with vector..\n";
    std::vector<int> vec_tmp;
    m_tlog.reset_start();
    for (const int value : vec) {
        vec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, vec.size(), "int", "vector");

    vec_tmp.clear();
    vec_tmp.reserve(vec.size());
    m_tlog.reset_start();
    for (const int value : vec) {
        vec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, vec.size(), "int", "vector_reserve");

    std::cout << "Testing int pushb with list..\n";
    std::list<int> list_tmp;
    m_tlog.reset_start();
    for (const int value : vec) {
        list_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, list.size(), "int", "list");

    std::cout << "Testing int pushb with deque..\n";
    std::deque<int> dec_tmp;
    m_tlog.reset_start();
    for (const int value : vec) {
        dec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, deq.size(), "int", "deque");
}

void experiments::PushBExperimentsWorker::double_pushb(std::vector<double> &vec, std::list<double> &list, std::deque<double> &deq) {
    std::cout << "Testing double pushb with vector..\n";
    std::vector<double> vec_tmp;
    m_tlog.reset_start();
    for (const double value : vec) {
        vec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, vec.size(), "double", "vector");

    vec_tmp.clear();
    vec_tmp.reserve(vec.size());
    m_tlog.reset_start();
    for (const double value : vec) {
        vec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, vec.size(), "double", "vector_reserve");

    std::cout << "Testing double pushb with list..\n";
    std::list<double> list_tmp;
    m_tlog.reset_start();
    for (const double value : vec) {
        list_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, list.size(), "double", "list");

    std::cout << "Testing double pushb with deque..\n";
    std::deque<double> dec_tmp;
    m_tlog.reset_start();
    for (const double value : vec) {
        dec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, deq.size(), "double", "deque");
}

void experiments::PushBExperimentsWorker::string_pushb(std::vector<std::string> &vec, std::list<std::string> &list, std::deque<std::string> &deq) {
    std::cout << "Testing string pushb with vector..\n";
    std::vector<std::string> vec_tmp;
    m_tlog.reset_start();
    for (const std::string& value : vec) {
        vec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, vec.size(), "string", "vector");

    vec_tmp.clear();
    vec_tmp.reserve(vec.size());
    m_tlog.reset_start();
    for (const std::string& value : vec) {
        vec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, vec.size(), "string", "vector_reserve");

    std::cout << "Testing string pushb with list..\n";
    std::list<std::string> list_tmp;
    m_tlog.reset_start();
    for (const std::string& value : vec) {
        list_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, list.size(), "string", "list");

    std::cout << "Testing string pushb with deque..\n";
    std::deque<std::string> dec_tmp;
    m_tlog.reset_start();
    for (const std::string& value : vec) {
        dec_tmp.push_back(value);
    }
    m_tlog.log_duration(m_file, deq.size(), "string", "deque");
}