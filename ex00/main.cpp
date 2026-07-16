#include "ScalarConverter.hpp"

#include <iostream>

int main(void)
{
	std::cout << "--- CHAR ---" << std::endl;
	ScalarConverter::convert("'a'");
	std::cout << std::endl;
	ScalarConverter::convert("'Z'");
	std::cout << std::endl;

	std::cout << "--- INT ---" << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("-42");
	std::cout << std::endl;
	ScalarConverter::convert("2147483647");   // INT_MAX
	std::cout << std::endl;
	ScalarConverter::convert("-2147483648");  // INT_MIN
	std::cout << std::endl;

	std::cout << "--- FLOAT ---" << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << std::endl;
	ScalarConverter::convert("4.2f");
	std::cout << std::endl;
	ScalarConverter::convert("-4.2f");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;

	std::cout << "--- DOUBLE ---" << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << std::endl;
	ScalarConverter::convert("4.2");
	std::cout << std::endl;
	ScalarConverter::convert("-4.2");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;

	std::cout << "--- CAS LIMITES ---" << std::endl;
	ScalarConverter::convert("42.0f");   // float rond → char '*'
	std::cout << std::endl;
	ScalarConverter::convert("256");     // hors plage ASCII → char impossible
	std::cout << std::endl;
	ScalarConverter::convert("-1");      // negatif → char impossible
	std::cout << std::endl;

	std::cout << "--- INVALIDE ---" << std::endl;
	ScalarConverter::convert("abc");
	std::cout << std::endl;
	ScalarConverter::convert("12abc");
	std::cout << std::endl;

	return 0;
}

