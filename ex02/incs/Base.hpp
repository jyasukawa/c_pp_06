#ifndef	BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
	public:
		virtual ~Base(void);//dynamic_castを使う条件、対象のクラス階層で少なくとも1つ以上の仮想関数が存在する必要があります。
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif