#include "Rational.h"
#include <iostream>

int main() {

	try {
		Rational drob;
		Rational drob1;
		Rational result;
		std::cout << "enter numerator denomerator and full part"<< std::endl;
		
		std::cin >> drob;
		//drob.setDenomerator(0);
		std::cin >> drob1;
		result = drob+drob1;
		
		std::cout << result;
	}
	catch(const char* error){
		std::cout << error << std::endl;
	}
	return 0;
}