#include <iostream>
#include "./Include/Log.h"
#include "./Include/Date.h"
#include "./Include/String.h"
#include "./Include/logger.h"

using Utility::date;
using Type::String;
using loging::Log;


int main()
{
    loging::Info("Fine!","ifdjs","iesdfju");
    loging::Warn("Carefull!");
    loging::Error("Stop!");
    loging::Info("Fine!", "ifdjs", "iesdfju");
    loging::default_logger()->setFileDump(false);
    loging::Warn("Carefull!");
    loging::Error("Stop!");
    loging::default_logger()->setFileDump(true);
    auto l = std::make_shared<Log>("my","my.txt");
    loging::Info("myInfo");
    loging::setDefaultLogger(l);
    l->log(Log::Level::LevelDebug, "my debug");
    l->log(Log::Level::LevelError, "my error");
    l->log(Log::Level::LevelCritical, "my critical");

}

