
#include "pch.h"
#include "profiler.h"

HRESULT STDMETHODCALLTYPE CorProfiler::FunctionEnter(FunctionID funcID) {
  return S_OK;
}

HRESULT STDMETHODCALLTYPE CorProfiler::FunctionLeave(FunctionID funcID) {
  return S_OK;
}