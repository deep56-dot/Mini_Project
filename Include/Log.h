#include<iostream>
#include "Date.h"

namespace loging {
   
    class Log
    {
  
    public:
        enum class Level {
            LevelError = 0, LevelWarning, LevelInfo
        };

        Log() : m_LogLevel{ Level::LevelInfo } {}

        Log(Level level) : m_LogLevel{level} {}

        void SetLogLevel(Level level) {
            m_LogLevel = level;
        }

        template<typename m, typename... arg>
        void Warn(const m message,arg... others)  const {
            std::cout << "inside WARN\n";
            if (m_LogLevel >= Level::LevelWarning)
                std::cout << "[Warning]: "; 
                print(message, others...);
                std::cout<< d1.getstringval() << std::endl;
        }

        template<typename m, typename... arg>
        void Error(const m message,arg... others) const {
            std::cout << "inside ERROR\n";
            if (m_LogLevel >= Level::LevelError)
                std::cout << "[Error]: ";
                print(message, others...);
                std::cout << d1.getstringval() << std::endl;
        }

        template<typename m, typename... arg>
        void Info(const m message,arg... others) const {
            std::cout << "inside INFO\n";
            if (m_LogLevel >= Level::LevelInfo)
                std::cout << "[Info]: ";
                print(message, others...);
                std::cout << d1.getstringval() << std::endl;
        }

    private:
        Level m_LogLevel;
        Utility::date d1{ 30,1,2024 };

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

