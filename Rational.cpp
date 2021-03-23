#include "Rational.h"
#include <iostream>

int main() {

	try {
		Rational drob;
		Rational drob1;
		Rational result;
		std::cin >> drob;
		result = drob;
		//std::cin >> drob1;
		result = result * drob / drob -drob + drob;
		int a[2323] = {};
		std::cout << a[0];
		std::cout << result;
	}
	catch(const char* error){
		std::cout << error << std::endl;
	}
}