// Singleton
#pragma once
#include <iostream>

class Singleton
{
public:
	static Singleton& getInstance()
	{
		std::cout << "Singleton::getInstance()\n";
		static Singleton instance;
		return instance;
	}
protected:
	Singleton() 
	{
		std::cout << "Singleton::ctor\n";
	}
	Singleton(const Singleton &classRef) {};
	Singleton& operator=(const Singleton &classRef) {};
};