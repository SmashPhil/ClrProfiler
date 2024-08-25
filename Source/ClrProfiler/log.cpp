#include "pch.h"
#include "log.h"
#include "logexport.h"

void Log::Message(std::string message) {
  g_logMessage(message);
}

void Log::Warning(std::string message) {
  g_logWarning(message);
}

void Log::Error(std::string message) {
  g_logError(message);
}