// Adapter \ Wrapper 
#pragma once
#include <iostream>

class ExecuteInterface
{
public:
	virtual ~ExecuteInterface() {}
	virtual void execute() = 0;
};

template <class TYPE>
class ExecuteAdapter : public ExecuteInterface
{
public:
	ExecuteAdapter(TYPE *o, void(TYPE:: *m)()) 
	{
		object = o;
		method = m;
	}

	~ExecuteAdapter() 
	{
		delete object;
	}

	void execute() 
	{
		(object->*method)();
	}

private:
	TYPE *object;
	void(TYPE:: *method)();
};

class Funny
{
public:
	~Funny() 
	{
		std::cout << "Funny::dtor\n";
	}

	void doFunny() 
	{
		std::cout << "Funny::doFunny()\n";
	}
};

class Sunny
{
public:
	~Sunny() 
	{
		std::cout << "Sunny::dtor\n";
	}

	void doSunny() 
	{
		std::cout << "Sunny::doSunny()\n";
	}
};

class Bunny
{
public:
	~Bunny() 
	{
		std::cout << "Bunny::dtor\n";
	}

	void doBunny() 
	{
		std::cout << "Bunny::doBunny()\n";
	}
};

ExecuteInterface **InitializeAdapter() 
{
	ExecuteInterface **adapter = new ExecuteInterface *[3];

	adapter[0] = new ExecuteAdapter<Funny>(new Funny(), &Funny::doFunny);
	adapter[1] = new ExecuteAdapter<Sunny>(new Sunny(), &Sunny::doSunny);
	adapter[2] = new ExecuteAdapter<Bunny>(new Bunny(), &Bunny::doBunny);

	return adapter;
}