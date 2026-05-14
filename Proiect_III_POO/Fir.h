#pragma once
#include <iostream>
#include "Produs.h"
class Fir: public Produs
{
	std::string denumire;
	float pret;
	int nrFire;
	std::string culoare;
public:
	Fir(const std::string& sir, double p, int s, bool per, const std::string& cul);


	
	std::string getDen() const override ;

	void setStoc(int n)override;

	void afisare();

	std::string specificatii();

	friend void giveYaName(const Produs& f, Comanda& c);
	friend float autoCalcTotPrice(Produs& p, Comanda& c, int n);
	friend bool verName(std::vector<std::unique_ptr<Produs>>& inventar, std::string s);

	void aplicaReducere(int procent);

	std::unique_ptr<Produs> clone() const override;

	~Fir();
};

