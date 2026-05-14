#pragma once
#include <iostream>
#include "Produs.h"
class Comanda;
class Livrare {
	Comanda* cmdAsociata;
	int idCmd;
	bool livrat = false;

public:
	//CONSTRUCTOR fara parametrii
	Livrare();

	//CONSTRUCTOR cu parametrii
	Livrare(Comanda& c, bool liv);

	//Functie prieten destinata supraincarcarii operatorului de afisare
	friend std::ostream& operator<<(std::ostream& o, Livrare& p);



	//METODE

	void afisare();

	bool verIdpentruLiv(int id);

	//FUNCTIE PRIETEN comuna clasei Comanda destinata stergerii unei comenzi, si, implicit livrarea corespunzatoare ei (daca exista)
	friend void strgLivrareComanda(std::vector<std::unique_ptr<Comanda>>& comenzi, std::vector<std::unique_ptr<Livrare>>& livrari, int id);

	friend bool existaLiv(std::vector<std::unique_ptr<Livrare>>& livrari, int id);

	friend void doTheWorkForMe(std::vector<std::unique_ptr<Livrare>>& livrari, int id);

	friend void conectComToLiv(Comanda& c, std::vector<std::unique_ptr<Livrare>>& livrari);

	//DESTRUCTOR
	~Livrare();
};

bool existaLiv(std::vector<std::unique_ptr<Livrare>>& livrari, int id);

void doTheWorkForMe(std::vector<std::unique_ptr<Livrare>>& livrari, int id);