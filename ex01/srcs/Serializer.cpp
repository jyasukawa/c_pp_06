#include "Serializer.hpp"

Serializer::Serializer(void)
{
	// std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy_src)
{
	// std::cout << "Serializer copy constructor called" << std::endl;
	*this = copy_src;
}

Serializer	&Serializer::operator=(const Serializer &rhs)
{
	// std::cout << "Serializer copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Serializer::~Serializer(void)
{
	// std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

// 整数型や列挙型と、ポインタ型との相互変換が行えます
// 保証されているのは、変換後の型から、変換前の型へきちんと戻せること