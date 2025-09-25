#include <iostream>

struct Vector2 {
	double x;
	double y;
};

enum eVecQuadrant {
	FIRST,
	SECOND,
	THIRD,
	FOURTH,
	NONE
};

void printVector(Vector2 v) {
	std::cout << "(" << v.x << " ; " << v.y << ")";
}

Vector2 vSum(Vector2 a, Vector2 b) {
	Vector2 result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return result;
}

Vector2 vSub(Vector2 a, Vector2 b) {
	Vector2 result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return result;
}

eVecQuadrant getVecQuadrant(Vector2 v) {
	if (v.x > 0 && v.y > 0) return FIRST;
	if (v.x < 0 && v.y > 0) return SECOND;
	if (v.x < 0 && v.y < 0) return THIRD;
	if (v.x > 0 && v.y < 0) return FOURTH;
	if (v.x == 0 && v.y == 0) return NONE;
}

void vNotation(Vector2 v) {
	std::cout << "\nВектор "; printVector(v); std::cout << " находится ";

	switch (getVecQuadrant(v)) {
		case 0: std::cout << "в первой четверти\n"; break;
		case 1: std::cout << "во второй четверти\n"; break;
		case 2: std::cout << "в третьей четверти\n"; break;
		case 3: std::cout << "в четвёртой четверти\n"; break;
		case 4: std::cout << "в начале координат\n"; break;
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	Vector2 a = { 1.24, -2 };
	Vector2 b = { 4, 5.2 };

	printVector(vSum(a, b)); std::cout << std::endl;
	printVector(vSub(a, b)); std::cout << std::endl;
	vNotation(a);
	
	return 0;
}
