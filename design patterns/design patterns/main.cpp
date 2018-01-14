// Design Patterns includes
#include <patterns\creational\factory_method.h>
#include <patterns\creational\abstract_factory.h>
#include <patterns\creational\singleton.h>
#include <patterns\creational\prototype.h>
#include <patterns\creational\object_pool.h>
#include <patterns\structural\adapter.h>
// Standard includes
#include <vector>
#include <iostream>

// Declare functions
// the definition is provided below
void doFactoryMethod();
void doAbstractFactory();
void doPrototype();
void doObjectPool();
void doAdapter();

int main()
{
	doFactoryMethod();
	doAbstractFactory();
	Singleton::getInstance();
	doPrototype();
	doAdapter();
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

void doAdapter()
{
	ExecuteInterface **adapter = InitializeAdapter();
	for (size_t i = 0; i < 3; i++)
	{
		adapter[i]->execute();
	}

	for (size_t i = 0; i < 3; i++)
	{
		delete adapter[i];
	}
	delete adapter;
}