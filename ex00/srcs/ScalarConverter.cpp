#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	// staticなら実装するべき
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

ScalarConverter::ScalarConverter(const std::string &arg) : _arg(arg), _c('\0'), _i(0), _f(0.0f), _d(0.0)
{
	// std::cout << "ScalarConverter string_name constructor called" << std::endl;
}

void	ScalarConverter::setChar()
{
	this->_c = this->_arg[0];
	this->_i = static_cast<int>(this->_c);
	this->_f = static_cast<float>(this->_c);
	this->_d = static_cast<double>(this->_c);
}

void	ScalarConverter::setInt()
{
	this->_i = std::stoi(this->_arg);//PDFよりまずstringを変換
	this->_c = static_cast<char>(this->_i);//並び順に依存関係あり
	this->_f = static_cast<float>(this->_i);
	this->_d = static_cast<double>(this->_i);
}

void	ScalarConverter::setFloat()
{
	this->_f = std::stof(this->_arg);
	this->_i = static_cast<int>(this->_f);
	this->_c = static_cast<char>(this->_i);//fではなくiなのは、PDFのexplicitlyによるもの
	this->_d = static_cast<double>(this->_f);
}

void	ScalarConverter::setDouble()
{
	this->_d = std::stod(this->_arg);
	this->_i = static_cast<int>(this->_d);
	this->_c = static_cast<char>(this->_i);
	this->_f = static_cast<float>(this->_d);
}

static void	ft_check_arg(const std::string &str)
{
	const std::string	type[4] = {"inf", "-inf", "+inf", "nan"};//NaN,-nanなどは対応しない

	for(int i = 0; i < 4; i++)
	{
		if(str == type[i] || str == (type[i] + "f"))
		{
			std::cout << "Char: " << "impossible" << std::endl;
			std::cout << "Int: " << "impossible" << std::endl;
			std::cout << "Float: " << type[i] + "f" << std::endl;
			std::cout << "Double: " << type[i] << std::endl;
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
	if (this->_i < -128 || this->_i > 127)
		std::cout << "Char: " << "impossible" << std::endl;
	else if (this->_i < 32 || this->_i == 127)
		std::cout << "Char: " << "Non displayable" << std::endl;
	else
		std::cout << "Char: " << "'" << this->_c << "'" << std::endl;
	if (this->_f < INT_MIN || this->_f > INT_MAX || this->_d < INT_MIN || this->_d > INT_MAX)
		std::cout << "Int: " << "impossible" << std::endl;
	else
		std::cout << "Int: " << this->_i << std::endl;
	
	if (this->_d < std::numeric_limits<float>::lowest() || this->_d > std::numeric_limits<float>::max())//FLT_MINだとダメ
		std::cout << "Float: " << "impossible" << std::endl;
	else
		std::cout << "Float: " << this->_f;
	if (this->_f == this->_i)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	std::cout << "Double:	" << this->_d;
	if (this->_d == this->_i)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::ft_convert()
{
	ft_check_arg(this->_arg);
	if (this->_arg.length() == 1)
		(this->_arg[0] >= '0' && this->_arg[0] <= '9') ? setInt() : setChar();
	else if (this->_arg.back() == 'f' && ft_isFloat(this->_arg) == true)
		setFloat();
	else if (this->_arg.find('.') != std::string::npos && ft_isDouble(this->_arg) == true)
		setDouble();
	else if (ft_isInt(this->_arg) == true)
		setInt();
	ft_print_message();
}
