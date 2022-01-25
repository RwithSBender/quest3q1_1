#pragma once
#include "MyTools.h"
#include <string>


class LoggerSingleton
{
public:
    virtual void __fastcall OpenLogFile(const std::string& FN) = 0;
    virtual void CloseLogFile() = 0;
    virtual void __fastcall WriteToLog(const std::string& str) = 0;
    virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;
    virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;
};

class LoggerProxy: public LoggerSingleton
{
public:
	LoggerProxy();
	~LoggerProxy();
	virtual void __fastcall OpenLogFile(const std::string& FN);
	virtual void CloseLogFile() = 0;
	virtual void __fastcall WriteToLog(const std::string& str);
	virtual void __fastcall WriteToLog(const std::string& str, int n);
	virtual void __fastcall WriteToLog(const std::string& str, double d);
private:
	long count = 0;
	LoggerSingleton* loggerproxy;
};