#include "factory_method.h"



Stooge * Stooge::make_stooge(int choice)
{
	if (choice == 1)
		return new Lol;
	else if (choice == 2)
		return new Kek;
	else
		return new Cheburek;
}
