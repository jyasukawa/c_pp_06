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

// reinterpret_cast は、式の値を変えずに、型だけを変えるようなキャストです。
// たとえば整数と浮動小数点数とでは表現方法が異なるように、型によって値の表現形式が異なることがありますが、reinterpret_cast は、そういったことに感知しません。式の値が、変換後の型においても適切なものかどうかは、プログラマーが責任を持たなければなりません。その意味で危険性があります。
// 整数型や列挙型と、ポインタ型との相互変換が行えます。型の大きさは実装依存ですから、情報を失わないために、変換後の型の大きさが十分であることをプログラマーが保証しなければなりません
// 異なるポインタ型同士や、異なる参照型同士の変換が行えます。しかし、変換後のポインタを間接参照した結果は実装依存です。保証されているのは、変換後の型から、変換前の型へきちんと戻せることだけです
// uintptr_tはポインタのアドレスを格納するのに十分な大きさを持つデータ型。