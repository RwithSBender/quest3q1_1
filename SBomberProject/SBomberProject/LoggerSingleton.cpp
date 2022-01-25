#include "LoggerSingleton.h"
#include "FileLoggerSingleton.h"
#include <iostream>

using namespace std;


LoggerProxy::LoggerProxy()
{
	loggerproxy = new FileLoggerSingleton();
};
LoggerProxy::~LoggerProxy()
{
	delete loggerproxy;
};
void __fastcall LoggerProxy::OpenLogFile(const std::string& FN)
{
	loggerproxy->OpenLogFile(FN);
}
void LoggerProxy::CloseLogFile()
{
	loggerproxy->CloseLogFile();
}
void __fastcall LoggerProxy::WriteToLog(const std::string& str)
{
	loggerproxy->WriteToLog(to_string(count++) + str);
}
void __fastcall LoggerProxy::WriteToLog(const std::string& str,int n)
{
	loggerproxy->WriteToLog(to_string(count++) + str, n);
}
void __fastcall LoggerProxy::WriteToLog(const std::string& str,double d)
{
	loggerproxy->WriteToLog(to_string(count++) + str, d);
}