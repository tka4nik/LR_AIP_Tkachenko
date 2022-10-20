#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "bugprone-unused-return-value"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-result"

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
////////////////////////////////////////////////////////////////////////////

experiments::SortExperimentsWorker::SortExperimentsWorker() {
    m_file.open("../sort_out.csv");
    m_tlog = time_log::TimeLogger();
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
////////////////////////////////////////////////////////////////////////////

experiments::PopFExperimentsWorker::PopFExperimentsWorker() {
    m_file.open("../popf_out.csv");
    m_tlog = time_log::TimeLogger();
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
////////////////////////////////////////////////////////////////////////////

experiments::PushFExperimentsWorker::PushFExperimentsWorker() {
    m_file.open("../pushf_out.csv");
    m_tlog = time_log::TimeLogger();
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
#pragma clang diagnostic pop
#pragma clang diagnostic pop