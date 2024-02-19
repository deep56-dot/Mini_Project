#ifndef _LOG_
#define _LOG_

#include<iostream>
#include "Date.h"
#include "String.h"

namespace loging {
    class Log {
    public:
        enum class Level {
            LevelCritical=0,LevelError, LevelWarning, LevelInfo, LevelDebug
        };

        Log(Type::String name, Type::String fn= "defaultlog.txt") : m_LogLevel{ Level::LevelInfo }, logger{ name }, fileName{fn} {}

        Log(Type::String name, Level level, Type::String fn= "defaultlog.txt") : m_LogLevel{ level }, logger{ name }, fileName{ fn } {}

        ~Log();

        void SetLogLevel(Level level) {
            m_LogLevel = level;
        }

        template<typename... T>
        void log(Level l, T... arg);


        void setupBuffer() {}
        template<typename m, typename... T>
        void setupBuffer(m s1, T... others) {
            logBuffer.append(s1);
            setupBuffer(others...);
        }
        void setFileDump(bool val) {
            fileDump=val;
        }
    private:
        Type::String getlevel(Level l) const {
            switch (l) {
            case Level::LevelError:
                return "\033[31mError\033[0m";

            case Level::LevelWarning:
                return "\033[33mWarning\033[0m";

            case Level::LevelInfo:
                return "\033[32mInfo\033[0m";

            case Level::LevelDebug:
                return "Debug";

            case Level::LevelCritical:
                return "\033[41;37mCritical\033[0m";
            }
        }


        String logBuffer;
        Level m_LogLevel;
        int m_cnt{ 0 };
        bool fileDump = true;
        Type::String logger;
        Utility::date d1{ 30,1,2024 };
        String fileName;
        void print() const {
            std::cout << "\n";
        }

        template<typename m, typename... arg>
        void print(const m message, arg... others) const {
            std::cout << message << " ";
            print(others...);
        }

    };
}



#endif