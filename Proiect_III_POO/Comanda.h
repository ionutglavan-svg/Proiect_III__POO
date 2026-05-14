#pragma once
#include <iostream>
#include "Produs.h"
#include "Fir.h"
#include "Ghiveci.h"
#include "Ornament.h"
#include "Buchet.h"
class Livrare;
class Comanda {
	std::string telefonClient;
	float totalPlata;
	int nrProduse;
	std::string produs;
	int id;
	bool valid = true;
	std::string adresa;
	std::string specificatii;
	friend std::ostream& operator<<(std::ostream& o, Livrare& p);

public:

	static int contor;//'contor' este incrementat la creerea unui nou obiect si decrementat la stergerea unui obiect de tip Comanda, el este ID - ul

	//CONSTRUCTOR fara parametrii
	Comanda();

	//CONSTRUCTOR cu parametrii
	Comanda(const std::string tel, Produs& prd, int nr, const std::string adr);

	//Functie prieten destinata supraincarcarii operatorului de afisare
	friend std::ostream& operator<<(std::ostream& t, Comanda& cmd);


	Comanda& operator=(Comanda alta);//op de copy si swap

	friend void swap(Comanda& prima, Comanda& aDoua) noexcept;// functie prietena swap

	Comanda(const Comanda& alta);//constructor de copiere

	//METODE

	void afisare();

	int merita();

	//FUNCTIE PRIETEN comuna clasei Livrare destinata stergerii unei comenzi, si, implicit livrarea corespunzatoare ei (daca exista)
	friend void strgLivrareComanda(std::vector<std::unique_ptr<Comanda>>& comenzi, std::vector<std::unique_ptr<Livrare>>& livrari, int id);
	
	friend void strgComenziEronate(std::vector<std::unique_ptr<Comanda>>& comenzi);

	friend void giveYaName(const Produs& p, Comanda& c);

	friend float autoCalcTotPrice(Produs& p, Comanda& c, int n);

	bool verIdandValid(int n);

	friend void conectComToLiv(Comanda& c, std::vector<std::unique_ptr<Livrare>>& livrari);

	//DESTRUCTOR
	~Comanda();
};
void strgComenziEronate(std::vector<std::unique_ptr<Comanda>>& comenzi);