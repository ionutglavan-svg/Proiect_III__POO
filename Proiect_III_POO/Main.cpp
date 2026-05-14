#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Produs.h"
#include "Comanda.h"
#include "Livrare.h"
#include "FuncCom.h"
#include "PC.h"
#include "Ghiveci.h"
#include "Fir.h"
#include "Ornament.h"
#include "Eroare.h"
#include "Buchet.h"
#include "Gestiune.h"
#include "ProdusFactory.h"
#include "StrategiePret.h"
#include "TipuriStrategii.h"



int citesteInt(int &x) 
{
		std::cin >> x;

		if (std::cin.fail()) //verifica daca a esuat citirea 
		{
			std::cin.clear(); //reseteaza flag ul de eroare
			std::cin.ignore(INT_MAX, '\n');
			throw std::runtime_error("\n\n ---- OPTIUNE INVALIDA ---- \n\n");
		}
		else {
			
			return x;
		}
}




int main()
{
	std::cout << "--- EVIDENTA DATELOR INTR-O FLORARIE --- \n\n";

	
	Gestiune<std::string> logEvenimente;
	logEvenimente.adauga("Aplicatia a pornit.");
	afiseazaInfoGestiune(logEvenimente);

	std::vector<std::unique_ptr<Produs>> inventar;
	std::vector<std::unique_ptr<Comanda>> comenzi;
	std::vector<std::unique_ptr<Livrare>> livrari;



	inventar.push_back(ProdusFactory::creeazaSimplu(1, "Trandafir", 6.7, 10, true,"rosu"));
	inventar.push_back(ProdusFactory::creeazaSimplu(1, "Lalea", 10.99, 8, true, "roz"));
	inventar.push_back(ProdusFactory::creeazaSimplu(2, "Ghiveci Lavanda", 27.99, 9, false, "ceramica"));
	inventar.push_back(ProdusFactory::creeazaSimplu(2, "Ghiveci Orhidee", 49.99, 8, false, "plastic"));
	inventar.push_back(ProdusFactory::creeazaComplex(3, "Ornament Floral", 40.50, 1, false, { "rosu", "galben", "portocaliu" }));
	inventar.push_back(ProdusFactory::creeazaComplex(3, "Trandafir criogenizat", 100, 2, false, { "rosu", "negru", "visiniu" }));
	inventar.push_back(ProdusFactory::creeazaComplex(4, "Buchet trandafiri", 100.34, 8, true, { "rosu", "roz", "alb" }, 25));
	
	comenzi.push_back(std::make_unique<Comanda>("0744 447 437", *inventar[0], 2, "Strada Copacului nr. 22"));
	comenzi.push_back(std::make_unique<Comanda>("0744 447 437", *inventar[1], 2, "Strada Copacului nr. 23"));
	comenzi.push_back(std::make_unique<Comanda>("0744 447 437", *inventar[2], 2, "Strada Copacului nr. 24"));
	comenzi.push_back(std::make_unique<Comanda>("0744 447 437", *inventar[3], 2, "Strada Copacului nr. 25"));
	comenzi.push_back(std::make_unique<Comanda>("0744 447 437", *inventar[4], 2, "Strada Copacului nr. 26"));
	comenzi.push_back(std::make_unique<Comanda>("0744 447 437", *inventar[5], 2, "Strada Copacului nr. 27"));
	comenzi.push_back(std::make_unique<Comanda>("0744 447 437", *inventar[6], 2, "Strada Copacului nr. 28"));



	livrari.push_back(std::make_unique<Livrare>(*comenzi[0], false));
	livrari.push_back(std::make_unique<Livrare>(*comenzi[1], false));
	livrari.push_back(std::make_unique<Livrare>(*comenzi[2], false));
	livrari.push_back(std::make_unique<Livrare>(*comenzi[3], false));
	livrari.push_back(std::make_unique<Livrare>(*comenzi[4], false));
	livrari.push_back(std::make_unique<Livrare>(*comenzi[5], false));
	livrari.push_back(std::make_unique<Livrare>(*comenzi[6], false));

	StrategieStandard  t1;
	StrategieSarbatori  t2;
	StrategieFidelitate  t3;
	
	int ok;//il folosesc ca sa citesc optiunea de la tastatura

	std::cout << "Apasati tasta :\n" << "0 -> EXIT\n" << "1 -> MENIU PRODUS\n"
		<< "2 -> MENIU COMANDA\n" << "3 -> MENIU LIVRARE\n" << "4 -> Vizualizare log\n\n\n";

	std::cin >> ok;

	while (ok)
	{
		
		switch (ok) {
		case 0:
			ok = 0;
			break;
		case 1:

			logEvenimente.adauga("Accesare meniu produs.(fara modificari)");
			std::cout << "----------------------------------------------------------------------------------------------------------------\n\n";
			std::cout << "------MENIU PRODUS-----\n\n";
			std::cout << "Apasati tasta :\n" << "0 -> BACK\n" << "1 -> AFISARE DATE PRODUSE\n"
				<< "2 -> APLICA O REDUCERE PE UN PRODUS\n" << "3 -> RESTOC\n\n\n";
			int m1; //m1 este notatie pentru meniul 1
			std::cin >> m1;//il folosesc ca sa citesc optiunea de la tastatura
			while (m1)
			{
				switch (m1) {

				case 0:
					m1 = 0;
					break;
				case 1:
					std::cout << "<-----------------------------\n";
					logEvenimente.adauga("Modificari produs: Viualiare produse.");
					afisareDate(inventar);
					std::cout << "\n";
					std::cout << "<-----------------------------\n";
					break;
				case 2:
					std::cout << "<-----------------------------\n";
					logEvenimente.adauga("Modificari produs: Aplica o reducere.");
					std::cout << "--- VARIANTE PRODUSE ---\n\n";
					afisareDate(inventar);
					std::cout << "--- INTRODUCETI PRODUSUL PE CARE VRETI SA APLICATI REDUCEREA ---\n\n";
					int var;//va fi una din variantele alese
					std::cin >> var;
					if (!(var < 1 || var>6))
					{
						std::cout << "--- OPTIUNI STRATEGII REDUCERI ---\n\n";
						std::cout << "--- 0 -> renuntare\n";
						std::cout << "--- 1 -> reducere sarbatori (80%)\n";
						std::cout << "--- 2 -> reducere fidelitate (90%)\n";
						int proc;
						std::cin >> proc;

						switch (var) {
						case 1:
							switch (proc){
								
							case 0:
								inventar[0]->setStrategie(&t1);
								inventar[0]->aplicaReducere(proc);
								break;
							case 1:
								inventar[0]->setStrategie(&t2);
								inventar[0]->aplicaReducere(proc);
								break;
							case 2:
								inventar[0]->setStrategie(&t3);
								inventar[0]->aplicaReducere(proc);
								break;
							}
							
							break;
						case 2:
							switch (proc) {

							case 0:
								inventar[1]->setStrategie(&t1);
								inventar[1]->aplicaReducere(proc);
								break;
							case 1:
								inventar[1]->setStrategie(&t2);
								inventar[1]->aplicaReducere(proc);
								break;
							case 2:
								inventar[1]->setStrategie(&t3);
								inventar[1]->aplicaReducere(proc);
								break;
							}
							break;
						case 3:
							switch (proc) {

							case 0:
								inventar[2]->setStrategie(&t1);
								inventar[2]->aplicaReducere(proc);
								break;
							case 1:
								inventar[2]->setStrategie(&t2);
								inventar[2]->aplicaReducere(proc);
								break;
							case 2:
								inventar[2]->setStrategie(&t3);
								inventar[2]->aplicaReducere(proc);
								break;
							}
							break;
						case 4:
							switch (proc) {

							case 0:
								inventar[3]->setStrategie(&t1);
								inventar[3]->aplicaReducere(proc);
								break;
							case 1:
								inventar[3]->setStrategie(&t2);
								inventar[3]->aplicaReducere(proc);
								break;
							case 2:
								inventar[3]->setStrategie(&t3);
								inventar[3]->aplicaReducere(proc);
								break;
							}
							break;
						case 5:
							switch (proc) {

							case 0:
								inventar[4]->setStrategie(&t1);
								inventar[4]->aplicaReducere(proc);
								break;
							case 1:
								inventar[4]->setStrategie(&t2);
								inventar[4]->aplicaReducere(proc);
								break;
							case 2:
								inventar[4]->setStrategie(&t3);
								inventar[4]->aplicaReducere(proc);
								break;
							}
							break;
						case 6:
							switch (proc) {

							case 0:
								inventar[5]->setStrategie(&t1);
								inventar[5]->aplicaReducere(proc);
								break;
							case 1:
								inventar[5]->setStrategie(&t2);
								inventar[5]->aplicaReducere(proc);
								break;
							case 2:
								inventar[5]->setStrategie(&t3);
								inventar[5]->aplicaReducere(proc);
								break;
							}
							break;
						case 7:
							switch (proc) {

							case 0:
								inventar[6]->setStrategie(&t1);
								inventar[6]->aplicaReducere(proc);
								break;
							case 1:
								inventar[6]->setStrategie(&t2);
								inventar[6]->aplicaReducere(proc);
								break;
							case 2:
								inventar[6]->setStrategie(&t3);
								inventar[6]->aplicaReducere(proc);
								break;
							}
							break;
						}
					}
					std::cout << "\n";
					std::cout << "<-----------------------------\n";
					break;
				case 3:
					std::cout << "<-----------------------------\n";
					logEvenimente.adauga("Modificari produs: Restoc.");
					std::cout << "OPTIUNI:\n->introduceti 0 pentru BACK;";
					std::cout << "\n->introduceti orice alt numar pentru a se face restoc la toate produsele;";//Daca vreau sa resetez toate stocurile, introduc numarul maxim de produse + 1
					std::cout << "\n->introduceti numarul unui produs(pentru restoc);\n\n";

					std::cout << "--- VARIANTE PRODUSE ---\n\n";
					afisareDate(inventar);
					int varianta;//va fi una din variantele alese
					std::cin >> varianta;
					if (varianta != 0)

					{
						//Setez stocul tuturor produselor la valoarea maxim posibila (cea initiala) in acelasi timp
						if (varianta < 1 || varianta>6)
						{
							std::cout << "--- INTRODUCETI NUMARUL DE BUCATI DORIT ---\n\n";
							int numarBuc;
							try {
								citesteInt(numarBuc);
								setAllStocs(inventar, numarBuc);
							}
							catch (const std::exception& e)
							{
								std::cout << e.what() << std::endl;
							}

						}
						else//Altfel setez stocul tuturor produselor la valoarea maxim posibila (cea initiala) selectiv
						{
							std::cout << "--- INTRODUCETI NUMARUL DE BUCATI DORIT ---\n\n";
							int numarBuc;
							try {
								citesteInt(numarBuc);
								switch (varianta) {
								case 1:
									inventar[0]->setStoc(-numarBuc);
									break;
								case 2:
									inventar[1]->setStoc(-numarBuc);
									break;
								case 3:
									inventar[2]->setStoc(-numarBuc);
									break;
								case 4:
									inventar[3]->setStoc(-numarBuc);
									break;
								case 5:
									inventar[4]->setStoc(-numarBuc);
									break;
								case 6:
									inventar[5]->setStoc(-numarBuc);
									break;
								case 7:
									inventar[6]->setStoc(-numarBuc);
									break;
								}
							}
							catch (const std::exception& e)
							{
								std::cout << e.what() << std::endl;
							}

						}
						std::cout << "------ ACTUALIZARE COMPLETA -----\n\n";
						afisareDate(inventar);
					}


					std::cout << "------ BACK -----\n";

					std::cout << "<-----------------------------\n";
					break;
				}
				std::cout << "Apasati tasta :\n" << "0 -> BACK\n" << "1 -> AFISARE DATE PRODUSE\n"
					<< "2 -> APLICA O REDUCERE PE UN PRODUS\n" << "3 -> RESTOC\n\n\n";
				std::cin >> m1;
			}
			std::cout << "----------------------------------------------------------------------------------------------------------------\n\n";
			break;

		case 2:
			logEvenimente.adauga("Accesare meniu comanda.(fara modificari)");
			std::cout << "----------------------------------------------------------------------------------------------------------------\n\n";
			std::cout << "------MENIU COMANDA-----\n\n";
			std::cout << "Apasati tasta :\n" << "0 -> BACK\n" << "1 -> AFISARE COMANDA\n"
				<< "2 -> STERGE COMANDA\n" << "3 -> ADAUGA COMANDA\n\n\n";
			int m2;//m1 este notatie pentru meniul 2
			std::cin >> m2;//il folosesc ca sa citesc optiunea de la tastatura
			while (m2)
			{
				switch (m2) {

				case 0:
					m2 = 0;
					break;
				case 1:
					std::cout << "<-----------------------------\n";
					logEvenimente.adauga("Modificari comanda: Vizualizare comenzi.");
					for (const auto& item : comenzi) {
						item->afisare();
					}
					std::cout << "\n";
					std::cout << "<-----------------------------\n";
					break;
				case 2:
					std::cout << "<-----------------------------\n";
					logEvenimente.adauga("Modificari comanda: Stergere comeni.");
					int k;//Va retine ID - ul comenzii destinate stergerii

					std::cout << "------MENIU STERGERE-----\n\n";
					std::cout << "Apasati tasta :\n" << "0 -> BACK\n" << "1 -> STERGERE SELECTIVA\n"
						<< "2 -> STERGERE COMENZI INVALIDE\n\n\n";
					int op;
					std::cin >> op;
					switch (op) {
					case 0:
						break;
					case 1:
						std::cout << "Introduceti ID-ul comenzii: ";
						std::cin >> k;
						std::cout << "\n";
						std::cout << "\n";
						if (0 < k && k <= Comanda::contor)
							strgLivrareComanda(comenzi, livrari, k);
						else
							std::cout << " ---- Reaccesati optiunea si introduceti un numar valid ---- \n";
						std::cout << "\n";
						for (const auto& item : comenzi) {
							item->afisare();
						}//Afisez lista actualizata
						std::cout << "\n";
						std::cout << "<-----------------------------\n";
						break;
					case 2:
						strgComenziEronate(comenzi);
						for (const auto& item : comenzi) {
							item->afisare();
						}//Afisez lista actualizata
						std::cout << "\n";
						std::cout << "<-----------------------------\n";
						break;
					}
					break;

				case 3:
					std::cout << "<-----------------------------\n\n";
					logEvenimente.adauga("Modificari comanda: Adaugare comeni.");

					int numar;//numarul de bucati

					std::string numePrd, NrTele, ad;
					//->numePrd este numele produsului
					//->NrTele este numarul de telefon
					//->ad este adresa (de livrare)


					std::cout << "---------	PRODUSE DISPONIBILE -----------";
					std::cout << "\n\n";
					afisareDate(inventar);
					std::cout << "\n";
					std::cout << "\n";


					try {
						std::cout << "	-> Numele produsului: ";
						std::getline(std::cin >> std::ws, numePrd);

						if (!verName(inventar, numePrd))
							throw NumeProdusInexistentException(numePrd);

						std::cout << "	-> Numarul de telefon in formatul `07XX XXX XXX` : ";
						std::getline(std::cin >> std::ws, NrTele);

						std::cout << "	-> Adresa dvs. : ";
						std::getline(std::cin >> std::ws, ad);

						std::cout << "	-> Numarul de bucati: ";
						std::cin >> numar;

						std::cout << "\n";

						Produs* produsGasit = nullptr;
						for (const auto& p : inventar) {
							if (p->getDen() == numePrd)
							{
								produsGasit = p.get();
								break;
							}


						}
						comenzi.push_back(std::make_unique<Comanda>(NrTele, *produsGasit, numar, ad));
						conectComToLiv(*comenzi.back(), livrari);


					}
					catch (const Eroare& e)
					{
						std::cout << "\n[EROARE SISTEM]: " << e.what() << "\n";
					}


					std::cout << "\n";

					std::cout << "-----------LISTA A FOST ACTUALIZATA CU SUSCCES-------------\n\n";
					std::cout << "\n";
					std::cout << "<-----------------------------\n";
					break;
				}

				std::cout << "Apasati tasta :\n" << "0 -> BACK\n" << "1 -> AFISARE COMANDA\n"
					<< "2 -> STERGE COMANDA\n" << "3 -> ADAUGA COMANDA\n\n\n";
				std::cin >> m2;


			}
			std::cout << "----------------------------------------------------------------------------------------------------------------\n\n";
			break;
		case 3:
			logEvenimente.adauga("Accesare meniu livrare.(fara modificari)");
			std::cout << "----------------------------------------------------------------------------------------------------------------\n\n";
			std::cout << "------MENIU LIVRARE-----\n\n";
			std::cout << "Apasati tasta :\n" << "0 -> BACK\n" << "1 -> AFISARE DATE LIVRARE\n"
				<< "2 -> MODIFICA STAREA UNEI LIVRARI\n\n\n";
			int m3;//m1 este notatie pentru meniul 3
			std::cin >> m3;//il folosesc ca sa citesc optiunea de la tastatura
			while (m3)
			{
				switch (m3) {

				case 0:
					m3 = 0;
					break;
				case 1:
					std::cout << "<-----------------------------\n";
					logEvenimente.adauga("Modificari livrare: Vizualizare livrari.");
					for (const auto& item : livrari) {
						item->afisare();
					}
					std::cout << "\n";
					std::cout << "<-----------------------------\n";
					break;
				case 2:
					std::cout << "<-----------------------------\n\n";
					logEvenimente.adauga("Modificari livrare: Modificare stare livrari.");
					std::cout << "Introduceti ID-ul livrarii careia ii va fi schimbata starea SAU 0 pentru a renunta: ";
					int x;
					//std::cin >> x;
					std::cout << "\n";

					try {
						citesteInt(x);
					}
					catch (const std::exception& e)
					{
						std::cout << e.what() << std::endl;
					}

					while (!existaLiv(livrari, x))
					{
						std::cout << "-- ID INVALID --\n\n";
						std::cout << "Reintroduceti: \na) Un ID valid;\nb) 0 (cancel)\n";
						try {
							citesteInt(x);
						}
						catch (const std::exception& e)
						{
							std::cout << e.what() << std::endl;
						}
						std::cout << "\n";
					}
					if (x != 0)
					{

						doTheWorkForMe(livrari, x);
						std::cout << "\n";
					}
					else {
						std::cout << "---- RENUNTARE ----\n\n";
					}
					std::cout << "<-----------------------------\n";
					break;
				}
				std::cout << "Apasati tasta :\n" << "0 -> BACK\n" << "1 -> AFISARE DATE LIVRARE\n"
					<< "2 -> MODIFICA STAREA UNEI LIVRARI\n\n\n";
				std::cin >> m3;
			}
			std::cout << "----------------------------------------------------------------------------------------------------------------\n\n";
			break;

		case 4:
			afiseazaElementeLog(logEvenimente);
			break;
		}
		afiseazaInfoGestiune(logEvenimente);
		std::cout << "Apasati tasta :\n" << "0 -> EXIT\n" << "1 -> MENIU PRODUS\n"
			<< "2 -> MENIU COMANDA\n" << "3 -> MENIU LIVRARE\n" << "4 -> Vizualizare log\n\n\n";
		std::cin >> ok;
	}
	afiseazaElementeLog(logEvenimente);
	std::cout << "----- LA REVEDERE -----" << "\n";




	return 0;
}