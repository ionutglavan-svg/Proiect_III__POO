#pragma once
#include <iostream>
#include "Produs.h"

class Ghiveci: public Produs
{
	std::string denumire;
	float pret;
	std::string materialGhiveci;
	int stoc;

public:
	//Constr
	Ghiveci(const std::string& sir, double p, int s, bool per, const std::string& sir2);

	std::string getDen() const override;
	void setStoc(int n)override;

	void afisare();

	std::string specificatii();


	void aplicaReducere(int procent);

	std::unique_ptr<Produs> clone() const override;

	friend void giveYaName(const Produs& p, Comanda& c);
	friend float autoCalcTotPrice(Produs& p, Comanda& c, int n);
	friend bool verName(std::vector<std::unique_ptr<Produs>>& inventar, std::string s);

	~Ghiveci();
};
