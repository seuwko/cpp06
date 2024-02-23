#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string data;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &copy);
		~Serializer(void);
		Serializer &operator=(Serializer const &copy);

	public:
		static uintptr_t serializer(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
