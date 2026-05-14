#include "Comanda.h"
#include <algorithm>

int Comanda::contor = 0;

Comanda::Comanda()
{
	telefonClient = "";
	this->totalPlata = 0;
	this->nrProduse = 0;
	produs = "";
	this->id = 0;
	this->valid = 0;
	adresa = "";
}

Comanda::Comanda(const std::string tel, Produs& prd, int nr, const std::string adr) : id(++contor), nrProduse(nr)
{
	totalPlata = autoCalcTotPrice(prd, *this, nr);

	adresa = adr;

	giveYaName(prd, *this);

	telefonClient = tel;

	specificatii = prd.specificatii();
}

std::ostream& operator<<(std::ostream& t, Comanda& cmd)
{
	t << "Comanda numarul-> " << cmd.id << " || "
		<< "Continut comanda-> " << cmd.produs << " || " << "Specificatii-> " << cmd.specificatii << " || "
		<< "Numar Produse-> " << cmd.nrProduse << " || "
		<< "Pret total-> " << cmd.totalPlata
		<< " || " << "Contact-> " << cmd.telefonClient << " || "
		<< "Adresa-> " << cmd.adresa << "\n" << "\n" << "\n";
	return t;
}

void Comanda::afisare()
{
	if(valid)
	std::cout << *this;
	else
		std::cout<< "Comanda numarul-> " << id << " || "
		<< "Continut comanda-> " << produs << " || "<< "Specificatii-> " << specificatii << " || "
		<< "Numar Produse-> " << "STOC INSUFICIENT" << " || "
		<< "Pret total-> " << totalPlata
		<< " || " << "Contact-> " << telefonClient << " || "
		<< "Adresa-> " << adresa << "\n" << "\n" << "\n";
			
}


int Comanda::merita()
{
	if(valid)
		return id;
	return -1;
}

bool Comanda::verIdandValid(int n) {
	if (this != nullptr && id == n && valid)
		return 1;
	return 0;
}

void strgComenziEronate(std::vector<std::unique_ptr<Comanda>>& comenzi) {

		std::erase_if(comenzi, [](const auto& item) { return !item->valid; });
			std::cout << "!!!BAZA DE DATE A FOST ACTUALIZATA CU SUCCES!!!\n\n";
			
}

void swap(Comanda& prima, Comanda& aDoua) noexcept {
	using std::swap;
	swap(prima.telefonClient, aDoua.telefonClient);
	swap(prima.totalPlata, aDoua.totalPlata);
	swap(prima.nrProduse, aDoua.nrProduse);
	swap(prima.produs, aDoua.produs);
	swap(prima.id, aDoua.id);
	swap(prima.valid, aDoua.valid);
	swap(prima.adresa, aDoua.adresa);
	swap(prima.specificatii, aDoua.specificatii);
}

Comanda::Comanda(const Comanda& alta) :
	telefonClient(alta.telefonClient),
	totalPlata(alta.totalPlata),
	nrProduse(alta.nrProduse),
	produs(alta.produs),
	id(++contor),
	valid(alta.valid),
	adresa(alta.adresa),
	specificatii(alta.specificatii)
{
}

Comanda& Comanda::operator=(Comanda alta) {
	swap(*this, alta);
	return *this;
}



Comanda::~Comanda()
{
	std::cout << "~Comanda" << std::endl;
}


