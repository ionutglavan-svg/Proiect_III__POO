#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "StrategiePret.h"
class Comanda;
class Produs {
	int stoc;
	bool perisabil;
protected:
	StrategiePret* strategie = nullptr;
public:

	static int cont;//'cont' este destinat numerotarii produselor la afisare (este incrementat doar in functia de afisare)
	

	//CONSTRUCTOR fara parametrii
	Produs();

	//CONSTRUCTOR cu parametrii
	Produs(bool per, int s);



	//METODE + getteri/setteri obligatorii

	friend void afisareDate(std::vector<std::unique_ptr<Produs>>& inventar);

	friend void afisarePer(std::vector<std::unique_ptr<Produs>>& inventar);

	friend void setAllStocs(std::vector<std::unique_ptr<Produs>>& inventar, int nrB);

	friend float autoCalcTotPrice(Produs& p, Comanda& c, int n);

	friend void giveYaName(const Produs& p, Comanda& c);

	virtual void afisare() = 0;//Virtualizare intuitiva necorespunzatoare temei


	void setStrategie(StrategiePret* s) {
		this->strategie = s;
	}

	virtual void aplicaReducere(int procent) = 0; //Virtualizare nonintuitiva corespunzatoare temei

	virtual std::unique_ptr<Produs> clone() const = 0;

	friend bool isPer(Produs& g);


	virtual std::string getDen() const;

	virtual void setStoc(int n);

	virtual std::string specificatii();

	friend bool verName(std::vector<std::unique_ptr<Produs>>& inventar, std::string s);


	//DESTRUCTOR

	virtual ~Produs();


};

bool isPer(Produs& g);
void afisareDate(std::vector<std::unique_ptr<Produs>>& inventar);
void afisarePer(std::vector<std::unique_ptr<Produs>>& inventar);
void setAllStocs(std::vector<std::unique_ptr<Produs>>& inventar, int nrB);
bool verName(std::vector<std::unique_ptr<Produs>>& inventar, std::string s);