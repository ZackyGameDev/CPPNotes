#pragma once // this exists just to make sure the inclusion only happens once. (avoiding multiple definitionos found error)

class Logger {
public:
    enum Level {
        LevelError = 0, LevelWarning, LevelInfo
    };  

    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    // int m_LogLevel = LogLevelInfo; // this is fine too
    Level m_LogLevel = LevelInfo;

public:
    void setLevel(Level level);

    void error(const char* message);
    void warn(const char* message);
    void info(const char* message);
};
