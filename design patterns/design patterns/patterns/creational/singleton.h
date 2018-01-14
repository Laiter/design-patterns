// Singleton
#pragma once

class Singleton
{
public:
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}
protected:
	Singleton() {};
	Singleton(const Singleton &classRef) {};
	Singleton& operator=(const Singleton &classRef) {};
};