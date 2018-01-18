// Proxy \ Surrogate
#pragma once
#include <string>
#include <iostream>

class Subject
{
public:
	virtual void execute() = 0;
};

class RealSubject : public Subject
{
public:
	RealSubject(std::string s)
	{
		str = s;
	}

	void execute() final
	{
		std::cout << str << std::endl;
	}

private:
	std::string str;
};

class ProxySubject : public Subject
{
public:
	ProxySubject(std::string s)
	{
		int num = 0;
		num = s.find_first_of(' ');
		first = s.substr(0, num);
		s = s.substr(num + 1);
		num = s.find_first_of(' ');
		second = s.substr(0, num);
		s = s.substr(num + 1);
		num = s.find_first_of(' ');
		third = s.substr(0, num);
		s = s.substr(num);
		ptr = new RealSubject(s);
	}

	RealSubject *operator->()
	{
		std::cout << first << ' ' << second;
		return ptr;
	}

	void execute()
	{
		std::cout << first << ' ' << third;
		ptr->execute();
	}

private:
	std::string first;
	std::string second;
	std::string third;
	RealSubject *ptr;
};
