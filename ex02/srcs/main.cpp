#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base *p = generate();

	identify(p);
	identify(*p);

	delete p;

	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }