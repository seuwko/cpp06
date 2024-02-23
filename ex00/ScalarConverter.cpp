#include "ScalarConverter.hpp"

char ScalarConverter::pCh = '\0';
int ScalarConverter::pIn = 0;
float ScalarConverter::pFl = 0.0f;
double ScalarConverter::pDo = 0.0;

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

void ScalarConverter::printChar(char c)
{
	pIn = static_cast<int>(c);
	pFl = static_cast<float>(c);
	pDo = static_cast<double>(c);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << pIn << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << pFl << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << pDo << std::endl;
}

void ScalarConverter::printInt(int i)
{
	if (i > 31 && i < 127)
	{
		pCh = static_cast<char>(i);
		std::cout << "char: '" << pCh << "'" << std::endl;
	}
	else if ((i >= 0 && i < 32) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	pFl = static_cast<float>(i);
	pDo = static_cast<double>(i);
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << pFl << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << pDo << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	if (f >= 32 && f < 127)
	{
		pCh = static_cast<char>(f);
		std::cout << "char: '" << pCh << "'" << std::endl;
	}
	else if ((f >= 0 && f < 32) || (f >= 127 && f < 128))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
	{
		pIn = static_cast<int>(f);
		std::cout << "int: " << pIn << std::endl;
	}
	pDo = static_cast<double>(f);
	if (floor(f) == f)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << pDo << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << pDo << std::endl;
	}
}

void ScalarConverter::printDouble(double d)
{
	if (d >= 32 && d < 127)
	{
		pCh = static_cast<char>(d);
		std::cout << "char: '" << pCh << "'" << std::endl;
	}
	else if ((d >= 0 && d < 32) || (d >= 127 && d < 128))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
	{
		pIn = static_cast<int>(d);
		std::cout << "int: " << pIn << std::endl;
	}
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		pFl = static_cast<float>(d);
		if (floor(d) == d)
			std::cout << "float: " << std::fixed << std::setprecision(1) << pFl << "f" << std::endl;
		else
			std::cout << "float: " << pFl << "f" << std::endl;
	}
	if (floor(d) == d)
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

bool ScalarConverter::ispseudo(std::string str)
{
	std::string pseudo[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (!str.compare(pseudo[i]))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (i < 3)
			{
				pFl = strtof(str.c_str(), NULL);
				pDo = static_cast<double>(pFl);
			}
			else
			{
				pDo = strtod(str.c_str(), NULL);
				pFl = static_cast<float>(pDo);
			}
			std::cout << std::showpos << "float: " << pFl << "f" << std::endl;
			std::cout << std::showpos << "double: " << pDo << std::endl;
			return (true);
		}
	}
	return (false);
}

bool ScalarConverter::checkStr(char *s)
{
	int i = 0;
	bool isDot = false;
	bool isE = false;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '.')
		return (true);
	while (s[i])
	{
		if (!isdigit(s[i]))
		{
			if (s[i] == '.')
			{
				if (isDot || !isdigit(s[i + 1]))
					return (true);
				else
					isDot = true;
			}
			else if (isDot && !isE && s[i] == 'e' && (s[i + 1] == '+' || s[i + 1] == '-'))
			{
				isE = true;
				i = i + 2;
			}
			else if (s[i] == 'f' && s[i + 1] == 0 && isDot)
				return (false);
			else
				return (true);
		}
		i++;
	}
	return (false);
}

void ScalarConverter::convert(char *input)
{
	std::string str(input);

	if (str.empty())
		return;
	if (str.length() == 1)
	{
		if (isdigit(input[0]))
		{
			pIn = atoi(input);
			printInt(pIn);
		}
		else
		{
			pCh = input[0];
			printChar(pCh);
		}
		return;
	}
	if (ispseudo(str))
		return;
	if (checkStr(input))
	{
		printImpossible();
		return;
	}
	double tmp = strtod(input, NULL);
	if (tmp == HUGE_VAL || tmp == -HUGE_VAL || errno == ERANGE || errno == EDOM || errno == EILSEQ)
	{
		printImpossible();
		return;
	}
	if (str.find('.') == std::string::npos)
	{
		if (tmp > INT_MAX || tmp < INT_MIN)
			printImpossible();
		else
		{
			pIn = atoi(input);
			printInt(pIn);
		}
		return;
	}
	if (str.find('f') != std::string::npos)
	{
		if (tmp > FLT_MAX || tmp < -FLT_MAX)
			printImpossible();
		else
		{
			pFl = strtof(input, NULL);
			printFloat(pFl);
		}
		return;
	}
	pDo = strtod(input, NULL);
	printDouble(pDo);
}
