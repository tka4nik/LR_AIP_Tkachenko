#pragma once
#include <chrono>
#include <string>

namespace time_log {
    class TimeLogger {
    public:
        using clock = std::chrono::high_resolution_clock;
        using time_point = std::chrono::time_point<clock>;

        TimeLogger() : m_start(clock::now()) {}

        void reset_start() { m_start = clock::now(); }

        void log_duration(std::ostream &out, int size, const char *type) {
            std::chrono::nanoseconds duration = clock::now() - m_start;
            out << duration.count() << ";" << std::to_string(size) << ";" << type << '\n';
        }

        void log_duration(std::ostream &out, int size, const char *type, const char *message) {
            std::chrono::nanoseconds duration = clock::now() - m_start;
            out << duration.count() << ";" << std::to_string(size) << ";" << type << ";" << message << '\n';
        }

    private:
        time_point m_start;
    };
}
