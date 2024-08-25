
#ifndef PROFILER_H
#define PROFILER_H

#include "pch.h"

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
  LONG m_refCount;
  ICorProfilerInfo* m_profilerInfo;
};

#endif // PROFILER_H