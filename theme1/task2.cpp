#include <iostream>

struct Complex {
	double re;
	double im;
};

enum eCompType {
	REAL,
	IMAGINARY,
	COMPLEX
};

void printComplex(Complex num) {
	if (num.im > 0)			std::cout << num.re << " + i*" << num.im << std::endl;
	else if (num.im < 0)	std::cout << num.re << " - i*" << num.im*(-1) << std::endl;
	else					std::cout << num.re << std::endl;
}

Complex compSum(Complex a, Complex b) {
	Complex result;
	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return result;
}

Complex compSub(Complex a, Complex b) {
	Complex result;
	result.re = a.re - b.re;
	result.im = a.im - b.im;
	return result;
}

eCompType getCompType(Complex num) {
	if (num.im == 0) return REAL;
	if (num.re == 0 && num.im != 0) return IMAGINARY;
	if (num.im != 0) return COMPLEX;
}

int main() {
	setlocale(LC_ALL, "rus");

	Complex a = { 2, -3 };
	Complex b = { 0.14, -5 };

	compSum(a, b);
	compSub(a, b);

	printComplex(a);

	switch (getCompType(a)) {
		case 0: std::cout << "Число действительное\n"; break;
		case 1: std::cout << "Число мнимое\n"; break;
		case 2: std::cout << "Число комплексное\n"; break;
	}

	return 0;
}
