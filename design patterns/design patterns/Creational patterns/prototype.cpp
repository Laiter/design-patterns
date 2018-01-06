#include "prototype.h"

namespace Prototype
{
	Stooge* Factory::s_prototypes[] = {
		0, new Lol, new Kek, new Cheburek
	};

	Stooge* Factory::make_stooge(int choice) {
		return s_prototypes[choice]->clone();
	}
}