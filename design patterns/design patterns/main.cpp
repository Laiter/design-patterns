// Design Patterns includes
#include <factory_method.h>
#include <abstract_factory.h>
#include <singleton.h>
#include <prototype.h>
#include <object_pool.h>
// Standard includes
#include <vector>
#include <iostream>

void doFactoryMethod();
void doAbstractFactory();
void doPrototype();
void doObjectPool();

int main()
{
	doFactoryMethod();
	doAbstractFactory();
	Singleton::getInstance();
	doPrototype();
	system("pause");
}

void doFactoryMethod()
{
	std::vector<Stooge*> roles;
	int choice;
	while (true)
	{
		std::cout << "Lol(1) Kek(2) Cheburek(3) print(0): ";
		std::cin >> choice;
		if (choice == 0)
			break;
		roles.push_back(Stooge::make_stooge(choice));
	}
	for (size_t i = 0; i < roles.size(); i++)
		roles[i]->slap_stick();
	for (size_t i = 0; i < roles.size(); i++)
		delete roles[i];
}

void doAbstractFactory()
{
	AbstractFactory::Factory* factory = 0;
#ifndef WINDOWS
	factory = new AbstractFactory::LinuxFactory;
#else
	factory = new AbstractFactory::WindowsFactory;
#endif

	AbstractFactory::Widget* w = factory->create_button();
	w->draw();
	display_window_one(factory);
	display_window_two(factory);
}

void doPrototype()
{
	std::vector<Prototype::Stooge *> roles;
	int choice;

	while (true) {
		std::cout << "Lol(1) Kek(2) Cheburek(3) print(0): ";
		std::cin >> choice;
		if (choice == 0)
			break;
		roles.push_back(
			Prototype::Factory::make_stooge(choice));
	}

	for (size_t i = 0; i < roles.size(); ++i)
		roles[i]->slap_stick();
	for (size_t i = 0; i < roles.size(); ++i)
		delete roles[i];
}

void doObjectPool()
{
	ObjectPool pool;
	for (size_t i = 0; i < 1000; ++i)
	{
		Object* object = pool.createNewObject();
		pool.deleteObject(object);
	}
}