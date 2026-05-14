#include "FuncCom.h"
#include <vector>
#include <memory>
#include <iostream>

void strgLivrareComanda(std::vector<std::unique_ptr<Comanda>>& comenzi, std::vector<std::unique_ptr<Livrare>>& livrari, int id)
{	bool x = true;
for (const auto& item : comenzi) {
	if (item->verIdandValid(id))
	{
		//true daca voi continua, false daca ma razgandesc
		std::cout << "--ATENTIE! LIVRAREA CU ID-UL SELECTAT VA FI DE ASEMENEA STEARSA--\n\nDoriti sa continuati?	( 1->DA / 0->NU )\n\n";
		std::cin >> x;//aici decid daca ma razgandesc sau nu
		if (x)
		{
			std::erase_if(comenzi, [id](const auto& item) { return item->verIdandValid(id); });
			std::erase_if(livrari, [id](const auto& item) { return item->verIdpentruLiv(id); });
			std::cout << "!!!BAZA DE DATE A FOST ACTUALIZATA CU SUCCES!!!\n\n";
		}
	}
}
if(!x)
	std::cout << "!!!ABANDON!!!\n\n";


}

void conectComToLiv(Comanda& c, std::vector<std::unique_ptr<Livrare>>& livrari) {

	if (c.valid)//Daca comanda este valida, ii este creata si o livrare, altfel nu
		livrari.push_back(std::make_unique<Livrare>(c, false));

}
