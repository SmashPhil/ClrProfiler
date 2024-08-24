
#ifndef PROFILER_H
#define PROFILER_H

#include "pch.h"

class CorProfiler : 
  public ICorProfilerCallback2
{
  HRESULT STDMETHODCALLTYPE FunctionEnter(FunctionID funcID);
  HRESULT STDMETHODCALLTYPE FunctionLeave(FunctionID funcID);
};

#endif // PROFILER_H