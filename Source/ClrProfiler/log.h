
#ifndef LOG_H
#define LOG_H

#include "pch.h"

#include <string>

class Log
{
public:
  static void Message(std::string message);
  static void Warning(std::string message);
  static void Error(std::string message);
};

#endif // LOG_H