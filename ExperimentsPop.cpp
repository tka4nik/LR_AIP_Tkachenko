#include "Experiments.h"
#include "FilesFunctions.h"
#include <string>


experiments::PopFExperimentsWorker::PopFExperimentsWorker() {
    m_file.open("../popf_out.csv");
    m_tlog = time_log::TimeLogger();
}

experiments::PopFExperimentsWorker::~PopFExperimentsWorker() {
    m_file.close();
}

void experiments::PopFExperimentsWorker::run() {
    std::cout << "Testing Find with containers..\n";

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<char> vec = data::load_vector_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::list<char> list = data::load_list_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::deque<char> deq = data::load_deque_char("../python/char/char_" + std::to_string(i) + ".txt");

        char_popf(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<int> vec = data::load_vector_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::list<int> list = data::load_list_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::deque<int> deq = data::load_deque_int("../python/int/int_" + std::to_string(i) + ".txt");

        int_popf(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<double> vec = data::load_vector_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::list<double> list = data::load_list_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::deque<double> deq = data::load_deque_double("../python/double/double_" + std::to_string(i) + ".txt");

        double_popf(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<std::string> vec = data::load_vector_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::list<std::string> list = data::load_list_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::deque<std::string> deq = data::load_deque_string("../python/string/string_" + std::to_string(i) + ".txt");

        string_popf(vec, list, deq);
    }
}

void experiments::PopFExperimentsWorker::char_popf(std::vector<char> &vec, std::list<char> &list, std::deque<char> &deq) {
    std::cout << "Testing char popf with vector..\n";
    int size = vec.size();
    m_tlog.reset_start();
    while(!vec.empty()) {
        vec.erase(vec.begin());
    }
    m_tlog.log_duration(m_file, size, "char", "vector");

    std::cout << "Testing char popf with list..\n";
    size = list.size();
    m_tlog.reset_start();
    while (!list.empty()) {
        list.pop_front();
    }
    m_tlog.log_duration(m_file, size, "char", "list");

    std::cout << "Testing char popf with deque..\n";
    size = deq.size();
    m_tlog.reset_start();
    while (!deq.empty()) {
        deq.pop_front();
    }    m_tlog.log_duration(m_file, size, "char", "deque");
}

void experiments::PopFExperimentsWorker::int_popf(std::vector<int> &vec, std::list<int> &list, std::deque<int> &deq) {
    std::cout << "Testing int popf with vector..\n";
    int size = vec.size();
    m_tlog.reset_start();
    while(!vec.empty()) {
        vec.erase(vec.begin());
    }
    m_tlog.log_duration(m_file, size, "int", "vector");

    std::cout << "Testing int popf with list..\n";
    size = list.size();
    m_tlog.reset_start();
    while (!list.empty()) {
        list.pop_front();
    }
    m_tlog.log_duration(m_file, size, "int", "list");

    std::cout << "Testing int popf with deque..\n";
    size = deq.size();
    m_tlog.reset_start();
    while (!deq.empty()) {
        deq.pop_front();
    }    m_tlog.log_duration(m_file, size, "int", "deque");
}

void experiments::PopFExperimentsWorker::double_popf(std::vector<double> &vec, std::list<double> &list, std::deque<double> &deq) {
    std::cout << "Testing double popf with vector..\n";
    int size = vec.size();
    m_tlog.reset_start();
    while(!vec.empty()) {
        vec.erase(vec.begin());
    }
    m_tlog.log_duration(m_file, size, "double", "vector");

    std::cout << "Testing double popf with list..\n";
    size = list.size();
    m_tlog.reset_start();
    while (!list.empty()) {
        list.pop_front();
    }
    m_tlog.log_duration(m_file, size, "double", "list");

    std::cout << "Testing double popf with deque..\n";
    size = deq.size();
    m_tlog.reset_start();
    while (!deq.empty()) {
        deq.pop_front();
    }    m_tlog.log_duration(m_file, size, "double", "deque");
}

void experiments::PopFExperimentsWorker::string_popf(std::vector<std::string> &vec, std::list<std::string> &list, std::deque<std::string> &deq) {
    std::cout << "Testing string popf with vector..\n";
    int size = vec.size();
    m_tlog.reset_start();
    while(!vec.empty()) {
        vec.erase(vec.begin());
    }
    m_tlog.log_duration(m_file, size, "string", "vector");

    std::cout << "Testing string popf with list..\n";
    size = list.size();
    m_tlog.reset_start();
    while (!list.empty()) {
        list.pop_front();
    }
    m_tlog.log_duration(m_file, size, "string", "list");

    std::cout << "Testing string popf with deque..\n";
    size = deq.size();
    m_tlog.reset_start();
    while (!deq.empty()) {
        deq.pop_front();
    }    m_tlog.log_duration(m_file, size, "string", "deque");
}
////////////////////////////////////////////////////////////////////////////

experiments::PopBExperimentsWorker::PopBExperimentsWorker() {
    m_file.open("../popb_out.csv");
    m_tlog = time_log::TimeLogger();
}

experiments::PopBExperimentsWorker::~PopBExperimentsWorker()  {
    m_file.close();
}

void experiments::PopBExperimentsWorker::run() {
    std::cout << "Testing PopB with containers..\n";

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<char> vec = data::load_vector_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::list<char> list = data::load_list_char("../python/char/char_" + std::to_string(i) + ".txt");
        std::deque<char> deq = data::load_deque_char("../python/char/char_" + std::to_string(i) + ".txt");

        char_popb(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<int> vec = data::load_vector_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::list<int> list = data::load_list_int("../python/int/int_" + std::to_string(i) + ".txt");
        std::deque<int> deq = data::load_deque_int("../python/int/int_" + std::to_string(i) + ".txt");

        int_popb(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<double> vec = data::load_vector_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::list<double> list = data::load_list_double("../python/double/double_" + std::to_string(i) + ".txt");
        std::deque<double> deq = data::load_deque_double("../python/double/double_" + std::to_string(i) + ".txt");

        double_popb(vec, list, deq);
    }

    for (int i = 1; i <= 10; i++) {
        std::cout << "File Size: " + std::to_string(i * 100000) + "\n";

        std::vector<std::string> vec = data::load_vector_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::list<std::string> list = data::load_list_string("../python/string/string_" + std::to_string(i) + ".txt");
        std::deque<std::string> deq = data::load_deque_string("../python/string/string_" + std::to_string(i) + ".txt");

        string_popb(vec, list, deq);
    }
}

void experiments::PopBExperimentsWorker::char_popb(std::vector<char> &vec, std::list<char> &list, std::deque<char> &deq) {
    std::cout << "Testing char popb with vector..\n";
    int size = vec.size();
    m_tlog.reset_start();
    while(!vec.empty()) {
        vec.pop_back();
    }
    m_tlog.log_duration(m_file, size, "char", "vector");

    std::cout << "Testing char popb with list..\n";
    size = list.size();
    m_tlog.reset_start();
    while (!list.empty()) {
        list.pop_back();
    }
    m_tlog.log_duration(m_file, size, "char", "list");

    std::cout << "Testing char popb with deque..\n";
    size = deq.size();
    m_tlog.reset_start();
    while (!deq.empty()) {
        deq.pop_back();
    }    m_tlog.log_duration(m_file, size, "char", "deque");
}

void experiments::PopBExperimentsWorker::int_popb(std::vector<int> &vec, std::list<int> &list, std::deque<int> &deq) {
    std::cout << "Testing int popb with vector..\n";
    int size = vec.size();
    m_tlog.reset_start();
    while(!vec.empty()) {
        vec.pop_back();
    }
    m_tlog.log_duration(m_file, size, "int", "vector");

    std::cout << "Testing int popb with list..\n";
    size = list.size();
    m_tlog.reset_start();
    while (!list.empty()) {
        list.pop_back();
    }
    m_tlog.log_duration(m_file, size, "int", "list");

    std::cout << "Testing int popb with deque..\n";
    size = deq.size();
    m_tlog.reset_start();
    while (!deq.empty()) {
        deq.pop_back();
    }    m_tlog.log_duration(m_file, size, "int", "deque");
}

void experiments::PopBExperimentsWorker::double_popb(std::vector<double> &vec, std::list<double> &list, std::deque<double> &deq) {
    std::cout << "Testing double popb with vector..\n";
    int size = vec.size();
    m_tlog.reset_start();
    while(!vec.empty()) {
        vec.pop_back();
    }
    m_tlog.log_duration(m_file, size, "double", "vector");

    std::cout << "Testing double popb with list..\n";
    size = list.size();
    m_tlog.reset_start();
    while (!list.empty()) {
        list.pop_back();
    }
    m_tlog.log_duration(m_file, size, "double", "list");

    std::cout << "Testing double popb with deque..\n";
    size = deq.size();
    m_tlog.reset_start();
    while (!deq.empty()) {
        deq.pop_back();
    }    m_tlog.log_duration(m_file, size, "double", "deque");
}

void experiments::PopBExperimentsWorker::string_popb(std::vector<std::string> &vec, std::list<std::string> &list, std::deque<std::string> &deq) {
    std::cout << "Testing string popb with vector..\n";
    int size = vec.size();
    m_tlog.reset_start();
    while(!vec.empty()) {
        vec.pop_back();
    }
    m_tlog.log_duration(m_file, size, "string", "vector");

    std::cout << "Testing char string with list..\n";
    size = list.size();
    m_tlog.reset_start();
    while (!list.empty()) {
        list.pop_back();
    }
    m_tlog.log_duration(m_file, size, "string", "list");

    std::cout << "Testing char string with deque..\n";
    size = deq.size();
    m_tlog.reset_start();
    while (!deq.empty()) {
        deq.pop_back();
    }    m_tlog.log_duration(m_file, size, "string", "deque");
}
