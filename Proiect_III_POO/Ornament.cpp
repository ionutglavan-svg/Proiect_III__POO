#include "Ornament.h"

Ornament::Ornament(const std::string& sir, double p, bool per, const std::vector<std::string>& cul, int s) : Produs(per,s), pret(p), denumire(sir), stoc(s){
	cromatica = cul;
	std::cout << "Ornament" << std::endl;
}


std::string Ornament::getDen() const
{
	return denumire;
}

void Ornament::setStoc(int n)
{
	stoc -= n;
}

void Ornament::afisare() {
	std::cout << denumire << "  ||  " << pret << " RON "
		<< "  ||  " << stoc << "  ||  ";
	this->afisareCrom();
	std::cout << "  ||  " << ((isPer(*this) == true) ? "perisabil" : "nonperisabil") << "\n\n";
}

void Ornament::afisareCrom() {
	std::cout << "[ - ";
	for (const auto& item : this->cromatica) {
		std::cout << item << " - ";
	}
	std::cout << "]";

}

std::string Ornament::specificatii() {
	std::string s="[ ";
	for (const auto& item : cromatica) {
			s+=item+" ";
		}
	s += "]";
	return s;
}

void Ornament::aplicaReducere(int procent) {
	if (this->strategie != nullptr) {
		this->pret = this->pret - this->pret * this->strategie->getCoeficient();

	}
	else {
		this->pret = this->pret - (this->pret * procent / 100);
	}
}

std::unique_ptr<Produs> Ornament::clone() const {
	return std::make_unique<Ornament>(*this);
}

Ornament::~Ornament() {
	std::cout << "~Ornament" << std::endl;
}
