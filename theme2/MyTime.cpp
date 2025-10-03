#include "MyTime.h"
#include <iostream>

MyTime::MyTime() {
	hour = 0; min = 0, sec = 0;
}

MyTime::MyTime(int h, int m, int s) {
	hour = h; min = m, sec = s;
}

void MyTime::info() {
	std::cout << "(" << hour << ":" << min << ":" << sec << ")\n";
}

MyTime MyTime::add(int s) {
	MyTime result;
	int totalSec = hour * 60 * 60 + min * 60 + sec + s;

	result.sec = totalSec % 60;
	result.min = totalSec / 60 % 60;
	result.hour = totalSec / 60 / 60;
	return result;
}

MyTime MyTime::sub(int s) {
	MyTime result;
	int totalSec = hour * 60 * 60 + min * 60 + sec - s;
	
	if (totalSec < 0) totalSec = 0;

	result.sec = totalSec % 60;
	result.min = totalSec / 60 % 60;
	result.hour = totalSec / 60 / 60;
	return result;
}

MyTime MyTime::mtAdd(MyTime t) {
	MyTime result;

	int totalSec = (hour + t.hour) * 60 * 60 + (min + t.min) * 60 + (sec + t.sec);

	if (totalSec < 0) totalSec = 0;

	result.sec = totalSec % 60;
	result.min = totalSec / 60 % 60;
	result.hour = totalSec / 60 / 60;

	return result;
}

MyTime MyTime::mtSub(MyTime t) {
	MyTime result;

	int totalSec1 = hour * 3600 + min * 60 + sec;
	int totalSec2 = t.hour * 3600 + t.min * 60 + t.sec;
	int diffSec = totalSec1 - totalSec2;

	if (diffSec < 0) diffSec = 0;

	result.sec = diffSec % 60;
	result.min = diffSec / 60 % 60;
	result.hour = diffSec / 60 / 60;

	return result;

}