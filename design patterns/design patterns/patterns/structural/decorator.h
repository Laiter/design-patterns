// Decorator \ Wrapper+
#pragma once
#include <iostream>
#include <vector>

namespace Decorator
{
	class Widget
	{
	public:
		virtual void draw() = 0;
	};

	class Stuff : public Widget
	{
	public:
		Stuff(std::vector<int> things)
		{
			things_ = things;
		}

		void draw()
		{
			std::cout << "Stuff - ";
			for (auto item : things_)
			{
				std::cout << item << " ";
			}
			std::cout << std::endl;
		}

	private:
		std::vector<int> things_;
	};

	class Decorator : public Widget
	{
	public:
		Decorator(Widget *w)
		{
			wid = w;
		}

		void draw()
		{
			wid->draw();
		}

	private:
		Widget *wid;
	};

	class FunDecorator : public Decorator
	{
	public:
		FunDecorator(Widget *w) : Decorator(w) {}

		void draw()
		{
			Decorator::draw();
			std::cout << "Fun Stuff - 69\n";
		}
	};

	class MoreFunDecorator : public Decorator
	{
	public:
		MoreFunDecorator(Widget *w) : Decorator(w) {}

		void draw()
		{
			Decorator::draw();
			std::cout << "More fun Stuff - 420\n";
		}
	};
} // namespace Decorator
