#include "Buchet.h"

Buchet::Buchet(const std::string& den, double p, bool per, const std::vector<std::string>& cul, int s, int f) : Produs(per, s), denumire(den), pret(p), nrFire(f), stoc(s) {

	cromatica = cul;
	std::cout << "Buchet" << std::endl;
}

std::string Buchet::getDen() const
{
	return denumire;
}

void Buchet::setStoc(int n)
{
	stoc -= n;
}

void Buchet::afisare() {
	std::cout << denumire << "  ||  " << pret << " RON "
		<< "  ||  " << stoc << "  ||  "<<
	this->specificatii()<<" <Numar Fire> "<<nrFire<<" ]"<<
	 "  ||  " << ((isPer(*this) == true) ? "perisabil" : "nonperisabil") << "\n\n";
}


std::string Buchet::specificatii() {
	std::string s = "[ ";
	for (const auto& item : cromatica) {
		s += item + " ";
	}
	
	return s;
}

void Buchet::aplicaReducere(int procent) {
	if (this->strategie != nullptr) {
		this->pret = this->pret - this->pret * this->strategie->getCoeficient();

	}
	else {
		this->pret = this->pret - (this->pret * procent / 100);
	}
}

std::unique_ptr<Produs> Buchet::clone() const {
	return std::make_unique<Buchet>(*this);
}

Buchet::~Buchet() {
	std::cout << "~Buchet" << std::endl;
}
