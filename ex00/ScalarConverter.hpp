#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <cerrno>
#include <cctype>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

class ScalarConverter
{
	private:
		static char	pCh;
		static int	pIn;
		static float	pFl;
		static double	pDo;

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter(void);
		ScalarConverter &operator=(ScalarConverter const &copy);

		static void printChar(char c);
		static void printInt(int i);
		static void printFloat(float f);
		static void printDouble(double d);
		static void printImpossible(void);
		static bool ispseudo(std::string str);
		static bool checkStr(char *s);
	public:
		static void convert(char *input);
};
