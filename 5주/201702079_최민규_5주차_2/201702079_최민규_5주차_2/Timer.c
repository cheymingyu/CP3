#include "Timer.h"
#include "Common.h"
#include <Windows.h>

typedef struct {
	LARGE_INTEGER	_frequency;
	LARGE_INTEGER	_startCounter;
	LARGE_INTEGER	_stopCounter;
} Timer;

Timer*	Timer_new(void) {
	Timer* _this;
	_this = NewObject(Timer);
	QueryPerformanceFrequency(&(_this->_frequency));
	return _this;
}

void	Timer_delete(Timer* _this) {
	free(_this);
}

void	Timer_start(Timer* _this) {
	QueryPerformanceCounter(&(_this->_startCounter));
}

void	Timer_stop(Timer* _this) {
	QueryPerformanceCounter(&(_this->_stopCounter));
}

double	Timer_duration(Timer* _this) {
	double elapsed = (double)(_this->_stopCounter.QuadPart - _this->_startCounter.QuadPart);
	return (elapsed * 1000000.0 / (double)_this->_frequency.QuadPart);
}