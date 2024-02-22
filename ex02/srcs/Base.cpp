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
			ptr = new(std::nothrow) A();
			if (ptr == NULL)
				std::exit(EXIT_FAILURE);
			break;
		case (1):
			ptr = new(std::nothrow) B();
			if (ptr == NULL)
				std::exit(EXIT_FAILURE);
			break;
		case (2):
			ptr = new(std::nothrow) C();
			if (ptr == NULL)
				std::exit(EXIT_FAILURE);
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
// dynamic_castは、C++で実行時の型安全性を提供するためのキャスト演算子の一つです。主に、クラス間の型の安全なダウンキャスト（基底クラスから派生クラスへの変換）に使用されます。このキャストは主にポリモーフィズム（多様性）を持つクラス階層での型安全な操作に用いられます。
// dynamic_castは、安全なダウンキャストを行います。これは、実際に指し示しているオブジェクトが指定された型であるかどうかを確認します。
// dynamic_castを使用するためには、対象のクラス階層で少なくとも1つ以上の仮想関数が存在する必要があります。これは、型情報を動的に取得するためです。

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The & type is A" << std::endl;
		return ;
	}
	catch (const std::exception &e)//std::bad_cast
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
// 参照であれば std::bad_cast例外（【標準ライブラリ】第１７章）が送出されます。
