#ifndef LOGEXPORT_H
#define LOGEXPORT_H

#include <string>

typedef void(*LogMessageFunction)(std::string);
typedef void(*LogWarningFunction)(std::string);
typedef void(*LogErrorFunction)(std::string);

LogMessageFunction g_logMessage = nullptr;
LogWarningFunction g_logWarning = nullptr;
LogErrorFunction g_logError = nullptr;

extern "C" __declspec(dllexport) void RegisterMessageLogger(LogMessageFunction logMessage) {
  g_logMessage = logMessage;
}

extern "C" __declspec(dllexport) void RegisterWarningLogger(LogWarningFunction logWarning) {
  g_logWarning = logWarning;
}

extern "C" __declspec(dllexport) void RegisterErrorLogger(LogErrorFunction logError) {
  g_logError = logError;
}

#endif // LOGEXPORT_H