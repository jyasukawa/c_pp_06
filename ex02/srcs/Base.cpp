#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
	// std::cout << "Base destructor called" << std::endl;
}

Base	*generate(void)
{
	Base *ptr = NULL;
	srand(time(NULL));
	int	i = rand() % 3;

	std::cout << i << std::endl;

	switch (i)
	{
		case (0):
			ptr = new A();
			break;
		case (1):
			ptr = new B();
			break;
		case (2):
			ptr = new C();
			break;
		default:
			break;
	}
	return (ptr);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "The * type is A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "The * type is B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "The * type is C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}
// 変換することができない型へ dynamic_cast を行おうとした場合、指定したものがポインタであれば、変換先のポインタ型で表現されるヌルポインタが返され、参照であれば std::bad_cast例外（【標準ライブラリ】第１７章）が送出されます。

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The & type is A" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "The & type is B" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "The & type is C" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}

	std::cout << "Error" << std::endl;
}
