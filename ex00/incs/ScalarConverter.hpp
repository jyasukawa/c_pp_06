#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <float.h>

class ScalarConverter//メンバがすべて static になっているクラスのことを、staticクラス（静的クラス）と呼ぶことがある。
{
	public:
		ScalarConverter(const ScalarConverter &copy_src);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter(void);

		static void	setChar();
		static void	setInt();
		static void	setFloat();
		static void	setDouble();

		static void	convert(const std::string &arg);
		static void	ft_print_message();

	private:
		ScalarConverter(void);
		// staticメンバはオブジェクトを生成せずに利用できるため、staticクラスはインスタンス化の必要性がないという点が特徴的です。そのため、staticクラスを作るのであれば、インスタンス化を禁止するように設計するのが親切でしょう。
		// C++ でインスタンス化を禁止するには、コンストラクタを「非公開」にします。
		// このコンストラクタが呼び出される可能性はないので、実は実装を書く必要もありませんし、書くべきでもありません。
		static std::string	_arg;
		static char		_c;
		static int		_i;
		static float	_f;
		static double	_d;
};

#endif
