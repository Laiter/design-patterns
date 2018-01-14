// Prototype

#pragma once

#include <iostream>

namespace Prototype
{
	class Stooge {
	public:
		virtual Stooge* clone() = 0;
		virtual void slap_stick() = 0;
	};

	class Factory {
	public:
		static Stooge* make_stooge(int choice);
	private:
		static Stooge* s_prototypes[4];
	};

	class Lol : public Stooge {
	public:
		Stooge * clone() { return new Lol; }
		void slap_stick() {
			std::cout << "Larry: poke eyes\n";
		}
	};
	class Kek : public Stooge {
	public:
		Stooge * clone() { return new Kek; }
		void slap_stick() {
			std::cout << "Moe: slap head\n";
		}
	};
	class Cheburek : public Stooge {
	public:
		Stooge * clone() { return new Cheburek; }
		void slap_stick() {
			std::cout << "Curly: suffer abuse\n";
		}
	};
}