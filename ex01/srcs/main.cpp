#include "Serializer.hpp"

int	main(void)
{
	Data			data;
	Data			*ptr = NULL;
	uintptr_t	u;

	data.n = 42;

	std::cout << "&data:	" << &data << std::endl;
	std::cout << "ptr:	" << ptr << std::endl;

	std::cout << "---------------------------- 1" << std::endl;

	u = Serializer::serialize(&data);
	std::cout << "u:	" << u << std::endl;
	ptr = Serializer::deserialize(u);
	std::cout << "ptr:	" << ptr << std::endl;

	std::cout << "---------------------------- 2" << std::endl;

	std::cout << ptr->n << std::endl;

	return (0);
}
