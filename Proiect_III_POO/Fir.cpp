#include "Fir.h"

Fir::Fir(const std::string& sir, double p, int s, bool per, const std::string& cul) : Produs(per,s), pret(p), nrFire(s), denumire(sir), culoare(cul){
	std::cout << "Fir" << std::endl;
}

void Fir::afisare() {
	std::cout << denumire << "  ||  " << pret << " RON "
		<< "  ||  " << nrFire << "  ||  " << culoare << "  ||  " << ((isPer(*this) == true) ? "perisabil" : "nonperisabil") << "\n\n";
}


std::string Fir::getDen() const
{
	return denumire;
}
void Fir::setStoc(int n)
{
	nrFire -= n;
}


void Fir::aplicaReducere(int procent) {
	if (this->strategie != nullptr) {
		this->pret = this->pret - this->pret * this->strategie->getCoeficient();

	}
	else {
		this->pret = this->pret - (this->pret * procent / 100);
	}
}

std::string Fir::specificatii() {
	return culoare;
}


std::unique_ptr<Produs> Fir::clone() const{
	return std::make_unique<Fir>(*this);
}

Fir::~Fir() {
	std::cout << "~Fir" << std::endl;
}
