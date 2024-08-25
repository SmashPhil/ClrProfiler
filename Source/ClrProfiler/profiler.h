
#ifndef PROFILER_H
#define PROFILER_H

#include "pch.h"

#include <fstream>

class CorProfiler :
  public ICorProfilerCallback2
{
public:
  CorProfiler();
  virtual ~CorProfiler();

  // IUnknown
  STDMETHODIMP QueryInterface(REFIID riid, void** ppv);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  // ICorProfilerCallback
  STDMETHODIMP Initialize(IUnknown* pICorProfilerInfoUnk);
  STDMETHODIMP Shutdown();

  HRESULT STDMETHODCALLTYPE FunctionEnter(FunctionID funcID);
  HRESULT STDMETHODCALLTYPE FunctionLeave(FunctionID funcID);

private:
  constexpr static char const* kLogFileName = "profiler_log.txt";

  LONG m_refCount;
  ICorProfilerInfo* m_profilerInfo;
  std::ofstream m_logFile{ kLogFileName, std::ios::out | std::ios::app };
};

#endif // PROFILER_H