// Factory Method \ Virtual Constructor
#pragma once

#include <iostream>

class Stooge
{
public:
	static Stooge *make_stooge(int choice);
	virtual void slap_stick() = 0;
};

class Lol : public Stooge
{
public:
	void slap_stick()
	{
		std::cout << "Lol\n";
	}
};
class Kek : public Stooge
{
public:
	void slap_stick()
	{
		std::cout << "Kek\n";
	}
};
class Cheburek : public Stooge
{
public:
	void slap_stick()
	{
		std::cout << "Cheburek\n";
	}
};