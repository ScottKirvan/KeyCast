/*
Based on "Simple C++ Timer Wrapper"
http://www.codeproject.com/Articles/146617/Simple-C-Timer-Wrapper
by ken.loveday

v1.0 2013 ArmyOfPirates
*/
#include <windows.h>
// static void CALLBACK TimerProc(void *, BOOLEAN);
// static void CALLBACK TimerProcOnce(void *param, BOOLEAN timerCalled);

///////////////////////////////////////////////////////////////////////////////
//
// class CTimer
//
class CTimer
{
public:
	CTimer();
	virtual ~CTimer();
	bool Start(unsigned int interval,	 // interval in ms
			   bool immediately = false, // true to call first event immediately
			   bool once = false);		 // true to call timed event only once
	void Stop();
	void (*OnTimedEvent)();
	void SetCount(int value);
	int GetCount();
	bool Enabled();

private:
	HANDLE m_hTimer;
	long m_mutexCount;
};
