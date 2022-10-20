#include "FilesFunctions.h"
#include <string>


std::vector<char> data::load_vector_char(const std::string &path_file) {
    std::vector<char> vec;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return vec;
    }
    char tmp;
    while (!file.eof()) {
        file >> tmp;
        vec.push_back(tmp);
    }
    file.close();
    return vec;
}


std::vector<int> data::load_vector_int(const std::string &path_file) {
    std::vector<int> vec;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return vec;
    }
    int tmp;
    while (!file.eof()) {
        file >> tmp;
        vec.push_back(tmp);
    }
    file.close();
    return vec;
}

std::vector<double> data::load_vector_double(const std::string &path_file) {
    std::vector<double> vec;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return vec;
    }
    double tmp;
    while (!file.eof()) {
        file >> tmp;
        vec.push_back(tmp);
    }
    file.close();
    return vec;
}

std::vector<std::string> data::load_vector_string(const std::string &path_file) {
    std::vector<std::string> vec;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return vec;
    }
    std::string tmp;
    while (std::getline(file, tmp, '\n')) {
        vec.push_back(tmp);
    }
    file.close();
    return vec;
}

std::list<char> data::load_list_char(const std::string &path_file) {
    std::list<char> list;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return list;
    }
    char tmp;
    while (!file.eof()) {
        file >> tmp;
        list.push_back(tmp);
    }
    file.close();
    return list;
}

std::list<int> data::load_list_int(const std::string &path_file) {
    std::list<int> list;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return list;
    }
    int tmp;
    while (!file.eof()) {
        file >> tmp;
        list.push_back(tmp);
    }
    file.close();
    return list;
}

std::list<double> data::load_list_double(const std::string &path_file) {
    std::list<double> list;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return list;
    }
    double tmp;
    while (!file.eof()) {
        file >> tmp;
        list.push_back(tmp);
    }
    file.close();
    return list;
}

std::list<std::string> data::load_list_string(const std::string &path_file) {
    std::list<std::string> list;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return list;
    }
    std::string tmp;
    while (std::getline(file, tmp, '\n')) {
        list.push_back(tmp);
    }
    file.close();
    return list;
}

std::deque<char> data::load_deque_char(const std::string &path_file) {
    std::deque<char> deque;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return deque;
    }
    char tmp;
    while (!file.eof()) {
        file >> tmp;
        deque.push_back(tmp);
    }
    file.close();
    return deque;
}

std::deque<int> data::load_deque_int(const std::string &path_file) {
    std::deque<int> deque;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return deque;
    }
    int tmp;
    while (!file.eof()) {
        file >> tmp;
        deque.push_back(tmp);
    }
    file.close();
    return deque;
}

std::deque<double> data::load_deque_double(const std::string &path_file) {
    std::deque<double> deque;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return deque;
    }
    double tmp;
    while (!file.eof()) {
        file >> tmp;
        deque.push_back(tmp);
    }
    file.close();
    return deque;
}

std::deque<std::string> data::load_deque_string(const std::string &path_file) {
    std::deque<std::string> deque;
    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cout << "Error while opening a file";
        return deque;
    }
    std::string tmp;
    while (std::getline(file, tmp, '\n')) {
        deque.push_back(tmp);
    }
    file.close();
    return deque;
}




