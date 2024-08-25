
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <windows.h>
#include <string>
#include <cstdio>

namespace Environment {

  DEFINE_GUID(CLSID_CorProfiler, 0x3E7F4F56, 0xB7CD, 0x4EB9, 0x82, 0x82, 0x2F, 0x16, 0x6B, 0x00, 0x52, 0xEC);

  static void StartProcess(LPWSTR appName, LPWSTR commandLine) {
    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory(&processInfo, sizeof(processInfo));

    if (!CreateProcess(appName, commandLine, NULL, NULL, FALSE, CREATE_UNICODE_ENVIRONMENT, NULL, NULL, &startupInfo, &processInfo)) {
      printf("CreateProcess failed (%d).\n", GetLastError());
      return;
    }

    WaitForSingleObject(processInfo.hProcess, INFINITE);

    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);
  }
}

#endif // ENVIRONMENT_H