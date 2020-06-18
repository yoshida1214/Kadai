#include "..\header\VariableType.h"
#include <iostream>
int main() {


	char16 a = '‚ ';
	int b;
	for (int i = 0;i < 32;i++)
	{
		a <<= 1;
		std::cout << a << std::endl;
	}
	std::cin >> b;
}