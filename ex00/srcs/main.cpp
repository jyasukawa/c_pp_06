#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid argument!";
		return (1);
	}
	
	ScalarConverter	converter(argv[1]);
	converter.ft_convert();
		
	return (0);
}

// ./convert 32
// ./convert 127
// ./convert 2147483647
// ./convert 3.4e+38f
// ./convert 1.8e+307