#include "ScalarConverter.hpp"

#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cctype>

ScalarConverter::ScalarConverter() {
	std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

bool	isChar(const std::string &input) {
	return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

bool	isInt(const std::string &input) {
	size_t i = 0;
	if(input.empty())
		return false;
	if(input[i] == '-' || input[i] == '+')
		i++;
	if(i == input.length())
		return false;
	while(i < input.length())
	{
		if(!isdigit(input[i]))
			return false;
		i++;
	}
	return true;
}

bool	isFloat(const std::string &string)
{
	if(string == "-inff" || string == "+inff" || string == "nanf")
		return true;
	int len = string.length() - 1;
	if(len < 0 || string[len] != 'f')
		return false;

	size_t			i = 0;
	bool			hasDot = false;
	std::string	num = string.substr(0, len);

	if(num[i] == '-' || num[i] == '+')
		i++;
	while(i < num.length())
	{
		if(num[i] == '.' && !hasDot)
			hasDot = true;
		else if(!isdigit(num[i]))
			return false;
		i++;
	}
	return hasDot;
}

bool	isDouble(const std::string &string)
{
	if(string == "-inf" || string == "+inf" || string == "nan")
		return true;

	size_t			i = 0;
	bool			hasDot = false;

	if(string[i] == '-' || string[i] == '+')
		i++;

	while(i < string.length())
	{
		if(string[i] == '.' && !hasDot)
			hasDot = true;
		else if(!isdigit(string[i]))
			return false;
		i++;
	}
	return hasDot;
}

void	printChar(double d)
{
	std::cout << "char: ";
	if(std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if(!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void	printInt(double d)
{
	std::cout << "int: ";
	if(std::isnan(d) || std::isinf(d)
		|| d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

void	printFloat(double d)
{
	std::cout << "float: ";
	if(std::isnan(d))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if(std::isinf(d))
	{
		std::cout << (d < 0 ? "-inff" : "+inff") << std::endl;
		return ;
	}
	float f = static_cast<float>(d);
	std::cout << f;
	if(f == std::floor(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	printDouble(double d)
{
	std::cout << "double: ";
	if(std::isnan(d))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if(std::isinf(d))
	{
		std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
		return ;
	}
	std::cout << d;
	if(d == std::floor(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &string)
{
	double	d;

	if(isChar(string))
		d = static_cast<double>(string[1]);
	else if(isInt(string))
		d = static_cast<double>(atoi(string.c_str()));
	else if(isFloat(string))
		d = static_cast<double>(strtof(string.c_str(), NULL));
	else if(isDouble(string))
		d = strtod(string.c_str(), NULL);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
