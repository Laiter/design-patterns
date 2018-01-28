// Design Patterns includes
// Creational
#include <patterns\creational\factory_method.h>
#include <patterns\creational\abstract_factory.h>
#include <patterns\creational\singleton.h>
#include <patterns\creational\prototype.h>
#include <patterns\creational\object_pool.h>
// Structural
#include <patterns\structural\adapter.h>
#include <patterns\structural\adapter2.h>
#include <patterns\structural\decorator.h>
#include <patterns\structural\proxy.h>
#include <patterns\structural\composite.h>
// Standard includes
#include <vector>
#include <iostream>

// Declare functions
// the definition is provided below
void doFactoryMethod();
void doAbstractFactory();
void doSingleton();
void doPrototype();
void doObjectPool();
void doAdapter();
void doAdapter2();
void doDecorator();
void doProxy();
void doComposite();

// Main
int main()
{
	doFactoryMethod();
	doAbstractFactory();
	doSingleton();
	doPrototype();
	doAdapter();
	doAdapter2();
	doDecorator();
	doProxy();
	doComposite();
	system("pause");
}

// Function def
void doFactoryMethod()
{
	std::cout << std::endl << "Factory Method:" << std::endl;
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
	std::cout << std::endl << "Abstract Factory:" << std::endl;
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

void doSingleton()
{
	std::cout << std::endl << "Singleton:" << std::endl;
	Singleton::getInstance();
	Singleton::getInstance();
}

void doPrototype()
{
	std::cout << std::endl << "Prototype:" << std::endl;
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
	std::cout << std::endl << "Object Pool:" << std::endl;
	ObjectPool pool;
	for (size_t i = 0; i < 1000; ++i)
	{
		Object* object = pool.createNewObject();
		pool.deleteObject(object);
	}
}

void doAdapter()
{
	std::cout << std::endl << "Adapter:" << std::endl;
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

void doAdapter2()
{
	std::cout << std::endl << "Adapter2:" << std::endl;
	Rectangle *r = new RectangleAdapter(100, 200, 50, 20);
	r->draw();
}

void doDecorator()
{
	std::cout << std::endl << "Decorator:" << std::endl;
	Decorator::Widget *decorator = 
		new Decorator::MoreFunDecorator(
			new Decorator::FunDecorator(
				new Decorator::Stuff({ 4, 8, 15, 16, 23, 42 })));
	decorator->draw();
}

void doProxy()
{
	std::cout << std::endl << "Proxy:" << std::endl;
	ProxySubject a("the quick brown fox jumped over the dog");
	a.execute();
	a->execute();
}

void doComposite()
{
	std::cout << std::endl << "Composite:" << std::endl;
	Row first(1);
	Row second(2);
	Column third(3);
	Column fourth(4);
	Row fifth(5);
	first.add(&second);
	first.add(&third);
	third.add(&fourth);
	third.add(&fifth);
	first.add(&Primitive(6));
	second.add(&Primitive(7));
	third.add(&Primitive(8));
	fourth.add(&Primitive(9));
	fifth.add(&Primitive(10));
	first.traverse();
}