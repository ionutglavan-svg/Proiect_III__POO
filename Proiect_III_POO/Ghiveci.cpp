#include "Ghiveci.h"

Ghiveci::Ghiveci(const std::string& sir, double p, int s, bool per, const std::string& sir2) : Produs(per,s), pret(p), stoc(s), denumire(sir), materialGhiveci(sir2){
	std::cout << "Ghiveci" << std::endl;
}

std::string Ghiveci::getDen() const
{
	return denumire;
}
void Ghiveci::setStoc(int n)
{
	stoc -= n;
}



void Ghiveci::afisare() {
	std::cout << denumire << "  ||  " << materialGhiveci << "  ||  " << pret << " RON "
				<< "  ||  " << stoc << "  ||  " << ((isPer(*this) == true) ? "perisabil" : "nonperisabil") << "\n\n";
}

std::string Ghiveci::specificatii() {
	return "-"+materialGhiveci+"-";
}

void Ghiveci::aplicaReducere(int procent) {
	if (this->strategie != nullptr) {
		this->pret = this->pret - this->pret * this->strategie->getCoeficient();

	}
	else {
		this->pret = this->pret - (this->pret * procent / 100);
	}
}

std::unique_ptr<Produs> Ghiveci::clone() const {
	return std::make_unique<Ghiveci>(*this);
}

Ghiveci::~Ghiveci()
{
	std::cout << "~Ghiveci" << std::endl;
}