#include <boost/asio/detail/win_iocp_operation.hpp>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifndef BOOST_UWP_HPP
#define BOOST_UWP_HPP

#ifdef __cplusplus
extern "C" {
#endif

typedef
	VOID
	(APIENTRY *PTIMERAPCROUTINE)(
		_In_opt_ LPVOID lpArgToCompletionRoutine,
		_In_     DWORD dwTimerLowValue,
		_In_     DWORD dwTimerHighValue
		);

WINBASEAPI
BOOL
WINAPI
SetWaitableTimer(
	_In_ HANDLE hTimer,
	_In_ const LARGE_INTEGER * lpDueTime,
	_In_ LONG lPeriod,
	_In_opt_ PTIMERAPCROUTINE pfnCompletionRoutine,
	_In_opt_ LPVOID lpArgToCompletionRoutine,
	_In_ BOOL fResume
);

WINBASEAPI
_Ret_maybenull_
HANDLE
WINAPI
CreateWaitableTimerW(
	_In_opt_ LPSECURITY_ATTRIBUTES lpTimerAttributes,
	_In_ BOOL bManualReset,
	_In_opt_ LPCWSTR lpTimerName
);

#ifdef UNICODE
#define CreateWaitableTimer  CreateWaitableTimerW
#endif

#ifdef __cplusplus
}
#endif

#endif // BOOST_UWP_HPP