#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base * generate(void)
{
	int select = std::time(0) % 3;

	switch (select)
	{
		case 0:
			std::cout << "Generate A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generate B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generate C" << std::endl;
			return new C();
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Pointer B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Pointer C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference C" << std::endl;
	}
	catch (std::exception &e) {}
}

int main(void)
{
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
    return (0);
}
