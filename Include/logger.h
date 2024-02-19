#ifndef LOG
#define LOG

#include<memory>
#include "Log.h"
#include "String.h"
#include <fstream>
using loging::Log;
using Type::String;
namespace loging {

    
    auto mylogger = std::make_shared<Log>("Deep");

    std::shared_ptr<Log> default_logger() {
        return mylogger;
    }

    void setDefaultLogger(std::shared_ptr<Log> l) {
        mylogger = l;
    }

    void flushBuffer(Type::String fn, Type::String buffer) {
        std::ofstream of(fn.getString(), std::ios::app);
        of <<buffer;
        std::cout << "files dumped succesfully\n";
    }

    template<typename... T>
    void Log::log(Log::Level l, T... arg) {
        if (m_LogLevel >= l) {
            String tmp = d1.getstringval();
            std::cout << d1.getstringval();
            std::cout << " [" << Log::logger << "] ";
           tmp.append(" [");
           tmp.append(String(Log::logger));
            tmp.append("] ");
            std::cout << " [" << default_logger()->getlevel(l) << "] ";
            tmp.append(" [");
            tmp.append(String(default_logger()->getlevel(l)));
            tmp.append("] ");
            Log::print(arg...);
            if (this->fileDump) {
                this->logBuffer.append(tmp);
                default_logger()->setupBuffer(arg...);
                this->m_cnt++;
                logBuffer.append("\n");
                if (this->m_cnt == 5) {
                    flushBuffer(Log::fileName, logBuffer);
                    this->logBuffer = "";
                    this->m_cnt = 0;
                }
            }
        }
    }

    Log::~Log() {
        if(this->logBuffer.length()>0)
        flushBuffer(fileName, logBuffer);

        this ->logBuffer = "";
    }

    template<typename m, typename... arg>
    void Warn(const m message, arg... others) {
        default_logger() -> Log::log(Log::Level::LevelWarning, message, others...);
    }

    template<typename m, typename... arg>
    void Error(const m message, arg... others) {
        default_logger()->Log::log(Log::Level::LevelError, message, others...);
    }

    template<typename m, typename... arg>
    void Info(const m message, arg... others) {
        default_logger()->Log::log(Log::Level::LevelInfo, message, others...);
    }
}
#endif