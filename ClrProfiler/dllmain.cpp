// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "ClrProfiler_i.h"
#include "dllmain.h"

#include <cor.h>
#include <cordebug.h>
#include <windows.h>
#include <cstdio>
#include <tchar.h>

void _tmain(int argc, TCHAR* argv[]) {

  STARTUPINFO startupInfo;
  PROCESS_INFORMATION processInfo;

  ZeroMemory(&startupInfo, sizeof(startupInfo));
  startupInfo.cb = sizeof(startupInfo);
  ZeroMemory(&processInfo, sizeof(processInfo));

  if (argc != 2) {
    printf("Usage: %ls [cmdline]\n", argv[0]);
    return;
  }

  if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo)) {
    printf("CreateProcess failed (%d).\n", GetLastError());
    return;
  }

  WaitForSingleObject(processInfo.hProcess, INFINITE);

  CloseHandle(processInfo.hProcess);
  CloseHandle(processInfo.hThread);

  return;
}