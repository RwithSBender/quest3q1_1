#pragma once
#include "LoggerSingleton.h"
#include <fstream>
using namespace std;

class FileLoggerSingleton: public LoggerSingleton
{
public:
    ofstream logOut;
    static FileLoggerSingleton& getInstance()
    {
        static FileLoggerSingleton theInstance;
        return theInstance;
    }

    void SetColor(ConsoleColor color);
    void __fastcall OpenLogFile(const std::string& FN);
    void CloseLogFile();
    void __fastcall WriteToLog(const std::string& str);
    void __fastcall WriteToLog(const std::string& str, int n);
    void __fastcall WriteToLog(const std::string& str, double d);
    FileLoggerSingleton() { };
    FileLoggerSingleton(const FileLoggerSingleton& root) = delete;
private:
    
    FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;
};