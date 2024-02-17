#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <float.h>

class ScalarConverter
{
	public:
		ScalarConverter(const ScalarConverter &copy_src);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter(void);

		ScalarConverter(const std::string &arg);

		void	setChar();
		void	setInt();
		void	setFloat();
		void	setDouble();

		void	ft_convert();
		void	ft_print_message();

	private:
		ScalarConverter(void);

		const std::string	_arg;
		char							_c;
		int								_i;
		float							_f;
		double						_d;
};

#endif
