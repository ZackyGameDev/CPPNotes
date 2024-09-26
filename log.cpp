#include <iostream>
#include "log.h"

void Log(const char* message_to_print) {
    std::cout << message_to_print << std::endl;
}

void Logger::setLevel(Level level) {
    m_LogLevel = level;
}

void Logger::error(const char* message) {
    if (m_LogLevel >= LevelError)
        std::cout << "[ERROR]: " << message << std::endl;
}

void Logger::warn(const char* message) {
    if (m_LogLevel >= LevelWarning)
        std::cout << "[WARNING]: " << message << std::endl;
}

void Logger::info(const char* message) {
    if (m_LogLevel >= LevelInfo)
        std::cout << "[WARNING]: " << message << std::endl;
}
