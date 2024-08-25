
#include "pch.h"
#include "framework.h"
#include "environment.h"

#include <cor.h>
#include <cordebug.h>
#include <windows.h>
#include <cstdio>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[]) {
  LPWSTR filePath = argv[0];
  LPWSTR commandLine = argv[1];
  Environment::StartProcess(filePath, commandLine);
  return 0;
}