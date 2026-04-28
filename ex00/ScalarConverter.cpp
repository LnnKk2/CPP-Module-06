#include "ScalarConverter.hpp"

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
	if(input[i] == '-' || input[i] == '+')
		i++;
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
	if(string[len] != 'f')
		return false;

	size_t			i = 0;
	bool			hasDot = false;
	std::string	num = string.substr(0, len);

	if(num[i] == '-' || num[i] == '+')
		i++;
	while(i <= num.length())
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

	while(i <= string.length())
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
	if(std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible" << std::endl;
	else if(d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if(!std::isprint(static_cast<int>(d)))
		std::cout << "char: non printable" << std::endl;
	else
		std::cout << "char '" << static_cast<char>(d) << "'" << std::endl;
}

void	printFloat(float f)
{
	if(std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	if(std::isinf(f))
	{
		if(f < 0 )
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
	}
		else
		std::cout << f;
		if(static_cast<int>(f))
		{
			std::cout << ".0";
			std::cout << "f";
			std::cout << std::endl;
		}
}

void	printDouble(double d)
{
	if(std::isnan(d))
		std::cout << "double: nan" << std::endl;
	if(std::isinf(d))
	{
		if(d < 0)
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << d;
		if(static_cast<int>(d))
		{
			std::cout << ".0";
			std::cout << std::endl;
		}
	}
}

void	printInt(double d)
{
	if(std::isinf(d) || std::isnan(d))
		std::cout << "Int: impossible" << std::endl;
	if(d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min())
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(d) << std::endl;
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
		std::cout << "Error: Invalid string" << std::endl;

	printChar(d);
	printDouble(d);
	printFloat(static_cast<float>(d));
	printInt(d);
}

