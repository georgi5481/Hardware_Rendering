#ifndef UTILS_TIME_TIME_H_
#define UTILS_TIME_TIME_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<chrono>

//3rd-party includes

//Own includes


class Time {
public:
	void init();
	//getElapsed() method simply mesures time between 2 points of time
	Time& getElapsed();

	int64_t toSeconds()const;
	int64_t toMilliseconds() const;
	int64_t  toMicroseconds() const
	int64_t  toNanoseconds() const;

std::chrono::time_point<std::chrono::steady_clock> _now = std::chrono::steady_clock::now();
std::chrono::time_point<std::chrono::steady_clock> _elcapsedLastCall;
};

#endif /* UTILS_TIME_TIME_H_ */
