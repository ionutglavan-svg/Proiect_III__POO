#include "Livrare.h"
#include "Comanda.h"

Livrare::Livrare()
{
	this->cmdAsociata = NULL;
	this->idCmd = 0;
	this->livrat = 0;
}

Livrare::Livrare(Comanda& c, bool liv = false) : livrat(liv), cmdAsociata(&c){
	idCmd = c.merita();
}

std::ostream& operator<<(std::ostream& o, Livrare& p)
{
	o << "ID-comanda-livrare-> " << p.idCmd << "  |  "
		<< "Adresa-> " << p.cmdAsociata->adresa << "  |  "
		<< "Stare-> " << ((p.livrat == true) ? "livrat" : "nelivrat") << "  |  "
		<< "Numar Produs-> " << ((p.cmdAsociata->valid == true) ? (p.cmdAsociata)->nrProduse : 0) << "\n";
	return o;
}

void Livrare::afisare()
{
	if(idCmd!=-1)
		std::cout << *this;
			
}

bool Livrare::verIdpentruLiv(int id) {
	return (idCmd == id);
}

bool existaLiv(std::vector<std::unique_ptr<Livrare>>& livrari, int id) {
	for (const auto& item : livrari) {
		if (item->idCmd == id)
			return 1;
	}
	return 0;
}

void doTheWorkForMe(std::vector<std::unique_ptr<Livrare>>& livrari, int id) {
	for (const auto& item : livrari) {
		if (item->idCmd == id)
		{
			int op2;
			std::cout << " STATUS: -- " << ((item->livrat) ? "livrat" : "nelivart") << " -- \n\n" << "--- INTRODUCETI ---\n0 -> nelivrat\n1 / ALT NUMAR(natural) -> livrat\n\n";

			std::cin >> op2;
			if (op2 == 0)
				item->livrat=0;
			else
				item->livrat = 1;
		}
	}
}

Livrare::~Livrare()
{
	std::cout << "DESTRUCTOR: Sterg Livrare asociata CMD " << this->idCmd << std::endl;
	
}







