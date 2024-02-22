#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid argument!";
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}

// ./convert 0
// ./convert nan
// ./convert 42.0f

// ./convert a
// ./convert -a
// ./convert 7b
// ./convert -0
// ./convert +1
// ./convert +-1
// ./convert 42
// ./convert -42
// ./convert 42.0
// ./convert -42.0f
// ./convert 32
// ./convert 127
// ./convert 2147483647
// ./convert 3.4e+38f
// ./convert 1.8e+307


// static_cast がもっとも一般的なキャストです。
// 適切なキャストがどれか分からなければ、まず試すべきは static_cast です。このキャストが不適切であれば、コンパイルエラーになります。たとえば、ポインタや参照から const や volatile を取り除くようなキャストは拒否されます。
// 暗黙の型変換によって情報が失われる可能性があるとき、コンパイラは警告を出すことがありますが、これを（プログラマーの責任で）黙らせるためことが可能です。