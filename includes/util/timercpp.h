#ifndef TIMERCPP_H
#define TIMERCPP_H

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

class Timer {
	bool clear = false;

public:
	void setTimeout(std::function<void(void)> &&callback, int delay);

	void setInterval(std::function<void(void)> &&callback, int interval);

	void stop( );
};

#endif
