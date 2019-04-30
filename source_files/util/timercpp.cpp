#include "../../includes/util/timercpp.h"

void Timer::setTimeout(std::function<void(void)> &&callback, int delay) {
	this->clear = false;
	std::thread t([=]( ) {
		if (this->clear) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear) return;
		callback();
	});
	t.detach();
}

void Timer::setInterval(std::function<void(void)> &&callback, int interval) {
	this->clear = false;
	std::thread t([=]( ) {
		while (true) {
			if (this->clear) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear) return;
			callback();
		}
	});
	t.detach();
}

void Timer::stop( ) {
	this->clear = true;
}
