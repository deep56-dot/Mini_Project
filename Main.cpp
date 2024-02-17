#include <iostream>
#include "./Include/Log.h"
#include "./Include/Date.h"
#include "./Include/String.h"

using Utility::date;
using Type::String;
using loging::Log;

int main()
{
    Log log;
    log = { Log::Level::LevelInfo };
    log.Info("Fine!");
    log.Warn("Carefull!");
    log.Error("Stop!");

    String s1("Deep");
    date d1;
    d1.setDate(30, 2, 2024);
    std::cout << s1[6]<<"\n";
}

