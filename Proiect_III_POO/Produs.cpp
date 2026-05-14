#include "Produs.h"
#include "Ghiveci.h"
#include "Fir.h"
#include "Ornament.h"
#include "Buchet.h"
#include <cstring>

int Produs::cont = 0;

Produs::Produs() {
	
	perisabil = 0;
	stoc = 0;

}

Produs::Produs(bool per, int s) : perisabil(per), stoc(s){
	std::cout << "Produs" << std::endl;
}

void Produs::afisare()
{
	std::cout << "P" << ++(Produs::cont) << std::endl;
}

void afisareDate(std::vector<std::unique_ptr<Produs>>& inventar) {
	Produs::cont = 0;
	for (const auto& item : inventar) {
		std::cout << ++Produs::cont << ".  ";
		item->afisare();
	}
}

void afisarePer(std::vector<std::unique_ptr<Produs>>& inventar) {
	for (const auto& item : inventar) {
		if(item->perisabil)
		item->afisare();
	}
}

void setAllStocs(std::vector<std::unique_ptr<Produs>>& inventar, int nrB) {
	for (const auto& item : inventar) {
			item->setStoc(-nrB);
	}
}

bool isPer(Produs& g) {
	return g.perisabil;
}

std::string Produs::getDen() const {
	return "";
}
void Produs::setStoc(int n)
{
	std::cout << "NUh Uh" << std::endl;
}



std::string Produs::specificatii() {
	return "";
}

bool verName(std::vector<std::unique_ptr<Produs>>& inventar, std::string s) {
	for (const auto& item : inventar) {
		const Fir* f = (dynamic_cast<const Fir*>(item.get()));
		const Ghiveci* g = (dynamic_cast<const Ghiveci*>(item.get()));
		const Ornament* o = (dynamic_cast<const Ornament*>(item.get()));
		const Buchet* b = (dynamic_cast<const Buchet*>(item.get()));

		if (f && f->denumire == s)
			return 1;
		else
			if (g && g->denumire == s)
				return 1;
			else
				if (o && o->denumire == s)
					return 1;
				else
					if (b && b->denumire == s)
						return 1;
	}
	return 0;
}

Produs::~Produs() = default;