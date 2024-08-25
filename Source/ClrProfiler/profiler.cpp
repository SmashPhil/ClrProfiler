
#include "pch.h"
#include "profiler.h"

#include <ostream>
#include <string>

//Global module
HMODULE g_hModule;

CorProfiler::CorProfiler()
{
  m_refCount = 0;
  m_profilerInfo = nullptr;

  remove(kLogFileName);
}

CorProfiler::~CorProfiler()
{
  if (m_profilerInfo) {
    m_profilerInfo->Release();
  }
}

STDMETHODIMP_(HRESULT __stdcall) CorProfiler::QueryInterface(REFIID riid, void** ppv)
{
  if (riid == IID_IUnknown || riid == IID_ICorProfilerCallback || riid == IID_ICorProfilerCallback2)
  {
    *ppv = static_cast<ICorProfilerCallback2*>(this);
    AddRef();
    return S_OK;
  }
  ppv = nullptr;
  return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG __stdcall) CorProfiler::AddRef()
{
  return InterlockedIncrement(&m_refCount);
}

STDMETHODIMP_(ULONG __stdcall) CorProfiler::Release()
{
  ULONG count = InterlockedDecrement(&m_refCount);
  if (count == 0) {
    delete this;
  }
  return count;
}

STDMETHODIMP_(HRESULT __stdcall) CorProfiler::Initialize(IUnknown* pICorProfilerInfoUnk)
{
  m_logFile << "Initializing profiler..." << std::endl;
  HRESULT hr = pICorProfilerInfoUnk->QueryInterface(IID_ICorProfilerInfo2, (LPVOID*)&m_profilerInfo);
  std::string result = FAILED(hr) ? "PASSED" : "FAILED";
  m_logFile << "Result = " << result << std::endl;
  if (FAILED(hr)) {
    return hr;
  }
  DWORD events = COR_PRF_MONITOR_ENTERLEAVE | COR_PRF_MONITOR_GC | COR_PRF_MONITOR_EXCEPTIONS | COR_PRF_MONITOR_THREADS | COR_PRF_MONITOR_ASSEMBLY_LOADS;
  m_logFile << "Setting event masks..." << std::endl;
  hr = m_profilerInfo->SetEventMask(events);
  if (FAILED(hr)) {
    return hr;
  }
  m_logFile << "Attached!" << std::endl;
  return S_OK;
}

STDMETHODIMP_(HRESULT __stdcall) CorProfiler::Shutdown()
{
  return S_OK;
}

HRESULT STDMETHODCALLTYPE CorProfiler::FunctionEnter(FunctionID funcID) {
  return S_OK;
}

HRESULT STDMETHODCALLTYPE CorProfiler::FunctionLeave(FunctionID funcID) {
  return S_OK;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
  if (ul_reason_for_call == DLL_PROCESS_ATTACH)
  {
    g_hModule = hModule;
  }
  return TRUE;
}

STDAPI DllCanUnloadNow()
{
  return S_OK;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
  // Create class factory and return it
  // Typically, you implement IClassFactory and return its instance here
  return E_NOTIMPL; // Replace with actual implementation
}

STDAPI DllRegisterServer()
{
  // Register the COM object in the registry
  return S_OK;
}

STDAPI DllUnregisterServer()
{
  // Unregister the COM object from the registry
  return S_OK;
}