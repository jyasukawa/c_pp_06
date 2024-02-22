#include "ScalarConverter.hpp"

// staticメンバ変数は、クラス定義内に記述しただけでは定義したことになりません。実体となる定義を別のところに書く必要がある。
// staticメンバ変数は、オブジェクトを生成せずとも、プログラム開始時にすでに存在しています。そして、その時点でゼロ初期化される。
// 通常のメンバ変数が、オブジェクト１つごとに別個に存在しているのに対して、staticメンバ変数は、クラスに対して１つだけしか存在しない。
std::string	ScalarConverter::_arg;
char		ScalarConverter::_c;
int			ScalarConverter::_i;
float		ScalarConverter::_f;
double	ScalarConverter::_d;

ScalarConverter::ScalarConverter(void)
{
	// staticクラスなら実装しないべき。
}

// ScalarConverter::ScalarConverter(void) : _arg("default"), _c('\0'), _i(0), _f(0.0f), _d(0.0)
// {
// 	// std::cout << "ScalarConverter default constructor called" << std::endl;
// }

ScalarConverter::ScalarConverter(const ScalarConverter &copy_src)
{
	// std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy_src;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	// std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	// std::cout << "ScalarConverter destructor called" << std::endl;
}

void	ScalarConverter::setChar()
{
	_c = _arg[0];
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_c);
	_d = static_cast<double>(_c);
}

void	ScalarConverter::setInt()
{
	_i = std::stoi(_arg);//PDFよりまずstringを変換
	_c = static_cast<char>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
}

void	ScalarConverter::setFloat()
{
	_f = std::stof(_arg);
	_i = static_cast<int>(_f);//並び順に注意
	_c = static_cast<char>(_i);//fではなくiなのは、ft_print_messageでオーバーフローをチェックするため
	_d = static_cast<double>(_f);
}

void	ScalarConverter::setDouble()
{
	_d = std::stod(_arg);
	_i = static_cast<int>(_d);
	_c = static_cast<char>(_i);
	_f = static_cast<float>(_d);
}

static void	ft_check_arg(const std::string &str)
{
	const std::string	type[4] = {"inf", "-inf", "+inf", "nan"};//NaN,-nanなどは対応しない

	for(int i = 0; i < 4; i++)
	{
		if(str == type[i] || str == (type[i] + "f"))
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << type[i] + "f" << std::endl;
			std::cout << "double: " << type[i] << std::endl;
			std::exit(EXIT_SUCCESS);
		}
	}
}

static bool	ft_isInt(const std::string &str)
{
	try
	{
		size_t	pos;
		std::stoi(str, &pos);

		// 全ての文字が変換された場合にのみ true を返す
		if (pos != str.length())
		{
			std::cerr << "Error: Invalid argument!" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		return (true);
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << "Error: Invalid argument!" << std::endl;
		std::exit(EXIT_FAILURE);
			// return false;  // 変換不可能な文字列
	}
	catch (const std::out_of_range&)
	{
		std::cerr << "Error: Overflows!" << std::endl;
		std::exit(EXIT_FAILURE);
			// return false;  // 値が double の範囲外
	}
}

static bool	ft_isFloat(const std::string &str)
{
	try
	{
		size_t	pos;
		std::stof(str, &pos);

		// 全ての文字が変換された場合にのみ true を返す
		if (pos != str.length() - 1)//fの分−１
		{
			std::cerr << "Error: Invalid argument!" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		return (true);
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << "Error: Invalid argument!" << std::endl;
		std::exit(EXIT_FAILURE);
			// return false;  // 変換不可能な文字列
	}
	catch (const std::out_of_range&)
	{
		std::cerr << "Error: Overflows!" << std::endl;
		std::exit(EXIT_FAILURE);
			// return false;  // 値が float の範囲外
	}
}

static bool	ft_isDouble(const std::string &str)
{
	try
	{
		size_t	pos;
		std::stod(str, &pos);

		// 全ての文字が変換された場合にのみ true を返す
		if (pos != str.length())
		{
			std::cerr << "Error: Invalid argument!" << std::endl;
			std::exit(EXIT_FAILURE);
		}
		return (true);
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << "Error: Invalid argument!" << std::endl;
		std::exit(EXIT_FAILURE);
			// return false;  // 変換不可能な文字列
	}
	catch (const std::out_of_range&)
	{
		std::cerr << "Error: Overflows!" << std::endl;
		std::exit(EXIT_FAILURE);
			// return false;  // 値が double の範囲外
	}
}

void	ScalarConverter::ft_print_message()
{
	if (_i < -128 || _i > 127)
		std::cout << "char: " << "impossible" << std::endl;
	else if (_i < 32 || _i == 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << _c << "'" << std::endl;
	if (_f < INT_MIN || _f > INT_MAX || _d < INT_MIN || _d > INT_MAX)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << _i << std::endl;
	
	if (_d < std::numeric_limits<float>::lowest() || _d > std::numeric_limits<float>::max())//FLT_MINだとダメ
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << _f;
	if (_f == _i)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	std::cout << "double:	" << _d;
	if (_d == _i)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string &arg)
{
	_arg = arg;
	ft_check_arg(_arg);
	if (_arg.length() == 1)
		(_arg[0] >= '0' && _arg[0] <= '9') ? setInt() : setChar();
	else if (_arg.back() == 'f' && ft_isFloat(_arg) == true)
		setFloat();
	else if (_arg.find('.') != std::string::npos && ft_isDouble(_arg) == true)
		setDouble();
	else if (ft_isInt(_arg) == true)
		setInt();
	ft_print_message();
}
