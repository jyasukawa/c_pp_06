#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data
{
	int	n;
};

class Serializer
{
	public:
		Serializer(const Serializer &copy_src);
		Serializer &operator=(const Serializer &rhs);
		~Serializer(void);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer(void);
};

#endif
