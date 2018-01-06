// Abstract Factory \ Kit
#pragma once

#include <iostream>

#define WINDOWS

namespace AbstractFactory
{
	// Widgets
	class Widget {
	public:
		virtual void draw() = 0;
	};

	class WindowsButton : public Widget {
	public:
		void draw() { std::cout << "WindowsButton\n"; }
	};

	class WindowsMenu : public Widget {
	public:
		void draw() { std::cout << "WindowsMenu\n"; }
	};

	class LinuxButton : public Widget {
	public:
		void draw() { std::cout << "LinuxButton\n"; }
	};

	class LinuxMenu : public Widget {
	public:
		void draw() { std::cout << "LinuxMenu\n"; }
	};

	// Factory
	class Factory {
	public:
		virtual Widget* create_button() = 0;
		virtual Widget* create_menu() = 0;
	};

	class WindowsFactory : public Factory {
	public:
		Widget * create_button() { return new WindowsButton; }
		Widget* create_menu() { return new WindowsMenu; }
	};

	class LinuxFactory : public Factory {
	public:
		Widget * create_button() { return new LinuxButton; }
		Widget* create_menu() { return new LinuxMenu; }
	};

	// Display func
	void display_window_one(Factory* factory) {
		Widget* w[] = { factory->create_button(), factory->create_menu() };
		w[0]->draw();  w[1]->draw();
	}

	void display_window_two(Factory* factory) {
		Widget* w[] = { factory->create_menu(), factory->create_button() };
		w[0]->draw();  w[1]->draw();
	}
}