#include <iostream>

struct Vector2 {
	double x;
	double y;
};

Vector2 vSum(struct Vector2 a, struct Vector2 b) {
	struct Vector2 result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;

	return result;
}

void printVector(struct Vector2 v) {
	std::cout << "[" << v.x << " ; " << v.y << "]\n";
}

int main() {

	struct Vector2 a = {1.24,2};
	struct Vector2 b = {4, 5.2};




	printVector(vSum(a,b));

	return 0;
}
