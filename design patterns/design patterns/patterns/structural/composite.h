#pragma once
#include <iostream>
#include <vector>

class Component
{
public:
	virtual void traverse() = 0;
};

class Primitive : public Component
{
private:
	int value;

public:
	Primitive(int val) : value(val) {}
	~Primitive() {}

	void traverse() override
	{
		std::cout << value << ") ";
	}
};

class Composite : public Component
{
private:
	int value;
	std::vector<Component *> child;

public:
	Composite(int val) : value(val) {}
	~Composite() {};

	void add(Component *comp)
	{
		child.push_back(comp);
	}

	void traverse() override
	{
		std::cout << value << " (";
		for (auto x : child)
		{
			x->traverse();
		}
	}
};

class Row : public Composite
{
public:
	Row(int val) : Composite(val) {}
	~Row() {}

	void traverse() final
	{
		std::cout << "Row";
		Composite::traverse();
	}
};

class Column : public Composite
{
public:
	Column(int val) : Composite(val) {}
	~Column() {}

	void traverse() final
	{
		std::cout << "Column";
		Composite::traverse();
	}
};